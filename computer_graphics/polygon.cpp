
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include<vector>
using namespace std;

float mouseX,mouseY;


void init(){

    glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);

}
void drawPoint(int x,int y){
    glBegin(GL_POINTS);
        glPointSize(10);
        glColor3d(0,0,0);
        glVertex2d(x,y);
    glEnd();
    glFlush();

}

void drawLine(int x1,int y1,int x2,int y2){
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
    glEnd();
    glFlush();

}

void drawPolygon(vector<vector<int>> points){
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_FAN);
        for (vector<int> point : points){
            glVertex2d(point[0],point[1]);
        }
    glEnd();
    glFlush();

}

static void mouse(int button, int state, int x, int y)
{
    static int p1x=0,p1y=0;
    static int p2x=0,p2y=0;
    static int count=0;
    static bool drawn=false;
    static vector<vector<int>> points;
    if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        drawPoint(x,480-y);
        vector<int> temp{x,480-y};
        points.push_back(temp);
    }
    if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        drawPolygon(points);
    }

	/*if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	    {

	        if (count==0){
                p1x=x;
                p1y=480-y;
	        }
	        if (count==1){
                p2x=x;
                p2y=480-y;
	        }
	        count++;

            if (!drawn && count>1){
                drawLine(p1x,p1y,p2x,p2y);
                p1x=p2x;
                p1y=p2y;
                count=1;
            }
            else if (drawn && count>1){
                drawLine(p1x,p1y,p2x,p2y);
            }

	    }*/
}




void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0,0 );
    glPointSize(10);
	glBegin(GL_POINTS);
        glVertex2f(mouseX, mouseY);
	glEnd();
	glFlush();

}






int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return EXIT_SUCCESS;
}
