#ifndef ARTIFICIAL_H
#define ARTIFICIAL_H

#include "ModelTextureRenderer.h"

class Artificial 
{
private:
    GLMmodel* castleModel, *castleTowerModel;
    GLuint castleTexture, castleTowerTexture;
public:
    Artificial(GLMmodel* castleModel, GLuint castleTexture, GLMmodel* castleTowerModel, GLuint castleTowerTexture);
    void DrawAll();
    void DrawAllWithTexture();
};

#endif // ARTIFICIAL_H