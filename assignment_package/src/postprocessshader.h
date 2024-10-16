#pragma once

#include <openglcontext.h>
#include "drawable.h"

class PostProcessShader
{
private:
    OpenGLContext* context;
    GLuint vertShader; // A handle for the vertex shader stored in this shader program
    GLuint fragShader; // A handle for the fragment shader stored in this shader program
    GLuint prog;       // A handle for the linked shader program stored in this class
    int unifSampler2D; // A handle to the "uniform" sampler2D that will be used to read the texture containing the scene render
    int unifTime; // A handle for the "uniform" float representing time in the shader
    int attrPos; // A handle for the "in" vec4 representing vertex position in the vertex shader
    int attrUV; // A handle for the "in" vec2 representing the UV coordinates in the vertex shader
    int unifDimensions; // A handle to the "uniform" ivec2 that stores the width and height of the texture being rendered

public:
    PostProcessShader(OpenGLContext* context);
    virtual ~PostProcessShader();

    // Sets up the requisite GL data and shaders from the given .glsl files
    void create(const char *vertfile, const char *fragfile);
    // Tells our OpenGL context to use this shader to draw things
    void useMe();
    // Draw the given object to our screen using this ShaderProgram's shaders
    void draw(Drawable &d, int textureSlot);
    // Utility function used in create()
    char* textFileRead(const char*);
    QString qTextFileRead(const char*);
    // Utility function that prints any shader compilation errors to the console
    void printShaderInfoLog(int shader);
    // Utility function that prints any shader linking errors to the console
    void printLinkInfoLog(int prog);
    void setTime(int t);
    void setDimensions(glm::ivec2 dims);
};
