#pragma once

#include "nlohmann/json.hpp"
#include "httplib.h"

#include <iostream>
#include <string>

using json = nlohmann::json;

namespace starpx
{
    void get_token()
    {
        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers =
            {
                {"Authorization", "Bearer YOUR_SECRET_TOKEN"},
                {"Apikey", ""}};
        auto res = client.Post("/v1/authenticate", headers, "", "application/json");
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void create_live_imaging_session(std::string json_body)
    {
        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers =
            {
                {"Content-Type", "application/json"},
                {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};

        auto res = client.Post("/v1/imagingsession/new", headers, json_body, "application/json");
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void get_upload_url()
    {
        std::string session_id = "__SESSION-ID__";
        std::string url = "/v1/imagingsession/upload/" + session_id;
        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers = {
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};

        auto res = client.Get(url.c_str(), headers);
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void file_uploaded()
    {
        std::string session_id = "__SESSION-ID__";
        std::string url = "/v1/imagingsession/upload/" + session_id;

        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers = {
            {"Content-Type", "application/json"},
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};

        std::string json_body = R"(
        {
            "fileId": "file123"
        })";

        auto res = client.Post(url.c_str(), headers, json_body, "application/json");
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void get_live_preview_details()
    {
        std::string session_id = "__SESSION-ID__";
        std::string url = "/v1/imagingsession/live-preview/" + session_id;

        httplib::Client client("https://api.starpx.com");

        httplib::Headers headers = {
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};
        auto res = client.Get(url.c_str(), headers);
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void finish_session()
    {
        std::string session_id = "__SESSION-ID__";
        std::string url = "/v1/imagingsession/finish/" + session_id;
        httplib::Client client("https://api.starpx.com");

        httplib::Headers headers = {
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};
        auto res = client.Post(url.c_str(), headers, "", "application/json");
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void perform_plate_solve_operation(std::string json_body)
    {
        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers = {
            {"Content-Type", "application/json"},
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};

        auto res = client.Post("/v1/platesolve", headers, json_body, "application/json");
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }

    void retrieve_plate_solve_results()
    {
        std::string platesolve_id = "__PLATESOLVE_ID__";
        std::string url = "/v1/platesolve/" + platesolve_id;
        httplib::Client client("https://api.starpx.com");
        httplib::Headers headers = {
            {"Authorization", "Bearer YOUR_SECRET_TOKEN"}};

        auto res = client.Get(url.c_str(), headers);
        json res_body = json::parse(res->body);
        if (res)
        {
            if (!res->body.empty())
            {
                json res_body = json::parse(res->body);
                std::cout << res_body.dump(4) << std::endl;
            }
        }
        else
        {
            std::cout << "Request failed: " << res.error() << std::endl;
        }
    }
}
