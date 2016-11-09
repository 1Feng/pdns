#include "grpcbackend.hh"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using pdnsbackend::BackEnd;
using pdnsbackend::DNSReply;
using pdnsbackend::DNSReplyRecord;
using pdnsbackend::DNSLookupMessage;

static const char *kBackendId = "[GrpcBackend]";

GrpcBackend::GrpcBackend(const std::string& suffix) : index_(-1) {
  setArgPrefix("grpc"+suffix);
  std::string connection_str = getArg("connection-string");
  stub_ = BackEnd::NewStub(grpc::CreateChannel(connection_str,
                           grpc::InsecureChannelCredentials()));
}

void GrpcBackend::lookup(const QType &qtype, const DNSName& qdomain, DNSPacket *pkt_p, int zoneId) {
  if (index_ != -1)
    throw PDNSException("Attempt to lookup while one running");

  std::string localIP="0.0.0.0";
  std::string remoteIP="0.0.0.0";
  std::string realRemote="0.0.0.0/0";

  if (pkt_p) {
    localIP=pkt_p->getLocal().toString();
    realRemote = pkt_p->getRealRemote().toString();
    remoteIP = pkt_p->getRemote().toString();
  }

  DNSLookupMessage request;
  request.set_remote(remoteIP);
  request.set_real_remote(realRemote);
  request.set_qname(qdomain.toString());
  request.set_qtype(qtype.getName());
  DNSReply reply;
  ClientContext context;
  Status status = stub_->LookUp(&context, request, &reply);
  if (!status.ok()) {
    L << Logger::Error << kBackendId <<" rpc call failed with error: "
                    << status.error_message()
                    << " erro code : " << status.error_code() << endl;
    return;
  }
  DNSResourceRecord rr;
  for (int i = 0; i < reply.record_size(); ++i) {
    const DNSReplyRecord& record = reply.record(i);
    //printf("%s\t%s\t%s\t%d\n", record.qtype().c_str(),
    //                           record.qname().c_str(),
    //                           record.content().c_str(),
    //                           record.ttl());
    rr.qtype = record.qtype();
    rr.qname = DNSName(record.qname());
    rr.qclass = QClass::IN;
    rr.content = record.content();
    rr.ttl = record.ttl();
    rrs_.push_back(rr);
  }

  if (rrs_.empty())
    return;

  index_ = 0;
}

bool GrpcBackend::list(const DNSName& target, int domain_id, bool include_disabled) {
   return false;
}

bool GrpcBackend::get(DNSResourceRecord &rr) {
  if (index_ == -1) return false;

  rr.qtype = rrs_[index_].qtype;
  rr.qname = rrs_[index_].qname;
  rr.qclass = rrs_[index_].qclass;
  rr.content = rrs_[index_].content;
  rr.ttl = rrs_[index_].ttl;
  rr.domain_id = rrs_[index_].domain_id;
  rr.auth = rrs_[index_].auth;
  rr.scopeMask = rrs_[index_].scopeMask;

  index_++;

  // id index is out of bounds, we know the results end here.
  if (index_ == static_cast<int>(rrs_.size())) {
    std::vector<DNSResourceRecord>().swap(rrs_);
    index_ = -1;
  }
  return true;
}

class GrpcBackendFactory : public BackendFactory {
 public:
  GrpcBackendFactory() : BackendFactory("grpc") {}

  void declareArguments(const std::string &suffix="") {
    declare(suffix,"connection-string","Connection string","");
  }

  DNSBackend *make(const std::string &suffix="") {
    return new GrpcBackend(suffix);
  }
};

class GrpcLoader {
 public:
  //! This reports us to the main UeberBackend class
  GrpcLoader() {
    BackendMakers().report( new GrpcBackendFactory());
    L << Logger::Info << "This is module grpcbackend reporting" << std::endl;
  }
};

static GrpcLoader grpcloader;
