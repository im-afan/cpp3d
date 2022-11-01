#include "../engine/terminalCanvas.h"
#include <Eigen/Dense>
#include <iostream>

int main(){
	TerminalCanvas canvas(100, 44);
	Eigen::Vector2d pos1(0, 0);
	Eigen::Vector2d pos2(0.9, 0);
	Eigen::Vector2d pos3(0, 0.9);
	std::cout << "sdkjnfa" << std::endl;
	canvas.drawTriangle(pos1, pos2, pos3, 1, 0, 0);
	std::cout << "??" << std::endl;	
	std::cout << canvas.render() << std::endl;
}

