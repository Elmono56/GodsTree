#include <iostream>
#include <stack>
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <thread>
#include <list>

#include "headers/cartas.h"
#include "headers/dioses.h"
#include "headers/pila.h"
#include "headers/cola.h"
#include "headers/juego.h"
#include "headers/mazo.h"
#include "headers/arbolinicial.h"
#include "headers/json.hpp"
#include "headers/avl.h"

using namespace std;

int main(){

//---------------------------------CREACION PILA MAZO-------------------------------------

    vector<Carta> vectorM = crearmazo();

    Pila<Carta> pilaCartas = Pila<Carta>(vectorM);

    
//---------------------------------CREACION COLA DIOSES-----------------------------------

    Cola colaDioses = Cola();
    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses = colaDioses.getColaDioses(); //por alguna razon si quitamos esto el parar el thread no sirve

//---------------------------------CREACION ARBOL INCIAL-------------------------------------------------

    avl *arbol = crearArbol();
    //vector<avl*> arboles = vector<avl*>();

    avl *bosque[100];

    bosque[0]=arbol;

    //arboles.insert(arbol);

//---------------------------------JUEGO--------------------------------------------------
    
    std::thread first(ejecutar,pilaCartas,colaDioses,bosque);
    std::thread second(finalizar);
    first.join();                
    second.join();

}
