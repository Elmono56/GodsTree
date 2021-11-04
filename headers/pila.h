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
        stack<T> segundomazo;

    public:
        Pila(vector<T> pVectorM){
            //---------------------------------CREACION PILA MAZO-------------------------------------
            
            random_shuffle(pVectorM.begin(), pVectorM.end()); //randomizar el mazo

            for (int cont = 0; cont<40;cont++){
                T elemento = pVectorM.at(cont);
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

                for (int i = 0;i<5;i++){

                    if (i<2){
                        T cartaN = mazoauxiliar.top();
                        mazoauxiliar.pop();
                        segundomazo.push(cartaN);
                    }
                    else if (i==2){
                        mazoauxiliar.pop();
                    }
                    else{
                        T cartaN = segundomazo.top();
                        segundomazo.pop();
                        mazoauxiliar.push(cartaN);
                    }   
                }
            }

            segundomazo.push(siguienteC);

            if (pilacartas.size()==0){
                int length = segundomazo.size();
                for (int i = 0; i<length; i++){
                    T carta = segundomazo.top();
                    segundomazo.pop();
                    pilacartas.push(carta);
                }
                cout<<"El mazo principal se ha vaciado, se ha intercambiado por el segundo mazo"<<endl;
            }
            return siguienteC;   
        }

        void accionRetornar(){
            
            int cont = 0;
            int length = mazoauxiliar.size();
            cout<<"PilaCartas: "<<pilacartas.size()<<"   MazoAuxiliar: "<<mazoauxiliar.size()<<"   SegundoMazo: "<<segundomazo.size()<<endl;
            for (int i = 0; i<length*2;i++){

                if (i<length){
                    T cartaN = mazoauxiliar.top();
                    mazoauxiliar.pop();
                    segundomazo.pop(); //eliminar la duplicacion de cartas
                    segundomazo.push(cartaN);
                }
                else{
                    T cartaN = segundomazo.top();
                    segundomazo.pop();
                    pilacartas.push(cartaN);
                    cont++;
                }
            }
            cout<<"Se han retornado "<<cont<< " cartas al mazo"<<endl;
        }
};

#endif