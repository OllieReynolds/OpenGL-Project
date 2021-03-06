#ifndef SHADER_HPP
#define SHADER_HPP

#include "include\GLEW_64-1.10.0\glew.h"
#include "include\GLFW_64-3.0.1\glfw3.h"
#include "include\GLM-0.9.4.4\gtc\matrix_transform.hpp" 
#include "include\GLM-0.9.4.4\gtc\type_ptr.hpp"

#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum ShaderTypes 
{ 
	VERT,
	FRAG,
	TESC,
	TESE,
	GEOM,
};

struct shaderDir {
	shaderDir() 
		:	vertex(NULL)
		,	fragment(NULL)
		,	tessControl(NULL)
		,	tessEval(NULL)
		,	geometry(NULL)
	{ }

	char* vertex;
	char* fragment;
	char* tessControl;
	char* tessEval;
	char* geometry;
};

class Shader
{
public:
	Shader()
		:	program(glCreateProgram()) { }

	~Shader() {
		glUseProgram(NULL);

		for (GLuint s : shaders) {
			glDetachShader(program, s);
			glDeleteShader(s);
		}

		glDeleteProgram(program);
	}

	int create(const shaderDir& dir);
	void use();

	void updateMat4(const GLchar* name, GLsizei n, const GLfloat* value);
	void update1i(int i, const GLchar* name);
	void update1f(float d, const GLchar* name);
	void update2f(float x, float y, const GLchar* name);

private:
	GLuint createShader(const char* dir, GLenum type);
	string loadFile(const string& directory);

	GLuint program; 
	GLuint shaders[5];
};

#endif // SHADER_HPP