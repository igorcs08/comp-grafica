#include <GL/glut.h>
#include "Figura.h"

#define R 0
#define G 1
#define B 2

#define X 0
#define Y 1

Figura::Figura(float cor[3], float pos[2]) {
    this->cor[R] = cor[R];
    this->cor[G] = cor[G];
    this->cor[B] = cor[B];
    this->pos[X] = pos[X];
    this->pos[Y] = pos[Y];
}

void Figura::paint() {
    short l = 20;
    glColor3fv(this->cor);
    glBegin(GL_QUADS);
    glVertex2fv(this->pos);
    glVertex2f(this->pos[X]+l, this->pos[Y]);
    glVertex2f(this->pos[X]+l, this->pos[Y]-l);
    glVertex2f(this->pos[X], this->pos[Y]-l);
    glEnd();
}

void Figura::setColor(int cor[3]) {
    this->cor[R] = cor[0];
    this->cor[G] = cor[1];
    this->cor[B] = cor[2];

}