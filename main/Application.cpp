#define GLEW_STATIC

#include <iostream>
#include <random>
#include "gl/glew.h"

#include "GLFW/glfw3.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glm/mat4x4.hpp"
#include <glm/gtx/string_cast.hpp>

#include "Renderer/Renderer.h"
#include "Renderer/Mesh.h"




void processInput(GLFWwindow* window, glm::mat4& view)
{


    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
       
    //Camera 2D Movement
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        view = glm::translate(view, glm::vec3(-0.025f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        view = glm::translate(view, glm::vec3(0.025f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        view = glm::translate(view, glm::vec3(-0.0f, 0.025f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        view = glm::translate(view, glm::vec3(0.0f, -0.025f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        view = glm::rotate(view, glm::radians(1.0f), glm::vec3(0, 1, 0));
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        view = glm::rotate(view, glm::radians(1.0f), glm::vec3(0, -1, 0));
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // This make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


//Start Point
int main()
{
    /* GLFW declaration with helper hints */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    //Window and Context Creation
    /* Create a window and set it as OpenGL context */
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);

    window = glfwCreateWindow((mode->width), (mode->height), "My Title", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    


    /* Glew should be only initiated once the Window context is setup */
    glewInit();


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //////////////////////////////////////////

    // glViewport sets up ther Frame size of content
    glViewport(0, 0, mode->width, mode->height);

    //Culling Back Faces
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    //Depth Enabled
    glEnable(GL_DEPTH_TEST);

    Renderer* mainRenderer = new Renderer;

    glm::mat4 view, model, proj;


    //Matrix Initializations
    view = glm::mat4(1.0f);
    model = glm::mat4(1.0f);
    proj = glm::mat4(1.0f);

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);


    proj  = glm::perspective(glm::radians(45.0f), (float)mode->width / (float)mode->height, 0.1f, 100.0f);


    

    glm::mat4 mvp = proj * view * model;

    mainRenderer->setupShader("E:/CodingProjects/SimpleRenderer/main/shaders/VertexShader.shader", "E:/CodingProjects/SimpleRenderer/main/shaders/FragmentShader.shader");
   
   /* 
    
    mainRenderer->GenerateVBO();

    Mesh* mesh1 = new Mesh;

    mainRenderer->AddToRender(mesh1);
   
   */ 


    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };


    float vertices2[] = {
     0.6f, 0.6f, 0.0f,
     0.7f, 0.0f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    float cube[]
    {
       //Vertex Positions             //Vertex Colors
       0.5,  0.5,  0.5,                0.35f, 0.05f, 0.85f,   // 0
       0.5,  0.5, -0.5,                0.55f, 0.25f, 0.55f,   // 1
       0.5, -0.5,  0.5,                0.75f, 0.55f, 0.55f,   // 2
       0.5, -0.5, -0.5,                0.65f, 0.65f, 0.25f,   // 3
      -0.5,  0.5,  0.5,                0.55f, 0.35f, 0.55f,   // 4
      -0.5,  0.5, -0.5,                0.55f, 0.05f, 0.15f,   // 5
      -0.5, -0.5,  0.5,                0.05f, 0.25f, 0.55f,   // 6
      -0.5, -0.5, -0.5,                0.25f, 0.25f, 0.05f,   // 7

    };

    GLuint indices[]
    {
        
        
        7,3,2,
        2,6,7,

        3,1,0,
        0,2,3,

        1,5,4,
        4,0,1,

        6,4,5,
        5,7,6,
               
        6,2,0,
        0,4,6,

        7,3,1,
        1,5,7,
        
        


    };

    GLuint mainVBO, secondVBO;
    GLuint mainIBO;

    glGenBuffers(1, &mainVBO);
    glGenBuffers(1, &secondVBO);
    glGenBuffers(1, &mainIBO);

    unsigned int colLoc;
    colLoc = glGetUniformLocation(mainRenderer->getShader().ID, "fcolor");

    unsigned int modvproj;
    modvproj = glGetUniformLocation(mainRenderer->getShader().ID, "mvp");

    float fcolor[4] = { 0.82f, 0.0f, 0.0f, 1.0f };

    glUniform4fv(colLoc,1, fcolor);
    glUniformMatrix4fv(modvproj, 1, GL_FALSE, glm::value_ptr(mvp));


    
    
    std::cout <<endl << glm::to_string(model) << std::endl;

    std::cout << endl << glm::to_string(view) << std::endl;


    


    while (!glfwWindowShouldClose(window))
    {
       
        glfwPollEvents();
        processInput(window, view);



        //Clear Buffer
        glClearColor(0.08f, 0.059f, 0.051f, 1.000f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   


        

        //The Below will update the mvp transform
        glm::mat4 mvp = proj * view * model;
        glUniformMatrix4fv(modvproj, 1, GL_FALSE, glm::value_ptr(mvp));

        //Render Below

        //Drawing Shapes using multiple buffers

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindBuffer(GL_ARRAY_BUFFER, mainVBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mainIBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cube), (void*)cube, GL_STATIC_DRAW); //This function will send data to the created and binded buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), (void*)indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);             //This sets up the variable aPos in vertex shader
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));  //This sets up the variable inputColor in vertex shader

        ///
        /// The Stride value is the bytes sizes between the vertex points. If a vertex point has 3 position point, 3 color point in the variable,
        /// then the stride will be a multiplication of (3+3)*sizeof(varianble type, EG:Float)
        /// 
        /// So now the opengl will know to jump to the second vertex position values based on the size in bytes. Same applies to color values too
        /// 
        ///

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
       
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        

        /*

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindBuffer(GL_ARRAY_BUFFER, secondVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), (void*)vertices2, GL_STATIC_DRAW);  //This function will send data to the created and binded buffer
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        */
        //mainRenderer->RenderOpaques();

       
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glfwSwapBuffers(window);
    }

   

    glfwTerminate();

    return 0;
}


