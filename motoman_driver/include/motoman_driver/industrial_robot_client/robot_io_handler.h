#include "ros/ros.h"
#include "simple_message/simple_message.h"


namespace industrial_robot_client
{
namespace robot_io_handler
{
using industrial::smpl_msg_connection::SmplMsgConnection;
using industrial::tcp_client::TcpClient;
using industrial::simple_message::SimpleMessage;
/**
 
*/
class RobotIOHandler
{
public:
	RobotIOHandler() : {};

	/**
	* \brief Initialize robot connection using default method.
	*
	* \param default_ip default IP address to use for robot connection [OPTIONAL]
	*                    - this value will be used if ROS param "robot_ip_address" cannot be read
	* \param default_port default port to use for robot connection [OPTIONAL]
	*                    - this value will be used if ROS param "~port" cannot be read
	*
	* \return true on success, false otherwise
	*/
  virtual bool init(std::string default_ip = "", int default_port = StandardSocketPorts::MOTION, bool version_0 = false);



	/**
	* \brief Initialize robot connection using specified method.
	*
	* \param connection new robot-connection instance (ALREADY INITIALIZED).
	*
	* \return true on success, false otherwise
	*/
	virtual bool init(SmplMsgConnection* connection);

	virtual ~RobotIOHandler();


protected:

	/**
	* \brief Callback function registered to ROS readIO service
	*   Read IO data from robot robot.
	*
	* \param req ReadIO request from service call
	* \param res ReadIO response to service call
	* \return true always.  Look at res.code.val to see if call actually succeeded.
	*/
  virtual bool ReadIO(industrial_msgs::WriteIO::Request &req,
                            industrial_msgs::WriteIO::Response &res);

  	/**
	* \brief Callback function registered to ROS writeIO service
	*   Read IO data from robot robot.
	*
	* \param req WriteIO request from service call
	* \param res WriteIO response to service call
	* \return true always.  Look at res.code.val to see if call actually succeeded.
	*/
  virtual bool WriteIO(industrial_msgs::WriteIO::Request &req,
                            industrial_msgs::WriteIO::Response &res);


	ros::NodeHandle node_;
	ros::ServiceServer srv_read_io_;  // handle for io_read service
	ros::ServiceServer srv_write_io_;  // handle for io_write service

} // class

} // namespace robot_io_handler
} // namespace industrial_robot_client