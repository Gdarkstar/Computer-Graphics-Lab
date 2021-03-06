#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
//Drawing funciton
void circle()
{
  float rad=5.0;
  glBegin(GL_POLYGON);
  glColor3f(1,0.5,0);
  glVertex2f(50,85);
  glColor3f(1,0.5,0);
  glVertex2f(95,85);
  glColor3f(1,0.5,0);
  glVertex2f(95,75);
  glColor3f(1,0.5,0);
  glVertex2f(50,75);

  glEnd();
 glBegin(GL_POLYGON);
  glColor3f(1,1,65);
  glVertex2f(50,55);
  glColor3f(1,1,1);
  glVertex2f(95,65);
  glColor3f(1,1,1);
  glVertex2f(95,75);
  glColor3f(1,1,1);
  glVertex2f(50,75);

  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0,1,0);
  glVertex2f(50,55);
  glColor3f(0,1,0);
  glVertex2f(95,55);
  glColor3f(0,1,0);
  glVertex2f(95,65);
  glColor3f(0,1,0);
  glVertex2f(50,65);

  glEnd();

  glBegin(GL_LINE_LOOP);
  for(int i=0;i<360;++i)
  {
  float degrad=(2*3.1416*rad)/float(360);
  glColor3f(0,0,1);
  glVertex2f(70+rad*cos(i*degrad),70+rad*sin(i*degrad));
  
  }
  glEnd();


   for(int i=0;i<24;++i)
  {
   glBegin(GL_LINES);
  float degrad=(2*3.1416*rad)/float(24);
  glColor3f(0,0,1);
  glVertex2f(70+rad*cos(i*degrad),70+rad*sin(i*degrad));
  glColor3f(0,0,1);
  glVertex2f(70,70);
  glEnd();
  }
  glFlush();
}


void Init(){
  //Background color(r,g,b,a) a is for transparancy
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT );

  glMatrixMode(GL_PROJECTION);//used for next function
  gluOrtho2D(0,100,0,100);//gluOrthod xmin xmax,ymin ymax
}

//Main program
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(400,200);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("My First Computer Graphics Program!");
  //Call to the drawing function
  Init();
  glutDisplayFunc(circle);
  glutMainLoop();
  return 0;
}
