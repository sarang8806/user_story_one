#include "ros/ros.h"
#include "user_story_one/vehicle_data.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vehicle_data_client");
  if (argc != 3)
  {
    ROS_INFO("usage: data required");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<user_story_one::vehicle_data>("add_two_ints");
  user_story_one::vehicle_data srv;
  srv.request.timestamp= atoll(argv[1]);
  if (client.call(srv))
  {
    ROS_INFO("Vehicle speed: %s", (string)srv.response.vehicle_speed);
    ROS_INFO("Engine speed: %s", (string)srv.response.engine_speed);
    ROS_INFO("Driver door status: %s", (string)srv.response.driver_door_status);
    ROS_INFO("Front passenger door status: %s", (string)srv.response.front_passenger_door_status);
    ROS_INFO("Rear left door status: %s", (string)srv.response.rear_left_door_status);
    ROS_INFO("Rear right door status: %s", (string)srv.response.rear_right_door_status);

  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
