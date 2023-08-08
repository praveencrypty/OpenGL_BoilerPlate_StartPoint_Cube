#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0  

layout(location = 1) in vec3 inputColor;

uniform vec4 fcolor;
uniform mat4 mvp;


out vec4 ourColor; // specify a color output to the fragment shader

void main()
{
    gl_Position = mvp * vec4(aPos, 1.0f) * 0.05f; // Mandotary Default Output variable 

    ourColor = vec4(inputColor,1.0f); // set the output variable to a dark-red color
}