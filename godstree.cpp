#include <iostream>
#include <stack>
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <thread>

#include "headers/cartas.h"
#include "headers/dioses.h"
#include "headers/pila.h"
#include "headers/cola.h"
#include "headers/juego.h"

using namespace std;

int main(){

//---------------------------------CREACION PILA MAZO-------------------------------------

    vector<Carta> vectorM;

    for (int i = 0; i<5;i++){
        vectorM.push_back(CartaMilagro()); //5 cartas de MILAGRO
    }

    for (int i = 0; i<4;i++){
        vectorM.push_back(CartaTraicion()); //5 cartas de TRAICION
    }

    for (int i = 0; i<7;i++){
        vectorM.push_back(CartaAnarquia()); //5 cartas de ANARQUIA
    }

    for (int i = 0; i<4;i++){
        vectorM.push_back(CartaUnion()); //5 cartas de UNION
    }

    for (int i = 0; i<4;i++){
        vectorM.push_back(CartaNuevoDios()); //5 cartas de NUEVO DIOS
    }

    for (int i = 0; i<6;i++){
        vectorM.push_back(CartaRetorno()); //5 cartas de RETORNO
    }

    for (int i = 0; i<10;i++){
        vectorM.push_back(CartaMuerte()); //5 cartas de MUERTE
    }

    Pila<Carta> pilaCartas = Pila<Carta>(vectorM);

    

//---------------------------------CREACION COLA DIOSES-----------------------------------

    Cola colaDioses = Cola();
    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses = colaDioses.getColaDioses(); //por alguna razon si quitamos esto el parar el thread no sirve

//---------------------------------JUEGO--------------------------------------------------

    //ejecutar(pilaCartas,colaDioses);
    //std::thread displaytd(displayAction, std::ref(td));

    
    std::thread first(ejecutar,pilaCartas,colaDioses);
    std::thread second(finalizar);
    first.join();                
    second.join();

}
