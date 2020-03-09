#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include "Figura.h"

Figura *f = NULL;

void init (void) {
    //            R    G    B    A
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void display(void){
    glClear(GL_COLOR_BUFFER_BIT);        
    if (f != NULL)
        f->paint();
    glFlush();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        float cor[3] = {0, 0.2, 0};
        float pos[2];
        pos[0] = x;
        pos[1] = 500 - y;        
        f = new Figura (cor,pos);
    }
    glutPostRedisplay();
        
}

void keyboard(unsigned char key, int x, int y){
    int cor1[3] = {0, 0, 0};
    switch(key){
        case 'R':
        case 'r':
            //mudar a cor para vermelho
            cor1[0] = 1;
            cor1[1] = 0;
            cor1[2] = 0;
            f->setColor(cor1);
            break;
        case 'G':
        case 'g':
            //mudar a cor para vermelho
            cor1[0] = 0;
            cor1[1] = 1;
            cor1[2] = 0;
            f->setColor(cor1);
            break;
        case 'B':
        case 'b':
            //mudar a cor para vermelho
            cor1[0] = 0;
            cor1[1] = 0;
            cor1[2] = 1;
            f->setColor(cor1);
            break;        
    }
    glutPostRedisplay();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello, GL!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();

    return 0;
}