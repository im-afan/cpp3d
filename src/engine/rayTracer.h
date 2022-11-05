#include <vector>
#include <Eigen/Dense>

bool rayTriangleIntersect(Eigen::VectorXd ray, Eigen::VectorXd p1, Eigen::VectorXd p2, Eigen::VectorXd p3){	
	
}

class RayTracerCamera{
public:
	double near, left, right, bottom, top, gridWidth, gridHeight;

	RayTracerCamera(n, l, r, b, t, gw, gh){
		near = n, left = l, right = r, gridWidth = gw, gridHeight = gh;	
		bottom = b;
		top = t;
	}

	std::vector<std::vector<double>> render(std::vector<Eigen::Vector4d<double>> triangles){ //triangle primitive
		std::vector<std::vector<double>> ret;
		std::vector<std::vector<double>> zbuffer;

		for(int i = 0; i < gridHeight; i++){
			ret.push_back(new std::vector<double>());
			zbuffer.push_back(new std::vector<double>());
			for(int j = 0; j < gridWidth; j++){
				ret[i].push_back(0);	
				zbuffer[i].push_back((double) INT_MAX);	
			}
		}

		for(int i = 0; i < gridHeight; i++){
			for(int j = 0; j < gridWidth; j++){
				Eigen::Vector4d gridpos(near, 
						left + j*(right-left)/gridWidth,
						bottom + i*(top-bottom)/gridHeight,
						1);
				Eigen::Vector4d origin(0, 0, 0, 1);
				Eigen::Vector4d ray = gridpos-origin;
				for(int k = 0; k < triangles.length(); k += 3){
					bool hitsPoint = trianglePointIntersect(ray, 
							triangles[k], 
							triangles[k+1], 
							triangles[k+2]);
				       	if(hitsPoint){
				       		ret[i][j] = 1;
						//TODO: implement depth		
				       	}	       
				}		
			}
		}
	}
}
