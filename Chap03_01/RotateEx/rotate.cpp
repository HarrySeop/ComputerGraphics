#include <gl/glut.h>
#include <gl/glu.h>
#include <math.h>

GLfloat theta = 45.0;

GLfloat RotateZ_matrix[4][4] = {
	{cos(theta), -sin(theta), 0.0, 0.0},
	{sin(theta), cos(theta), 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

GLfloat RotateY_matrix[4][4] = {
	{cos(theta), 0.0, -sin(theta), 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{-sin(theta), 0.0, cos(theta), 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

GLfloat RotateX_matrix[4][4] = {
	{1.0, 0.0, 0.0, 0.0},
	{0.0, cos(theta), -sin(theta), 0.0},
	{0.0, sin(theta), cos(theta), 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

void XYZ() {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -2.0, 0.0);
	glVertex3f(0.0, 2.0, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -2.0);
	glVertex3f(0.0, 0.0, 2.0);
	glEnd();
}


//glMultMatrix((float*)RotateZ_matrix);
//glutSolidTeapot(1.0);


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	XYZ();
	//glRotatef(135.0, 0.0, 1.0, 0.0);
	//glTranslatef(1.0, 0.0, 0.0);
	//glScalef(1.0, 3.0, 1.0);

	//glMultMatrixf((float*)RotateX_matrix);
	// (회전하는 각의 크기, x축, y축, z축) 회전하고싶은 축에 값을 주면 됨.
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glutWireTeapot(0.5);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Composite Transformation");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
