
#ifndef ROS_RECOGNIZER_VIEWER_H
#define ROS_RECOGNIZER_VIEWER_H

#include <nodelet/nodelet.h>
#include <sensor_msgs/PointCloud2.h>
#include <ros/ros.h>
#include <ros_recognizer/common/dynamic_configurator.h>
#include <ros_recognizer/visualization/visualizer.h>

namespace ros_recognizer
{

class Viewer : public nodelet::Nodelet
{
public:
  virtual void onInit();

private:
  ros::NodeHandle node_handle_;

  Visualizer visualizer_;
  std::unique_ptr<DynamicConfigurator<Visualizer>> visualizer_cfg_;

  ros::Timer spinTimer;
  void spinTimerCb(const ros::TimerEvent& event);
};

}

#endif //ROS_RECOGNIZER_VIEWER_H