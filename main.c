
#include <windows.h>
#include <GL/glut.h> 
#include <stdlib.h>  
#include <math.h>
#define PI 3.1415926535



float timex = 0, timey = 0;
float posix = 0, posiy = 0;
int i1,i2;
float time = 0;





void initGL() {
glClearColor(0,0,0, 1.0f); 
glClearDepth(1.0f); 
glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
switch (key) {
case 's':
timex -=0.03;
break;
case 'w':
timex += 0.03;

break;
case 'a':
timey += 3;

break;
case 'd':
timey -= 3	;

break;

}
glutPostRedisplay();
}


void roda(){

}


void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();



glPushMatrix();
glTranslatef(0,-2,-5);
glRotatef(10,1,0,0);



//-----------------------------------------------ceu

glPushMatrix();
glRotatef(-timey,0,1,0);


//-----------------------------------------------chao


glTranslatef(posix,0,posiy);



for(i1=-10;i1<10;i1+=1){
for(i2=-10;i2<10;i2+=1){




glPushMatrix();
glTranslatef((i1)*20,-1,(i2)*20);

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex3f( 10, 0,  10);
glVertex3f(-10, 0,  10);
glVertex3f(-10, 0, -10);
glVertex3f( 10, 0, -10);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0,0,0);
glVertex3f( 10, 0.1,  10);
glVertex3f(-10, 0.1,  10);
glVertex3f(-10, 0.1, -10);
glVertex3f( 10, 0.1, -10);
glEnd();

glPopMatrix();



}
}

glPopMatrix();


//------------------------------------------------objeto






glPushMatrix();
glRotatef(-time/2,1,0,0);
glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex3f( 1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f( 1.0f, 1.0f, 1.0f);

glColor3f(1.0f, 0.5f, 0.0f);
glVertex3f( 1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f( 1.0f, -1.0f, -1.0f);

glColor3f(1.0f, 0.0f, 0.0f); 
glVertex3f( 1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f( 1.0f, -1.0f, 1.0f);

glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f( 1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f( 1.0f, 1.0f, -1.0f);

glColor3f(0.0f, 0.0f, 1.0f); 
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);

glColor3f(1.0f, 0.0f, 1.0f);
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();

glPopMatrix();

glPopMatrix();






glutSwapBuffers();
//----------------------------------------------colisao



//----------------------------------------basicos
posix += timex*sin(timey*PI/180);
posiy += timex*cos(timey*PI/180);


time += timex*50;






if(timey >360 || timey <-360)timey=0;

if(posix >10){
posix=-10;	
}
if(posix <-10){
posix=10;
}
if(posiy >10){
posiy=-10;
}
if(posiy <-10){
posiy=10;	
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
gluPerspective(100, aspect, 0.1f, 800);
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
