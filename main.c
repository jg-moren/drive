
#include <windows.h>
#include <GL/glut.h> 
#include <stdlib.h>  
#include <math.h>
#define PI 3.1415926535



float timex = 0, timey = 0;
float posix = 0, posiy = 0;
int i1,i2,x=0,y=0;
float time = 0,curva = 180;
float camera = 0;

int mapa[8][8][2]={
{ {2,-1},{3,-1},{1, 0},{3,-1},{3,-1},{1, 0},{1, 0},{2, 0} },
{ {1, 1},{3, 2},{1, 0},{2, 1},{2, 2},{1, 0},{3,-1},{2, 1} },
{ {1, 1},{1, 1},{2,-1},{1, 0},{1, 0},{2, 0},{3, 2},{2, 0} },
{ {2, 2},{3, 0},{1, 1},{2,-1},{2, 0},{1, 1},{1, 1},{1, 1} },
{ {2,-1},{3, 1},{3, 0},{2, 2},{3, 0},{1, 1},{1, 1},{1, 1} },
{ {1, 1},{2,-1},{2, 1},{2,-1},{3, 1},{3, 1},{3, 0},{1, 1} },
{ {1, 1},{1, 1},{2,-1},{3, 1},{1, 0},{1, 0},{3, 0},{1, 1} },
{ {2, 2},{3, 1},{3, 1},{1, 0},{1, 0},{1, 0},{3, 1},{2, 1} }
};



void initGL() {
glClearColor(0,0,0, 1.0f); 
glClearDepth(1.0f); 
glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
switch (key) {
case 's':
timex -=0.02;
if (timex < 0)timex = 0;
break;
case 'w':
timex = timex*1.02 + 0.01;

break;
case 'a':
timey += 2;

break;
case 'd':
timey -= 2;

break;

}
glutPostRedisplay();
}

void car (){
glScalef(0.05,0.05,0.05);
glRotatef(-90,0,1,0);
//https://community.khronos.org/t/model-car-3d/76847
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-40.0f,0.0f,15.0f);
        glVertex3f(40.0f,0.0f,15.0f);
        glColor3f(0.1, 0.1, 0.1);
        glVertex3f(40.0f,-15.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,15.0f);
        glColor3f(0.1, 0.1, 0.1);
        glVertex3f(40.0f,-15.0f,15.0f);
        glVertex3f(40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glVertex3f(-40.0f,0.0f,15.0f);
        glColor3f(0.1, 0.1, 0.1);
		glVertex3f(-40.0f,-15.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,-15.0f);
        glColor3f(0.1, 0.1, 0.1);
        glVertex3f(40.0f,-15.0f,-15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-40.0f,0.0f,15.0f);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glColor3f(0.175, 0.175, 0.175);
        glVertex3f(40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(1,1,1);
        glVertex3f(-40.0f,-15.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
        glVertex3f(40.0f,-15.0f,-15.0f);
        glVertex3f(40.0f,-15.0f,15.0f);
    glEnd();

    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-20.0f,0.0f,15.0f);
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-10.0f,10.0f,15.0f);
        glVertex3f(20.0f,10.0f,15.0f);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(25.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-20.0f,0.0f,-15.0f);
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-10.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(25.0f,0.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.25, 0.25, 0.25);
        glVertex3f(-10.0f,10.0f,15.0f);
        glVertex3f(-10.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.25, 0.25, 0.25);
        glVertex3f(-10.0f,10.0f,15.0f);
    	glColor3f(0.3, 0.3, 0.3);
        glVertex3f(-20.0f,0.0f,15.0f);
    	glColor3f(0.25, 0.25, 0.25);
        glVertex3f(-20.0f,0.0f,-15.0f);
    	glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-10.0f,10.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(20.0f,10.0f,15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glVertex3f(25.0f,0.0f,-15.0f);
        glVertex3f(25.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.2, 0.2, 0.2);
        glVertex3f(-30.0f,-15.0f,15.0f);
        glVertex3f(-30.0f,-15.0f,-15.0f);
        glVertex3f(30.0f,-15.0f,-15.0f);
        glVertex3f(30.0f,-15.0f,15.0f);
    glEnd();
	

}

void predio(){
glPushMatrix();
glScalef(0.085,0.085,0.085);
glBegin(GL_QUADS);


glColor3f(0.3f, 0.3f, 0.3f); 
glVertex3f(0, 100,0);
glVertex3f(0, 0,0);
glColor3f(0.4,0.4,0.4);
glVertex3f(55, 0,0);
glVertex3f(55, 100,0);

glColor3f(0.3f, 0.3f, 0.3f); 
glVertex3f(55, 100,0);
glVertex3f(55, 0,0);
glColor3f(0.4,0.4,0.4);
glVertex3f(55, 0,50);
glVertex3f(55, 100,50);

glColor3f(0.3f, 0.3f, 0.3f); 
glVertex3f(0, 100,0);
glVertex3f(0, 0,0);
glColor3f(0.4,0.4,0.4);
glVertex3f(0, 0,50);
glVertex3f(0, 100,50);

glColor3f(0.3f, 0.3f, 0.3f); 
glVertex3f(0, 100,50);
glVertex3f(0, 0,50);
glColor3f(0.4,0.4,0.4);
glVertex3f(55, 0,50);
glVertex3f(55, 100,50);

glEnd();
glPopMatrix();

}

void predios (){
glPushMatrix();
glScalef(0.085,0.085,0.085);
glBegin(GL_QUADS);

glColor3f(0.7f, 0.3f, 0.1f); 
glVertex3f(55, 100,0.01f);
glVertex3f(5, 100,0.01f);
glVertex3f(5, 0,0.1f);
glVertex3f(55, 0,0.01f);

glColor3f(0.6f, 0.2f, 0.1f); 
glVertex3f(55, 100,50);
glVertex3f(55, 100,0);
glVertex3f(55, 0,0);
glVertex3f(55, 0,50);

glVertex3f(5, 100,50);
glVertex3f(5, 100,0);
glVertex3f(5, 0,0);
glVertex3f(5, 0,50);

//---------------------------------------
glColor3f(0.6f,0.3f,0.6f); 
glVertex3f(110, 90,0.1f);
glVertex3f(60, 90,0.1f);
glVertex3f(60, 0,0.1f);
glVertex3f(110, 0,0.1f);

glColor3f(0.5f,0.2f,0.5f);
glVertex3d(110, 90,50);
glVertex3d(110, 90,0);
glVertex3d(110, 0,0);
glVertex3d(110, 0,50);

glVertex3d(60, 90,50);
glVertex3d(60, 90,0);
glVertex3d(60, 0,0);
glVertex3d(60, 0,50);
//---------------------------------------

glColor3f(0.7f,0.1f,0.1f);
glVertex3f(120,0,0.1f);
glVertex3f(170,0,0.1f);
glVertex3f(170,95,0.1f);
glVertex3f(120,95,0.1f);

glColor3f(0.6f,0.1f,0.1f);
glVertex3d(170,0,50);
glVertex3d(170,0,0);
glVertex3d(170,95,0);
glVertex3d(170,95,50);


glVertex3d(120,0,50);
glVertex3d(120,0,0);
glVertex3d(120,95,0);
glVertex3d(120,95,50);
//--------------------------------------
glColor3f(0.1f,0.1f,0.7f);
glVertex3f(180,0,0.1);
glVertex3f(230,0,0.1);
glVertex3f(230,80,0.1);
glVertex3f(180,80,0.1);

glColor3f(0.0f,0.1f,0.6f);
glVertex3f(230,0,50);
glVertex3f(230,0,0);
glVertex3f(230,80,0);
glVertex3f(230,80,50);

glColor3f(0.1f,0.2f,0.6f);
glVertex3f(180,0,50);
glVertex3f(180,0,0);
glVertex3f(180,80,0);
glVertex3f(180,80,50);


// Janela 5 andar
glColor3f(1.0f, 1.0f, 0.0f); 
glVertex2d(195, 75);
glVertex2d(185, 75);
glVertex2d(185, 70);
glVertex2d(195, 70);

glVertex2d(225, 75);
glVertex2d(215, 75);
glVertex2d(215, 70);
glVertex2d(225, 70);
// Janela 4 andar
glVertex2d(195, 60);
glVertex2d(185, 60);
glVertex2d(185, 55);
glVertex2d(195, 55);

glVertex2d(225, 60);
glVertex2d(215, 60);
glVertex2d(215, 55);
glVertex2d(225, 55);
// Janela 3 andar
glVertex2d(195, 45);
glVertex2d(185, 45);
glVertex2d(185, 40);
glVertex2d(195, 40);

glVertex2d(225, 45);
glVertex2d(215, 45);
glVertex2d(215, 40);
glVertex2d(225, 40);
// Janela 2 andar
glVertex2d(195, 30);
glVertex2d(185, 30);
glVertex2d(185, 25);
glVertex2d(195, 25);

glVertex2d(225, 30);
glVertex2d(215, 30);
glVertex2d(215, 25);
glVertex2d(225, 25);
// Janela 1 andar
glVertex2d(195, 15);
glVertex2d(185, 15);
glVertex2d(185, 10);
glVertex2d(195, 10);

glVertex2d(225, 15);
glVertex2d(215, 15);
glVertex2d(215, 10);
glVertex2d(225, 10);
// Janela 5 andar
glVertex2d(135, 75);
glVertex2d(125, 75);
glVertex2d(125, 70);
glVertex2d(135, 70);

glVertex2d(165, 75);
glVertex2d(155, 75);
glVertex2d(155, 70);
glVertex2d(165, 70);
// Janela 4 andar
glVertex2d(135, 60);
glVertex2d(125, 60);
glVertex2d(125, 55);
glVertex2d(135, 55);

glVertex2d(165, 60);
glVertex2d(155, 60);
glVertex2d(155, 55);
glVertex2d(165, 55);
// Janela 3 andar
glVertex2d(135, 45);
glVertex2d(125, 45);
glVertex2d(125, 40);
glVertex2d(135, 40);

glVertex2d(165, 45);
glVertex2d(155, 45);
glVertex2d(155, 40);
glVertex2d(165, 40);
// Janela 2 andar
glVertex2d(135, 30);
glVertex2d(125, 30);
glVertex2d(125, 25);
glVertex2d(135, 25);

glVertex2d(165, 30);
glVertex2d(155, 30);
glVertex2d(155, 25);
glVertex2d(165, 25);
// Janela 1 andar
glVertex2d(135, 15);
glVertex2d(125, 15);
glVertex2d(125, 10);
glVertex2d(135, 10);

glVertex2d(165, 15);
glVertex2d(155, 15);
glVertex2d(155, 10);
glVertex2d(165, 10);
// Janela 5 andar
glVertex2d(75, 75);
glVertex2d(65, 75);
glVertex2d(65, 70);
glVertex2d(75, 70);

glVertex2d(105, 75);
glVertex2d(95, 75);
glVertex2d(95, 70);
glVertex2d(105, 70);
// Janela 4 andar
glVertex2d(75, 60);
glVertex2d(65, 60);
glVertex2d(65, 55);
glVertex2d(75, 55);

glVertex2d(105, 60);
glVertex2d(95, 60);
glVertex2d(95, 55);
glVertex2d(105, 55);
// Janela 3 andar
glVertex2d(75, 45);
glVertex2d(65, 45);
glVertex2d(65, 40);
glVertex2d(75, 40);

glVertex2d(105, 45);
glVertex2d(95, 45);
glVertex2d(95, 40);
glVertex2d(105, 40);
// Janela 2 andar
glVertex2d(75, 30);
glVertex2d(65, 30);
glVertex2d(65, 25);
glVertex2d(75, 25);

glVertex2d(105, 30);
glVertex2d(95, 30);
glVertex2d(95, 25);
glVertex2d(105, 25);
// Janela 1 andar
glVertex2d(75, 15);
glVertex2d(65, 15);
glVertex2d(65, 10);
glVertex2d(75, 10);

glVertex2d(105, 15);
glVertex2d(95, 15);
glVertex2d(95, 10);
glVertex2d(105, 10);
//Janela 6 andar
glVertex2d(20, 90);
glVertex2d(10, 90);
glVertex2d(10, 85);
glVertex2d(20, 85);

glVertex2d(50, 90);
glVertex2d(40, 90);
glVertex2d(40, 85);
glVertex2d(50, 85);
//Janela 5 andar
glVertex2d(20, 75);
glVertex2d(10, 75);
glVertex2d(10, 70);
glVertex2d(20, 70);

glVertex2d(50, 75);
glVertex2d(40, 75);
glVertex2d(40, 70);
glVertex2d(50, 70);
//Janela 4 andar
glVertex2d(20, 60);
glVertex2d(10, 60);
glVertex2d(10, 55);
glVertex2d(20, 55);

glVertex2d(50, 60);
glVertex2d(40, 60);
glVertex2d(40, 55);
glVertex2d(50, 55);
//Janela 3 andar
glVertex2d(20, 45);
glVertex2d(10, 45);
glVertex2d(10, 40);
glVertex2d(20, 40);

glVertex2d(50, 45);
glVertex2d(40, 45);
glVertex2d(40, 40);
glVertex2d(50, 40);
//Janela 2 andar
glVertex2d(20, 30);
glVertex2d(10, 30);
glVertex2d(10, 25);
glVertex2d(20, 25);

glVertex2d(50, 30);
glVertex2d(40, 30);
glVertex2d(40, 25);
glVertex2d(50, 25);
//Janela 1 andar
glVertex2d(20, 15);
glVertex2d(10, 15);
glVertex2d(10, 10);
glVertex2d(20, 10);

glVertex2d(50, 15);
glVertex2d(40, 15);
glVertex2d(40, 10);
glVertex2d(50, 10);

glEnd();

glPopMatrix();
}

void roda(){

glPushMatrix();
glRotatef(-time/2,1,0,0);
for(i1 = 0; i1 < 10; i1++){
glBegin(GL_LINE_LOOP);
glColor3f(0,0,0);
glVertex3f(-0.2,0.5*cos((2*PI*i1)/10),0.5*sin((2*PI*i1)/10)); 
glVertex3f( 0.2,0.5*cos((2*PI*i1)/10),0.5*sin((2*PI*i1)/10)); 
glVertex3f( 0.2,0.5*cos((2*PI*(i1+1))/10),0.5*sin((2*PI*(i1+1))/10)); 
glVertex3f(-0.2,0.5*cos((2*PI*(i1+1))/10),0.5*sin((2*PI*(i1+1))/10)); 
glEnd();
}
for(i1 = 0; i1 < 10; i1++){
glBegin(GL_POLYGON);
glColor3f(0.3,0.3,0.3);
glVertex3f(-0.2,0.49*cos((2*PI*i1)/10),0.49*sin((2*PI*i1)/10)); 
glVertex3f( 0.2,0.49*cos((2*PI*i1)/10),0.49*sin((2*PI*i1)/10)); 
glVertex3f( 0.2,0.49*cos((2*PI*(i1+1))/10),0.49*sin((2*PI*(i1+1))/10)); 
glVertex3f(-0.2,0.49*cos((2*PI*(i1+1))/10),0.49*sin((2*PI*(i1+1))/10)); 
glEnd();
}

glBegin(GL_POLYGON);
for(i1 = 0; i1 < 10; i1++){
glColor3f(0.6,0.6,0.6);
glVertex3f(-0.2,0.49*cos((2*PI*i1)/10),0.49*sin((2*PI*i1)/10)); 
}glEnd();
glPopMatrix();

}

void I (int rotate){
	
glPushMatrix();
glRotatef(rotate*90,0,1,0);


glBegin(GL_QUADS);
glColor3f(0.4,0.4,0.4); 
glVertex3f( 10, 0, -10);
glVertex3f(-10, 0, -10);
glVertex3f(-10, 0,  10);
glVertex3f( 10, 0,  10);

glColor3f(0.5,0.5,0.5); 
glVertex3f( 5, 0.1, -10);
glVertex3f(-5, 0.1, -10);
glVertex3f(-5, 0.1,  10);
glVertex3f( 5, 0.1,  10);

glColor3f(0,0,0);
glVertex3f( 9,10, -10);
glVertex3f( 9, 0, -10);
glVertex3f( 9, 0,  10);
glVertex3f( 9,10,  10);

glColor3f(0,0,0);
glVertex3f( -9,10, -10);
glVertex3f( -9, 0, -10);
glVertex3f( -9, 0,  10);
glVertex3f( -9,10,  10);

glEnd();

glPushMatrix();
glTranslatef(5,0,10);
glRotatef(90,0,1,0);
predios();
glPopMatrix();

glPushMatrix();
glTranslatef(-5,0,-10);
glRotatef(-90,0,1,0);
predios();
glPopMatrix();


glPopMatrix();




}

void L (int rotate){
	
glPushMatrix();
glRotatef(rotate*90,0,1,0);
glBegin(GL_QUADS);
glColor3f(0.4,0.4,0.4); 
glVertex3f( 10, 0, -10);
glVertex3f(-10, 0, -10);
glVertex3f(-10, 0,  10);
glVertex3f( 10, 0,  10);


glColor3f(0.5,0.5,0.5); 
glVertex3f( 5, 0.1, -10);
glVertex3f(-5, 0.1, -10);
glVertex3f(-5, 0.1,  5);
glVertex3f( 5, 0.1,  5);

glColor3f(0.5,0.5,0.5); 
glVertex3f(10, 0.1, -5);
glVertex3f(-5, 0.1, -5);
glVertex3f(-5, 0.1,  5);
glVertex3f(10, 0.1,  5);

glColor3f(0,0,0);
glVertex3f(-9, 0, -10);
glVertex3f(-9, 0,  9);
glVertex3f(-9,10,  9);
glVertex3f(-9,10, -10);


glVertex3f(-9,10,  9);
glVertex3f(-9, 0,  9);
glVertex3f(10, 0, 9);
glVertex3f(10,10, 9);

glVertex3f(9, 0,  -9);
glVertex3f(9,10,  -9);
glVertex3f(9,10,  -10);
glVertex3f(9, 0, -10);

glVertex3f(9, 0,  -9);
glVertex3f(9,10,  -9);
glVertex3f(10,10, -9);
glVertex3f(10, 0,  -9);

glEnd();

glPushMatrix();
glTranslatef(-10,0,5);
glRotatef(0,0,1,0);
predios();
glPopMatrix();

glPushMatrix();
glTranslatef(-5,0,-10);
glRotatef(-90,0,1,0);
predios();
glPopMatrix();


glPushMatrix();
glTranslatef(5,0,-5);
glRotatef(90,0,1,0);
predio();
glPopMatrix();


glPopMatrix();

}

void T (int rotate){
	
glPushMatrix();
glRotatef(rotate*90,0,1,0);
glBegin(GL_QUADS);
glColor3f(0.4,0.4,0.4); 
glVertex3f( 10, 0, -10);
glVertex3f(-10, 0, -10);
glVertex3f(-10, 0,  10);
glVertex3f( 10, 0,  10);

glColor3f(0.5,0.5,0.5); 
glVertex3f( 5, 0.1, -10);
glVertex3f(-5, 0.1, -10);
glVertex3f(-5, 0.1,  5);
glVertex3f( 5, 0.1,  5);

glColor3f(0.5,0.5,0.5); 
glVertex3f( 10, 0.1, -5);
glVertex3f(-10, 0.1, -5);
glVertex3f(-10, 0.1,  5);
glVertex3f( 10, 0.1,  5);

glColor3f(0,0,0);

glVertex3f(-10, 0,  9);
glVertex3f(-10,10,  9);
glVertex3f( 10,10,  9);
glVertex3f( 10, 0,  9);

glVertex3f(9, 0,  -9);
glVertex3f(9,10,  -9);
glVertex3f(9,10,  -10);
glVertex3f(9, 0, -10);

glVertex3f(9, 0,  -9);
glVertex3f(9, 10,  -9);
glVertex3f(10, 10,  -9);
glVertex3f(10, 0, -9);

glVertex3f(-9, 0,  -9);
glVertex3f(-9, 10,  -9);
glVertex3f(-9, 10,  -10);
glVertex3f(-9, 0, -10);

glVertex3f(-9, 0,  -9);
glVertex3f(-9, 10,  -9);
glVertex3f(-10, 10,  -9);
glVertex3f(-10, 0, -9);

glEnd();

glPushMatrix();
glRotatef(0,0,1,0);
glTranslatef(-10,0,5);
glRotatef(0,0,1,0);
predios();
glPopMatrix();

glPushMatrix();
glTranslatef(5,0,-5);
glRotatef(90,0,1,0);
predio();
glPopMatrix();

glPushMatrix();
glTranslatef(-5,0,-5);
glRotatef(180,0,1,0);
predio();
glPopMatrix();

glPopMatrix();

}

void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();



glPushMatrix();
glTranslatef(0,-1.5,-1.75);
glRotatef(10,1,0,0);
glRotatef(-camera,0,1,0);


//-----------------------------------------------ceu

glPushMatrix();
glRotatef(-curva,0,1,0);

glPushMatrix();
glTranslatef(10,20,-20);
glColor3f(1.0f, 1.0f, 1.0f); 
glutSolidSphere(5,20,20);
glPopMatrix();


for(i1=0;i1<10;i1+=1){
for(i2=0;i2<10;i2+=1){

glPushMatrix();

glRotatef((i2)*20,0,1,0);
glTranslatef(i1-i2,8.3,0.5);
glRotatef(i1*20,0,1,0);

glScalef(3,1,3);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f); 
glVertex3f( 1,0,1);
glVertex3f( -2,0,-4);
glVertex3f( 3,0,3);
glVertex3f( -2,0,-1);

glEnd();

glPopMatrix();
}
}

//-----------------------------------------------chao


glTranslatef(posix,0,posiy);



for(i1=0;i1<8;i1+=1){
for(i2=0;i2<8;i2+=1){




glPushMatrix();
glTranslatef((i1-x)*20,0,(i2-y)*20);


switch (mapa[i1][i2][0]){
case 1:
I(mapa[i1][i2][1]);
break;

case 2:	
L(mapa[i1][i2][1]);

break;
case 3:
T(mapa[i1][i2][1]);
break;
}


glPopMatrix();



}
}




glPopMatrix();


//------------------------------------------------objeto

glPushMatrix();
glTranslatef(0,0.3,0);
glScalef(0.3,0.3,0.3);

glPushMatrix();
glTranslatef(0,0.5,0);
car();
glPopMatrix();

glPushMatrix();
glTranslatef(0.8,0,1);
glScalef(-1,-1,-1);
roda();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.8,0,1);
roda();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.8,0,-1);
glRotatef(timey,0,1,0);
roda();
glPopMatrix();

glPushMatrix();
glTranslatef(0.8,0,-1);
glRotatef(timey,0,1,0);
glScalef(-1,-1,-1);
roda();
glPopMatrix();

glPopMatrix();
//---------------------------------comandos

glPopMatrix();


glBegin(GL_LINE_STRIP);
glColor3f(1,0,0);
glVertex3f(-0.6,-1,-1);
glVertex3f(-0.2*cos((2*PI*timex)/2)-0.6,0.2*sin((2*PI*timex)/2)-1,-1); 
glEnd();


glutSwapBuffers();
//----------------------------------------------colisao

switch (mapa[x][y][0]){
case  1:

if(mapa[x][y][1] == 1 || mapa[x][y][1] == -1){
if(posiy > 4.5)posiy= 4.5,timex=timex/1.1; 
if(posiy <-4.5)posiy=-4.5,timex=timex/1.1;
}
else{
if(posix > 4.5)posix= 4.5,timex=timex/1.1;
if(posix <-4.5)posix=-4.5,timex=timex/1.1;
}

break;

case 2:	

if(mapa[x][y][1] == 1){
if(posix <-4.5)posix=-4.5,timex=timex/1.1;
if(posiy <-4.5)posiy=-4.5,timex=timex/1.1;
if(posiy > 4.5 && posix > 5) posiy = 4.5,timex=timex/1.1;
if(posix > 4.5 && posiy > 5) posix = 4.5,timex=timex/1.1;
}
else if (mapa[x][y][1] == 0){
if(posiy <-4.5)posiy=-4.5,timex=timex/1.1; 
if(posix > 4.5)posix= 4.5,timex=timex/1.1;
if(posiy > 4.5 && posix <-5) posiy = 4.5,timex=timex/1.1;
if(posix <-4.5 && posiy > 5) posix =-4.5,timex=timex/1.1;
}
else if(mapa[x][y][1] == -1){
if(posix > 4.5)posix= 4.5,timex=timex/1.1;
if(posiy > 4.5)posiy= 4.5,timex=timex/1.1;
if(posiy <-4.5 && posix <-5) posiy =-4.5,timex=timex/1.1;
if(posix <-4.5 && posiy <-5) posix =-4.5,timex=timex/1.1;
}
else if (mapa[x][y][1] == 2){
if(posiy > 4.5)posiy= 4.5,timex=timex/1.1; 
if(posix <-4.5)posix=-4.5,timex=timex/1.1;
if(posiy <-4.5 && posix > 5) posiy =-4.5,timex=timex/1.1;
if(posix > 4.5 && posiy <-5) posix = 4.5,timex=timex/1.1;
}

break;
case 3:

if(mapa[x][y][1] == 1){
if(posix <-4.5)posix=-4.5,timex=timex/1.1;
if(posiy > 4.5 && posix > 5) posiy = 4.5,timex=timex/1.1;
if(posix > 4.5 && posiy > 5) posix = 4.5,timex=timex/1.1;
if(posiy <-4.5 && posix > 5) posiy =-4.5,timex=timex/1.1;
if(posix > 4.5 && posiy <-5) posix = 4.5,timex=timex/1.1;
}
else if (mapa[x][y][1] == 0){
if(posiy <-4.5)posiy=-4.5,timex=timex/1.1; 
if(posiy > 4.5 && posix <-5) posiy = 4.5,timex=timex/1.1;
if(posix <-4.5 && posiy > 5) posix =-4.5,timex=timex/1.1;
if(posiy > 4.5 && posix > 5) posiy = 4.5,timex=timex/1.1;
if(posix > 4.5 && posiy > 5) posix = 4.5,timex=timex/1.1;
}
else if(mapa[x][y][1] == -1){
if(posix > 4.5)posix= 4.5,timex=timex/1.1;
if(posiy > 4.5 && posix <-5) posiy = 4.5,timex=timex/1.1;
if(posix <-4.5 && posiy > 5) posix =-4.5,timex=timex/1.1;
if(posiy <-4.5 && posix <-5) posiy =-4.5,timex=timex/1.1;
if(posix <-4.5 && posiy <-5) posix =-4.5,timex=timex/1.1;
}
else if (mapa[x][y][1] == 2){
if(posiy > 4.5)posiy= 4.5,timex=timex/1.1; 
if(posiy <-4.5 && posix > 5) posiy =-4.5,timex=timex/1.1;
if(posix > 4.5 && posiy <-5) posix = 4.5,timex=timex/1.1;
if(posiy <-4.5 && posix <-5) posiy =-4.5,timex=timex/1.1;
if(posix <-4.5 && posiy <-5) posix =-4.5,timex=timex/1.1;
}

break;


}

//----------------------------------------basicos
posix += timex*sin(curva*PI/180);
posiy += timex*cos(curva*PI/180);

timex = timex/1.005;

time += timex*50;



if (timex > 0.001 ){
curva = curva+timey/10;
if (timey > 0)timey =timey/1.05;
if (timey < 0)timey =timey/1.05;

}

camera = (camera-timey)/2;

if(timey >360 || timey <-360)timey=0;

if(posix >10){
posix=-10;
x-=1;	
}
if(posix <-10){
posix=10;
x+=1;	
}
if(posiy >10){
posiy=-10;
y-=1;	
}
if(posiy <-10){
posiy=10;
y+=1;	
}

}
 

void timer(int value) {
glutPostRedisplay(); 
glutTimerFunc(0, timer, 0);
}

void reshape(GLsizei width, GLsizei height) { 
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;


glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluPerspective(100, aspect, 1, 800);
}



int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE); 
glutInitWindowSize(600, 600); 
glutInitWindowPosition(50, 50); 
glutCreateWindow("super cubo"); 
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
initGL(); 
glutTimerFunc(0, timer, 0); 
glutMainLoop(); 
return 0; }
