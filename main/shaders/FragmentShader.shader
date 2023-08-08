#version 330 core

out vec4 FragColor; //Mandotary Default Output variable 

in vec4 ourColor; // we get this variable from vertex shader


vec4 ambientLight = vec4(1.5f);

void main()
{
    FragColor = ambientLight * ourColor;
}  