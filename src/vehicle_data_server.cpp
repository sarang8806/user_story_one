#include "ros/ros.h"
#include <fstream>
#include <string>
#include <iostream>
#include "user_story_one/vehicle_data.h"

bool vehicle_status(user_story_one::vehicle_data::Request  &req,
        user_story_one::vehicle_data::Response  &res)
{
   std::ifstream infile;
   std::string timestamp;
   bool ret_val = true;
   
   ROS_INFO("Ready to receive inputs from client.");
   infile.open("/home/sarangp1/catkin_ws/src/user_story_one/src/can_data.csv",std::ios::in);
   if(infile)
   {
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
          //ROS_INFO("Request: timestamp=%s",(std::string)req.timestamp);
          /*std::cout<<"Request: timestamp="<<req.timestamp<<std::endl;
          ROS_INFO("Sending back response:\n");
          ROS_INFO("msg_id:                      %s", (std::string)res.msg_id);
          ROS_INFO("vehicle_speed:               %s", (std::string)res.vehicle_speed);
          ROS_INFO("engine_speed:                %s", res.engine_speed);
          ROS_INFO("driver_door_status:          %s", res.driver_door_status);
          ROS_INFO("front_passenger_door_status: %s", res.front_passenger_door_status);
          ROS_INFO("rear_left_door_status:       %s", res.rear_left_door_status);
          ROS_INFO("rear_right_door_status:      %s", res.rear_right_door_status); */

	  std::cout<<"Request: timestamp="<<req.timestamp<<std::endl;
          std::cout<<"Sending back response:\n";
          std::cout<<"msg_id:                      " <<res.msg_id<<std::endl;
          std::cout<<"vehicle_speed:               " <<res.vehicle_speed<<std::endl;
          std::cout<<"engine_speed:                " <<res.engine_speed<<std::endl;
          std::cout<<"driver_door_status:          " <<res.driver_door_status<<std::endl;
          std::cout<<"front_passenger_door_status: " <<res.front_passenger_door_status<<std::endl;
          std::cout<<"rear_left_door_status:       " <<res.rear_left_door_status<<std::endl;
          std::cout<<"rear_right_door_status:      " <<res.rear_right_door_status<<std::endl;
          break;
        }
      }
   }
   else
   {
     ROS_INFO("File open error");
     ret_val = false;
   }
   return ret_val;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vehicle_data_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("vehicle_data", vehicle_status);
  ros::spin();
  return 0;
}

