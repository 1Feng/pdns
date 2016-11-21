// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: pdns_backend.proto
#ifndef GRPC_pdns_5fbackend_2eproto__INCLUDED
#define GRPC_pdns_5fbackend_2eproto__INCLUDED

#include "pdns_backend.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace pdnsbackend {

class BackEnd GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status LookUp(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::pdnsbackend::DNSReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::pdnsbackend::DNSReply>> AsyncLookUp(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::pdnsbackend::DNSReply>>(AsyncLookUpRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::pdnsbackend::DNSReply>* AsyncLookUpRaw(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status LookUp(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::pdnsbackend::DNSReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::pdnsbackend::DNSReply>> AsyncLookUp(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::pdnsbackend::DNSReply>>(AsyncLookUpRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::pdnsbackend::DNSReply>* AsyncLookUpRaw(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_LookUp_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status LookUp(::grpc::ServerContext* context, const ::pdnsbackend::DNSLookupMessage* request, ::pdnsbackend::DNSReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_LookUp : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_LookUp() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_LookUp() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LookUp(::grpc::ServerContext* context, const ::pdnsbackend::DNSLookupMessage* request, ::pdnsbackend::DNSReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLookUp(::grpc::ServerContext* context, ::pdnsbackend::DNSLookupMessage* request, ::grpc::ServerAsyncResponseWriter< ::pdnsbackend::DNSReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_LookUp<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_LookUp : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_LookUp() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_LookUp() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LookUp(::grpc::ServerContext* context, const ::pdnsbackend::DNSLookupMessage* request, ::pdnsbackend::DNSReply* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace pdnsbackend


#endif  // GRPC_pdns_5fbackend_2eproto__INCLUDED