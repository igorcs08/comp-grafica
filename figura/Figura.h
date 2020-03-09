#ifndef FIGURA_H
#define FIGURA_H

class Figura {
    public:
        float cor[3];
        float pos[2];
        //Figura();  ----- CONSTRUTOR PADRÃO
        Figura(float cor[3], float pos[2]);
        void paint();
        void setColor(int cor[3]);
    
};

#endif