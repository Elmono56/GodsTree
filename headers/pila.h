#ifndef _PILA_
#define _PILA_ 0

#include <stack>
#include<iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

template <class T> 

class Pila {

    private:

        stack<T> pilacartas;
        stack<T> mazoauxiliar;

        /*
        void swapCartas(Carta* pCarta1, Carta* pCarta2){
            Carta* temp = pCarta1;
            pCarta1 = pCarta2;
            pCarta1 = temp;
        }
        */

    public:
        Pila(vector<T> vectorM){
            //---------------------------------CREACION PILA MAZO-------------------------------------
            
            random_shuffle(vectorM.begin(), vectorM.end());

            for (int cont = 0; cont<40;cont++){
                T elemento = vectorM.at(cont);
                pilacartas.push(elemento);
            }
            
        }

        int getSize(){
            return pilacartas.size();
        }
        
        T getCarta(){ //Carta getCarta(){
            
            T siguienteC = pilacartas.top();
            pilacartas.pop();

            mazoauxiliar.push(siguienteC); //poner carta en las últimas 3 utilizadas

            if (mazoauxiliar.size()>3){
                //mazoauxiliar.pop_back();
            }

            return siguienteC;
            
        }

        void accionRetornar(){
            
            int cont = 0;
            /*
            while(!mazoauxiliar.empty()){
                Carta c = mazoauxiliar.back();  //recupera antepenultima, luego penultima y luego ultima carta utilizada
                pilacartas.push(c);             //las pushea al mazo
                //mazoauxiliar.pop_back();        //las elimina de la pila auxiliar
                cont++;
            }*/

            cout<<"Se han retornado "<<cont<< " cartas al mazo"<<endl;
            

        }

    

};

#endif