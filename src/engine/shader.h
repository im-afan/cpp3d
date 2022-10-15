#pragma once

#include <Eigen/Dense>

double calcDiffuse(Eigen::VectorXd lightPos, Eigen::VectorXd vertPos, Eigen::VectorXd vertNormal){
	Eigen::VectorXd lightDir = (lightPos-vertPos).normalized();
	Eigen::VectorXd normalizedNormal = vertNormal.normalized(); //holy fuk that sounds weird

	return normalizedNormal.dot(lightDir);
}
