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

    Pila mazo = Pila();

//---------------------------------CREACION COLA DIOSES------------------------------

    Cola colaDioses = Cola();
    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses = colaDioses.getColaDioses();

//---------------------------------JUEGO-----------------------------------

//ejecutar(mazo, &colaPrioridadDioses);

std::thread first(ejecutar,mazo,&colaPrioridadDioses);
std::thread second(finalizar);
first.join();                
second.join();
}
