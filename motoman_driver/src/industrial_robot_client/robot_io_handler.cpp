#include "motoman_driver/industrial_robot_client/robot_io_handler.h"

using industrial::simple_message::SimpleMessage;


namespace industrial_robot_client
{
namespace robot_io_handler
{

bool RobotIOHandler::init(SmplMsgConnection* connection)
{
	this->connection_ = connection;
	connection_->makeConnect();

	this->srv_read_io_ = this->node_.advertiseService(
                             "read_io", &JointTrajectoryInterface::readIOCB, this);

	this->srv_write_io_ = this->node_.advertiseService(
                             "write_io", &JointTrajectoryInterface::writeIOCB, this);

}



bool RobotIOHandler::readIOCB(
	industrial_msgs::readIOCB::Request &req,
	industrial_msgs::readIOCB::Response &res)
{
  	/* DO COOL STUFF HERE */
	SimpleMessage request, reply;
	// here we need to create the request message
	ROS_INFO("Robot IO Handler: reading IO");
	this->connection_->sendAndReceiveMsg(request, reply);


	// no success/fail result from .  Assume success.
	res.code.val = industrial_msgs::ServiceReturnCode::SUCCESS;

	return true;  // always return true.  To distinguish between call-failed and service-unavailable.
}



bool RobotIOHandler::writeIOCB(
	industrial_msgs::writeIOCB::Request &req,
	industrial_msgs::writeIOCB::Response &res)
{
  	/* DO COOL STUFF HERE */
	SimpleMessage request, reply;
	// here we need to create the request message
	ROS_INFO("Robot IO Handler: sending IO command");
	this->connection_->sendAndReceiveMsg(request, reply);


	// no success/fail result from .  Assume success.
	res.code.val = industrial_msgs::ServiceReturnCode::SUCCESS;



  	

	// no success/fail result from .  Assume success.
	res.code.val = industrial_msgs::ServiceReturnCode::SUCCESS;

	return true;  // always return true.  To distinguish between call-failed and service-unavailable.
}


void RobotIOHandler::run()
{
  node_.spin();
}

}  // namespace robot_io_handler
}   // namespace industrial_robot_client