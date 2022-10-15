#pragma once

#include "geometry.h"
#include <Eigen/Dense>

class PerspectiveCamera{
	public:
		double right, left, top, bottom;
		double near, far;
		
		Eigen::Vector4d pos = {0.0, 0.0, 0.0, 1.0};
		Eigen::Vector4d eulerAngles = {0.0, 0.0, 0.0, 0};

		PerspectiveCamera(double l, double r, double b, double t, double n, double f){
			right = r;
			left = l;
			bottom = b;
			top = t;
			near = n;
			far = f;
		}

		Eigen::Vector2d project(Eigen::Vector4d point){
			//view matrix
			//printf("point before view matrix: %f %f %f\n", point[0], point[1], point[2]);
			Eigen::Matrix4d rot = rotation3d(-eulerAngles);
			Eigen::Matrix4d transform = rotation3d(-pos);	
			//std::cout << "view matrix: " << rot*transform << std::endl;
			point = rot * transform * point;
			
			double x = point[0], y = point[1], z = point[2];

			//if(z > far || z < near)
			//	return Eigen::Vector2d(-2, -2);		
			//printf("point after view matrix: %f %f %f\n", x, y, z);
			//draw a "line" to the projection plane
			//printf("near: %f, right: %f, left: %f\n", near, right, left);
			//printf("near/z*x: %f, 1/(right-left): %f\n", near/z*x, 1/right-left);
			if(z >= near) 
				return Eigen::Vector2d(near/z*x * 1/(right-left), near/z*y * 1/(top-bottom)); //reminder: it's from -1 to 1, not 0 to 1 rn
			else
				return Eigen::Vector2d(near/z*x * 1/(right-left), near/z*y * 1/(top-bottom)); //reminder: it's from -1 to 1, not 0 to 1 rn
			//return Eigen::Vector2d(near/z*x, near/z*y);
			//return Eigen::Vector2d(0.5, 0.5);
		}
};
