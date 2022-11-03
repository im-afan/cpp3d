#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include <Eigen/Dense>
#include "engine/terminalCanvas.h"

int main(){
	const unsigned width=1024;
	const unsigned height=720;
	
	TerminalCanvas canvas(width, height);

	sf::RenderWindow window(sf::VideoMode(width, height), "cube");
	
	sf::Texture texture;
	texture.create(width, height);
	
	canvas.drawTriangle(Eigen::Vector2d(0, 0), Eigen::Vector2d(0, 0.9), Eigen::Vector2d(0.9, 0), 1, 0, 0);

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
	}
}
