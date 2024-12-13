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
  "/doctor_console.DoctorConsoleService/GetSettings",
  "/doctor_console.DoctorConsoleService/SetSettings",
  "/doctor_console.DoctorConsoleService/GetUser",
  "/doctor_console.DoctorConsoleService/EyeCalibration",
  "/doctor_console.DoctorConsoleService/Login",
  "/doctor_console.DoctorConsoleService/Logout",
};

std::unique_ptr< DoctorConsoleService::Stub> DoctorConsoleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< DoctorConsoleService::Stub> stub(new DoctorConsoleService::Stub(channel, options));
  return stub;
}

DoctorConsoleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetSettings_(DoctorConsoleService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SetSettings_(DoctorConsoleService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetUser_(DoctorConsoleService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_EyeCalibration_(DoctorConsoleService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Login_(DoctorConsoleService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Logout_(DoctorConsoleService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DoctorConsoleService::Stub::GetSettings(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Settings* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetSettings_, context, request, response);
}

void DoctorConsoleService::Stub::async::GetSettings(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSettings_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::GetSettings(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSettings_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Settings>* DoctorConsoleService::Stub::PrepareAsyncGetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetSettings_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Settings>* DoctorConsoleService::Stub::AsyncGetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetSettingsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::SetSettings(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SetSettings_, context, request, response);
}

void DoctorConsoleService::Stub::async::SetSettings(::grpc::ClientContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetSettings_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::SetSettings(::grpc::ClientContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetSettings_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncSetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Settings, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SetSettings_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncSetSettingsRaw(::grpc::ClientContext* context, const ::doctor_console::Settings& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSetSettingsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::GetUser(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::User* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetUser_, context, request, response);
}

void DoctorConsoleService::Stub::async::GetUser(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetUser_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::GetUser(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::PrepareAsyncGetUserRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::User, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetUser_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::AsyncGetUserRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetUserRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::EyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_EyeCalibration_, context, request, response);
}

void DoctorConsoleService::Stub::async::EyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EyeCalibration_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::EyeCalibration(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EyeCalibration_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_EyeCalibration_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncEyeCalibrationRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncEyeCalibrationRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::Login(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::doctor_console::User* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Login_, context, request, response);
}

void DoctorConsoleService::Stub::async::Login(::grpc::ClientContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::Login(::grpc::ClientContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::User, ::doctor_console::Credentials, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Login_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::User>* DoctorConsoleService::Stub::AsyncLoginRaw(::grpc::ClientContext* context, const ::doctor_console::Credentials& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLoginRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status DoctorConsoleService::Stub::Logout(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::doctor_console::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Logout_, context, request, response);
}

void DoctorConsoleService::Stub::async::Logout(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, std::move(f));
}

void DoctorConsoleService::Stub::async::Logout(::grpc::ClientContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Logout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::PrepareAsyncLogoutRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Logout_, context, request);
}

::grpc::ClientAsyncResponseReader< ::doctor_console::Empty>* DoctorConsoleService::Stub::AsyncLogoutRaw(::grpc::ClientContext* context, const ::doctor_console::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLogoutRaw(context, request, cq);
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
               return service->GetSettings(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Settings, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Settings* req,
             ::doctor_console::Empty* resp) {
               return service->SetSettings(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::User* resp) {
               return service->GetUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::Empty* resp) {
               return service->EyeCalibration(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Credentials, ::doctor_console::User, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Credentials* req,
             ::doctor_console::User* resp) {
               return service->Login(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DoctorConsoleService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DoctorConsoleService::Service, ::doctor_console::Empty, ::doctor_console::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](DoctorConsoleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::doctor_console::Empty* req,
             ::doctor_console::Empty* resp) {
               return service->Logout(ctx, req, resp);
             }, this)));
}

DoctorConsoleService::Service::~Service() {
}

::grpc::Status DoctorConsoleService::Service::GetSettings(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Settings* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::SetSettings(::grpc::ServerContext* context, const ::doctor_console::Settings* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::GetUser(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::EyeCalibration(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::Login(::grpc::ServerContext* context, const ::doctor_console::Credentials* request, ::doctor_console::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DoctorConsoleService::Service::Logout(::grpc::ServerContext* context, const ::doctor_console::Empty* request, ::doctor_console::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace doctor_console
