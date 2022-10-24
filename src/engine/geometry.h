#include <cmath>
#include <Eigen/Dense>
#include <iostream>

Eigen::Matrix4d rotation3d(Eigen::VectorXd angles){ //angles given in x, y, z
	Eigen::Matrix4d roll; 
        roll <<
		cos(angles[2]), -sin(angles[2]), 0, 0,
		sin(angles[2]), cos(angles[2]), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	;

	//std::cout << yaw << "\n\n";	

	Eigen::Matrix4d pitch;
       	pitch <<
		cos(angles[1]), 0, sin(angles[1]), 0,
		0, 1, 0, 0,
		-sin(angles[1]), 0, cos(angles[1]), 0,
		0, 0, 0, 1
	;	

	//std::cout << pitch << "\n\n";
	
	Eigen::Matrix4d yaw;
	yaw << 
		1, 0, 0, 0,
		0, cos(angles[0]), -sin(angles[0]), 0,
		0, sin(angles[0]), cos(angles[0]), 0,
		0, 0, 0, 1
	;

	//std::cout << roll << "\n\n";

	return yaw*pitch*roll;
}

Eigen::Matrix4d translation3d(Eigen::VectorXd transform){
	Eigen::Matrix4d ret;
	ret << 
		1, 0, 0, transform[0],
		0, 1, 0, transform[1],
		0, 0, 1, transform[2],
		0, 0, 0, 1
	;

	return ret;
}
