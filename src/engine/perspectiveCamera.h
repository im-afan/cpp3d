#pragma once

#include <xtensor/xarray.hpp>

class PerspectiveCamera{
	public:
		double right, left, top, bottom;
		double near, far;
		
		xtensor::xarray<double> pos = {0.0, 0.0, 0.0, 1.0};

		PerspectiveCamera(left, right, bottom, top, near, far){
			right = right;
			left = left;
			bottom = bottom;
			top = top;
			near = near;
			far = far;
		}

		xtensor::xarray<double> project(xtensor::xarray<double> point){
			
		}
}
