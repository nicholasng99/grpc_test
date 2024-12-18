// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: DoctorConsoleService.proto

#include "DoctorConsoleService.pb.h"
#include "DoctorConsoleService.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace doctor_console {

static const char* DoctorConsoleService_method_names[] = {
  "/doctor_console.DoctorConsoleService/getSettings",
  "/doctor_console.DoctorConsoleService/setSettings",
  "/doctor_console.DoctorConsoleService/getUser",
  "/doctor_console.DoctorConsoleService/startEyeCalibration",
  "/doctor_console.DoctorConsoleService/stopEyeCalibration",
  "/doctor_console.DoctorConsoleService/login",
  "/doctor_console.DoctorConsoleService/logout",
};

std::unique_ptr< DoctorConsoleService::Stub> DoctorConsoleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< DoctorConsoleService::Stub> stub(new DoctorConsoleService::Stub(channel, options));
  return stub;
}

DoctorConsoleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_getSettings_(DoctorConsoleService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_setSettings_(DoctorConsoleService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getUser_(DoctorConsoleService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_startEyeCalibration_(DoctorConsoleService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_stopEyeCalibration_(DoctorConsoleService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_login_(DoctorConsoleService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logout_(DoctorConsoleService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DoctorConsoleService::Stub::getSettings(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Settings* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getSettings_, context, request, response);
}

void DoctorConsoleService::Stub::async::getSettings(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getSettings_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::getSettings(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getSettings_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Settings>* DoctorConsoleService::Stub::PrepareAsyncgetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getSettings_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Settings>* DoctorConsoleService::Stub::AsyncgetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetSettingsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::setSettings(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_setSettings_, context, request, response);
}

void DoctorConsoleService::Stub::async::setSettings(::grpc::ClientContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_setSettings_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::setSettings(::grpc::ClientContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_setSettings_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncsetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_setSettings_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncsetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsetSettingsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::getUser(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::User* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getUser_, context, request, response);
}

void DoctorConsoleService::Stub::async::getUser(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getUser_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::getUser(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::PrepareAsyncgetUserRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::User, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getUser_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::AsyncgetUserRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetUserRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::startEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_startEyeCalibration_, context, request, response);
}

void DoctorConsoleService::Stub::async::startEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_startEyeCalibration_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::startEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_startEyeCalibration_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncstartEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_startEyeCalibration_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncstartEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncstartEyeCalibrationRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::stopEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_stopEyeCalibration_, context, request, response);
}

void DoctorConsoleService::Stub::async::stopEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_stopEyeCalibration_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::stopEyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_stopEyeCalibration_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncstopEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_stopEyeCalibration_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncstopEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncstopEyeCalibrationRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::login(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::doctor_console::User* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_login_, context, request, response);
}

void DoctorConsoleService::Stub::async::login(::grpc::ClientContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::login(::grpc::ClientContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::PrepareAsyncloginRaw(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::User, ::doctor_console::Credentials, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_login_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::AsyncloginRaw(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncloginRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::logout(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::User* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logout_, context, request, response);
}

void DoctorConsoleService::Stub::async::logout(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::logout(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::PrepareAsynclogoutRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::User, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logout_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::AsynclogoutRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogoutRaw(context, request, cq);
  result->StartCall();
  return result;
}

DoctorConsoleService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::Settings* resp) {
               return service->getSettings(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Settings* req,
             ::doctor_console::Empty* resp) {
               return service->setSettings(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::User* resp) {
               return service->getUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::Empty* resp) {
               return service->startEyeCalibration(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::Empty* resp) {
               return service->stopEyeCalibration(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Credentials* req,
             ::doctor_console::User* resp) {
               return service->login(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::User* resp) {
               return service->logout(ctx, req, resp);
             }, this)));
}

DoctorConsoleService::Service::~Service() {
}

::grpc::Status DoctorConsoleService::Service::getSettings(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::setSettings(::grpc::ServerContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::getUser(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::startEyeCalibration(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::stopEyeCalibration(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::login(::grpc::ServerContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::logout(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace doctor_console

