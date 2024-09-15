#ifndef NATURAL_H
#define NATURAL_H

#include "ModelTextureRenderer.h"

class Natural 
{
private:
    GLMmodel* mountainModel, *horrorTreeModel, *dragonModel;
    GLuint mountainTexture, horrorTreeTexture, dragonTexture;

public:
    Natural(GLMmodel* mountainModel, GLuint mountainTexture, GLMmodel* horrorTreeModel, GLuint horrorTreeTexture, GLMmodel* dragonModel, GLuint dragonTexture);
    void DrawAll();
    void DrawAllWithTexture();
};

#endif // NATURAL_H