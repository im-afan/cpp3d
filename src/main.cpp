#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

int main(int argc, char* argv[]){
	xt::xarray<double> arr = {1.0, 2.0, 3.0};
	xt::xarray<double> arr1 = 2*arr;

	std::cout << arr1 << std::endl;
	return 0;
}
