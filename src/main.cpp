#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include "engine/geometry.h"

int main(int argc, char* argv[]){
	xt::xarray<double> rot = {1.0, 2.0, 3.0};
	std::cout << rot << std::endl;
	xt::xarray<double> newarr = rotation3d(rot);

	//std::cout << newarr;

	return 0;
}
