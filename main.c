
#include <windows.h>
#include <GL/glut.h> 
#include <stdlib.h>  
#include <math.h>
#define PI 3.1415926535


float timex = 0, timey = 0;
float posix = 0, posiy = 0;

 
void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
glClearDepth(1.0f); 
glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
switch (key) {
case 's':
timex -=0.001;
break;
case 'w':
timex += 0.001;
break;
case 'a':
timey += 0.05;
break;
case 'd':
timey -= 0.05;
break;

}
glutPostRedisplay();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();


 
glPushMatrix();
glTranslatef(0,0,-10);
glRotatef(0,1,0,0);




glPushMatrix();


glTranslatef(posix,posiy,0);

glPushMatrix();
glBegin(GL_QUADS);
glColor3f(1,1,1); 
glVertex3f( 0.3,  -0.5,0);
glVertex3f(-0.3,  -0.5,0);
glVertex3f(-0.3,   0.5,0);
glVertex3f( 0.3,   0.5,0);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(1,0,0);
glVertex3f(0,0,0);
glVertex3f(10*timex*sin(timey),10*timex*cos(timey),0.1); 
glEnd();


glPopMatrix();


glPopMatrix();




glPopMatrix();

glutSwapBuffers(); 
//---------------------------------comandos

posix += timex*sin(timey);
posiy += timex*cos(timey);


if(timey >6.28319)timey=0;
if(timey <-6.28319)timey=0;


}


void timer(int value) {
glutPostRedisplay(); 
glutTimerFunc(0, timer, 0);
}

void reshape() { 
glMatrixMode(GL_PROJECTION); 
gluPerspective(30, 1, 10, 100.0f);
}





int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE); 
glutInitWindowSize(800, 800); 
glutInitWindowPosition(50, 50); 
glutCreateWindow("super cubo"); 
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
initGL(); 
glutTimerFunc(0, timer, 0); 
glutMainLoop(); 
return 0; }
