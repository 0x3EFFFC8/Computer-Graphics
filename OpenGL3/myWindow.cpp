#include "myWindow.h" 
	
myWindow::myWindow(): cameraAngleX(0.0f), cameraAngleY(0.0f), cameraDistance(5.0f){}

void myWindow::OnRender(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
    glTranslatef(0, 0, -cameraDistance);
    glRotatef(cameraAngleY, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngleX, 0.0f, 1.0f, 0.0f);

    if (shader) shader->begin();
	glPushMatrix();
	world->CreateWorld();
	glPopMatrix();
    if (shader) shader->end();

	if (shader1) shader1->begin();
	glPushMatrix();
	world->CreateWorldWithTexture();
	glPopMatrix();
	if (shader1) shader1->end();
    
    glPopMatrix();
    glutSwapBuffers();
    UpdateTimer();
	Repaint();
}

void myWindow::OnIdle() {}

// When OnInit is called, a render context (in this case GLUT-Window) 
// is already available!
void myWindow::OnInit()
{	
	glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	shader = SM.loadfromFile("vertexshader.txt","fragmentshader.txt"); // load (and compile, link) from file
	if (shader==0) 
        std::cout << "Error Loading, compiling or linking shader\n";
    else
    {
        ProgramObject = shader->GetProgramObject();
    }

	//*** To Texture: Open the shaders for textures
	shader1 = SM.loadfromFile("vertexshaderT.txt","fragmentshaderT.txt"); // load (and compile, link) from file
	if (shader1 == 0)
		std::cout << "Error Loading, compiling or linking shader\n";
	else
	{   
        ProgramObject = shader1->GetProgramObject();
	}
    
    time0 = clock();
    timer010 = 0.0f;
    bUp = true;

	world = new World();

	DemoLight();

}

void myWindow::OnResize(int w, int h)
{
    if(h == 0) h = 1;
	float ratio = 1.0f * (float)w / (float)h;

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glViewport(0, 0, w, h);

    gluPerspective(45,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,4.0f, 0.0,0.0,-1.0, 0.0f,1.0f,0.0f);
}

void myWindow::OnClose(void){}
void myWindow::OnMouseDown(int button, int x, int y){}    
void myWindow::OnMouseUp(int button, int x, int y){}
void myWindow::OnMouseWheel(int nWheelNumber, int nDirection, int x, int y){}

void myWindow::OnKeyDown(int nKey, char cAscii)
{       
	if (cAscii == 27) // 0x1b = ESC
	{
		this->Close(); // Close Window!
	} 
};
void myWindow::OnKeyUp(int nKey, char cAscii)
{       
    if (cAscii == 27) // 0x1b = ESC
    {
        this->Close(); // Close Window!
    }
    else if (cAscii == 'w') // Move forward
    {
        cameraDistance -= 1.0f;
    }
    else if (cAscii == 's') // Move backward
    {
        cameraDistance += 1.0f;
    }
    else if (cAscii == 'a') // Move left
    {
        cameraAngleX -= 1.0f;
    }
    else if (cAscii == 'd') // Move right
    {
        cameraAngleX += 1.0f;
    }
    else if (cAscii == 'q') // Tilt camera up
    {
        cameraAngleY -= 1.0f; 
    }
    else if (cAscii == 'e') // Tilt camera down
    {
        cameraAngleY += 1.0f;
    }

    if (cameraAngleY > 89.0f) cameraAngleY = 89.0f;
    if (cameraAngleY < -89.0f) cameraAngleY = -89.0f;

    glutPostRedisplay();
}

void myWindow::OnMouseMotion(int x, int y){}

void myWindow::UpdateTimer()
{
    time1 = clock();
    float delta = static_cast<float>(static_cast<double>(time1-time0)/static_cast<double>(CLOCKS_PER_SEC));
    delta = delta / 4;
    if (delta > 0.00005f)
    {
        time0 = clock();
        if (bUp)
        {
            timer010 += delta;
            if (timer010>=1.0f) { timer010 = 1.0f; bUp = false;}
        }
        else
        {
            timer010 -= delta;
            if (timer010<=0.0f) { timer010 = 0.0f; bUp = true;}
        }
    }
}

void myWindow::DemoLight(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
}
