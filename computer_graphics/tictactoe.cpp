#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
int width=640,height=480;

using namespace std;

void init(){
    glClearColor(0,0,0,1);
    gluOrtho2D(0,width,0,height);
}

void drawLine(int x1,int y1,int x2,int y2,int r=0,int g=1,int b=1){
    glColor3d(r,g,b);
    glBegin(GL_LINES);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
    glEnd();
    glFlush();
}

void drawPoint(int x,int y,int r=0,int g=1,int b=0){
    glColor3d(r,g,b);
    glBegin(GL_POINTS);
        glVertex2d(x,y);
    glEnd();
    glFlush();
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



static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    drawLine(0,height/3,width,height/3,1,0,0);
    drawLine(0,2*height/3,width,2*height/3,1,0,0);
    drawLine(width/3,0,width/3,height,1,0,0);
    drawLine(2*width/3,0,2*width/3,height,1,0,0);
    glFlush();
}

void returnRegionCenter(int &x,int &y){
    //region 7
    if (x>0 && x<width/3 && y>0 && y<height/3){
        x=width/6;
        y=height/6;
    }
    //region 4
    else if (x>0 && x<width/3 && y>height/3 && y<2*height/3){
        x=width/6;
        y=height/2;
    }
    //region 1
    else if (x>0 && x<width/3 && y>2*height/3 && y<height){
        x=width/6;
        y=5*height/6;
    }
    //region 8
    else if (x>width/3 && x<2*width/3 && y>0 && y<height/3){
        x=width/2;
        y=height/6;
    }
    //region 5
    else if (x>width/3 && x<2*width/3 && y>height/3 && y<2*height/3){
        x=width/2;
        y=height/2;
    }
    //region 2
    else if (x>width/3 && x<2*width/3 && y>2*height/3 && y<height){
        x=width/2;
        y=5*height/6;
    }
    //region 9
    else if (x>2*width/3 && x<width && y>0 && y<height/3){
        x = 5*width/6;
        y = height/6;
    }
    //region 6
    else if (x>2*width/3 && x<width && y>height/3 && y<2*height/3){
        x = 5*width/6;
        y = height/2;
    }
    //region 3
    else if (x>2*width/3 && x<width && y>2*height/3 && y<height){
        x = 5*width/6;
        y = 5*height/6;
    }


}

void drawX(int x,int y){
    int xShift = width/12;
    int yShift = height/12;
    glColor3d(0,1,1);
    glBegin(GL_LINES);
        glVertex2d(x-xShift,y+yShift);
        glVertex2d(x+xShift,y-yShift);
        glVertex2d(x-xShift,y-yShift);
        glVertex2d(x+xShift,y+yShift);
    glEnd();
    glFlush();
}

void mouse(int button,int state,int x,int y){
    y=height-y;
    static bool p1Turn=true;
    if (button==GLUT_LEFT_BUTTON and state==GLUT_DOWN){
        returnRegionCenter(x,y);
        if (p1Turn){
            drawX(x,y);
        }
        else{
            drawCircle(x,y,width/12);
        }
        p1Turn=!p1Turn;




    }
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
