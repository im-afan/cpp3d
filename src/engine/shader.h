#pragma once

#include <Eigen/Dense>
#include <algorithm>
#include <cmath>

double calcDiffuse(Eigen::VectorXd lightPos, Eigen::VectorXd vertPos, Eigen::VectorXd vertNormal){
	Eigen::VectorXd lightDir = (lightPos-vertPos).normalized();
	Eigen::VectorXd normalizedNormal = vertNormal.normalized(); //holy fuk that sounds weird

	double ret = normalizedNormal.dot(lightDir);
	
	//return std::abs(ret);
	if(ret > 0) return ret;
	return 0;
}
