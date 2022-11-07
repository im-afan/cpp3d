#include <vector>
#include <Eigen/Dense>

bool rayTriangleIntersect(Eigen::VectorXd ray, Eigen::VectorXd v1, Eigen::VectorXd v2, Eigen::VectorXd v3){	
	Eigen::Vector3d p1, p2, p3;
	p1 = v1.head<3>(), p2 = v2.head<3>(), p3 = v3.head<3>();
	
	Eigen::Vector3d edge1, edge2;
	edge1 = (p2 - p1).head<3>();
	edge2 = (p3 - p2).head<3>();

	Eigen::Vector3d normal = edge1.cross(edge2);

	//plane equation: normal[0]x + normal[1]y + normal[2]z + D = 0
	
	double a = normal[0], double b = normal[1], double c = normal[2];

	//ax + bx + cz + d = 0

	//solve for d
	double d = -(a * p1[0] + b * p1[1] + c * p2[2]); //any point would work in this case

	//calculate constant n such that ray*n intersects with plane
	
	n = -d / (a*ray[0] + b*ray[1] + c*ray[2]);

	if(n < 0) return false; //plane is behind ray

	Eigen::Vector3d intersect = ray*n;

	Eigen::Vector3d s1, s2, s3; //segments connecting vertices of triangle to intersection point
	s1 = p1-intersect, s2 = p2-intersect, s3 = p3-intersect;
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
