#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include "glsl.h"
#include "glm.h"
#include <iostream>
#include <time.h>
#include <FreeImage.h> 
#include "World.h"

class myWindow : public cwc::glutWindow
{
protected:
   cwc::glShaderManager SM;
   cwc::glShader *shader;
   cwc::glShader* shader1; 
   GLuint ProgramObject;
   clock_t time0,time1;
   float timer010;  
   bool bUp;       
   float cameraAngleX, cameraAngleY, cameraDistance;
   World* world;
public:
	myWindow();
	virtual void OnRender(void);
	virtual void OnIdle();
	virtual void OnInit();
	virtual void OnResize(int w, int h);
	virtual void OnClose(void);
	virtual void OnMouseDown(int button, int x, int y);    
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y);
	virtual void OnKeyDown(int nKey, char cAscii);
    virtual void OnKeyUp(int nKey, char cAscii);
    virtual void OnMouseMotion(int x, int y); 
    void UpdateTimer();
    void DemoLight(void);
};

#endif // MYWINDOW_H
