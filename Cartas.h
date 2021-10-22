#ifndef _CARTAS_
#define _CARTAS_ 0

#include <iostream>
#include <string>

using namespace std;

class Carta{

    private:
    
        string tipo;
        int cantidad;

    public:

        Carta(string pTipo, int pCantidad){
            tipo = pTipo;
            cantidad = pCantidad;
        }

        void setName(string pTipo){
            tipo = pTipo;
        }

        void setFieles(int pCantidad){
            cantidad = pCantidad;
        }

        string getName() const{
            return tipo;
        }

        int getFieles() const{
            return cantidad;
        }
};

#endif