#ifndef WORLD_H
#define WORLD_H

#include "Natural.h"
#include "Artificial.h"
#include "ModelTextureRenderer.h"

class World 
{
private:
    Natural* naturalObjects;
    Artificial* artificialObjects;

public:
    World();
    ~World();
    void CreateWorld();
    void CreateWorldWithTexture();
};

#endif // WORLD_H