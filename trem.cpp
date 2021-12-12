#include "trem.h"
#include <QtCore>
#include "mutex"

using namespace std;

mutex mutex0;
mutex mutex1;
mutex mutex2;
mutex mutex3;
mutex mutex4;
mutex mutex5;
mutex mutex6;
mutex mutex7;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (x < 320 && y == 20)
                x+=10;
            else if (x == 320 && y < 220)
                y+=10;
            else if (x > 120 && y == 220)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            if (x == 300 && y == 20)
                mutex0.lock();
            else if (x == 320 && y == 200)
                mutex2.lock();
            else if (x == 300 && y == 220)
                mutex0.unlock();
            else if (x == 240 && y == 220)
                mutex1.lock();
            else if (x == 200 && y == 220)
                mutex2.unlock();
            else if (x == 120 && y == 200)
                mutex1.unlock();
            break;
        case 2: //Trem 2
            if (x < 520 && y == 20)
                x+=10;
            else if (x == 520 && y < 220)
                y+=10;
            else if (x > 320 && y == 220)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            if (x == 520 && y == 200)
                mutex4.lock();
            else if (x == 440 && y == 220)
                mutex3.lock();
            else if (x == 400 && y == 220)
                mutex4.unlock();
            else if (x == 340 && y == 220)
                mutex0.lock();
            else if (x == 320 && y == 200)
                mutex3.unlock();
            else if (x == 340 && y == 20)
                mutex0.unlock();
            break;
        case 3: //Trem 3
            if (x < 220 && y == 220)
                x+=10;
            else if (x == 220 && y < 420)
                y+=10;
            else if (x > 20 && y == 420)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            if (x == 100 && y == 220)
                mutex1.lock();
            else if (x == 200 && y == 220)
                mutex5.lock();
            else if (x == 220 && y == 240)
                mutex1.unlock();
            else if (x == 200 && y == 420)
                mutex5.unlock();
            break;
        case 4: //Trem 4
            if (x < 420 && y == 220)
                x+=10;
            else if (x == 420 && y < 420)
                y+=10;
            else if (x > 220 && y == 420)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            if (x == 300 && y == 220)
                mutex3.lock();
            else if (x == 400 && y == 220)
                mutex6.lock();
            else if (x == 420 && y == 240)
                mutex3.unlock();
            else if (x == 400 && y == 420)
                mutex6.unlock();
            else if (x == 240 && y == 420)
                mutex5.lock();
            else if (x == 220 && y == 240)
                mutex2.lock();
            else if (x == 240 && y == 220)
                mutex5.unlock();
            else if (x == 340 && y == 220)
                mutex2.unlock();
            break;
        case 5: //Trem 5
            if (x < 620 && y == 220)
                x+=10;
            else if (x == 620 && y < 420)
                y+=10;
            else if (x > 420 && y == 420)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal

            if (x == 440 && y == 420)
                mutex6.lock();
            else if (x == 420 && y == 240)
                mutex4.lock();
            else if (x == 440 && y == 220)
                mutex6.unlock();
            else if (x == 540 && y == 220)
                mutex4.unlock();
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




