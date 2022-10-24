#pragma once

#include "perspectiveCamera.h"

class RenderContext{
public:
	PerspectiveCamera camera;
	Shader shader;

	RenderContext(PerspectiveCamera cam, Shader shdr){
		camera = cam;
		shader = shdr;
	}

	
}
