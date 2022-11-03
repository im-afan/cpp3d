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

void getLines(std::string path, std::vector<std::string> &vec){
	std::string line;
	std::ifstream infile(path);
	while(std::getline(infile, line)){
		vec.push_back(line);
	}
}

std::vector<Eigen::Vector4d> parseVerts(std::vector<std::string> lines){
	std::vector<Eigen::Vector4d> verts;

	for(std::string line: lines){
		std::istringstream iss(line);
		std::string type; iss >> type;
		//std::cout << type << std::endl;
		if(type == "v"){
			Eigen::Vector4d vert;
			iss >> vert[0] >> vert[1] >> vert[2];
			vert[3] = 1;
			verts.push_back(vert);
		}
	}
	return verts;
}

std::vector<Eigen::Vector4d> parseNormals(std::vector<std::string> lines){
	std::vector<Eigen::Vector4d> normals;

	for(std::string line: lines){
		std::istringstream iss(line);
		std::string type; iss >> type;
		if(type == "vn"){
			Eigen::Vector4d normal;
			iss >> normal[0] >> normal[1] >> normal[2];
			normal[3] = 1;
			normals.push_back(normal);
		}
	}

	return normals;
}

std::vector<int> parseInds(std::vector<std::string> lines){
	std::vector<int> inds;

	for(std::string line: lines){
		std::string tmpline = "";
		for(int i = 0; i < line.size(); i++){
			if(line[i] == '/') tmpline += ' ';
			else tmpline += line[i];
		}
		std::istringstream iss(tmpline);
		std::string type; iss >> type;
		std::cout << tmpline << std::endl;
		if(type == "f"){
			int ind;
			while(iss >> ind) inds.push_back(--ind);	
		}
	}

	return inds;
}
