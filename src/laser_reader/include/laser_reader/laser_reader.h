#ifndef LASER_TURTLE_H
#define LASER_TURTLE_H
#include "ros/node_handle.h"
#include "sensor_msgs/LaserScan.h"
#include <ros/ros.h>

class TurtleClass {
private:
    ros::NodeHandle n;
    ros::Subscriber laser_sub;
    void laser_callback(const sensor_msgs::LaserScan::ConstPtr &laser_msg);

    float *last_laser_ranges[10];
public:
    TurtleClass();
    ~TurtleClass();
};

#endif