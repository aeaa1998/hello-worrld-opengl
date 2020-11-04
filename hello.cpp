#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

void display(void) {

    //clear white, draw with black
    
    glClearColor(255, 255, 255, 0);
    glColor3d(0, 0, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f( 1, 0, 0 ); // red
    glVertex2f( -0.8, -0.8 );
    glColor3f( 0, 1, 0 ); // green
    glVertex2f( 0.8, -0.8 );
    glColor3f( 0, 0, 1 ); // blue
    glVertex2f( 0, 0.9 );
    glEnd(); 
    

    //a more useful helper
    // glRecti(200, 200, 250, 250);

    glutSwapBuffers();

}


void idle(void) {

    glutPostRedisplay();
}

int main(int argc, char*argv[]) {
    
    glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);  
    //create the window, the argument is the title
    glutCreateWindow("Hello World");

    //pass the callbacks
    glutDisplayFunc(display);
    
    // glutIdleFunc(idle);

    glutMainLoop();

    //we never get here because glutMainLoop() is an infinite loop
    return 0;

}