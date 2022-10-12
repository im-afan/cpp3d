#pragma warning (push)

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <Eigen/Dense>
#include "engine/geometry.h"
#include "engine/terminalCanvas.h"

int main(int argc, char* argv[]){
	std::ios_base::sync_with_stdio(false);
	Eigen::Vector3d vec(0, 0, 0.1);
	
	Eigen::Vector4d pos1(0.5, 0, 0, 1);
	Eigen::Vector4d pos2(0, 0.5, 0, 1);
	Eigen::Vector4d pos3(0.5, 0.5, 0, 1);
	
	Eigen::Matrix4d rotmat = rotation3d(vec);

	std::cout << rotmat << std::endl;

	int width = 160, height = 44;

	TerminalCanvas canvas(width, height);

	char* s;

	while(true){
		canvas.clear();
		pos1 = rotmat * pos1;
		pos2 = rotmat * pos2;
		pos3 = rotmat * pos3;
		
		canvas.drawSegment(pos1, pos2, 1);
		canvas.drawSegment(pos2, pos3, 1);
		canvas.drawSegment(pos3, pos1, 1);
		
		s = canvas.render();
		
		printf("\033[H\033[2J");
		printf("%s", s);
		//std::cout << s;
		usleep(8000*3);
	}
	
	return 0;
}
