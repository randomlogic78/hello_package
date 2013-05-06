 #include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello");
  ros::NodeHandle n;

  ros::Publisher hello_publisher = n.advertise<std_msgs::String>("hello_message", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    //ROS_INFO("%s", msg.data.c_str());
    if( 0 == count % 100 )
    {
	std::cout << ".";
	std::cout.flush();
    }

    hello_publisher.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
