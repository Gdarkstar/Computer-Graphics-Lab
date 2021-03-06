#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#define RAD (3.142/180.0)

using namespace std;
//Drawing funciton
int w1,n=1;
void Init(){
  //Background color(r,g,b,a) a is for transparancy
  glViewport(0,0,1000,1000);
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT );
  glMatrixMode(GL_PROJECTION);//used for next function
  gluOrtho2D(0,1000,0,1000);//gluOrthod xmin xmax,ymin ymax
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

int wx=1000,wy=1000;
int r=0,g=1,b=0;
int temp=5,flag=0;
GLfloat th=0,x,y;
void draw()
{
		glBegin(GL_POLYGON);
    glColor3f(r,g,b);
      glVertex2f(x,y);
      glVertex2f(-y,x);
      glVertex2f(-x,-y);
      glVertex2f(y,-x);
    glEnd();
    glFlush();
	}
void timer(int v)
{
    glutPostRedisplay();
    glutTimerFunc(1/n,timer,v);
}
void idle()
{
    th = th+2;
    if(th >= 360.0)
        th = th-360;
      x= 0.5*cos(RAD*th);
      y= 0.5*sin(RAD*th);
    //glutPostRedisplay();
}
void mousefunction(int button, int state, int x, int y)
{
	int x1=x;
	int y1=y;
	
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
		{
			glutIdleFunc(NULL);
			
		}
	else if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) 
		{
			glutIdleFunc(idle);
			
		}
  
}

void display(){

glClear(GL_COLOR_BUFFER_BIT);
    draw();
  glutSwapBuffers();
}
void keyboardtest(unsigned char key, int x, int y){
	//printf("handy");
	if(key=='r')	
	{
		r=1;
		 g=0;
		b=0;
	}
	else if(key=='g')
	{
		r=0;
		 g=1;
		b=0;
	}
	else if(key=='b')
	{
		r=0;
		 g=0;
		b=1;
	}
	else if(key=='+')
	{
    glScaled(2,2,2);
	  glutPostRedisplay(); 
	}
	else if(key=='-')
	{
	glScaled(0.5,0.5,0.5);
	  glutPostRedisplay(); 
	}
	else if(key=='t')
	{
		flag=1;
	}
	else if(key=='s')
	{
		flag=0;
	}
	else if(key=='q')
	{
		exit(0);
	}

}

void key1(int k,int x,int y)
{
   switch(k)
  {
       case GLUT_KEY_UP:
        glTranslated(0,1,0);
	      glutPostRedisplay();
         break;
      case GLUT_KEY_DOWN:
        glTranslated(0,-1,0);
	      glutPostRedisplay();
         break;
      case GLUT_KEY_LEFT:
        glTranslated(-1,0,0);
	      glutPostRedisplay(); 
      break;
      case GLUT_KEY_RIGHT:
        glTranslated(1,0,0);
	      glutPostRedisplay();
 break;
  }

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    w1 = glutCreateWindow("Translate square");
 
    glutDisplayFunc(display);
    glutSpecialFunc(key1);
    glutKeyboardFunc(keyboardtest);
glutTimerFunc(100,timer,n);
    glutIdleFunc(idle);
    glutMouseFunc(mousefunction);
    Init();
    glutMainLoop();


  return 0;
}
