#pragma once
#define GLEW_STATIC

#include<iostream>
#include <GL/glew.h>



class Mesh
{
private:
	float vertices[1];


public:
	Mesh();
	void SetupMesh();
	void DrawMesh();
};

