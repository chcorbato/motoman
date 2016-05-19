

#include "motoman_driver/robot_io_handler.h"
#include "industrial_utils/param_utils.h"

using motoman::robot_io_handler::RobotIOHandler;

int main(int argc, char** argv)
{
	const int FS100_motion_port = 50240;  // FS100 uses a "non-standard" port to comply with MotoPlus guidelines

	// initialize node
	ros::init(argc, argv, "io_interface");

	// launch the FS100 RobotIOHandler connection/handlers
	RobotIOHandler io;

	if (io.init("", FS100_state_port, false))
	{
    	io.run();
	}
	return 0;
}
