#include <gl/glut.h>

void MyInit(void) {
	// 전부 0이면 검정색이다.
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//칼라 버퍼를 지워줌.

	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);
	glutWireTeapot(1.5);

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//  아래 주석처럼 투영 변환이 가능하다.
	//	glOrtho(-3.0, 3.0, -3.0, 3.0, 0.0, 5.0);
		glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Projection - gluPerspective");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);

	glutMainLoop();
	return 0;
}
