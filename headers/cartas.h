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

        void realizaraccion(Dios* diosA, vector<avl*>bosque){
            //El dios A se separa del árbol de dioses y crea su propio árbol con los dioses con menos fieles que él

            int posiDiosA=0;
            avl_tree arbol = avl_tree();

            int cont = 0;

            for (vector<avl*>::iterator it = bosque.begin() ; cont<bosque.size();it++,cont++){// != bosque.end(); it++){
                
                if (arbol.buscarDios(*it,*diosA) == 1){ //encontrar el arbol en el que está diosA
                    posiDiosA = cont;
                    break;
                }
                else{
                }
                
            }

            avl* arbolp = bosque.at(posiDiosA); //arbol en el que se encuentra el diosA

            if (arbolp->getValue().getName()==diosA->getName() & arbol.cantNodos(arbolp)==1){ //esta en un arbol el solo
                cout<<"El dios"<<diosA->getName()<<" ya se encuentra aislado en un arbol solo"<<endl;
            }

            else{
                
                cout<<"ANTES"<<endl;
                avl* arbolanarquico = arbol.deleteNode(nullptr,arbolp,*diosA); //nuevo arbol
                cout<<"DESPUES"<<endl;
                arbolp = arbol.balance(arbolp); //balanceo
                cout<<"BALANCEO1"<<endl;
                int cant = arbol.cantNodos(arbolanarquico) - 1;
                cout<<"CANT"<<endl;
                //arbolanarquico = arbol.balance(arbolanarquico); //balanceo
                cout<<"BALANCEO2"<<endl;
                arbol.postorder(arbolanarquico);

                //pArboles.insert(arbolanarquico); //insertar el nuevo arbol del dios A

                bosque.push_back(arbolanarquico);

                cout<<"El dios "<<diosA->getName()<<" se ha vuelto anarquico y se ha llevado consigo "<<cant <<" dios(es)"<<endl;
            }
                        

        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaUnion : public Carta{

    public:

        CartaUnion():Carta("Union"){

        }

        void realizaraccion(Dios* diosA, Dios* diosB,vector<avl*> bosque){
            //Si el dios A y el dios B se encuentran en árboles diferentes se vuelven a unir en un solo árbol
            int posiDiosA=0;
            int posiDiosB=0;
            avl_tree arbol = avl_tree();

            int cont = 0;

            for (vector<avl*>::iterator it = bosque.begin() ; cont<bosque.size();it++,cont++){// != bosque.end(); it++){
                
                if (arbol.buscarDios(*it,*diosA) == 1){ //encontrar el arbol en el que está diosA
                    posiDiosA = cont;
                    break;
                }
                else{
                }
                
            }

            cont=0;
            for (vector<avl*>::iterator it = bosque.begin() ; cont<bosque.size();it++,cont++){
                
                if (arbol.buscarDios(*it,*diosB) == 1){//encontrar el arbol en el que está diosB
                    posiDiosB = cont;
                    break;
                }
                else{
                }
                
            }

            if (posiDiosA == posiDiosB){
                cout<<diosA->getName()<<" y "<<diosB->getName()<<" se encuentran en el mismo arbol"<<endl; //arboles son iguales
            }

            else{

                
                avl* arboldiosA = bosque.at(posiDiosA);
                bosque.erase(bosque.begin()+posiDiosA);

                cont=0;
                for (vector<avl*>::iterator it = bosque.begin() ; cont<bosque.size();it++,cont++){
                    
                    if (arbol.buscarDios(*it,*diosB) == 1){//encontrar otra vez el arbol en el que está diosB
                        posiDiosB = cont;
                        break;
                    }
                    else{
                    }
                    
                }
                
                avl* arboldiosB = bosque.at(posiDiosB);
                bosque.erase(bosque.begin()+posiDiosB);

                int cantnodos1 = arbol.cantNodos(arboldiosA); 
                int cantnodos2 = arbol.cantNodos(arboldiosB);

                arbol.postorder(arboldiosA);
                cout<<"/////////////////"<<endl;
                arbol.postorder(arboldiosB);
                
                cout<<endl;

                if (cantnodos1>cantnodos2){ 
                    arbol.insertAVL(arboldiosA,arboldiosB);
                    bosque.push_back(arboldiosA);
                    arbol.postorder(arboldiosA);
                }
                else{
                    arbol.insertAVL(arboldiosB,arboldiosA);
                    bosque.push_back(arboldiosB);
                    arbol.postorder(arboldiosB);
                }

                cout<<"El arbol del dios "<<diosA->getName()<<" se ha unido al arbol del dios "<<diosB->getName()<<endl;
                
            }
        }

};

//-----------------------------------------------------------------------------------------------------------------------------------

class CartaNuevoDios : public Carta{

    public:

        CartaNuevoDios():Carta("NuevoDios"){

        }

        void realizaraccion(Dios* diosA, Dios* diosB, Cola* pColaDioses){
            //Los dioses A y B tienen un hijo dios que inicia con cantidad de fieles igual a la suma de ambos dioses
            
            int fielesN = diosA->getFieles() + diosB->getFieles();

            Dios DiosG = Dios("Generico",fielesN);

            cout<<DiosG.getName()<< " ha nacido de "<<diosA->getName() << " y de "<<diosB->getName()<<endl;

            pColaDioses->pushDios(&DiosG);
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