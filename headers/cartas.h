#ifndef CARTAS
#define CARTAS 0

#include <iostream>
#include <string>

#include "dioses.h"

using namespace std;

class Carta{

    private:
    
        string tipo;

        void milagro(Dios *diosA, Dios *diosB){
            //El dios A le gana el 20% de los fieles al dios B
            
            int fielesA = diosA->getFieles();
            int fielesB = diosB->getFieles();

            int robo =int (fielesB*0.2);
            
            fielesA = fielesA + robo;
            fielesB = fielesB - robo;

            diosA->setFieles(fielesA);
            diosB->setFieles(fielesB);

            cout<<diosA->getName()<< " le ha robado "<<robo <<" seguidores a "<<diosB->getName()<<endl;

            if (fielesB <= 0){
                cout<<diosB->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }

        void traicion(Dios *diosA, Dios *diosB){
            //El dios A pierde el 30% de sus fieles y se los da a B 
            
            int fielesA = diosA->getFieles();
            int fielesB = diosB->getFieles();

            int traidores =int (fielesA*0.3);
            
            fielesA = fielesA - traidores;
            fielesB = fielesB + traidores;

            diosA->setFieles(fielesA);
            diosB->setFieles(fielesB);

            cout<<diosA->getName()<< " ha sido traicionado por  "<<traidores <<" seguidores, los cuales han preferido a "<<diosB->getName()<<endl;

            if (fielesA <= 0){
                cout<<diosA->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }

        void anarquia(){
            //El dios A se separa del árbol de dioses y crea su propio árbol con los dioses con menos fieles que él
        }

        void unionA(){
            //Si el dios A y el dios B se encuentran en árboles diferentes se vuelven a unir en un solo árbol
        }

        void nuevoDios(Dios *diosA, Dios *diosB){
            //Los dioses A y B tienen un hijo dios que inicia con cantidad de fieles igual a la suma de ambos dioses
        }


        void retorno(){
            //El mazo del destino recupera las últimas 3 cartas de las que ya fueron sacadas, pero en orden inverso
            
        }

        void muerte(Dios *diosA){
            //El dios A pierde el 10% de sus fieles

            int fielesA = diosA->getFieles();

            int muertos = int (fielesA*0.1);

            fielesA = fielesA - muertos;

            diosA->setFieles(fielesA);

            cout<<"Han muerto "<<muertos<<" seguidores de "<<diosA->getName()<<endl;

            if (fielesA<=0){
                cout<<diosA->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }

    public:

        Carta(string pTipo){
            tipo = pTipo;
        }

        void setTipo(string pTipo){
            tipo = pTipo;
        }

        string getTipo(){
            return tipo;
        }


        void realizaraccion(Dios *diosA, Dios *diosB){
            if (tipo == "Milagro"){
                milagro(diosA, diosB);
            }
            else if (tipo == "Traicion"){
                traicion(diosA, diosB);
            }
            else if (tipo == "Anarquia"){
                anarquia();
            }
            else if (tipo =="Union"){
                unionA();
            }
            else if (tipo =="NuevoDios"){
                nuevoDios(diosA, diosB);
            }
            else if (tipo =="Retorno"){
                retorno();
            }
            else{
                muerte(diosA);
            }
        }
};

#endif