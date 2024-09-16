#include "starpx.h"
#include <iostream>

using json = nlohmann::json;

int main()
{
    starpx::get_token();

    std::string json_body = R"(
    {
        "localTime": "2024-05-27T10:00:00Z",
        "geolocation": {
            "lat": 34.0522,
            "lon": -118.2437
        },
        "targetname": "Mars",
        "skycoordinates": {
            "ra": 14.66,
            "dec": -60.835
        }
    })";
    starpx::create_live_imaging_session(json_body);
    starpx::get_upload_url();
    starpx::file_uploaded();
    starpx::finish_session();
    std::string json_body2 = R"(
    {
        "skyCoordinate": {
            "ra": 180,
            "dec": 45
        },
        "radius": 1,
        "sourceList": [
            {
                "x": 256,
                "y": 256,
                "brightness": 1500,
                "background": 100
            }
        ],
        "clipList": [
            {
                "width": 64,
                "height": 64,
                "imageClip": "eJzT0yMAAGTvBe8="
            }
        ]
    })";
    starpx::perform_plate_solve_operation(json_body2);
    starpx::retrieve_plate_solve_results();
    return 0;
}