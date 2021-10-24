#ifndef _PILA_
#define _PILA_ 0


#include <stack>
#include<iostream>
#include "cartas.h"
#include <string>

class Pila{

    private:
        stack<Carta> pilacartas;

    public:
        Pila(){
            //---------------------------------CREACION PILA MAZO-------------------------------------

            for (int i = 0; i<4;i++){
                pilacartas.push(Carta("Traicion")); //5 cartas de TRAICION
            }

            for (int i = 0; i<7;i++){
                pilacartas.push(Carta("Anarquia")); //5 cartas de ANARQUIA
            }

            for (int i = 0; i<4;i++){
                pilacartas.push(Carta("Union")); //5 cartas de UNION
            }

            for (int i = 0; i<4;i++){
                pilacartas.push(Carta("NuevoDios")); //5 cartas de NUEVO DIOS
            }

            for (int i = 0; i<6;i++){
                pilacartas.push(Carta("Retorno")); //5 cartas de RETORNO
            }

            for (int i = 0; i<5;i++){
                pilacartas.push(Carta("Milagro")); //5 cartas de MILAGRO
            }

            for (int i = 0; i<10;i++){
                    pilacartas.push(Carta("Muerte")); //5 cartas de MUERTE
            }       
        }

        int getSize(){
            return pilacartas.size();
        }

        Carta getCarta(){
            Carta siguienteC = pilacartas.top();
            pilacartas.pop();
            return siguienteC;
        }

};

#endif