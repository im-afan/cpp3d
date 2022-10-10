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
	Eigen::Vector4d pos(0.5, 0, 0, 1);
	
	Eigen::Matrix4d rotmat = rotation3d(vec);

	std::cout << rotmat << std::endl;

	int width = 160, height = 44;

	TerminalCanvas canvas(width, height);

	char* s;

	while(true){
		canvas.clear();
		pos = rotmat * pos;
		//std::cout << pos << std::endl;
		canvas.drawPoint(pos[0], pos[1], 1);
		s = canvas.render();
		/*for(int i = 0; i < canvas.height; i++){
			for(int j = 0; j < canvas.width; j++){
				std::cout << canvas.state[i][j] << " ";
			}
			std::cout << std::endl;
		}*/
		//std::cout << sizeof(s)/sizeof(s[0]) << std::endl;
		printf("\033[2J");
		for(int i = 0; i < (width+1)*height; i++){
			putchar(s[i]);	
		}
		//printf("%s", s);
		//std::cout << s;
		usleep(8000*2);
	}
	
	return 0;
}
