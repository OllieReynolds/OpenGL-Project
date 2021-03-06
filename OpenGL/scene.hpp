#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "shader.hpp"
#include "skybox.h"
#include "panel.hpp"
#include "plane.hpp"
#include "mesh.hpp"
#include "shader_manager.hpp"

class Scene
{
public:
	Scene();
	~Scene();

	void create();
	void draw(GLFWwindow *window);
	void kill();

	static bool recompileShaders;

private:
	Camera*	camera;

	mesh* test;

	Plane*	plane;

	Skybox* skybox;

	Panel*	panel;

	Shader* activeShader;

	ShaderManager* shaderMgr;
	
};

#endif // SCENE_HPP