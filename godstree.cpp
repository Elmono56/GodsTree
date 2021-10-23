#include <iostream>
#include <stack>
#include <string>
#include <functional>
#include <queue>
#include <vector>

#include "headers/cartas.h"
#include "headers/dioses.h"
#include "headers/pila.h"
#include "headers/cola.h"
//#include "headers/jsoncpp.h"

using namespace std;

int main(){

//---------------------------------CREACION MAZO-------------------------------------
    Pila mazo = Pila();

    cout<<mazo.getSize()<<endl; //ver el tamaño del mazo

//---------------------------------CREACION COLA DIOSES-------------------------------------
    Cola colaDioses;

    Dios Thor = Dios("Thor",100);
    Dios Loki = Dios("Loki",500);
    Dios Hela = Dios("Hela", 150);
    Dios Zeus = Dios("Zeus",400);
    Dios Jesus = Dios("Jesus",50);

    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses;

    colaPrioridadDioses.push(Thor);
    colaPrioridadDioses.push(Loki);
    colaPrioridadDioses.push(Hela);
    colaPrioridadDioses.push(Zeus);
    colaPrioridadDioses.push(Jesus);

    //colaDioses.imprimirCola(colaPrioridadDioses);

//---------------------------------JUEGO-------------------------------------

    Carta siguiente = mazo.getCarta();

    siguiente.realizaraccion(Thor,Loki);
    siguiente.realizaraccion(Zeus,Jesus);
}
