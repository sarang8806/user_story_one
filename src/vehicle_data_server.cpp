#include "ros/ros.h"
#include <fstream>
#include <string>
#include "user_story_one/vehicle_data.h"

bool vehicle_status(user_story_one::vehicle_data::Request  &req,
        user_story_one::vehicle_data::Response  &res)
{
   ifstream infile;
   string timestamp;
   
   infile.open("can_data.csv");
   if(infile.is_open())
     ROS_INFO("File is open!"); 
   else
     ROS_INFO("File open error"); 

   while(!infile.eof())
   {
      getline(infile,res.msg_id,',');
      getline(infile,res.vehicle_speed,',');
      getline(infile,res.engine_speed,',');
      getline(infile,res.driver_door_status,',');
      getline(infile,res.front_passenger_door_status,',');
      getline(infile,res.rear_left_door_status,',');
      getline(infile,res.rear_right_door_status,',');
      infile>>timestamp;
      
      if(timestamp == req.timestamp)
      {  
        ROS_INFO("Request: timestamp=%ld", (long int)req.timestamp);
        ROS_INFO("Sending back response:\n");
        ROS_INFO("msg_id:                      %s", res.msg_id);
        ROS_INFO("vehicle_speed:               %s", res.vehicle_speed);
        ROS_INFO("engine_speed:                %s", res.engine_speed);
        ROS_INFO("driver_door_status:          %s", res.driver_door_status);
        ROS_INFO("front_passenger_door_status: %s", res.front_passenger_door_status);
        ROS_INFO("rear_left_door_status:       %s", res.rear_left_door_status);
        ROS_INFO("rear_right_door_status:      %s", res.rear_right_door_status);
        break;
      }
   }

   return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vehicle_data_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("vehicle_data", vehicle_status);
  ros::spin();
  return 0;
}

