#include "Artificial.h"

Artificial::Artificial(GLMmodel* castleModel, GLuint castleTexture, GLMmodel* castleTowerModel, GLuint castleTowerTexture) : castleModel(castleModel), castleTexture(castleTexture), castleTowerModel(castleTowerModel), castleTowerTexture(castleTowerTexture) {}

void Artificial::DrawAll(){}

void Artificial::DrawAllWithTexture()
{
    ModelTextureRenderer::DrawModel(castleModel, -0.67f, -0.1f, -1.05f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, castleTexture);
    ModelTextureRenderer::DrawModel(castleTowerModel, -3.46f, 0.0f, -0.3f, 0.2f, 1.2f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f, castleTowerTexture);
}