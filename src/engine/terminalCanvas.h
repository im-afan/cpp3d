#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Eigen/Dense>

class TerminalCanvas {
public:
	int width, height;
	//int** state;
	std::vector<std::vector<int>> state;
	std::vector<std::vector<double>> zbuffer;
	std::string ramp = ".-:=+m&$#";
	
	TerminalCanvas(int w, int h){ //width, height
		width = w, height = h;
		
		std::vector<int> temp(width);
		std::vector<double> temp1(width);
		std::fill(temp.begin(), temp.end(), 0);
		std::fill(temp1.begin(), temp1.end(), 0);

		for(int i = 0; i < height; i++){
			state.push_back(temp);
			zbuffer.push_back(temp1);
		}		
	}

	void drawPoint(double x, double y, double a){ // 0 <= x, y <= 1 TODO: switch to vector input
		if(0 <= x && x <= 1 && 0 <= y && y <= 1)
			state[(int) (y*height)][(int) (x*width)] = (int) (a*(ramp.size()-1));
	}

	void clear(){
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				state[i][j] = 0;
				zbuffer[i][j] = 0;
			}
		}
	}

	char* render(){
		//printf("height: %d, width: %d\n", height, width);
		char* ret = new char[(width+1) * height]; // = (width+1)(height)
		for(int i = height-1; i >= 0; i--){
			//std::cout << i << std::endl;	
			int tmpi = height-i-1;
			for(int j = 0; j < width; j++){
				//std::cout << state[i][j] << std::endl;	
				int tmpj = j;
				ret[tmpi*width + tmpj] = ramp[state[i][j]];	
				//std::cout << ramp[state[i][j]];
			}
			ret[(tmpi+1)*width-1] = '\n';
		}
		return ret;
		//std::cout << ret << std::endl;
	}

	void drawSegment(double x1, double y1, double x2, double y2, double a){ //TODO: switch to vector input
		for(double i = 0; i < 1; i += 0.01){
			drawPoint(i*x1+(1-i)*x2, i*y1+(1-i)*y2, a);
		}
	}

	void drawTriangle(Eigen::VectorXd p1, Eigen::VectorXd p2, Eigen::VectorXd p3, double a1, double a2, double a3){}
};

