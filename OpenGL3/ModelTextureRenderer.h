#ifndef MODELTEXTURERENDER_H
#define MODELTEXTURERENDER_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include "glm.h"
#include <FreeImage.h>


class ModelTextureRenderer
{
public:
    ModelTextureRenderer() = delete;
    static void openMesh(GLMmodel** objmodel_ptr, char* model);
    static void initialize_textures(GLuint* texid, char* texture);
    static void DrawModel(GLMmodel* objmodel_ptr, float x, float y, float z, float s_x, float s_y, float s_z, float r_a, float r_x, float r_y, float r_z);
    static void DrawModel(GLMmodel* objmodel_ptr, float x, float y, float z, float s_x, float s_y, float s_z, float r_a, float r_x, float r_y, float r_z, GLuint texture);
};

#endif // MODELTEXTURERENDER_H