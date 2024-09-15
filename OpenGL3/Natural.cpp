#include "Natural.h"

Natural::Natural(GLMmodel* mountainModel, GLuint mountainTexture, GLMmodel* horrorTreeModel, GLuint horrorTreeTexture, GLMmodel* dragonModel, GLuint dragonTexture): mountainModel(mountainModel), mountainTexture(mountainTexture), horrorTreeModel(horrorTreeModel), horrorTreeTexture(horrorTreeTexture), dragonModel(dragonModel), dragonTexture(dragonTexture) {}

void Natural::DrawAll(){}

void Natural::DrawAllWithTexture() 
{
    ModelTextureRenderer::DrawModel(mountainModel, 0.0f, 0.0f, -0.0f, 4.0f, 4.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0.0f, mountainTexture);
    ModelTextureRenderer::DrawModel(dragonModel, 0.0f, 3.0f, 0.0f, 0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, dragonTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, -5.0f, -1.0f, 6.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, 5.0f, -2.0f, 6.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, 7.0f, -2.0f, 8.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, 7.0f, -2.0f, 0.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, -5.0f, -2.0f, -6.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, 7.0f, -2.0f, -8.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
    ModelTextureRenderer::DrawModel(horrorTreeModel, -10.0f, -2.7f, 2.0f, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f, horrorTreeTexture);
}