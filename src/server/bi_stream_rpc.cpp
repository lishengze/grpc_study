#include "bi_stream_rpc.h"

#include "../include/time_util.h"
#include <thread>
#include <chrono>

#include "server.h"
#include "config.h"


void ServerStreamAppleRPC::register_request()
{
    cout << "ServerStreamAppleRPC::register_request!" << endl;

    service_->RequestServerStreamApple(&context_, &responder_, cq_, cq_, this);
}

void ServerStreamAppleRPC::send_msg(string message, string rsp_id)
{
    try
    {
        // cout << "\nServerStreamAppleRPC::write_msg " << endl;
        int sleep_secs = 100;

        grpc::Status status;
        
        string name = "ServerStreamAppleRPC";
        string time = NanoTimeStr();
        reply_.set_name(name);
        reply_.set_time(time);
        reply_.set_session_id(session_id_);
        reply_.set_obj_id(std::to_string(obj_id_));
        reply_.set_response_id(rsp_id);
        reply_.set_message(message);

        // std::this_thread::sleep_for(std::chrono::milliseconds(sleep_secs)); 
        
        responder_.Write(reply_, this);

        cout << "[SERVER]: "
             << "session_id_=" << session_id_ 
             << ", rpc=" << rpc_id_
             << ", rsp_id=" << rsp_id 
             << ", msg=" << message
             << ", time=" << time 
             << "\n"
             << endl;

        // responder_.Finish(status, this);

        is_write_cq_ = true;

        if (!status.ok())
        {
            cout << "ServerStreamAppleRPC Write Error: " << status.error_details() << " " << status.error_message() << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\n[E] ServerStreamAppleRPC::write_msg " << e.what() << '\n';
    }

}

void ServerStreamAppleRPC::process_read_cq()
{
    try
    {
        responder_.Read(&request_, this);

        // cout << "[CLIENT]: session_id_=" << request_.session_id() 
        //      << ", rpc=" << request_.rpc_id()
        //      << ", req_id=" << request_.request_id()
        //      << ", time=" << request_.time() 
        //      << endl;

            // << ", name=" << request_.name() 
            
            // << ", obj_id=" << request_.obj_id() << endl;

        // 初次连接;
        if (request_.session_id().length() == 0)
        {
            cout << "Client Connect!" << endl;

            on_connect();
            
            return;
        }

        // cout << "[CLIENT]: session_id_=" << request_.session_id() 
        //      << ", rpc=" << request_.rpc_id()
        //      << ", req_id=" << request_.request_id()
        //      << ", time=" << request_.time() 
        //      << ", msg=" << request_.message() 
        //      << endl;        

        // 登陆请求；
        if (request_.message() == "login")
        {
            session_id_ = request_.session_id();

            on_req_login();
        }
        else
        {
            ++request_count_;
            if (request_count_ % 100 == 0)
            {
                cout << "[CLIENT]: session_id_=" << request_.session_id() 
                    << ", rpc=" << request_.rpc_id()
                    << ", req_id=" << request_.request_id()
                    << ", req_count=" << request_count_
                    << ", time=" << request_.time() 
                    << endl;
            }


            string session_id = request_.session_id();
            if (request_count_ == 1) 
            {
                TimeStruct time_struct;
                time_struct.test_start_time_ = std::stol(request_.time());
                
                test_time[session_id] = time_struct;
            }

            if (request_count_ == CONFIG->get_test_count())
            {
                test_time[session_id].test_end_time_ = NanoTime();

                long cost_micros = (test_time[session_id].test_end_time_ - test_time[session_id].test_start_time_) /1000;

                cout << "\n[R]Get " << session_id << " " << request_count_ << " request cost " 
                    << cost_micros << " micros" 
                    << " ave: " << cost_micros / request_count_ << " micros"
                    << endl;
            }

            // write_msg("", request_.request_id());
        }            
        
    }
    catch(const std::exception& e)
    {
        std::cerr <<"ServerStreamAppleRPC::process " << e.what() << '\n';
    }
    catch(...)
    {
        cout << "ServerStreamAppleRPC::process unkonwn exceptions" << endl;
    }
}

// void ServerStreamAppleRPC::process_write_cq()
// {
//     try
//     {
//         //  std::lock_guard<std::mutex> lk(mutex_);

//         // cout << "\nServerStreamAppleRPC::process obj_id = "  << obj_id_ << endl;

//         is_write_cq_ = false;
//         // cout << "This is Write_CQ" << endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr <<"ServerStreamAppleRPC::process " << e.what() << '\n';
//     }
//     catch(...)
//     {
//         cout << "ServerStreamAppleRPC::process unkonwn exceptions" << endl;
//     }    
// }

void ServerStreamAppleRPC::add_data(PackagePtr pkg)
{
    try
    {
        grpc::Status status;

        ApplePtr apple = GetField<Apple>(pkg);
        
        reply_.set_name(apple->name);
        reply_.set_time(apple->time);
        reply_.set_session_id(session_id_);
        reply_.set_obj_id(std::to_string(obj_id_));
        reply_.set_response_id(std::to_string(++rsp_id_));

        responder_.Write(reply_, this);

        cout << "[SERVER]: "
             << "session_id_=" << session_id_ 
             << ", rpc=" << rpc_id_
             << ", rsp_id=" << rsp_id_
             << ", msg=" << apple->message
             << ", time=" << apple->time 
             << "\n"
             << endl;

        is_write_cq_ = true;

        if (!status.ok())
        {
            cout << "ServerStreamAppleRPC Write Error: " << status.error_details() << " " << status.error_message() << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\n[E] ServerStreamAppleRPC::add_data " << e.what() << '\n';
    }
}

BaseRPC* ServerStreamAppleRPC::spawn()
{
    try
    {
        std::cout << "\n ******* Spawn A New ServerStreamAppleRPC Server For Next Client ********" << std::endl;
        std::lock_guard<std::mutex> lk(mutex_);

        ServerStreamAppleRPC* new_rpc = new ServerStreamAppleRPC(service_, cq_);
        new_rpc->set_server(server_);

        return new_rpc;
    } 
    catch(const std::exception& e)
    {
        std::cerr << "\n[E]  ServerStreamAppleRPC::spawn" << e.what() << '\n';
    }    
}
