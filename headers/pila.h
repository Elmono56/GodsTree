#ifndef _PILA_
#define _PILA_ 0


#include <stack>
#include<iostream>
#include "cartas.h"
#include <string>

class Pila{

    private:
        stack<Carta> pilacartas;
        stack<Carta> mazoauxiliar;

        /*
        void swapCartas(Carta* pCarta1, Carta* pCarta2){
            Carta* temp = pCarta1;
            pCarta1 = pCarta2;
            pCarta1 = temp;
        }
        */


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

            //randomizar el mazo
            /*
            for(int i = 0; i<20;i++){
                int valor1 = rand()%39;
                int valor2 = rand()%39;

                
            }
            */


        }

        int getSize(){
            return pilacartas.size();
        }

        Carta getCarta(){

            Carta siguienteC = pilacartas.top();
            pilacartas.pop();

            mazoauxiliar.push(siguienteC); //poner carta en las últimas 3 utilizadas

            if (mazoauxiliar.size()>3){
                //mazoauxiliar.pop_back();
            }

            return siguienteC;
        }


        void accionRetornar(){
            
            /*
            int cont = 0;
            
            while(!mazoauxiliar.empty()){
                Carta c = mazoauxiliar.back();  //recupera antepenultima, luego penultima y luego ultima carta utilizada
                pilacartas.push(c);             //las pushea al mazo
                mazoauxiliar.pop_back();        //las elimina de la pila auxiliar
                cont++;
            }

            cout<<"Se han retornado "<<cont<< " cartas al mazo"<<endl;
            */

        }

};

#endif