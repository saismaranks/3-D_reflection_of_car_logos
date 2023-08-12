#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<string.h>
#define TIMER 33
#define IntroScreen 0 
#define ProjectScreen 1
int viewScreen=0; 
 int SCREEN_WIDTH = 1024;
 int SCREEN_HEIGHT = 768;
 void project_screen(); 

void *font = GLUT_STROKE_ROMAN;
void *fonts[] =
{
    GLUT_STROKE_ROMAN, GLUT_STROKE_MONO_ROMAN};
static float xrot;
int value=15,val=5,valu,v=1;
void polygon();
int theObject = -1;
char *objectNames[10] ={"BENZ","AUDI","HYUNDAI","TOYOTA"};

void output(GLfloat x, GLfloat y, char *format,...)
{
va_list args;
char buffer[200], *p;
if(theObject>=0)
  {
va_start(args, format);
vsprintf(buffer, format, args);
va_end(args);
glPushMatrix();
glTranslatef(x, y, 0);
for (p = buffer; *p; p++)
glutStrokeCharacter(font, *p);
glPopMatrix();
  }
}
void text()
{
glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
gluOrtho2D(0, 3000, 0, 3000);
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glColor3f(1.0,1.0,1.0);
output(1800,2800, "%s",objectNames[theObject]);
glPopMatrix();
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);
glPopAttrib();
}
void Colors()
{
switch(val)
  {
case 3:
	glColor3f(1.0,0.0,0.0);
	break;
case 4:
	glColor3f(0.0,1.0,0.0);
	break;
case 5:
	glColor3f(0.0,0.0,1.0);
	break;
case 6:
	glColor3f(1.0,1.0,1.0);
	break;
case 7:
	glColor3f(1.0,1.0,0.0);
	break;
default: glColor3f(.5, .5, 1.);
	break;
  }
 }
void col(int p)
{
	val=p;
}
void drawScene (GLenum order)
{
GLfloat pos[4] = {-2.5, 5., 2.2, 1.};
glLightfv (GL_LIGHT1, GL_POSITION, pos);
	glPushMatrix();
	glEnable (GL_CULL_FACE);
	glCullFace (GL_BACK);
	glFrontFace (order);
text();

	/* Draw the walls */
    glColor3f (1., 1., 1.);
	glBegin(GL_QUADS);
	  glNormal3f (1., 0., 0.);
	    glVertex3f (-3., 3., 4.);
	    glVertex3f (-3., -3., 4.);
	    glVertex3f (-3., -3., -3.);
	    glVertex3f (-3., 3., -3.);
	  glNormal3f (0., 0., 1.);
		glVertex3f (-3., 3., -3.);
		glVertex3f (-3., -3., -3.);
		glVertex3f (3., -3., -3.);
		glVertex3f (3., 3., -3.);
	  glNormal3f (-1., 0., 0.);
		glVertex3f (3., 3., -3.);
		glVertex3f (3., -3., -3.);
		glVertex3f (3., -3., 3.);
		glVertex3f (3., 3., 3.);
	glEnd();
	glDisable (GL_CULL_FACE);
	/* Draw the polygon */
glRotatef(xrot, 1.,1., 1.);
	Colors();
glPushMatrix ();
glPopMatrix ();
	polygon();
	glPopMatrix();
}
void tor()
{
	theObject = 0;
	//glutSolidTorus(0.2,0.3,80,90);
	glTranslatef(0.0,0.0,0.6);
	glutSolidTorus(0.1,0.6,80,90);
    glPushMatrix();
	glRotated(90,1.,0.,0);
	glutSolidCone(0.12,0.6,5,5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90,1.,0.,0);
	glRotated(120,0,1.,0);
	glutSolidCone(0.12,0.6,5,5);
	glPopMatrix();
    	glPushMatrix();
	glRotated(90,1.,0.,0);
	glRotated(240,0,1.,0);
	glutSolidCone(0.12,0.6,5,5);
	glPopMatrix();

	//glutSolidDodecahedron();
}
void oct()
{
theObject=1;
glScaled(.5,.5,.5);
glPushMatrix();
glTranslated(0,0,0);
glutSolidTorus(0.08,0.6,8,90);
glTranslated(1,0,0);
glutSolidTorus(0.08,0.6,8,90);
glTranslated(-2,0,0);
glutSolidTorus(0.08,0.6,8,90);
glTranslated(-1,0,0);
glutSolidTorus(0.08,0.6,8,90);
glPopMatrix();
}
void tet()
{
	theObject = 2;
	glPushMatrix();
	glScaled(1.5,0.75,1);
glutSolidTorus(0.15,0.9,30,90);
glPopMatrix();
glPushMatrix();
glRotated(90,1.,0.,0);
glTranslated(0.6,0,-0.6);
glutSolidCone(0.15,1.4,5,5);
glPopMatrix();
glPushMatrix();
glRotated(90,1.,0.,0);
glTranslated(-0.6,0,-0.6);
glutSolidCone(0.15,1.4,5,5);
glPopMatrix();
glPushMatrix();
glRotated(90,1.,0.,0);
glTranslated(-0.6,0,-0.6);
glRotated(45,0,1,0);
glutSolidCone(0.18,1.5,5,5);
glPopMatrix();

glPushMatrix();
glRotated(90,1.,0.,0);
glTranslated(0.6,0,0.6);
glRotated(225,0,1,0);
glutSolidCone(0.18,1.5,5,5);
glPopMatrix();



}
void cube()
{

	theObject = 3;
    glTranslatef(0.0,0.0,0.6);
	glutSolidTorus(0.05,0.6,80,90);
    glScaled(1.5,0.75,1);
    glutSolidTorus(0.12,0.5,90,90);

	//glutSolidCube(1);
}
void polygon()
{
	if(value==14)
		tor();
	if(value==15)
		oct();
	if(value==16)
		tet();
	if(value==17)
	{
		cube();
	}
}
void pol(int p)
{
	value=p;
}
void main_menu(int valu)
{
	value=valu;
if (value == 0)
exit(0);
}
void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    /*for(c=string;*c!='\0';c++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*c);
    }*/
    for(i = 0;i<len;i++)
    {
        glColor3f(1.0,1.0,1.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
}

void intro_screen() 
 { 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
 glColor3f(1,0,0);
 drawstring(0.35 * SCREEN_HEIGHT,SCREEN_WIDTH *.7,0.0,"JSS ACADEMY OF TECHNICAL EDUCATION, BENGALURU ");
 glColor3f(1,0,0);
 drawstring(0.33 * SCREEN_HEIGHT,SCREEN_WIDTH *.62,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(0.55 * SCREEN_HEIGHT,SCREEN_WIDTH *.54,0.0,"A MINI PROJECT ON");
 glColor3f(1,0,0);
 drawstring(0.45 * SCREEN_HEIGHT,SCREEN_WIDTH *.46,0.0,"3-D REFLECTION OF CAR LOGOS");
 glColor3f(1,0.5,0);
 drawstring(0.45 * SCREEN_HEIGHT,SCREEN_WIDTH *.38,0.0,"BY:");
 glColor3f(1,1,1);
 drawstring(0.5 * SCREEN_HEIGHT,SCREEN_WIDTH *.325,0.0," SAI SMARAN K S(1JS20CS139)");
 glColor3f(1,0.5,0);
 drawstring(0.4 * SCREEN_HEIGHT,SCREEN_WIDTH *.22,0.0,"GUIDES:");
 glColor3f(1,1,1);
 drawstring(0.5 * SCREEN_HEIGHT,SCREEN_WIDTH *.17,0.0,"Dr.Sharana Basavana Gowda");
 glColor3f(1,1,1);
 drawstring(0.5 * SCREEN_HEIGHT,SCREEN_WIDTH *.12,0.0,"Mrs.Rashmi.B.N");
 glColor3f(1,0.1,1);
 drawstring(0.55 * SCREEN_HEIGHT,SCREEN_WIDTH *.05,0.0,"CLICK TO CONTINUE");
 glutSwapBuffers(); 
 glFlush();
    
 } 
   void mouseClick(int button, int state, int x, int y) 
 { 
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
     { 
        if(viewScreen==IntroScreen) 
              viewScreen=ProjectScreen;                      
     }     
     glutPostRedisplay();       
 } 


void reshape(int w, int h)
{
SCREEN_WIDTH = w; 
SCREEN_HEIGHT = h; 
glViewport (0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective(50.0,(float)w/(float)h,1.0,20.0);
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}

void project_screen( )
{
glutReshapeFunc (reshape);
glutPostRedisplay();
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity ();
gluLookAt (2., 1., 4.,-1., 0., 0.,0., 1., 0.);

	/* Draw reflected scene first */
	glPushMatrix ();
	/* Mirrors lies in YZ plane, we can scale mirror in all three axes */
	glScalef (-1., 1., 1.);
	/* Mirror is 2.0 units from origin, so translate by 4.0 */
	glTranslatef (4, 0., 0.);
	//glTranslatef (-4, 0., 0.);
drawScene(GL_CW);
	glPopMatrix ();

	glPushMatrix ();
	/* Mirrors lies in YZ plane, we can scale mirror in all three axes */
	glScalef (-1.0, 1.0, 1.0);
	/* Mirror is 2.0 units from origin, so translate by 4.0 */
	glTranslatef (-1, 0., -4.);
drawScene(GL_CW);
	glPopMatrix ();
	/* draw mirror */
	glClear (GL_DEPTH_BUFFER_BIT);
	glPushAttrib (0xffffffff);
	glDisable (GL_LIGHTING);
	/* Create imperfect reflector effect by blending a black
	mirror over the reflected scene with alpha of 0.05 */
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(6);
	glColor3f(1.0,0.0,0.0);
	glBegin (GL_LINE_LOOP);
	glVertex3f (-2.,1.5, 2.2);
	glVertex3f (-2., -1.5, 2.5);
	glVertex3f (-2., -1.5, -2.5);
	glVertex3f (-2., 1.5, -2.5);
	glEnd ();
	glColor4f (0., 0., 0., 0.05);
	glBegin (GL_QUADS);
	glVertex3f (-2.,1.5, 2.2);
	glVertex3f (-2., -1.5, 2.5);
	glVertex3f (-2., -1.5, -2.5);
	glVertex3f (-2., 1.5, -2.5);
	glEnd();





    glColor3f(1.0,0.0,0.0);
	glBegin (GL_LINE_LOOP);
    glVertex3f (-1.,1.4, -1.5);
	glVertex3f (-1., -1.4, -1.5);
	glVertex3f (2.2, -1., -1.5);
	glVertex3f (2.1, 1.4, -1.5);
    glEnd();

    glColor4f (0., 0., 0., 0.05);
    glBegin(GL_QUADS);
    glVertex3f (-1.,1.4, -1.5);
	glVertex3f (-1., -1.4, -1.5);
	glVertex3f (2.2, -1., -1.5);
	glVertex3f (2.1, 1.4, -1.5);
	glEnd ();
	glPopAttrib();
	/* Draw the real scene */
drawScene(GL_CCW);
glutSwapBuffers();
}
 void display() 
 { 
    switch(viewScreen) 
    { 
       case IntroScreen: intro_screen(); 
                         break;                     
  
       
  
       case ProjectScreen: project_screen(); 
                               break;
    } 
 } 
void selectFont(int newfont)
{
font = fonts[newfont];
glutPostRedisplay();
}

void kb(unsigned char key, int x, int y)
{
	int nv=value,cv=val;
	if(key=='n' &&nv>=14 &&nv<=17)
		value++;
	if(key=='n' &&nv==17)
		value=14;
	if(key=='c' && cv>=3 && cv<=7)
		val++;
	if(key=='c' && cv==7)
		val=3;
	if(key=='i' && v<16)
		v++;
	if(key=='d' &&v>=1)
		v--;
}
static void timer (int value)
{
xrot +=v;
if (xrot> 360.f) xrot -= 360.f;
glutPostRedisplay ();
glutTimerFunc (TIMER, timer, 0);
}
static void init ()
{
int s1,s2,s3;
xrot = 1.;
glEnable (GL_DEPTH_TEST);
    {
GLfloat white[4] = {1., 1., 1., 1.};
GLfloat black[4] = {0., 0., 0., 0.};
        /* Set up light1 */
glEnable (GL_LIGHTING);
glEnable (GL_LIGHT1);
glLightfv (GL_LIGHT1, GL_DIFFUSE, white);
glLightfv (GL_LIGHT1, GL_SPECULAR, white);
        /* ambient and diffuse will track glColor */
glEnable (GL_COLOR_MATERIAL);
glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
glMaterialfv (GL_FRONT, GL_SPECULAR, white);
		glMaterialf (GL_FRONT, GL_SHININESS, 20.);
    }
	
	glutDisplayFunc (display);

glutTimerFunc (TIMER, timer, 0);
    s1=glutCreateMenu(pol);
glutAddMenuEntry("BENZ", 14);
glutAddMenuEntry("AUDI", 15);
	glutAddMenuEntry("HYUNDAI",16);
	glutAddMenuEntry("TOYOTA",17);
	s2= glutCreateMenu(col);
glutAddMenuEntry("red", 3);
glutAddMenuEntry("green", 4);
glutAddMenuEntry("Blue",5);
glutAddMenuEntry("white",6);
glutAddMenuEntry("yellow",7);
	s3=glutCreateMenu(selectFont);
glutAddMenuEntry("Roman",0);
glutAddMenuEntry("Mono Roman",1);
glutCreateMenu(main_menu);
	glutAddSubMenu("Object",s1);
	glutAddSubMenu("Colors",s2);
	glutAddSubMenu("texts",s3);
	glutAddMenuEntry("Quit", 0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char** argv)
{
glutInit (&argc,argv);
glutInitDisplayMode (GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
glutInitWindowPosition(0,0); 
glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
glutCreateWindow ("Different Car Logos");
	glutKeyboardFunc(kb);
init ();
glutMouseFunc(mouseClick);
glMatrixMode(GL_PROJECTION);
glOrtho(0,SCREEN_WIDTH,0,SCREEN_HEIGHT,0,1.0);
glutMainLoop ();
return 0;
}
