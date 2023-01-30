

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int width = 640;
int height = 480;

int r1x=200,r1y=200,r2x=300,r2y=300;

void init(){
    glClearColor(0,0,0,1);
    gluOrtho2D(0,width,0,height);
}

void drawLine(double x1,double y1,double x2,double y2,bool red=false){
    if (red)
        glColor3d(1,0,0);
    else
        glColor3d(0,1,1);

    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glFlush();
}
string findTBLR(int x,int y){
    string tblr="0000";
    if (x<r1x){
        tblr[2]='1';
    }
    else if (x>r2x){
        tblr[3]='1';
    }
    if (y<r1y){
        tblr[1]='1';
    }
    else if (y>r2y){
        tblr[0] = '1';
    }
    return tblr;
}

double* findXY(string tblr,double slope,int x,int y){
    double arr[2] = {x,y};

    if (tblr=="0000"){
         return arr;
    }
    if (tblr[0]=='1'){
        arr[1] = r2y;
        arr[0] = x + (r2y-y)/slope;
    }
    if (tblr[1]=='1'){
        arr[1] = r1y;
        arr[0] = x + (r1y-y)/slope;
    }
    if (tblr[2]=='1'){
        arr[0] = r1x;
        arr[1] = y - slope*(x-r1x);
    }
    if (tblr[3]=='1'){
        arr[0] = r2x;
        arr[1] = y - slope*(x-r2x);
    }
    return arr;
}

void lineClipping(int x1,int y1,int x2,int y2){
    string tblr1 = findTBLR(x1,y1);
    string tblr2 = findTBLR(x2,y2);
    double slope = (y2-y1)/(x2-x1);
    double* arr1 = findXY(tblr1,slope,x1,y1);
    drawLine(arr1[0],arr1[1],x2,y2,true);
    cout<<"done";

}

void mouse(int button,int state,int x,int y){
    y=height-y;
    static bool flag=false;
    static int x1=0,y1=0;
    if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        if (!flag){
            x1=x;
            y1=y;
        }
        else if (flag){
            drawLine(x1,y1,x,y);
            lineClipping(x1,y1,x,y);

        }
        flag=!flag;
    }
}





void drawRect(int x1,int y1,int x2,int y2){
    glColor3d(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(x1,y1);
        glVertex2d(x2,y1);
        glVertex2d(x2,y2);
        glVertex2d(x1,y2);
    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    drawRect(r1x,r1y,r2x,r2y);
    glFlush();
}

int main(int argc,char *argv[]){

    glutInit(&argc,argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("no funding");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}



