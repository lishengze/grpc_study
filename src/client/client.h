#pragma once

#include <iostream>

#include "../include/global_declare.h"
#include "data_struct.h"

#include "cpp/test.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/alarm.h>

#include "package_simple.h"
#include "user_rpc.h"

using grpc::Alarm;
using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientAsyncReader;
using grpc::ClientReader;

using grpc::ClientReaderWriter;
using grpc::ClientAsyncReaderWriter;

using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using TestPackage::TestStream;

using TestPackage::TestRequest;
using TestPackage::TestResponse;

using std::cout;
using std::endl;

class BaseClient
{
public:

    BaseClient(std::shared_ptr<Channel> channel):
        stub_{TestStream::NewStub(channel)}
    {
        // cout << "Client connect: " << stub_-> 
    }

    virtual ~BaseClient();

    virtual void start();

    virtual void thread_run();

    virtual void request() { }

      

    std::unique_ptr<TestPackage::TestStream::Stub>  stub_;    
    CompletionQueue*                                cq_;
    std::shared_ptr<std::thread>                    thread_{nullptr};    
};

class TestSimpleClient:public BaseClient
{

public:
    TestSimpleClient(std::shared_ptr<Channel> channel):BaseClient(channel)
    {

    }

    virtual ~TestSimpleClient(){ }

    // virtual void start();

    // virtual void thread_run();

    virtual void request();


private:
    TestRequest                                     request_;
    TestResponse                                    reply_;    
    bool                                            is_ansyc_{false};
    
    std::unique_ptr<ClientAsyncResponseReader<TestResponse>> rpc_;
};

class ServerStreamClient:public BaseClient
{

public:
    ServerStreamClient(std::shared_ptr<Channel> channel):BaseClient(channel)
    {

    }

    virtual ~ServerStreamClient(){ }

    // virtual void start();

    // virtual void thread_run();

    virtual void request();


private:
    TestRequest                                     request_;
    TestResponse                                    reply_;    
    bool                                            is_ansyc_{true};

    std::unique_ptr<ClientReader<TestResponse>>     sync_rpc_;

    std::unique_ptr<ClientAsyncReaderWriter<TestRequest, TestResponse>> async_rpc_;
};

class ServerStreamAppleClient:public BaseClient
{

public:
    ServerStreamAppleClient(std::shared_ptr<Channel> channel):BaseClient(channel)
    {

    }

    virtual ~ServerStreamAppleClient(){ }

    // virtual void start();

    // virtual void thread_run();

    virtual void request();


private:
    TestRequest                                     request_;
    TestResponse                                    reply_;    
    bool                                            is_ansyc_{true};

    std::unique_ptr<ClientAsyncReaderWriter<TestRequest, TestResponse>> async_rpc_;
};

class ClientBaseRPC;
class ClientApplePRC;

class AsyncClient
{
public:

    AsyncClient(std::shared_ptr<Channel> channel, string session_id):
                channel_{channel}, session_id_{session_id}
    {
        // cout << "Client connect: " << stub_-> 
    }

    virtual ~AsyncClient() 
    {
        if (cq_thread_ &&  cq_thread_->joinable())
        {
            cq_thread_->join();
        }
    }

    void start();

    void init_rpc_client();

    void init_cq_thread();

    void run_cq_loop();

    void set_client_map(RpcType rpc_id, ClientBaseRPC* client_rpc);

    void add_data(PackagePtr pkg);   

    void reconnect(ClientBaseRPC* rpc);

    void check_dead_rpc(ClientBaseRPC* rpc);

    void record_dead_rpc(ClientBaseRPC* rpc);

    std::shared_ptr<Channel>                        channel_;

    CompletionQueue                                 cq_;

    string                                          session_id_;
    
    boost::shared_ptr<std::thread>                  cq_thread_{nullptr};   

    ClientApplePRC*                                 apple_rpc_{nullptr};

    DoubleApplePRC*                                 double_rpc_{nullptr};

    map<RpcType, ClientBaseRPC*>                    client_rpc_map_;

    set<int>                                        dead_rpc_id_set_;

    map<RpcType, map<SessionType, ClientBaseRPC*>>  wait_to_release_rpc_map_;    

    std::mutex                                      cq_mutex_;

    

};

using AsyncClientPtr = boost::shared_ptr<AsyncClient>;


class SyncClient
{
    public:
        SyncClient(std::shared_ptr<Channel> channel, string session_id):
        channel_(channel), session_id_{session_id} 
        {

        }

        ~SyncClient();

        void start();

        void thread_main();

        void request_();

private:

    boost::shared_ptr<std::thread>      thread_{nullptr};
    std::shared_ptr<Channel>            channel_{nullptr};
    string                              session_id_{""};
    string                              rpc_id_{"DoubleStreamApple"};
};

using SyncClientPtr = boost::shared_ptr<SyncClient>;