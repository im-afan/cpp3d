#include <Eigen/Dense>
#include "engine/geometry.h"
#include <iostream>

int main(){
	Eigen::Vector4d pos(1, 2, 3, 1);
	Eigen::Vector4d t(1, 1, 1, 0);
	Eigen::Matrix4d translate= translation3d(t);
	std::cout << translate * pos;
}
