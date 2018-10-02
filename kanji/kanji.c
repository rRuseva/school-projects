// Радина Росенова Русева, №80853, 6 група


#include <stdlib.h>
#include <math.h>
#include <GL/glfw.h>
#include <math.h>
#include <stdbool.h>


void drawSolidRotatedParallelipiped (float x, float y, float z, float a, float b, float c, float k)
{
    a = a/2;
    b = b/2;
    c = c/2;
    //Рисуване на стена откъм -X
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x-a+k, y+b, z+c+k); //B1
        glVertex3f(x-a+k, y+b, z-c+k); //B
        glColor3f(0,1,1);
        glVertex3f(x-a+k, y-b, z-c+k); //C
        glVertex3f(x-a+k, y-b, z+c+k); // C1


    glEnd();
     // Рисуване на стена откъм +X
    glBegin( GL_POLYGON );
        glNormal3f(+1.0, 0.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x+a-k, y+b, z-c-k); //A
        glVertex3f(x+a-k, y+b, z+c-k); //A1
        glColor3f(0,1,1);
        glVertex3f(x+a-k, y-b, z+c-k); //D1
        glVertex3f(x+a-k, y-b, z-c-k); //D


    glEnd();

    // Рисуване на стена откъм -Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, -1.0, 0.0);
        glColor3f(0, 1, 1);
        glVertex3f(x-a+k, y-b, z-c+k); //C
        glVertex3f(x-a+k, y-b, z+c+k); // C1
        glVertex3f(x+a-k, y-b, z+c-k); //D1
        glVertex3f(x+a-k, y-b, z-c-k); //D
    glEnd();
    glColor3f(0,0, 1);
    // Рисуване на стена откъм +Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, +1.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x-a+k, y+b, z-c+k);//B
        glVertex3f(x-a+k, y+b, z+c+k); //B1
        glVertex3f(x+a-k, y+b, z+c-k); //A1
        glVertex3f(x+a-k, y+b, z-c-k); //A
    glEnd();

    // Рисуване на стена откъм -Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glColor3f(0,1,1);
        glVertex3f(x+a-k, y-b, z-c-k); //D
        glVertex3f(x-a+k, y-b, z-c+k); //C
        glColor3f(0,0,1);
        glVertex3f(x-a+k, y+b, z-c+k);//B
        glVertex3f(x+a-k, y+b, z-c-k); //A

    glEnd();

    // Рисуване на стена откъм +Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, +1.0);
        glColor3f(0,1,1);
        glVertex3f(x+a-k, y-b, z+c-k); //D1
        glVertex3f(x-a+k, y-b, z+c+k); // C1
        glColor3f(0,0,1);
        glVertex3f(x-a+k, y+b, z+c+k); //B1
        glVertex3f(x+a-k, y+b, z+c-k); //A1

    glEnd();
}

void drawSolidParallelipiped (float x, float y, float z, float a, float b, float c)
{
    a = a/2;
    b = b/2;
    c = c/2;
 // Рисуване на стена откъм -X
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z+c); //B1
        glVertex3f(x-a, y+b, z-c); //B
        glColor3f(0,1,1);
        glVertex3f(x-a, y-b, z-c); //C
        glVertex3f(x-a, y-b, z+c); //C1


    glEnd();
     // Рисуване на стена откъм +X
    glBegin( GL_POLYGON );
        glNormal3f(+1.0, 0.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x+a, y+b, z+c); //A
        glVertex3f(x+a, y+b, z-c); //A1
        glColor3f(0,1,1);
        glVertex3f(x+a, y-b, z-c); //D1
        glVertex3f(x+a, y-b, z+c); //D

    glEnd();

    // Рисуване на стена откъм -Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, -1.0, 0.0);
        glColor3f(0,1,1);
        glVertex3f(x-a, y-b, z-c); //C
        glVertex3f(x-a, y-b, z+c); //C1
        glVertex3f(x+a, y-b, z+c); //D1
        glVertex3f(x+a, y-b, z-c); //D
    glEnd();

    // Рисуване на стена откъм +Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, +1.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z-c);
        glVertex3f(x-a, y+b, z+c);
        glVertex3f(x+a, y+b, z+c);
        glVertex3f(x+a, y+b, z-c);
    glEnd();

    // Рисуване на стена откъм -Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glColor3f(0,1,1);
        glVertex3f(x+a, y-b, z-c); //D
        glVertex3f(x-a, y-b, z-c); //C
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z-c); //B
        glVertex3f(x+a, y+b, z-c); //A

    glEnd();

    // Рисуване на стена откъм +Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, +1.0);
        glColor3f(0,1,1);
        glVertex3f(x+a, y-b, z+c);//D1
        glVertex3f(x-a, y-b, z+c);//C1
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z+c); //B1
        glVertex3f(x+a, y+b, z+c); //A1
    glEnd();
}

void drawSolidPrizma (float x, float y, float z, float a, float b, float c)
{
    a = a/2;
    b = b/2;
    c = c/2;
    //Рисуване на стена откъм -X
    glBegin( GL_POLYGON );
        glNormal3f(-1.0, 0.0, +1.0);
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z-c); //B
        glVertex3f(x+a, y+b, z+c); //A1
        glColor3f(0,1,1);
        glVertex3f(x+a, y-b, z+c); //D1
        glVertex3f(x-a, y-b, z-c); //C

    glEnd();
     // Рисуване на стена откъм +X
    glBegin( GL_POLYGON );
        glNormal3f(+1.0, 0.0, 1.0);
        glColor3f(0,0,1);
        glVertex3f(x+a, y+b, z-c); //A
        glVertex3f(x+a, y+b, z+c); //A1
        glColor3f(0,1,1);
        glVertex3f(x+a, y-b, z+c); //D1
        glVertex3f(x+a, y-b, z-c); //D

    glEnd();

    // Рисуване на стена откъм -Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, -1.0, 0.0);
        glColor3f(0,1,1);
        glVertex3f(x-a, y-b, z-c); //C
        glVertex3f(x+a, y-b, z+c); //D1
        glVertex3f(x+a, y-b, z-c); //D
    glEnd();

    // Рисуване на стена откъм +Y
    glBegin( GL_POLYGON );
        glNormal3f(0.0, +1.0, 0.0);
        glColor3f(0,0,1);
        glVertex3f(x-a, y+b, z-c);//B
        glVertex3f(x+a, y+b, z+c); //A1
        glVertex3f(x+a, y+b, z-c); //A
    glEnd();

    // Рисуване на стена откъм -Z
    glBegin( GL_POLYGON );
        glNormal3f(0.0, 0.0, -1.0);
        glColor3f(0,0,1);
        glVertex3f(x+a, y+b, z-c); //A
        glVertex3f(x-a, y+b, z-c);//B
        glColor3f(0,1,1);
        glVertex3f(x-a, y-b, z-c); //C
        glVertex3f(x+a, y-b, z-c); //D

    glEnd();

}
void drawSolidCylinder1 ( float x, float y, float z, float r, float h )
{
    int n = 32;
    h=h/2;
    float alpha = (-1)*M_PI/2;
    float dalpha = (-2)*M_PI/n;

    int i = 0;
    for( i=0; i<n/4; i++)
    {
        float dx1 = r*cos(alpha);
        float dy1 = r*sin(alpha);

        float dx2 = r*cos(alpha+dalpha);
        float dy2 = r*sin(alpha+dalpha);

        // Рисуване на околна стена
        glBegin( GL_POLYGON );
            glNormal3f( cos(alpha+dalpha/2), 0, sin(alpha+dalpha/2) );
            glColor3f(0,1,1);
            glVertex3f( x+dx1, y, z+dy1 );
            glVertex3f( x+dx2, y, z+dy2 );
            glColor3f(0,0,1);
            glVertex3f( x+dx2, y+h, z+dy2 );
            glVertex3f( x+dx1, y+h, z+dy1 );
        glEnd();

        // Рисуване на парче от долната основа
        glBegin( GL_POLYGON );
            glNormal3f( 0, -1, 0 );
            glColor3f(0,1,1);
            glVertex3f( x,     y,     z );
            glVertex3f( x+dx1, y, z+dy1 );
            glVertex3f( x+dx2, y, z+dy2 );
        glEnd();

        // Рисуване на парче от горната основа
        glBegin( GL_POLYGON );
            glNormal3f( 0, 1, 0 );
            glColor3f(0,0,1);
            glVertex3f( x,     y+h,     z );
            glVertex3f( x+dx1, y+h, z+dy1 );
            glVertex3f( x+dx2, y+h, z+dy2 );
        glEnd();

        alpha += dalpha;
    }
}

void drawSolidArc(float x, float y, float z, float r1, float h, float start, float k, int s)
{
    int n = 72;
    float r2 = r1-0.2;
    float alpha = start;
    float dalpha = s*2*M_PI/n;
    float a = 1.5;

    int i=0;
    for( i=0; i<n/k; i++)
    {
        float bx1 = r1*cos(alpha);
        float by1 = r1*sin(alpha);

        float bx2 = r1*cos(alpha-dalpha);
        float by2 = r1*sin(alpha-dalpha);

        float sx1 = r2*cos(alpha);
        float sy1 = r2*sin(alpha);

        float sx2 = r2*cos(alpha-dalpha);
        float sy2 = r2*sin(alpha-dalpha);

        // Рисуване на външна околна стена
        glBegin( GL_POLYGON );
            glNormal3f( cos(alpha+dalpha/2), 0, sin(alpha+dalpha/2) );
            glColor3f(0,1,1);
            glVertex3f( x+bx1, y, z+by1*a );
            glVertex3f( x+bx2, y, z+by2*a );
            glColor3f(0,0,1);
            glVertex3f( x+bx2, y+h, z+by2*a );
            glVertex3f( x+bx1, y+h, z+by1*a );
        glEnd();

        // Рисуване на вътрешна околна стена
        glBegin( GL_POLYGON );
            glNormal3f( sin(alpha+dalpha/2), 0, cos(alpha+dalpha/2) );
            glColor3f(0,1,1);
            glVertex3f( x+sx1, y, z+sy1*a );
            glVertex3f( x+sx2, y, z+sy2*a );
            glColor3f(0,0,1);
            glVertex3f( x+sx2, y+h, z+sy2*a );
            glVertex3f( x+sx1, y+h, z+sy1*a );
        glEnd();

        //стени на сечението
        glBegin( GL_POLYGON );
            glNormal3f( cos(alpha+dalpha/2), 0, sin(alpha+dalpha/2) );
            glColor3f(0,1,1);
            glVertex3f( x+sx2, y, z+sy2*a );
            glVertex3f( x+bx2, y, z+by2*a );
            glColor3f(0,0,1);
            glVertex3f( x+bx2, y+h, z+by2*a );
            glVertex3f( x+sx2, y+h, z+sy2*a );

        glEnd();
        glBegin( GL_POLYGON );
            glNormal3f( cos(alpha+dalpha/2), 0, sin(alpha+dalpha/2) );
            glColor3f(0,1,1);
            glVertex3f( x+sx1, y, z+sy1*a );
            glVertex3f( x+bx1, y, z+by1*a );
            glColor3f(0,0,1);
            glVertex3f( x+bx1, y+h, z+by1*a );
            glVertex3f( x+sx1, y+h, z+sy1*a );

        glEnd();

        // Рисуване на парче от долната основа
        glBegin( GL_POLYGON );
            glNormal3f( 0, -1, 0 );
            glColor3f(0,1,1);
            glVertex3f( x+sx1, y, z+sy1*a );
            glVertex3f( x+bx1, y, z+by1*a );
            glVertex3f( x+bx2, y, z+by2*a );
            glVertex3f( x+sx2, y, z+sy2*a );
        glEnd();

        // Рисуване на парче от горната основа
        glBegin( GL_POLYGON );
            glNormal3f( 0, 1, 0 );
            glColor3f(0,0,1);
            glVertex3f( x+sx1, y+h, z+sy1*a );
            glVertex3f( x+bx1, y+h, z+by1*a );
            glVertex3f( x+bx2, y+h, z+by2*a );
            glVertex3f( x+sx2, y+h, z+sy2*a );
        glEnd();

        alpha += dalpha;
    }
}

bool running()
{
    return( !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED) );
}

void init()
{
    int width, height;

    glfwInit();
    if( !glfwOpenWindow( 640, 480, 0, 0, 0, 0, 8, 0, GLFW_WINDOW ) ) return;

    glfwGetWindowSize( &width, &height );
    height = height > 0 ? height : 1;

    glViewport( 0, 0, width, height );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(0.0f, 8.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f );
}

void finit()
{
    glfwTerminate();
}

int main()
{
    init();

    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_LIGHT0 );

    while( running() )
    {
        glClear( GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT );
        glRotatef( 0.04, 0.4, -0.2, 0.7);

        float b = 5;

        //big horizontal line
        drawSolidParallelipiped(-0.5,0,0,3.5,b, 0.25);
        //двата спускащи се стълба от хоризонталната линия
        drawSolidParallelipiped(+0.9,0,-0.8,0.3,b, 1.5);
        drawSolidParallelipiped(+0.2,0,-1,0.3,b, 1.8);
        //двете линии свързващи вертикалните стълбове
        drawSolidParallelipiped(+0.5,0,-0.6,0.5,b, 0.15);
        drawSolidParallelipiped(+0.5,0,-1.07,0.5,b, 0.15);
        //наклонена свързваща
        drawSolidRotatedParallelipiped(+0.7, 0, -1.5, 1.5, b, 0.15, 0.15);
        drawSolidRotatedParallelipiped(1.25, 0, -1.7, 0.1, b, 0.15, 0.015);

        //втора хоризонтална линия
        drawSolidParallelipiped(-0.95, 0, -0.57, 2.1, b, 0.25);
        //ъгълче
        drawSolidPrizma(-2.1, 0, -0.55, 0.25, b, 0.30);
        // полу дъга
        drawSolidArc(-0.6, -b/2, 0.35, 1.5, b, (7)*M_PI/6, 5, 1);
        drawSolidArc(-1.8, -b/2, 0.35, 1.5, b, (-1)*M_PI/6, 5, -1);

        //голяма вертикална линия
        drawSolidParallelipiped(1.85, 0, 0,0.3,b, 3.75);
        drawSolidParallelipiped(1.8, 0, 1.875 ,0.4, b, 0.1);
        //заобляне
        drawSolidCylinder1(2,-b/2, -1.78, 0.3, 2*b);
        //ченгелче
        drawSolidParallelipiped(2.15,0, -1.93,0.3, b, 0.3);

        //хоризонтална пресичаща линия
        drawSolidParallelipiped(1.85,0,0.78,1.3,b, 0.3);
        //наклонена пресичаща линия
        drawSolidRotatedParallelipiped(1.85,0,-0.57,1.3,b, 0.3, 0.15);
        drawSolidParallelipiped(2.3,0,-0.8, 0.1, b, 0.25);

        //прозорче
        drawSolidParallelipiped(-0.57, 0, 1.91, 2.84, b, 0.15); //горна страна
        drawSolidParallelipiped(0.7, 0, 1.31, 0.3, b, 1.06);    //лява
        drawSolidParallelipiped(-0.57, 0, 0.73, 2.84, b, 0.15); //долна
        drawSolidRotatedParallelipiped(-1.85, 0, 1.31, 0.3, b, 1.06,0);    //дясна
        drawSolidParallelipiped(-0.57, 0, 1.27, 2.84, b, 0.15); //средна

        glfwSwapBuffers();
    }

    finit();
    return 0;
}


