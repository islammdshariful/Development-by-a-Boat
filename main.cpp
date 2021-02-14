#include<iostream>
using namespace std;
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.141659265358979323846
#include<math.h>
#include<windows.h>
#include<mmsystem.h>



int BoatPositionHouse1 = 0;
int BoatPositionHouse2 = 0;
int HouseWindow = 0;

int BoatPositionSchool1 = 0;
int BoatPositionSchool2 = 0;
int SchoolWindow = 0;

int BoatPositionHospital1 = 0;
int BoatPositionHospital2 = 0;
int HospitalWindow = 0;

GLfloat CloudPositionX = 0.0f;
GLfloat CloudSpeed = 0.003f;
GLboolean StopCloud = false;
int KeyC = 1;
void MoveCloud(int value)
{
    if(StopCloud == false)
    {
        if(CloudPositionX > 1.0f)
        {
            CloudPositionX = -1.6f;
        }
        else
        {
            CloudPositionX += CloudSpeed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveCloud, 0);
    }
}

GLfloat Cloud2PositionX = 0.0f;
GLfloat Cloud2Speed = 0.0033f;
GLboolean StopCloud2 = false;
int KeyX = 1;

GLfloat BoatPositionX = 0.0f;
GLfloat BoatSpeed = 0.003f;
GLboolean StopBoat = false;
int KeyB = 1;

void MoveBoat(int value)
{
    if(StopBoat == false)
    {
        if(BoatPositionX > 2.0f)
        {
            BoatPositionX = -0.5f;
            BoatPositionHouse1 =0;
            BoatPositionHouse2 =0;
            HouseWindow =0;
            BoatPositionSchool1 =0;
            BoatPositionSchool2 =0;
            SchoolWindow =0;
            BoatPositionHospital1 =0;
            BoatPositionHospital2 =0;
            HospitalWindow =0;
        }

        if(BoatPositionX > 0.1)
        {
            BoatPositionHouse1 =1;
        }
        if(BoatPositionX > 0.2)
        {
            BoatPositionHouse2 =1;
        }
        if(BoatPositionX > 0.3)
        {
            HouseWindow =1;
        }
        if(BoatPositionX > 0.5)
        {
            BoatPositionSchool1 =1;
        }
        if(BoatPositionX > 0.7)
        {
            BoatPositionSchool2 =1;
        }
        if(BoatPositionX > 0.8)
        {
            SchoolWindow =1;
        }
        if(BoatPositionX > 1.1)
        {
            BoatPositionHospital1 =1;
        }
        if(BoatPositionX > 1.2)
        {
            BoatPositionHospital2 =1;
        }
        if(BoatPositionX > 1.3)
        {
            HospitalWindow =1;
        }
        BoatPositionX += BoatSpeed;
        glutPostRedisplay();
        glutTimerFunc(27, MoveBoat, 0);
    }
}

void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void DrawCircle1(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 10; i <= triangleAmount;i++)
        {
            glVertex2f(
                       x - (radius * cos(i *  twicePi / triangleAmount)),
                       y - (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void DrawCircle2(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount/2;i++)
        {
            glVertex2f(
                       x + (radius * cos(i *  twicePi / triangleAmount)),
                       y - (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void sun()
{
    GLfloat x=0.3f; GLfloat y=0.9f; GLfloat radius =0.06f;
	int triangleAmount = 20;
    glColor3ub(255, 204, 0);
    DrawCircle(x,y,radius,triangleAmount);
}

void cloud()
{
	GLfloat x = 0.45f; GLfloat y = 0.83f; GLfloat radius = 0.05f;
	GLfloat x1 = 0.5f; GLfloat y1 = 0.8f;
	GLfloat x2 = 0.4f; GLfloat y2 = 0.8f;
	GLfloat x3 = 0.47f; GLfloat y3 = 0.77f;
	GLfloat x4 = 0.55f; GLfloat y4 = 0.79f;
	int triangleAmount = 20;

    glColor3ub(255, 255, 255);
    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}

void river()
{
    glBegin(GL_QUADS);
    glColor3ub(38, 154, 214);
    glVertex2f(-1.0f, -0.4000f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f,-0.4000f);
    glEnd();
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(140, 200, 255 );
	glVertex2f(-1.0f, -0.1000f);
	glVertex2f(1.0f, -0.1000f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void tree1(GLfloat vx)
{
    glBegin(GL_QUADS);
    glColor3ub(80, 2, 0);
    glVertex2f((-0.91f + vx), 0.1f);
    glVertex2f((-0.91f + vx), -0.1000f);
    glVertex2f((-0.92f + vx), -0.1000f);
    glVertex2f((-0.92f + vx), 0.1f);
    glEnd();

    GLfloat x = (-0.915f + vx); GLfloat y = 0.11f; GLfloat radius = 0.03f;
	int triangleAmount = 20;
    glColor3ub(14, 129, 0);
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.885f + vx); y = 0.14f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.915f + vx); y = 0.17f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.945f + vx); y = 0.14f;
    DrawCircle(x,y,radius,triangleAmount);
}

void Tree()
{
    tree1(0.1f);
    tree1(0.3f);
    tree1(0.6f);
    tree1(0.8f);
    tree1(0.001f);
    tree1(1.36f);
    tree1(1.70f);
    tree1(1.80f);
    tree1(1.20f);
    tree1(1.90f);

}

void oldhouse()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(149, 161, 0);
    glVertex2f(-0.55f, 0.1f);
	glVertex2f(-0.55f, -0.1000f);
	glVertex2f(-0.35, -0.1000f);
    glVertex2f(-0.35f,0.1f);
    glEnd();
    glBegin(GL_TRIANGLES);
    //upper
    glColor3ub(202, 202, 202);
    glVertex2f(-0.55f, 0.1f);
    glVertex2f(-0.35, 0.1f);
	glVertex2f(-0.45f, 0.3f);
    glEnd();
    glBegin(GL_QUADS);
    //door
    glColor3ub(170, 77, 0);
    glVertex2f(-0.5f, 0.05f);
	glVertex2f(-0.5f, -0.1000f);
	glVertex2f(-0.45, -0.1000f);
    glVertex2f(-0.45f,0.05f);
    glEnd();
    glBegin(GL_LINES);
    //door line
    glColor3ub(20, 21, 17);
    glVertex2f(-0.475f, 0.049f);
	glVertex2f(-0.475f, -0.1000f);
    glEnd();
    glBegin(GL_QUADS);
    //window
    glColor3ub(170, 77, 0);
    glVertex2f(-0.4f, 0.03f);
	glVertex2f(-0.4f, -0.02f);
	glVertex2f(-0.37f, -0.02f);
    glVertex2f(-0.37f,0.03f);
    glEnd();
    glBegin(GL_LINES);
    //window line
    glColor3ub(20, 21, 17);
    glVertex2f(-0.385f, 0.027f);
	glVertex2f(-0.385f, -0.017f);
    glEnd();
}

void newhouse2()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(218, 247, 166);
    glVertex2f(-0.55f, 0.5f);
	glVertex2f(-0.55f, -0.1000f);
	glVertex2f(-0.35, -0.1000f);
    glVertex2f(-0.35f,0.5f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(86, 101, 115);
    glVertex2f(-0.53f, 0.03f);
	glVertex2f(-0.53f, -0.1000f);
	glVertex2f(-0.37, -0.1000f);
    glVertex2f(-0.37f,0.03f);
    glEnd();
}

void houseWindow()
{
    glBegin(GL_QUADS);
    //window 3
    glColor3ub(93, 173, 226);
    glVertex2f(-0.4f, 0.15f);
	glVertex2f(-0.4f, 0.1f);
	glVertex2f(-0.37f,0.1f);
    glVertex2f(-0.37f,0.15f);
    glEnd();
    glBegin(GL_QUADS);
    //window 4
    glVertex2f(-0.47f, 0.15f);
	glVertex2f(-0.47f, 0.1f);
	glVertex2f(-0.44f, 0.1f);
    glVertex2f(-0.44f,0.15f);
    glEnd();
    glBegin(GL_QUADS);
    //window 5
    glVertex2f(-0.53f, 0.15f);
	glVertex2f(-0.53f, 0.1f);
	glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.5f,0.15f);
    glEnd();

    glBegin(GL_QUADS);
    //window 6
    glVertex2f(-0.4f, 0.27f);
	glVertex2f(-0.4f, 0.22f);
	glVertex2f(-0.37f,0.22f);
    glVertex2f(-0.37f,0.27f);
    glEnd();
    glBegin(GL_QUADS);
    //window 7
    glVertex2f(-0.47f, 0.27f);
	glVertex2f(-0.47f, 0.22f);
	glVertex2f(-0.44f, 0.22f);
    glVertex2f(-0.44f,0.27f);
    glEnd();
    glBegin(GL_QUADS);
    //window 8
    glVertex2f(-0.53f, 0.27f);
	glVertex2f(-0.53f, 0.22f);
	glVertex2f(-0.5f, 0.22f);
    glVertex2f(-0.5f,0.27f);
    glEnd();
    glBegin(GL_QUADS);
    //window 9
    glVertex2f(-0.4f, 0.39f);
	glVertex2f(-0.4f, 0.34f);
	glVertex2f(-0.37f,0.34f);
    glVertex2f(-0.37f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    //window 10
    glVertex2f(-0.47f, 0.39f);
	glVertex2f(-0.47f, 0.34f);
	glVertex2f(-0.44f, 0.34f);
    glVertex2f(-0.44f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    //window 11

    glVertex2f(-0.53f, 0.39f);
	glVertex2f(-0.53f, 0.34f);
	glVertex2f(-0.5f, 0.34f);
    glVertex2f(-0.5f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    //window 12
    glVertex2f(-0.53f, 0.49f);
	glVertex2f(-0.53f, 0.45f);
	glVertex2f(-0.37f, 0.45f);
    glVertex2f(-0.37f,0.49f);
    glEnd();
}

void newhouse1()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(218, 247, 166);
    glVertex2f(-0.55f, 0.3f);
	glVertex2f(-0.55f, -0.1f);
	glVertex2f(-0.35, -0.1f);
    glVertex2f(-0.35f,0.3f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(86, 101, 115);
    glVertex2f(-0.53f, 0.03f);
	glVertex2f(-0.53f, -0.1000f);
	glVertex2f(-0.37, -0.1000f);
    glVertex2f(-0.37f,0.03f);
    glEnd();
}

void oldschool()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(199, 0, 57);
    glVertex2f(-0.2f, 0.1f);
	glVertex2f(-0.2f, -0.1000f);
	glVertex2f(0.2, -0.1000f);
    glVertex2f(0.2f,0.1f);
    glEnd();
    glBegin(GL_TRIANGLES);
    //upper
    glColor3ub(202, 202, 202);
    glVertex2f(-0.2f, 0.1f);
	glVertex2f(0.0f, 0.3f);
    glVertex2f(0.2, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    //left door
    glColor3ub(218, 247, 166);
    glVertex2f(-0.1f, 0.05f);
	glVertex2f(-0.1f, -0.1000f);
	glVertex2f(-0.05f, -0.1000f);
    glVertex2f(-0.05f,0.05f);
    glEnd();
    glBegin(GL_LINES);
    //left door line
    glColor3ub(20, 21, 17);
    glVertex2f(-0.075f, 0.049f);
	glVertex2f(-0.075f, -0.1000f);
    glEnd();

    glBegin(GL_QUADS);
    //right door
    glColor3ub(218, 247, 166);
    glVertex2f(0.1f, 0.05f);
	glVertex2f(0.1f, -0.1000f);
	glVertex2f(0.05f, -0.1000f);
    glVertex2f(0.05f,0.05f);
    glEnd();
    glBegin(GL_LINES);
    //right door line
    glColor3ub(20, 21, 17);
    glVertex2f(0.075f, 0.049f);
	glVertex2f(0.075f, -0.1000f);
    glEnd();
    glBegin(GL_QUADS);
    //left window
    glColor3ub(218, 247, 166);
    glVertex2f(-0.17f, 0.03f);
	glVertex2f(-0.17f, -0.02f);
	glVertex2f(-0.13f, -0.02f);
    glVertex2f(-0.13f,0.03f);
    glEnd();
    glBegin(GL_LINES);
    //left window line
    glColor3ub(20, 21, 17);
    glVertex2f(-0.15f, 0.027f);
	glVertex2f(-0.15f, -0.017f);
    glEnd();
    glBegin(GL_QUADS);
    //right window
    glColor3ub(218, 247, 166);
    glVertex2f(0.17f, 0.03f);
	glVertex2f(0.17f, -0.02f);
	glVertex2f(0.13f, -0.02f);
    glVertex2f(0.13f,0.03f);
    glEnd();
    glBegin(GL_LINES);
    //right window line
    glColor3ub(20, 21, 17);
    glVertex2f(0.15f, 0.027f);
	glVertex2f(0.15f, -0.017f);
    glEnd();
}

void newschool1()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(199, 0, 57);
    glVertex2f(-0.2f, 0.3f);
	glVertex2f(-0.2f, -0.1000f);
	glVertex2f(0.2, -0.1000f);
    glVertex2f(0.2f,0.3f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(213, 216, 220);
    glVertex2f(-0.05f, 0.05f);
    glVertex2f(-0.05f,-0.1000f);
    glVertex2f(0.05f, -0.1000f);
	glVertex2f(0.05f, 0.05f);
    glEnd();
}

void newschool2()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(199, 0, 57);
    glVertex2f(-0.2f, 0.55f);
	glVertex2f(-0.2f, -0.1000f);
	glVertex2f(0.2, -0.1000f);
    glVertex2f(0.2f,0.55f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(213, 216, 220);
    glVertex2f(-0.05f, 0.05f);
    glVertex2f(-0.05f,-0.1000f);
    glVertex2f(0.05f, -0.1000f);
	glVertex2f(0.05f, 0.05f);
    glEnd();
}

void Schoolwindow()
{
    glBegin(GL_QUADS);
    //left window 1
    glVertex2f(-0.17f, 0.03f);
	glVertex2f(-0.17f, -0.02f);
	glVertex2f(-0.13f, -0.02f);
    glVertex2f(-0.13f,0.03f);
    glEnd();
    glBegin(GL_QUADS);
    //left window 2
    glVertex2f(-0.11f, 0.03f);
	glVertex2f(-0.11f, -0.02f);
	glVertex2f(-0.07f, -0.02f);
    glVertex2f(-0.07f,0.03f);
    glEnd();

    glBegin(GL_QUADS);
    //right window 1
    glVertex2f(0.11f, 0.03f);
	glVertex2f(0.11f, -0.02f);
	glVertex2f(0.07f, -0.02f);
    glVertex2f(0.07f,0.03f);
    glEnd();
    glBegin(GL_QUADS);
    //right window 2
    glVertex2f(0.17f, 0.03f);
	glVertex2f(0.17f, -0.02f);
	glVertex2f(0.13f, -0.02f);
    glVertex2f(0.13f,0.03f);
    glEnd();

    glBegin(GL_QUADS);
    //left window first floor
    glVertex2f(-0.17f, 0.15f);
	glVertex2f(-0.17f, 0.07f);
	glVertex2f(-0.07f, 0.07f);
    glVertex2f(-0.07f,0.15f);
    glEnd();


    glBegin(GL_QUADS);
    //middle window first floor
    glVertex2f(-0.05f, 0.15f);
	glVertex2f(-0.05f, 0.07f);
	glVertex2f(0.05f, 0.07f);
    glVertex2f(0.05f,0.15f);

    glBegin(GL_QUADS);
    //right window first floor
    glVertex2f(0.07f, 0.15f);
	glVertex2f(0.07f, 0.07f);
	glVertex2f(0.17f, 0.07f);
    glVertex2f(0.17f,0.15f);
    glEnd();

    glBegin(GL_QUADS);
    //left window 2nd floor
    glVertex2f(-0.17f, 0.27f);
	glVertex2f(-0.17f, 0.19f);
	glVertex2f(-0.07f, 0.19f);
    glVertex2f(-0.07f,0.27f);
    glEnd();


    glBegin(GL_QUADS);
    //middle window 2nd floor
    glVertex2f(-0.05f, 0.27f);
	glVertex2f(-0.05f, 0.19f);
	glVertex2f(0.05f, 0.19f);
    glVertex2f(0.05f,0.27f);

    glBegin(GL_QUADS);
    //right window 2nd floor
    glVertex2f(0.07f, 0.27f);
	glVertex2f(0.07f, 0.19f);
	glVertex2f(0.17f, 0.19f);
    glVertex2f(0.17f,0.27f);
    glEnd();

    glBegin(GL_QUADS);
    //left window 3rd floor
    glVertex2f(-0.17f, 0.39);
	glVertex2f(-0.17f, 0.31);
	glVertex2f(-0.07f, 0.31);
    glVertex2f(-0.07f,0.39);
    glEnd();


    glBegin(GL_QUADS);
    //middle window 3rd floor
    glVertex2f(-0.05f, 0.39);
	glVertex2f(-0.05f, 0.31);
	glVertex2f(0.05f, 0.31);
    glVertex2f(0.05f,0.39);

    glBegin(GL_QUADS);
    //right window 3rd floor
    glVertex2f(0.07f, 0.39);
	glVertex2f(0.07f, 0.31);
	glVertex2f(0.17f, 0.31);
    glVertex2f(0.17f,0.39);
    glEnd();

    glBegin(GL_QUADS);
    //left window 4th floor
    glVertex2f(-0.17f, 0.51);
	glVertex2f(-0.17f, 0.43);
	glVertex2f(-0.07f, 0.43);
    glVertex2f(-0.07f,0.51);
    glEnd();


    glBegin(GL_QUADS);
    //middle window 4th floor
    glVertex2f(-0.05f, 0.51);
	glVertex2f(-0.05f, 0.43);
	glVertex2f(0.05f, 0.43);
    glVertex2f(0.05f,0.51);

    glBegin(GL_QUADS);
    //right window 4th floor
    glVertex2f(0.07f, 0.51);
	glVertex2f(0.07f, 0.43);
	glVertex2f(0.17f, 0.43);
    glVertex2f(0.17f,0.51);
    glEnd();
}

void flagg()
{
    glBegin(GL_LINES);
    //flag pipe
    glColor3ub(1,1,1);

    glVertex2f(0.01f, 0.15f);
	glVertex2f(0.01f, -0.1000f);
    glVertex2f(0.0095f, 0.2f);
	glVertex2f(0.0095f, -0.1000f);
    glEnd();
    glBegin(GL_QUADS);
    //flag
    glColor3ub(0, 155, 7);
    glVertex2f(0.01f, 0.2f);
	glVertex2f(0.01f, 0.1f);
	glVertex2f(0.095f, 0.1f);
    glVertex2f(0.095f, 0.2f);
    glEnd();
    GLfloat x = 0.04f; GLfloat y = 0.15f; GLfloat radius = 0.02f;
    glColor3ub(255, 2, 2);
    int triangleAmount = 20;
    DrawCircle(x,y,radius,triangleAmount);
}

void oldhospital()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(212, 252, 249);
    glVertex2f(0.4f, 0.1f);
	glVertex2f(0.4f, -0.1000f);
	glVertex2f(0.7, -0.1000f);
    glVertex2f(0.7f,0.1f);
    glEnd();
    glBegin(GL_TRIANGLES);
    //upper
    glColor3ub(255, 255, 255);
    glVertex2f(0.4f, 0.1f);
	glVertex2f(0.55f, 0.3f);
    glVertex2f(0.7f,0.1f);
    glEnd();

    glBegin(GL_QUADS);
    //left door
    glColor3ub(136, 78, 160);
    glVertex2f(0.45f, 0.05f);
	glVertex2f(0.45f, -0.1000f);
	glVertex2f(0.5f, -0.1000f);
    glVertex2f(0.5f,0.05f);
    glEnd();
    glBegin(GL_LINES);
    //left door line
    glColor3ub(255,255,255);
    glVertex2f(0.475f, 0.049f);
	glVertex2f(0.475f, -0.1000f);
    glEnd();

    glBegin(GL_QUADS);
    //right door
    glColor3ub(136, 78, 160);
    glVertex2f(0.6f, 0.05f);
	glVertex2f(0.6f, -0.1000f);
	glVertex2f(0.65f, -0.1000f);
    glVertex2f(0.65f,0.05f);
    glEnd();
    glBegin(GL_LINES);
    //right door line
    glColor3ub(255,255,255);
    glVertex2f(0.625, 0.049f);
	glVertex2f(0.625, -0.1000f);
    glEnd();

    glBegin(GL_QUADS);
    //hospital logo
    // |
    glColor3ub(255, 0, 0);
    glVertex2f(0.54f, 0.24f);
	glVertex2f(0.54f, 0.12f);
	glVertex2f(0.56,  0.12f);
    glVertex2f(0.56, 0.24f);
    // -
    glColor3ub(255, 0, 0);
    glVertex2f(0.509f, 0.2f);
	glVertex2f(0.509f, 0.17f);
	glVertex2f(0.59, 0.17f);
    glVertex2f(0.59f,0.2f);
    glEnd();


}

void newhospital1()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(212, 252, 249);
    glVertex2f(0.4f, 0.3f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.7, -0.1f);
    glVertex2f(0.7f,0.3f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(215, 189, 226);
    glVertex2f(0.45f, 0.05f);
	glVertex2f(0.45f, -0.1000f);
	glVertex2f(0.65f, -0.1000f);
    glVertex2f(0.65f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    //door line
    glColor3ub(255, 255, 255);
    glVertex2f(0.55f, 0.049f);
	glVertex2f(0.55f, -0.1f);
    glEnd();
}

void newhospital2()
{
    glBegin(GL_QUADS);
    //body
    glColor3ub(212, 252, 249);
    glVertex2f(0.4f, 0.65f);
	glVertex2f(0.4f, -0.1000f);
	glVertex2f(0.7, -0.1000f);
    glVertex2f(0.7f,0.65f);
    glEnd();

    glBegin(GL_QUADS);
    //door
    glColor3ub(215, 189, 226);
    glVertex2f(0.45f, 0.05f);
	glVertex2f(0.45f, -0.1000f);
	glVertex2f(0.65f, -0.1000f);
    glVertex2f(0.65f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    //door line
    glColor3ub(255, 255, 255);
    glVertex2f(0.55f, 0.049f);
	glVertex2f(0.55f, -0.1f);
    glEnd();
}

void Hospitalwindow()
{
    glBegin(GL_QUADS);
    //window 1st floor
    glColor3ub(235, 222, 240);
    glVertex2f(0.41f, 0.15f);
	glVertex2f(0.41f, 0.08f);
	glVertex2f(0.69f, 0.08f);
    glVertex2f(0.69f,0.15f);
    glEnd();
    glBegin(GL_QUADS);
    //window 2nd floor
    glVertex2f(0.41f, 0.27f);
	glVertex2f(0.41f, 0.2f);
	glVertex2f(0.69f, 0.2f);
    glVertex2f(0.69f,0.27f);
    glEnd();

    glBegin(GL_QUADS);
    //window 3rd floor
    glVertex2f(0.41f, 0.39);
	glVertex2f(0.41f, 0.32f);
	glVertex2f(0.69f, 0.32f);
    glVertex2f(0.69f,0.39);
    glEnd();

    glBegin(GL_QUADS);
    //window 3rd floor
    glVertex2f(0.41f, 0.51);
	glVertex2f(0.41f, 0.44f);
	glVertex2f(0.69f, 0.44f);
    glVertex2f(0.69f,0.51);
    glEnd();
    glBegin(GL_QUADS);
    //hospital logo
    // |
    glColor3ub(255, 0, 0);
    glVertex2f(0.54f, 0.63f);
	glVertex2f(0.54f, 0.51f);
	glVertex2f(0.56,  0.51f);
    glVertex2f(0.56, 0.63f);
    // -
    glColor3ub(255, 0, 0);
    glVertex2f(0.509f, 0.59f);
	glVertex2f(0.509f, 0.56f);
	glVertex2f(0.59, 0.56f);
    glVertex2f(0.59f,0.59f);
    glEnd();
}

void boat()
{
    int triangleAmount = 20;

    GLfloat  x= -0.8 , y = -0.7, radius = 0.2f;
    //black
    glColor3ub(9, 32, 23);
    DrawCircle2(x,y,radius,triangleAmount);


    x= -0.8 , y = -0.55, radius = 0.25f;
    //blue
    glColor3ub(38, 154, 214);
    DrawCircle2(x,y,radius,triangleAmount);


    glBegin(GL_POLYGON);
    //upper part
    glColor3ub(179, 140, 17);

    glVertex2f(-0.7f, -0.778f);
    glVertex2f(-0.7f,-0.6f);
    glVertex2f(-0.92f, -0.6f);
	glVertex2f(-0.92f, -0.77f);


    glVertex2f(-0.90f, -0.775f);
	glVertex2f(-0.88f, -0.79f);
	glVertex2f(-0.86f, -0.79f);
    glVertex2f(-0.84f,-0.8f);
    glVertex2f(-0.84f,-0.8f);

    glVertex2f(-0.82f, -0.80f);
	glVertex2f(-0.80f, -0.80f);
	glVertex2f(-0.78f, -0.80f);
    glVertex2f(-0.76f,-0.787f);

    glVertex2f(-0.74f, -0.78f);
    glVertex2f(-0.74f, -0.79f);
    glVertex2f(-0.73f, -0.79f);
	glVertex2f(-0.72f, -0.755f);
    glEnd();
    //upper design
    glBegin(GL_LINES);
    glColor3ub(20, 21, 17);
    glVertex2f(-0.92f, -0.6f);
	glVertex2f(-0.92f, -0.8f);
    glVertex2f(-0.9f, -0.6f);
	glVertex2f(-0.9f, -0.8f);
	glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.8f,-0.8f);
    glVertex2f(-0.85f, -0.6f);
    glVertex2f(-0.85f,-0.8f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.7f,-0.8f);
    glVertex2f(-0.75f, -0.6f);
    glVertex2f(-0.75f,-0.8f);
    glVertex2f(-0.92f, -0.6f);
    glVertex2f(-0.7f, -0.6f);
    glEnd();
}

void surface()
{
    glBegin(GL_QUADS);
    glColor3ub(44, 171, 2);
    glVertex2f(-1.0f, -0.1f);
	glVertex2f(-1.0f, -0.4f);
    glVertex2f( 1.0f,-0.4f);
	glVertex2f( 1.0f, -0.1f);
    glEnd();
}

void road()
{
    glBegin(GL_QUADS);
    glColor3ub(171, 178, 185);
    glVertex2f(-1.0f, -0.1f);
	glVertex2f(-1.0f, -0.15f);
    glVertex2f( 1.0f,-0.15f);
	glVertex2f( 1.0f, -0.1f);
    glEnd();
}

void MainDisplay()
{
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        sky();
        Tree();
        sun();
        glPushMatrix();
        glTranslatef(CloudPositionX, 0.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(CloudPositionX, 0.0f, 0.0f);
        glPopMatrix();

        river();
        surface();
        road();

        oldhouse();

        oldschool();

        oldhospital();

        if(BoatPositionHouse1 == 1)
        {
            newhouse1();

        }
        if(BoatPositionHouse2 == 1)
        {
            newhouse2();
        }
        if(HouseWindow == 1)
        {
            houseWindow();
        }

        if(BoatPositionSchool1 == 1)
        {
            newschool1();
        }
        if(BoatPositionSchool2 == 1)
        {
            newschool2();
        }
        if(SchoolWindow == 1)
        {
            Schoolwindow();
        }
        if(BoatPositionHospital1 == 1)
        {
            newhospital1();
        }
        if(BoatPositionHospital2 == 1)
        {
            newhospital2();
        }
        if(HospitalWindow == 1)
        {
            Hospitalwindow();
        }
        flagg();

        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(BoatPositionX, 0.0f, 0.0f);
        boat();

        glPopMatrix();

        DrawCircle2(0.5f, -0.5, 0.3, 20);
        glEnd();
        glFlush();
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1050, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Development by Boat");
    glutDisplayFunc(MainDisplay);
    init();
    glutTimerFunc(100, MoveBoat, 0);
    glutTimerFunc(100, MoveCloud, 0);
    glutMainLoop();
    return 0;
}
