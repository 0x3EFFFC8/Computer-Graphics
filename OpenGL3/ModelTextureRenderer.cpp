#include "ModelTextureRenderer.h"

void ModelTextureRenderer::openMesh(GLMmodel** objmodel_ptr, char* model)
{	
    *objmodel_ptr = glmReadOBJ(model);
    if (!*objmodel_ptr)
        exit(0);

    glmUnitize(*objmodel_ptr);
    glmFacetNormals(*objmodel_ptr);
    glmVertexNormals(*objmodel_ptr, 90.0);
}

void ModelTextureRenderer::initialize_textures(GLuint* texid, char* texture)
{
	int w, h;
	GLubyte* data = 0;

	glGenTextures(1, texid);
	glBindTexture(GL_TEXTURE_2D, *texid);
	glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Loading JPG file
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(texture, 0),texture);  
	FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
	int nWidth = FreeImage_GetWidth(pImage);
	int nHeight = FreeImage_GetHeight(pImage);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

	FreeImage_Unload(pImage);

	glEnable(GL_TEXTURE_2D);
}

void ModelTextureRenderer::DrawModel(GLMmodel* objmodel_ptr, float x, float y, float z, float s_x, float s_y, float s_z, float r_a, float r_x, float r_y, float r_z)
{
    glPushMatrix();
	glScalef(s_x, s_y, s_z);
	glRotatef(r_a, r_x, r_y, r_z);
	glTranslatef(x, y, z);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}

void ModelTextureRenderer::DrawModel(GLMmodel* objmodel_ptr, float x, float y, float z, float s_x, float s_y, float s_z, float r_a, float r_x, float r_y, float r_z, GLuint texture)
{
    glPushMatrix();
	glScalef(s_x, s_y, s_z);
	glRotatef(r_a, r_x, r_y, r_z);
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}
