#include <GL/glut.h>

float vertices[3][3] = {{-75, -75, 0}, {75, -75, 0}, {0, 75, 0}};
float vert[4][3] = {{-75, -75, 0}, {-75, 75, 0}, {75, -75, 0}, {75, 75, 0}};

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
    
    glColor3fv(cor);
    glVertex3fv(v[0]);
    glVertex3fv(v[1]);
    glVertex3fv(v[2]);

    glEnd();
}

float cor1[3] = {1, 1, 0};
float cor2[3] = {0, 1, 1};

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

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);    
    float cor1[3] = {1, 0, 0};
    float cor2[3] = {0, 0, 1};
    //triangle(vetor, vertices);
    square(cor1, vert);
    glFlush();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello, GL!");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}