#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
GLfloat ex = 0.0, ey = -4.0, ez = -3.0;
void init()
{
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glFrustum(-4.0, 4.0, -4.0, 4.0, 1.0, 10.0);
        //glOrtho(-4.0, 4.0, -4.0,  4.0, 1.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(ex, ey, ez,  0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
GLfloat vertices[9][3]={
    {-1.0, -1.0, 1.0},     {-1.0, 1.0, 1.0},    {1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0},    {-1.0, -1.0, -1.0},     {-1.0, 1.0, -1.0},
    {1.0, 1.0, -1.0},    {1.0, -1.0, -1.0}
};

GLfloat vertices2[6][3]={
    {0.0, 4.0, 0.0},{-2.0,0.0,-2.0},{2.0,0.0,-2.0},{2.0,0.0,2.0},{-2.0,0.0,2.0},{0.0, -4.0, 0.0}
};

GLfloat colors[8][3]={
    {1.0, 0.0, 0.0},{1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},{0.0, 1.0, 1.0},
    {1.0, 0.0, 1.0},{1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},{0.0, 1.0, 1.0}
};

void quad(int a, int b, int c, int d) {
    glBegin(GL_QUADS);
        glVertex3fv(vertices2[a]);
        glVertex3fv(vertices2[b]);
        glVertex3fv(vertices2[c]);
        glVertex3fv(vertices2[d]);
    glEnd();
}

void tri(int a,int b,int c) {
    glBegin(GL_TRIANGLES);
        glVertex3fv(vertices2[a]);
        glVertex3fv(vertices2[b]);
        glVertex3fv(vertices2[c]);
    glEnd();
}

void drawPyramid() {
    glColor3f(1.0,0.0,0.0);
    glColor3fv(colors[1]);     tri(0,1,2);
    glColor3fv(colors[2]);     tri(0,2,3);
    glColor3fv(colors[1]);     tri(0,3,4);
    glColor3fv(colors[2]);     tri(0,1,4);
    glColor3fv(colors[2]);     tri(5,1,2);
    glColor3fv(colors[1]);     tri(5,2,3);
    glColor3fv(colors[2]);     tri(5,3,4);
    glColor3fv(colors[1]);     tri(5,1,4);
}

void resize(int width, int height) {
    double aspect;
    glViewport(0, 0, width, height);
    aspect = (double) width / (double) height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (aspect < 1.0)
    {
        glOrtho(-4., 4., -4./aspect, 4./aspect, 1., 100.);
    }
    else
    {
        glOrtho(-4.*aspect, 4.*aspect, -4., 4., 1., 100.);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 5., 0., 0., 0., 0., 1., 0.);

}

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPyramid();
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':

            ez += 1.0;
            break;

        case '-':

            ez -= 1.0;
            break;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ex, ey, ez,  0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutPostRedisplay();

}


static void arrowKey(int key, int x, int y)
{

    switch(key)
    {
        case GLUT_KEY_LEFT:

            ex -= 1.0;
            break;

        case GLUT_KEY_RIGHT:

            ex += 1.0;
            break;

        case GLUT_KEY_UP:

            ey -= 1.0;
            break;

       case GLUT_KEY_DOWN:

            ey += 1.0;
            break;

    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ex, ey, ez,  0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D Projection");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(arrowKey);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
