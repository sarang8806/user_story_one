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
   std::string file_name = "/home/sarangp1/catkin_ws/src/user_story_one/src/can_data.csv";
   
   infile.open(file_name,std::ios::in);
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
      	  std::cout<<"Request: timestamp = "<<req.timestamp<<std::endl;
          std::cout<<"Sending back response:"<<std::endl;
          std::cout<<"msg_id:                      " <<res.msg_id<<std::endl
                   <<"vehicle_speed:               " <<res.vehicle_speed<<std::endl
                   <<"engine_speed:                " <<res.engine_speed<<std::endl
                   <<"driver_door_status:          " <<res.driver_door_status<<std::endl
                   <<"front_passenger_door_status: " <<res.front_passenger_door_status<<std::endl
                   <<"rear_left_door_status:       " <<res.rear_left_door_status<<std::endl
                   <<"rear_right_door_status:      " <<res.rear_right_door_status<<std::endl;
          break;
        }
      }
      infile.close();
      if(timestamp != req.timestamp)
      {
	ROS_INFO("No Matching Timestamp");
        return false;
      }
   }
   else
   {
     ROS_INFO("File open error");
     return false;
   }

   return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vehicle_data_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("vehicle_data", vehicle_status);
  ROS_INFO("Ready to receive inputs from client.");
  ros::spin();
  return 0;
}

