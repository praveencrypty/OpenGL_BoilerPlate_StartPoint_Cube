#include "Mesh.h"

Mesh::Mesh()
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};


	SetupMesh();
}


void Mesh::SetupMesh() {

	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

void Mesh::DrawMesh()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
