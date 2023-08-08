#pragma once

#include "Shader.h"
#include "Mesh.h"
#include <vector>

using namespace std;

class Renderer
{
private:
	Shader* defShader;
	
	GLuint mainVBO;

	vector<Mesh> meshesToRender;

public:
	Renderer();

	void setupShader(const char* vertexPath, const char* fragmentPath);

	void GenerateVBO();

	void setVertexBuffer(GLuint vbo);

	void AddToRender(Mesh* mesh);

	void RenderOpaques();

	Shader getShader();
};

