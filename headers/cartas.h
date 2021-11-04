#ifndef _CARTAS_
#define _CARTAS_ 0

#include <iostream>
#include <string>
#include <vector>

#include "dioses.h"
#include "pila.h"
#include "cola.h"
#include "avl.h"

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
        
        void realizaraccion(Dios *pDiosA, Dios *pDiosB){
            //El dios A le gana el 20% de los fieles al dios B
            
            int fielesA = pDiosA->getFieles();
            int fielesB = pDiosB->getFieles();

            int robo =int (fielesB*0.2);
            
            fielesA = fielesA + robo;
            fielesB = fielesB - robo;

            pDiosA->setFieles(fielesA);
            pDiosB->setFieles(fielesB);

            cout<<pDiosA->getName()<< " le ha robado "<<robo <<" seguidores a "<<pDiosB->getName()<<endl;

            if (fielesB <= 0){
                cout<<pDiosB->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaTraicion : public Carta{

    public:

        CartaTraicion():Carta("Traicion"){

        }

        void realizaraccion(Dios *pDiosA, Dios *pDiosB){
            //El dios A pierde el 30% de sus fieles y se los da a B 
            
            int fielesA = pDiosA->getFieles();
            int fielesB = pDiosB->getFieles();

            int traidores =int (fielesA*0.3);
            
            fielesA = fielesA - traidores;
            fielesB = fielesB + traidores;

            pDiosA->setFieles(fielesA);
            pDiosB->setFieles(fielesB);

            cout<<pDiosA->getName()<< " ha sido traicionado por  "<<traidores <<" seguidores, los cuales han preferido a "<<pDiosB->getName()<<endl;

            if (fielesA <= 0){
                cout<<pDiosA->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaAnarquia : public Carta{

    public:

        CartaAnarquia():Carta("Anarquia"){

        }

        void realizaraccion(Dios* pDiosA, vector<avl*>* pBosque){
            /*
            ///El dios A se separa del árbol de dioses y crea su propio árbol con los dioses con menos fieles que él

            int posipDiosA=0;
            avl_tree arbol = avl_tree();

            int cont = 0;

            for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
                
                if (arbol.buscarDios(*it,*pDiosA) == 1){ //encontrar el arbol en el que está pDiosA
                    posipDiosA = cont;
                    break;
                }
                else{
                }
            }

            avl* arbolp = pBosque->at(posipDiosA); //arbol en el que se encuentra el pDiosA

            if (arbolp->getValue().getName()==pDiosA->getName() & arbolp->getRS()==nullptr){ //esta en un arbol el solo
                cout<<"El dios"<<pDiosA->getName()<<" ya se encuentra aislado en un arbol"<<endl;
            }

            else{
                pBosque->erase(pBosque->begin()+posipDiosA);
                
                avl* arbolanarquico = arbol.deleteNode(nullptr,arbolp,*pDiosA); //nuevo arbol

                int cant = arbol.cantNodos(arbolanarquico) - 1;
                
                pBosque->push_back(arbolp);
                pBosque->push_back(arbolanarquico);


                cout<<"El dios "<<pDiosA->getName()<<" se ha vuelto anarquico y se ha llevado consigo "<<cant <<" dios(es)"<<endl;
            }
            */
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaUnion : public Carta{

    public:

        CartaUnion():Carta("Union"){

        }

        void realizaraccion(Dios* pDiosA, Dios* pDiosB,vector<avl*>* pBosque){
            //Si el dios A y el dios B se encuentran en árboles diferentes se vuelven a unir en un solo árbol
            int posipDiosA=0;
            int posipDiosB=0;
            avl_tree arbol = avl_tree();

            int cont = 0;

            for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
                
                if (arbol.buscarDios(*it,*pDiosA) == 1){ //encontrar el arbol en el que está pDiosA
                    posipDiosA = cont;
                    break;
                }
                else{
                }
            }

            cont=0;
            for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
                
                if (arbol.buscarDios(*it,*pDiosB) == 1){//encontrar el arbol en el que está pDiosB
                    posipDiosB = cont;
                    break;
                }
                else{
                }
            }

            if (posipDiosA == posipDiosB){
                cout<<pDiosA->getName()<<" y "<<pDiosB->getName()<<" se encuentran en el mismo arbol"<<endl; //arboles son iguales
            }

            else{

                
                avl* arbolpDiosA = pBosque->at(posipDiosA);
                pBosque->erase(pBosque->begin()+posipDiosA);

                cont=0;
                for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
                    
                    if (arbol.buscarDios(*it,*pDiosB) == 1){//encontrar otra vez el arbol en el que está pDiosB
                        posipDiosB = cont;
                        break;
                    }
                    else{
                    }
                    
                }
                
                avl* arbolpDiosB = pBosque->at(posipDiosB);
                pBosque->erase(pBosque->begin()+posipDiosB);

                int cantnodos1 = arbol.cantNodos(arbolpDiosA); 
                int cantnodos2 = arbol.cantNodos(arbolpDiosB);

                if (cantnodos1>cantnodos2){ 
                    arbol.insertAVL(arbolpDiosA,arbolpDiosB);
                    pBosque->push_back(arbolpDiosA);
                }
                else{
                    arbol.insertAVL(arbolpDiosB,arbolpDiosA);
                    pBosque->push_back(arbolpDiosB);
                }

                cout<<"El arbol del dios "<<pDiosA->getName()<<" se ha unido al arbol del dios "<<pDiosB->getName()<<endl;
                
            }
        }
};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaNuevoDios : public Carta{

    public:

        CartaNuevoDios():Carta("NuevoDios"){

        }

        void realizaraccion(Dios* pDiosA, Dios* pDiosB, Cola* pColaDioses, vector<avl*>* pBosque){
            //Los dioses A y B tienen un hijo dios que inicia con cantidad de fieles igual a la suma de ambos dioses
            
            int fielesN = pDiosA->getFieles() + pDiosB->getFieles();

            Dios DiosG = Dios("Generico",fielesN);

            cout<<DiosG.getName()<< " ha nacido de "<<pDiosA->getName() << " y de "<<pDiosB->getName()<<" con "<<DiosG.getFieles()<<" fieles"<<endl;

            pColaDioses->pushDios(&DiosG);

            int posipDiosA = 0;

            int cont = 0;

            avl_tree arbolPadre;

            for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
                
                if (arbolPadre.buscarDios(*it,*pDiosA) == 1){ //encontrar el arbol en el que está pDiosA (padre)
                    posipDiosA = cont;
                    break;
                }
                else{
                }
            }

            avl* arbolpDiosA = pBosque->at(posipDiosA);
            pBosque->erase(pBosque->begin()+posipDiosA);

            arbolpDiosA= arbolPadre.insert(arbolpDiosA,DiosG);

            pBosque->push_back(arbolpDiosA);

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

        void realizaraccion(Dios *pDiosA){
            //El dios A pierde el 10% de sus fieles

            int fielesA = pDiosA->getFieles();

            int muertos = int (fielesA*0.1);

            fielesA = fielesA - muertos;

            pDiosA->setFieles(fielesA);

            cout<<"Han muerto "<<muertos<<" seguidores de "<<pDiosA->getName()<<endl;

            if (fielesA<=0){
                cout<<pDiosA->getName()<< " ha perdido todos sus seguidores"<<endl;
            }
        }
};

#endif