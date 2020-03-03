#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>

float vertices[3][3] = {{-75, -75, 0}, {75, -75, 0}, {0, 75, 0}};
float vert[4][3] = {{-75, -75, 0}, {-75, 75, 0}, {75, -75, 0}, {75, 75, 0}};
float cor1[3] = {1, 1, 0};
float cor2[3] = {0, 1, 1};
float pontos[3] = {0, 0, 0};


void init (void) {
    //            R    G    B    A
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void triangle(float cor[3], float v[3][3]){
    glBegin(GL_TRIANGLES);
    
    glColor3fv(cor1);
    glVertex3fv(v[0]);
    glVertex3fv(v[1]);
    glVertex3fv(v[2]);

    glEnd();
}


void select_point(void){    
    srand(time(0));

    pontos[0] = (rand()%(75-(-75)+1))+(-75);
    pontos[1] = (rand()%(75-(-75)+1))+(-75);
    pontos[2] = 0;
    printf("%f %f", pontos[0], pontos[1]);

}

void square(float cor[3], float v[4][3]) {
    float v1[3][3], v2[3][3];

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            v1[i][j] = v[i][j];
            v2[i][j] = v[i+1][j];
        }
    }

    triangle(cor1, v1);
    triangle(cor2, v2);
}

void desenha_ponto(){
    glBegin(GL_POINTS);
    select_point();
    glColor3fv(cor1);
    glVertex3fv(pontos);
    glEnd();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'R':
            //mudar a cor para vermelho
            cor1[0] = 1;
            cor1[1] = 0;
            cor1[2] = 0;            
            break;
        case 'r':
            //mudar a cor para vermelho
            cor1[0] = 1;
            cor1[1] = 0;
            cor1[2] = 0;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);    
    float cor1[3] = {0, 0, 1};
    float cor2[3] = {0, 0, 1};    
    triangle(cor1, vertices);
    desenha_ponto();
    //square(cor1, vert);
    glFlush();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello, GL!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;
}