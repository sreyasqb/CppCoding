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

void drawPoint(int x,int y,bool point=false,bool red=false){
    glPointSize(2);
    if (point)
        glColor3d(1,1,1);
    else
        glColor3d(0,1,1);
    if (red){
        glColor3d(1,0,0);
    }

    glBegin(GL_POINTS);
        glVertex2d(x,y);
    glEnd();
    glFlush();
}

void generalBresenham(int x1,int y1,int x2,int y2){

    int x=x1;
    int y=y1;
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int s1= x2-x1>0 ? 1: x2-x1 == 0 ? 0 : -1;
    int s2= y2-y1>0 ? 1: y2-y1 == 0 ? 0 : -1;

    bool interchange;
    if (dy>dx){
        int temp=dx;
        dx=dy;
        dy=temp;
        interchange=true;
    }
    else{
        interchange=false;
    }
    int p = 2*dy - dx,a = 2*dy ,b = 2*dy - 2*dx;
    drawPoint(x,y);
    for (int i=1;i<dx;i++){
        if (p<0){
            if (interchange){
                y+=s2;

            }else{
                x+=s1;
            }
            p+=a;
        }
        else{
            y+=s2;
            x+=s1;
            p+=b;
        }
        drawPoint(x,y);
    }

}



void drawCircleOctants(int x,int y,int xShift,int yShift){
    //transformOrigin(y,x);

    drawPoint(x,y);
    int X=x-xShift;
    int Y=y-yShift;
    drawPoint(Y+xShift,X+yShift);
    drawPoint(-X+xShift,Y+yShift);
    drawPoint(-Y+xShift,X+yShift);
    drawPoint(-Y+xShift,-X+yShift);
    drawPoint(-X+xShift,-Y+yShift);
    drawPoint(X+xShift,-Y+yShift);
    drawPoint(Y+xShift,-X+yShift);
}

void drawCircle(int x,int y,int r){
    int p=1-r;
    int xShift=x,yShift=y;
    drawPoint(x,y+r);
    int x1=0,y1=0;
    y1=y1+r;
    while (x1<y1){
        if (p<0){
            x1++;
            p+=2*x1+1;
        }
        else{
            x1++;
            y1--;
            p+=2*x1-2*y1+1;
        }
        //cout<<x1<<","<<y1<<endl;
        drawCircleOctants(x+x1,y+y1,x,y);
    }
}

void dda(int x1,int y1,int x2,int y2){
    int dy=y2-y1,dx=x2-x1,steps;
    if (dy>dx){
        steps=dy;
    }
    else{
        steps=dx;
    }
    float xinc=dx/steps,yinc=dy/steps;
    for (int i=0;i<steps;i++){
        x1+=xinc;
        y1+=yinc;
        drawPoint(round(x1),round(y1));
    }
}

void mouseCircle(int button,int state,int x,int y){
    y=height-y;
    static int x1=0,y1=0;
    static bool plot=false;
    if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        drawPoint(x,y,false,true);
        plot=!plot;
        if (plot){
            x1=x;
            y1=y;
        }
        if (!plot){
            int radius=round(sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)));
            cout<<radius;
            drawCircle(x1,y1,radius);
        }
    }
}

void mouse(int button,int state,int x,int y){
    y=height-y;
    static int x1=0,y1=0;
    static bool p1=false;
    if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        drawPoint(x,y,true);
        p1=!p1;
        if (p1){
            x1=x;
            y1=y;
            cout<<x<<y;
        }
        if (!p1){
            generalBresenham(x1,y1,x,y);
            //dda(x1,y1,x,y);

        }
    }
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    generalBresenham(width/2,0,width/2,height);
    generalBresenham(0,height/2,width,height/2);
    //drawCircle(width/2,height/2,100);
    //drawPoint(width/2,height/2,false,true);
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
    //glutMouseFunc(mouse);
    glutMouseFunc(mouseCircle);
    glutMainLoop();
    return EXIT_SUCCESS;
}


