#pragma warning (push)

#include <iostream>
#include <Eigen/Dense>
#include "engine/geometry.h"

int main(int argc, char* argv[]){
	Eigen::Vector3d vec(1.0, 2.0, 3.0);
	//std::cout << vec << std::endl << std::endl;
	//std::cout << vec[0] << std::endl;
	auto rotmat = rotation3d(vec);
	std::cout << rotmat;
	
	return 0;
}
