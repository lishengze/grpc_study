// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace TestPackage {

static const char* TestStream_method_names[] = {
  "/TestPackage.TestStream/TestSimple",
  "/TestPackage.TestStream/TestClientStream",
  "/TestPackage.TestStream/TestServerStream",
  "/TestPackage.TestStream/TestDoubleStream",
  "/TestPackage.TestStream/ServerStreamApple",
  "/TestPackage.TestStream/ServerStreamPear",
  "/TestPackage.TestStream/ServerStreamMango",
  "/TestPackage.TestStream/DoubleStreamApple",
  "/TestPackage.TestStream/DoubleStreamPear",
  "/TestPackage.TestStream/DoubleStreamMango",
};

std::unique_ptr< TestStream::Stub> TestStream::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< TestStream::Stub> stub(new TestStream::Stub(channel));
  return stub;
}

TestStream::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_TestSimple_(TestStream_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_TestClientStream_(TestStream_method_names[1], ::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_TestServerStream_(TestStream_method_names[2], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_TestDoubleStream_(TestStream_method_names[3], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_ServerStreamApple_(TestStream_method_names[4], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_ServerStreamPear_(TestStream_method_names[5], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_ServerStreamMango_(TestStream_method_names[6], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_DoubleStreamApple_(TestStream_method_names[7], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_DoubleStreamPear_(TestStream_method_names[8], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_DoubleStreamMango_(TestStream_method_names[9], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status TestStream::Stub::TestSimple(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::TestPackage::TestResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::TestPackage::TestRequest, ::TestPackage::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_TestSimple_, context, request, response);
}

void TestStream::Stub::experimental_async::TestSimple(::grpc::ClientContext* context, const ::TestPackage::TestRequest* request, ::TestPackage::TestResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::TestPackage::TestRequest, ::TestPackage::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TestSimple_, context, request, response, std::move(f));
}

void TestStream::Stub::experimental_async::TestSimple(::grpc::ClientContext* context, const ::TestPackage::TestRequest* request, ::TestPackage::TestResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_TestSimple_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncTestSimpleRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::TestPackage::TestResponse, ::TestPackage::TestRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_TestSimple_, context, request);
}

::grpc::ClientAsyncResponseReader< ::TestPackage::TestResponse>* TestStream::Stub::AsyncTestSimpleRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncTestSimpleRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientWriter< ::TestPackage::TestRequest>* TestStream::Stub::TestClientStreamRaw(::grpc::ClientContext* context, ::TestPackage::TestResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::TestPackage::TestRequest>::Create(channel_.get(), rpcmethod_TestClientStream_, context, response);
}

void TestStream::Stub::experimental_async::TestClientStream(::grpc::ClientContext* context, ::TestPackage::TestResponse* response, ::grpc::experimental::ClientWriteReactor< ::TestPackage::TestRequest>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::TestPackage::TestRequest>::Create(stub_->channel_.get(), stub_->rpcmethod_TestClientStream_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::TestPackage::TestRequest>* TestStream::Stub::AsyncTestClientStreamRaw(::grpc::ClientContext* context, ::TestPackage::TestResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::TestPackage::TestRequest>::Create(channel_.get(), cq, rpcmethod_TestClientStream_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::TestPackage::TestRequest>* TestStream::Stub::PrepareAsyncTestClientStreamRaw(::grpc::ClientContext* context, ::TestPackage::TestResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::TestPackage::TestRequest>::Create(channel_.get(), cq, rpcmethod_TestClientStream_, context, response, false, nullptr);
}

::grpc::ClientReader< ::TestPackage::TestResponse>* TestStream::Stub::TestServerStreamRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_TestServerStream_, context, request);
}

void TestStream::Stub::experimental_async::TestServerStream(::grpc::ClientContext* context, ::TestPackage::TestRequest* request, ::grpc::experimental::ClientReadReactor< ::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_TestServerStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::AsyncTestServerStreamRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_TestServerStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncTestServerStreamRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_TestServerStream_, context, request, false, nullptr);
}

::grpc::ClientReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::TestDoubleStreamRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_TestDoubleStream_, context);
}

void TestStream::Stub::experimental_async::TestDoubleStream(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::TestPackage::TestRequest,::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::TestPackage::TestRequest,::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_TestDoubleStream_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::AsyncTestDoubleStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_TestDoubleStream_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncTestDoubleStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_TestDoubleStream_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::ServerStreamAppleRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_ServerStreamApple_, context);
}

void TestStream::Stub::experimental_async::ServerStreamApple(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::TestPackage::TestRequest,::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::TestPackage::TestRequest,::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_ServerStreamApple_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::AsyncServerStreamAppleRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamApple_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncServerStreamAppleRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamApple_, context, false, nullptr);
}

::grpc::ClientReader< ::TestPackage::TestResponse>* TestStream::Stub::ServerStreamPearRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_ServerStreamPear_, context, request);
}

void TestStream::Stub::experimental_async::ServerStreamPear(::grpc::ClientContext* context, ::TestPackage::TestRequest* request, ::grpc::experimental::ClientReadReactor< ::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_ServerStreamPear_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::AsyncServerStreamPearRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamPear_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncServerStreamPearRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamPear_, context, request, false, nullptr);
}

::grpc::ClientReader< ::TestPackage::TestResponse>* TestStream::Stub::ServerStreamMangoRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_ServerStreamMango_, context, request);
}

void TestStream::Stub::experimental_async::ServerStreamMango(::grpc::ClientContext* context, ::TestPackage::TestRequest* request, ::grpc::experimental::ClientReadReactor< ::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_ServerStreamMango_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::AsyncServerStreamMangoRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamMango_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncServerStreamMangoRaw(::grpc::ClientContext* context, const ::TestPackage::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_ServerStreamMango_, context, request, false, nullptr);
}

::grpc::ClientReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::DoubleStreamAppleRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_DoubleStreamApple_, context);
}

void TestStream::Stub::experimental_async::DoubleStreamApple(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::TestPackage::TestRequest,::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::TestPackage::TestRequest,::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_DoubleStreamApple_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::AsyncDoubleStreamAppleRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamApple_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncDoubleStreamAppleRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamApple_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::DoubleStreamPearRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_DoubleStreamPear_, context);
}

void TestStream::Stub::experimental_async::DoubleStreamPear(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::TestPackage::TestRequest,::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::TestPackage::TestRequest,::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_DoubleStreamPear_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::AsyncDoubleStreamPearRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamPear_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncDoubleStreamPearRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamPear_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::DoubleStreamMangoRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), rpcmethod_DoubleStreamMango_, context);
}

void TestStream::Stub::experimental_async::DoubleStreamMango(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::TestPackage::TestRequest,::TestPackage::TestResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::TestPackage::TestRequest,::TestPackage::TestResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_DoubleStreamMango_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::AsyncDoubleStreamMangoRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamMango_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::TestPackage::TestRequest, ::TestPackage::TestResponse>* TestStream::Stub::PrepareAsyncDoubleStreamMangoRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::TestPackage::TestRequest, ::TestPackage::TestResponse>::Create(channel_.get(), cq, rpcmethod_DoubleStreamMango_, context, false, nullptr);
}

TestStream::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             const ::TestPackage::TestRequest* req,
             ::TestPackage::TestResponse* resp) {
               return service->TestSimple(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[1],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::TestPackage::TestRequest>* reader,
             ::TestPackage::TestResponse* resp) {
               return service->TestClientStream(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[2],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             const ::TestPackage::TestRequest* req,
             ::grpc::ServerWriter<::TestPackage::TestResponse>* writer) {
               return service->TestServerStream(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[3],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::TestPackage::TestResponse,
             ::TestPackage::TestRequest>* stream) {
               return service->TestDoubleStream(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[4],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::TestPackage::TestResponse,
             ::TestPackage::TestRequest>* stream) {
               return service->ServerStreamApple(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[5],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             const ::TestPackage::TestRequest* req,
             ::grpc::ServerWriter<::TestPackage::TestResponse>* writer) {
               return service->ServerStreamPear(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[6],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             const ::TestPackage::TestRequest* req,
             ::grpc::ServerWriter<::TestPackage::TestResponse>* writer) {
               return service->ServerStreamMango(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[7],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::TestPackage::TestResponse,
             ::TestPackage::TestRequest>* stream) {
               return service->DoubleStreamApple(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[8],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::TestPackage::TestResponse,
             ::TestPackage::TestRequest>* stream) {
               return service->DoubleStreamPear(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestStream_method_names[9],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestStream::Service, ::TestPackage::TestRequest, ::TestPackage::TestResponse>(
          [](TestStream::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::TestPackage::TestResponse,
             ::TestPackage::TestRequest>* stream) {
               return service->DoubleStreamMango(ctx, stream);
             }, this)));
}

TestStream::Service::~Service() {
}

::grpc::Status TestStream::Service::TestSimple(::grpc::ServerContext* context, const ::TestPackage::TestRequest* request, ::TestPackage::TestResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::TestClientStream(::grpc::ServerContext* context, ::grpc::ServerReader< ::TestPackage::TestRequest>* reader, ::TestPackage::TestResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::TestServerStream(::grpc::ServerContext* context, const ::TestPackage::TestRequest* request, ::grpc::ServerWriter< ::TestPackage::TestResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::TestDoubleStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::TestPackage::TestResponse, ::TestPackage::TestRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::ServerStreamApple(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::TestPackage::TestResponse, ::TestPackage::TestRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::ServerStreamPear(::grpc::ServerContext* context, const ::TestPackage::TestRequest* request, ::grpc::ServerWriter< ::TestPackage::TestResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::ServerStreamMango(::grpc::ServerContext* context, const ::TestPackage::TestRequest* request, ::grpc::ServerWriter< ::TestPackage::TestResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::DoubleStreamApple(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::TestPackage::TestResponse, ::TestPackage::TestRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::DoubleStreamPear(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::TestPackage::TestResponse, ::TestPackage::TestRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestStream::Service::DoubleStreamMango(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::TestPackage::TestResponse, ::TestPackage::TestRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace TestPackage

