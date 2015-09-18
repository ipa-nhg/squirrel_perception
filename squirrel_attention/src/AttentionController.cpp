/**
 * AttentionController.h
 *
 * Gets to look to from various attention channels and decides how to move the
 * camera (and robot if necessary).
 * 
 * @author Michael Zillich zillich@acin.tuwien.ac.at
 * @date Sept 2015
 */

#include <std_msgs/Float64.h>

#include <squirrel_attention/AttentionController.h>

AttentionController::AttentionController()
{
  // nh_.param("some", var_, defVal);
  panPub_ = nh_.advertise<std_msgs::Float64>("/pan_controller/command", 2);
  tiltPub_ = nh_.advertise<std_msgs::Float64>("/tilt_controller/command", 2);

  lookImageSrv_ = nh_.advertiseService("/attention/look_at_image_position", &AttentionController::lookAtImagePosition, this);
  lookSrv_ = nh_.advertiseService("/attention/look_at_position", &AttentionController::lookAtPosition, this);
  fixateSrv_ =  nh_.advertiseService("/attention/fixate_position", &AttentionController::fixatePosition, this);
  clearSrv_ = nh_.advertiseService("/attention/clear_fixation", &AttentionController::clearFixation, this);

  ros::spin();
}

AttentionController::~AttentionController()
{
  nh_.shutdown();
}

bool AttentionController::lookAtImagePosition(squirrel_object_perception_msgs::LookAtImagePosition::Request &req,
                                             squirrel_object_perception_msgs::LookAtImagePosition::Response &res)
{
  return true;
}

bool AttentionController::lookAtPosition(squirrel_object_perception_msgs::LookAtPosition::Request &req,
                                        squirrel_object_perception_msgs::LookAtPosition::Response &res)
{
  return true;
}

bool AttentionController::fixatePosition(squirrel_object_perception_msgs::FixatePosition::Request &req,
                                        squirrel_object_perception_msgs::FixatePosition::Response &res)
{
  return true;
}

bool AttentionController::clearFixation(squirrel_object_perception_msgs::ClearFixation::Request &req,
                                       squirrel_object_perception_msgs::ClearFixation::Response &res)
{
  return true;
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "attention_controller_node");
  AttentionController ac;
  exit(0);
}