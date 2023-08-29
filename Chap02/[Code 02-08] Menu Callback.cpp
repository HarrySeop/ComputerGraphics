#include <gl/glut.h>

GLboolean IsSphere = true; 
GLboolean IsSmall = true; 
GLboolean IsModel = true;

void MyDisplay() {
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0, 0.5, 0.5);

     if ((IsSphere) && (IsSmall) && (IsModel))
         glutWireSphere(0.5, 30, 30);
     else if ((IsSphere) && (!IsSmall) && (IsModel))
         glutWireSphere(0.7, 30, 30);
     else if ((!IsSphere) && (IsSmall) && (IsModel))
         glutWireTorus(0.1, 0.3, 40, 20);
     else if ((!IsSphere) && (!IsSmall) && (IsModel))
         glutWireTorus(0.2, 0.5, 40, 20);
     else if ((IsSphere) && (IsSmall) && (!IsModel))
         glutSolidSphere(0.5, 30, 30);
     else if ((IsSphere) && (!IsSmall) && (!IsModel))
         glutSolidSphere(0.7, 30, 30);
     else if ((!IsSphere) && (IsSmall) && (!IsModel))
         glutSolidTorus(0.1, 0.3, 40, 20);
     else glutSolidTorus(0.2, 0.5, 40, 20);

     glFlush( );
}

void MyMainMenu(int entryID) {
    static int Model_mode = 0;
    if (entryID == 1) { 
        Model_mode = ~Model_mode; // 비트를 반전 시키는 연산자 !를 사용했더니 에러나와서 바꿈
        glutPostRedisplay();
    }
    else if (entryID == 2) {
        exit(0);
    }
    IsModel = Model_mode;
     glutPostRedisplay(); 
}

void MyFigureMenu(int entryID) { 
    if (entryID == 1) {
        IsSphere = true; 
    }
    else if (entryID == 2) {
        IsSphere = false; 
    }
     glutPostRedisplay();
}

void SphereSizeMenu(int entryID) {
    if (entryID == 1) {
        IsSmall = true; 
    }
    else if (entryID == 2) { 
        IsSmall = false; 
    }
    glutPostRedisplay();
}

void TorusSizeMenu(int entryID) {
    if (entryID == 1) {
        IsSmall = true; 
        IsSphere = false;
    }
    else if (entryID == 2) { 
        IsSmall = false; 
        IsSphere = false;
    }
    glutPostRedisplay();
}


void MyInit() {
     glClearColor (1.0, 1.0, 1.0, 1.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity( );

     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

     GLint SphereSizeID = glutCreateMenu(SphereSizeMenu);
     glutAddMenuEntry("Small Sphere", 1);
     glutAddMenuEntry("Large Sphere", 2);

     GLint TorusSizeID = glutCreateMenu(TorusSizeMenu);
     glutAddMenuEntry("Small Torus", 1);
     glutAddMenuEntry("Large Torus", 2);
     
     GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
     glutAddMenuEntry("Change Model", 1);
     glutAddSubMenu("Draw Sphere", SphereSizeID);
     glutAddSubMenu("Draw Torus", TorusSizeID);
     glutAddMenuEntry("Exit", 2);
     glutAttachMenu(GLUT_RIGHT_BUTTON); 
}

int main(int argc, char** argv) {
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(0, 0);
     glutCreateWindow("Menu Callback");
     MyInit();
	 glutDisplayFunc(MyDisplay);

     glutMainLoop();
     return 0;
}