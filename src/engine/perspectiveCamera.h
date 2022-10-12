#pragma once

#include "geometry.h"
#include <Eigen/Dense>

class PerspectiveCamera{
	public:
		double right, left, top, bottom;
		double near, far;
		
		Eigen::Vec4d pos = {0.0, 0.0, 0.0, 1.0};
		Eigen::Vec4d eulerAngles = {0.0, 0.0, 0.0};

		PerspectiveCamera(left, right, bottom, top, near, far){
			right = right;
			left = left;
			bottom = bottom;
			top = top;
			near = near;
			far = far;
		}

		Eigen::Vec2d project(Eigen::Vec4d point){
			
			
			//view matrix
			Eigen::Mat4d rot = rotation3d(-eulerAngles);
			Eigen::Mat4d transform = rotation3d(-pos);	
			point = rot * transform * point;
			double x = point[0], y = point[1], z = point[2];		
	
			//draw a "line" to the projection plane
			return Eigen::Vec2d proj(near/z*x * 1/(right-left), near/z*y * 1/(top-bottom)); //reminder: it's from -1 to 1, not 0 to 1 rn
		}
}
