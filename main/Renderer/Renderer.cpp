#include "Renderer.h"

Renderer::Renderer()
{
	vector<Mesh> meshesToRender = {

	};
}

void Renderer::setupShader(const char* vertexPath, const char* fragmentPath)
{
	defShader = new Shader(vertexPath, fragmentPath);
	defShader->use();
}

void Renderer::GenerateVBO()
{
	glGenBuffers(1, &mainVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mainVBO);
}

void Renderer::setVertexBuffer(GLuint vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void Renderer::AddToRender(Mesh* mesh)
{
	meshesToRender.push_back(*mesh);


}

void Renderer::RenderOpaques()
{
	for (Mesh mainMesh : meshesToRender) {
		mainMesh.DrawMesh();
	}
}

Shader Renderer::getShader()
{
	return *defShader;
}
