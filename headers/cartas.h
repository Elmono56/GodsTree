#ifndef _CARTAS_
#define _CARTAS_ 0

#include <iostream>
#include <string>

#include "dioses.h"
#include "pila.h"

using namespace std;

class Carta{

    private:
    
        string tipo;

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

        void realizaraccion();

};


//-----------------------------------------------------------------------------------------------------------------------------------

class CartaMilagro : public Carta{

    public:
        
        CartaMilagro():Carta("Milagro"){

        }
        
        void realizaraccion(Dios *diosA, Dios *diosB){
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

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaTraicion : public Carta{

    public:

        CartaTraicion():Carta("Traicion"){

        }

        void realizaraccion(Dios *diosA, Dios *diosB){
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

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaAnarquia : public Carta{

    public:

        CartaAnarquia():Carta("Anarquia"){

        }

        void realizaraccion(){
            //El dios A se separa del árbol de dioses y crea su propio árbol con los dioses con menos fieles que él
        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaUnion : public Carta{

    public:

        CartaUnion():Carta("Union"){

        }

        void realizaraccion(){
            //Si el dios A y el dios B se encuentran en árboles diferentes se vuelven a unir en un solo árbol
        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaNuevoDios : public Carta{

    public:

        CartaNuevoDios():Carta("NuevoDios"){

        }

        void realizaraccion(Dios* diosA, Dios* diosB){
            //Los dioses A y B tienen un hijo dios que inicia con cantidad de fieles igual a la suma de ambos dioses
            
            int fielesN = diosA->getFieles() + diosB->getFieles();

            Dios DiosG = Dios("Generico",fielesN);

            cout<<DiosG.getName()<< " ha nacido de "<<diosA->getName() << " y de "<<diosB->getName()<<endl;
        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaRetorno : public Carta{

    public:

        CartaRetorno():Carta("Retorno"){

        }

        void realizaraccion(Pila<Carta>* pMazoCartas){//Pila* pMazoCartas){
            //El mazo del destino recupera las últimas 3 cartas de las que ya fueron sacadas, pero en orden inverso
            pMazoCartas->accionRetornar();
        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaMuerte : public Carta{

    public:

        CartaMuerte():Carta("Muerte"){

        }

        void realizaraccion(Dios *diosA){
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

};

#endif