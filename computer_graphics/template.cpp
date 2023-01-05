#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int width=640,height=480;

void init(){
    glClearColor(0,0,0,1);
    gluOrtho2D(0,width,0,height);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    glFlush();
}

int main(int argc,char *argv[]){

    glutInit(&argc,argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("no funding");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
