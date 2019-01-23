#include "ros/ros.h"
#include "user_story_one/vehicle_data.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vehicle_data_client");
  if (argc != 2)
  {
    ROS_INFO("usage: data required");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<user_story_one::vehicle_data>("vehicle_data");
  user_story_one::vehicle_data srv;
  srv.request.timestamp = (std::string)argv[1];
  if (client.call(srv))
  {
    /*ROS_INFO("Vehicle speed: %s", (std::string)srv.response.vehicle_speed);
    ROS_INFO("Engine speed: %s", (std::string)srv.response.engine_speed);
    ROS_INFO("Driver door status: %s", (std::string)srv.response.driver_door_status);
    ROS_INFO("Front passenger door status: %s", srv.response.front_passenger_door_status);
    ROS_INFO("Rear left door status: %s", srv.response.rear_left_door_status);
    ROS_INFO("Rear right door status: %s", srv.response.rear_right_door_status); */

    std::cout<<"Vehicle speed:               "<< srv.response.vehicle_speed<<std::endl;
    std::cout<<"Engine speed:                "<< (std::string)srv.response.engine_speed<<std::endl;
    std::cout<<"Driver door status:          "<< (std::string)srv.response.driver_door_status<<std::endl;
    std::cout<<"Front passenger door status: "<< srv.response.front_passenger_door_status<<std::endl;
    std::cout<<"Rear left door status:       "<< srv.response.rear_left_door_status<<std::endl;
    std::cout<<"Rear right door status:      "<< srv.response.rear_right_door_status<<std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service vehicle_data");
    return 1;
  }

  return 0;
}
