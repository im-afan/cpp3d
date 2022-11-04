#pragma once

#include <Eigen/Dense>
#include <SFML/Graphics> 

class SFMLCanvas {
public:
	bool USE_Z_BUFFER = true;

	sf::Image buffer;
	sf::Image zbuffer;

	SFMLCanvas(unsigned int width, unsigned int height){
		buffer.create(width, height, sf::Color(0, 0, 0));
		zbuffer.create(width, height, sf::Color(255, 255, 255));
	}

	sf::Image getBuffer(){
		return buffer;
	}
	
	void drawSegment(Eigen::VectorXd p1, Eigen::VectorXd p2, double a){ //TODO: switch to vector input
		for(double i = 0; i <= 1; i += 0.01){
			drawPoint(i*p1[0]+(1-i)*p2[0], i*p1[1]+(1-i)*p2[1], a);
		}
	}

	void drawTriangle(Eigen::VectorXd p1, Eigen::VectorXd p2, Eigen::VectorXd p3, double a1, double a2, double a3, double depth=0){
		double area = std::abs((p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1]) - (p1[1]*p2[0] + p2[1]*p3[0] + p3[1]*p1[0]));

		/*std::cout << area << std::endl;
		std::cout << "area 1:" << (p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1]) << std::endl;
		std::cout << "area 2: " << (p1[1]*p2[0] + p2[1]*p3[0] + p3[1]*p1[0]) << std::endl;*/


		for(double w1 = 0; w1 <= 1; w1 += 1/area/1000){
			for(double w2 = 0; w1+w2 <= 1; w2 += 1/area/1000){
				double w3 = 1-w1-w2;
				double a = w1*a1 + w2*a2 + w3*a3;
				Eigen::VectorXd p = p1*w1 + p2*w2 + p3*w3;
				drawPoint(p[0], p[1], a, depth);
			}
		}
	}

	void drawPoint(double x, double y, double a, double depth=0){ // 0 <= x, y <= 1 TODO: switch to vector input
		if(a > 1) a = 1;
		if(a < 0) a = 0;
		if(0 <= x && x <= 1 && 0 <= y && y <= 1){
			if(USE_Z_BUFFER){
				int canvasy = (int) (y*height);
				int canvasx = (int) (x*width);
				if(depth <= zbuffer[canvasy][canvasx]){
					buffer.setPixel(canvasx, canvasy, sf::Color(a*255, a*255, a*255));
				}
			} else{
			       	state[(int) (y*height)][(int) (x*width)] = (int) (a*(ramp.size()-1));
			}
		}
	}
}
