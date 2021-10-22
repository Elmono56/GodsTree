#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "Dioses.h"
#include "Cola.h"

int main(){

    Cola colaDioses;

    Dios Maluma("Maluma",10);
    Dios Anuel("Anuel",50);
    Dios Javier("Javier", 15);
    Dios Enrique("Enrique",40);
    Dios Jeremy("Jeremy",5);

    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses;

    colaPrioridadDioses.push(Maluma);
    colaPrioridadDioses.push(Anuel);
    colaPrioridadDioses.push(Javier);
    colaPrioridadDioses.push(Enrique);
    colaPrioridadDioses.push(Jeremy);

    colaDioses.imprimirCola(colaPrioridadDioses);
}