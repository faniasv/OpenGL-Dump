#include <GL/glut.h>
#include <stdlib.h>

/* GLUT callback Handlers */
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
static void reclines(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // X AXIS
    glBegin(GL_LINES);
        glVertex3f(-1,-1,-10); // kanan bawah
        glVertex3f(1,-1,-10); // kana bawah
        glVertex3f(1,1,-10); // kanan atas
        glVertex3f(-1,1,-10); // kanan atas
    // Y AXIS
    glBegin(GL_LINES);
        glVertex3f(1,-1,-10); // kiri bawah
        glVertex3f(1,1,-10); //
        glVertex3f(-1,1,-10);
        glVertex3f(-1,-1,-10);
    // axis silang
    glBegin(GL_LINES);
        glVertex3f(1,1,-10);
        glVertex3f(-1,-1,-10);
    glBegin(GL_LINES);
        glVertex3f(-1,1,-10);
        glVertex3f(1,-1,-10);

    glEnd();
    glutSwapBuffers();
}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Primitive Object");

    glutReshapeFunc(resize);
    glutDisplayFunc(reclines);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,0);

    glutMainLoop();

    return EXIT_SUCCESS;
}
