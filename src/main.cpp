#pragma warning (push)
#pragma once

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <Eigen/Dense>
//#include "engine/geometry.h"
#include "engine/terminalCanvas.h"
#include "engine/perspectiveCamera.h"
#include "engine/shader.h"
#include <vector>

double DIFFUSE_POWER = 2;
double AMBIENT_POWER = 1;

int main(int argc, char* argv[]){
	std::ios_base::sync_with_stdio(false);
	
	/*Eigen::Vector4d pos1(0.5, 0, 0, 1);
	Eigen::Vector4d pos2(0, 0.5, 0, 1);
	Eigen::Vector4d pos3(0.5, 0.5, 0, 1);*/
	std::vector<Eigen::Vector4d> verts = {
		Eigen::Vector4d(1, 1, 0, 1),
		Eigen::Vector4d(-1, 1, 0, 1),
		Eigen::Vector4d(-1, -1, 0, 1),
		Eigen::Vector4d(1, -1, 0, 1)
	};

	std::vector<Eigen::Vector4d> normals = {
		Eigen::Vector4d(1, 1, 0, 0),
		Eigen::Vector4d(-1, 1, 0, 0),
		Eigen::Vector4d(-1, -1, 0, 0),
		Eigen::Vector4d(1, -1, 0, 0)
	};

	std::vector<int> inds = {
		0, 1, 2,
		0, 3, 2
	};
	
	PerspectiveCamera cam(-1, 1, -1, 1, 1, 100);
	
	Eigen::Vector3d vec(0.01, 0, 0.01);
	Eigen::Matrix4d rotmat = rotation3d(vec);

	Eigen::Matrix4d transform = translation3d(Eigen::Vector3d(0, 0, 2)); //rename this to model matrix later oops

	std::cout << rotmat << std::endl;

	int width = 160, height = 60;

	TerminalCanvas canvas(width, height);

	char* s;

	while(true){
		canvas.clear(); //reset canvas
		
		/*for(int i = 0; i < verts.size(); i++) {
			verts[i] = rotmat * verts[i]; //apply rotation to all vertices
		}*/
		transform = transform * rotmat;
		
		for(int i = 0; i < inds.size(); i += 3){ //draw each triangle
			int i1 = inds[i], i2 = inds[i+1], i3 = inds[i+2];
			//get projected points using camera
			Eigen::Vector2d proj1 = cam.project(transform * verts[i1]), proj2 = cam.project(transform * verts[i2]), proj3 = cam.project(transform * verts[i3]);
			
			double a1 = DIFFUSE_POWER * calcDiffuse(Eigen::Vector4d(1, 1, 0, 1), verts[i1], transform * normals[i1]) + AMBIENT_POWER;
			double a2 = DIFFUSE_POWER * calcDiffuse(Eigen::Vector4d(1, 1, 0, 1), verts[i2], transform * normals[i2]) + AMBIENT_POWER;
			double a3 = DIFFUSE_POWER * calcDiffuse(Eigen::Vector4d(1, 1, 0, 1), verts[i3], transform * normals[i3]) + AMBIENT_POWER;
			//projected points are between 1 and -1, but we need them between 0 and 1 to draw them
			Eigen::Vector2d move(1, 1);
			canvas.drawTriangle((proj1+move)/2, (proj2+move)/2, (proj3+move)/2, a1, a2, a3);
		}
		
		s = canvas.render();
		
		printf("\033[H\033[2J");
		printf("%s", s);
		usleep(50000);
	}
	
	return 0;
}
