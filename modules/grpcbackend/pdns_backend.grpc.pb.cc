// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: pdns_backend.proto

#include "pdns_backend.pb.h"
#include "pdns_backend.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace pdnsbackend {

static const char* BackEnd_method_names[] = {
  "/pdnsbackend.BackEnd/LookUp",
};

std::unique_ptr< BackEnd::Stub> BackEnd::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< BackEnd::Stub> stub(new BackEnd::Stub(channel));
  return stub;
}

BackEnd::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_LookUp_(BackEnd_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BackEnd::Stub::LookUp(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::pdnsbackend::DNSReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_LookUp_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::pdnsbackend::DNSReply>* BackEnd::Stub::AsyncLookUpRaw(::grpc::ClientContext* context, const ::pdnsbackend::DNSLookupMessage& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::pdnsbackend::DNSReply>(channel_.get(), cq, rpcmethod_LookUp_, context, request);
}

BackEnd::Service::Service() {
  (void)BackEnd_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      BackEnd_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BackEnd::Service, ::pdnsbackend::DNSLookupMessage, ::pdnsbackend::DNSReply>(
          std::mem_fn(&BackEnd::Service::LookUp), this)));
}

BackEnd::Service::~Service() {
}

::grpc::Status BackEnd::Service::LookUp(::grpc::ServerContext* context, const ::pdnsbackend::DNSLookupMessage* request, ::pdnsbackend::DNSReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace pdnsbackend

