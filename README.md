# user_story_one
ROS user story based on Automotive CAN signals

To RUN this package,

1) We should make sure that roscore is up and running in one terminal.

2) Run "rosrun user_story_one vehicle_data_server" command in another terminal. This is for running server node.

3) Run "rosrun user_story_one vehicle_data_client @timestamp" command in another terminal. This is for running client node and please 
replace @timestamp with timestamp vale (ex: 8420777).

NOTE: Make sure workspace related and file path related changes are done.
