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
    std::cout<<"Msg_id:                      "<< srv.response.msg_id<<std::endl
             <<"Vehicle speed:               "<< srv.response.vehicle_speed<<std::endl
             <<"Engine speed:                "<< srv.response.engine_speed<<std::endl
             <<"Driver door status:          "<< srv.response.driver_door_status<<std::endl
            <<"Front passenger door status: "<< srv.response.front_passenger_door_status<<std::endl
             <<"Rear left door status:       "<< srv.response.rear_left_door_status<<std::endl
             <<"Rear right door status:      "<< srv.response.rear_right_door_status<<std::endl;
  }
  else
  {
    ROS_ERROR("Failed to call service vehicle_data or unknown timestamp entered");
    return 1;
  }

  return 0;
}
