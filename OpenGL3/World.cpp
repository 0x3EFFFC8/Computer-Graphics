#include "World.h"

World::World() 
{
    // Load models
    GLMmodel* castleModel = new GLMmodel;
    GLMmodel* castleTowerModel = new GLMmodel;
    GLMmodel* dragonModel = new GLMmodel;
    GLMmodel* mountainModel = new GLMmodel;
    GLMmodel* horrorTreeModel = new GLMmodel;

    ModelTextureRenderer::openMesh(&castleModel, "./Meshes/castle/castle.obj");
    ModelTextureRenderer::openMesh(&castleTowerModel, "./Meshes/castleTower/castleTower.obj");
    ModelTextureRenderer::openMesh(&mountainModel, "./Meshes/mountain/mountain.obj");
    ModelTextureRenderer::openMesh(&dragonModel, "./Meshes/dragon/dragon.obj");
    ModelTextureRenderer::openMesh(&horrorTreeModel, "./Meshes/horrorTree/HorrorTree.obj");
    
    // Load textures
    GLuint castleTexture, mountainTexture, dragonTexture, horrorTreeTexture, castleTowerTexture;
    
    ModelTextureRenderer::initialize_textures(&castleTexture, "./Meshes/castle/textures/BrickOldMixedSize0046_1_S_COLOR.png");
    ModelTextureRenderer::initialize_textures(&castleTowerTexture, "./Meshes/castleTower/castleTower.png");
    ModelTextureRenderer::initialize_textures(&mountainTexture, "./Meshes/mountain/mountain.jpg");
    ModelTextureRenderer::initialize_textures(&dragonTexture, "./Meshes/dragon/dragon.jpg");
    ModelTextureRenderer::initialize_textures(&horrorTreeTexture,"./Meshes/horrorTree/horrorTree.jpg");
    
    naturalObjects = new Natural(mountainModel, mountainTexture, horrorTreeModel, horrorTreeTexture, dragonModel, dragonTexture);
    artificialObjects = new Artificial(castleModel, castleTexture, castleTowerModel, castleTowerTexture);
}

World::~World() 
{
    delete naturalObjects;
    delete artificialObjects;
}

void World::CreateWorld() 
{
    artificialObjects->DrawAll();
    naturalObjects->DrawAll();
}

void World::CreateWorldWithTexture() 
{   
    artificialObjects->DrawAllWithTexture();
    naturalObjects->DrawAllWithTexture();
}