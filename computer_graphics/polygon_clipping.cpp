#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point{
    public:
        int x;
        int y;
        Point():x(0),y(0){};
        Point(int x,int y):x(x),y(y){};
};

int width=640,height=480;
int xWmin = 200,xWmax=400,yWmin = 200,yWmax = 400;

void drawPoint(int x,int y,int r=1,int g=1,int b=1){
    glColor3d(r,g,b);
    glBegin(GL_POINTS);
        glVertex2d(x,y);
    glEnd();
    glFlush();
}

void drawRect(int x1,int y1,int x2,int y2){
    int width = x2-x1;
    int height = y2-y1;
    glColor3d(1,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2d(x1,y1);
        glVertex2d(x1+width,y1);
        glVertex2d(x1+width,y1+height);
        glVertex2d(x1,y1+height);
    glEnd();
    glFlush();
}

void drawPolygon(vector<Point> &points,int r=0,int g=1,int b=0,int type = GL_LINE_LOOP){
    glColor3d(r,g,b);
    glBegin(type);
        for (Point p : points)
            glVertex2d(p.x,p.y);
    glEnd();
    glFlush();
}



vector<Point> jaingBarsky(int x1, int y1, int x2, int y2, int Xwmin, int Ywmin, int Xwmax, int Ywmax) {
    int dx = x2 - x1, dy = y2 - y1, xn1, yn1, xn2, yn2;
    vector<int> p = {-dx, dx, -dy, dy};
    vector<int> q = {x1 - Xwmin, Xwmax - x1, y1 - Ywmin, Ywmax - y1};
    vector<float> r = {0.0, 0, 1, 1};
    vector<Point> ans;
    float t1 = 0, t2 = 1;
    for(int i = 0; i < 4; i++) {
        if(p[i] == 0 && q[i] < 0) {
            //drawLine(x1, y1, x2, y2, 1);
            return ans;
        }
        r[i] = 1.0 * q[i] / p[i];
        if(p[i] < 0) t1 = max(t1, r[i]);
        if(p[i] > 0) t2 = min(t2, r[i]);
    }
    if(t1 > t2) {
        //drawLine(x1, y1, x2, y2, 1);
        return ans;
    }
    xn1 = x1 + dx * t1;
    yn1 = y1 + dy * t1;
    xn2 = x1 + dx * t2;
    yn2 = y1 + dy * t2;
    //drawLine(x1, y1, xn1, yn1, 1);
    //drawLine(xn1, yn1, xn2, yn2, 1, 1, 0, 0);
    ans.push_back(Point(xn1,yn1));
    ans.push_back(Point(xn2,yn2));
    return ans;
    //drawLine(xn2, yn2, x2, y2, 1);
}

void clipPolygon(vector<Point> &points){
    int n = points.size();
    vector<Point> ans ;
    for (int i = 0;i<n-1;i++){
        Point cp = points[i],np = points[i+1];
        vector<Point> temp = jaingBarsky(cp.x,cp.y,np.x,np.y,xWmin,yWmin,xWmax,yWmax);
        for (Point p : temp){
            ans.push_back(p);
        }
    }
    drawPolygon(ans,0,1,1,GL_POLYGON);
}

void init(){
    glClearColor(0,0,0,1);
    gluOrtho2D(0,width,0,height);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    drawRect(xWmin,yWmin,xWmax,yWmax);
    glFlush();
}

void mouse(int button,int state,int x,int y){
    y = height - y;
    static vector<Point> points;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        points.push_back(Point(x,y));
        drawPoint(x,y);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        drawPolygon(points);
        clipPolygon(points);
    }
}

int main(int argc,char *argv[]){
    cout<<GL_LINE_LOOP;
    glutInit(&argc,argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("no funding");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}
