#include "maid/channel.h"
#include "channelimpl.h"

using maid::Channel;

Channel::Channel(uv_loop_t* loop)
{
    channel_ = new ChannelImpl(loop);
}

void Channel::CallMethod(const google::protobuf::MethodDescriptor* method,
        google::protobuf::RpcController* controller,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        google::protobuf::Closure* done)
{
    channel_->CallMethod(method, controller, request, response, done);
}

int64_t Channel::Listen(const char* host, int32_t port, int32_t backlog)
{
    return channel_->Listen(host, port, backlog);
}

int64_t Channel::Connect(const char* host, int32_t port, bool as_default)
{
    return channel_->Connect(host, port, as_default);
}

void Channel::AppendService(google::protobuf::Service* service)
{
    channel_->AppendService(service);
}

void Channel::set_default_fd(int64_t fd)
{
    channel_->set_default_fd(fd);
}

int64_t Channel::default_fd()
{
    return channel_->default_fd();
}

void Channel::Update()
{
    channel_->Update();
}

Channel::~Channel()
{
    delete channel_;
}
