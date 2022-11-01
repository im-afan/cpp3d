#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <Eigen/Dense>

void fileToStr(std::string path, std::string &s){
	//std::ifstream t("/home/andrew/sdcard/code/cpp3d/src/cube.obj");
	std::ifstream t(path);
	std::stringstream ret;
	
	if(!t){
		std::cout << "file does not exist\n";
		return;
	}

	ret << t.rdbuf();
	


	s = ret.str();
}

std::vector<Eigen::Vector4d> parseVerts(std::string objString){
	std::vector<Eigen::Vector4d> normals;

	for(int i = 0; i < objString.size(); i++){
		
	}
}
