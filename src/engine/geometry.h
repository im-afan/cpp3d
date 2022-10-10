#include <cmath>
#include <xtensor/xarray.hpp>
#include <iostream>

xt::xarray<double> rotation3d(xt::xarray<double> angles){ //angles given in x, y, z
	xt::xarray<double> yaw = {
		{1, 0, 0, 0},
		{0, cos(angles[0]), -sin(angles[0]), 0},
		{0, sin(angles[0]), cos(angles[0]), 0},
		{0, 0, 0, 1}
	};	
	xt::xarray<double> pitch = {
		{cos(angles[1]), 0, sin(angles[1]), 0},
		{0, 1, 0, 0},
		{-sin(angles[1]), 0, cos(angles[1]), 0},
		{0, 0, 0, 1}
	};	
	
	xt::xarray<double> roll = {
		{cos(angles[0]), -sin(angles[0]), 0},
		{sin(angles[0]), cos(angles[0]), 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	std::cout << yaw << std::endl;
	

	return yaw*pitch*roll;
}


