#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "Dioses.h"
#include "Cola.h"


int main(){

    Cola colaDeDioses;

    Dios Maluma("Maluma",10);
    Dios Anuel("Anuel",50);
    Dios Javier("Javier", 15);
    Dios Enrique("Enrique",40);
    Dios Jeremy("Jeremy",5);


    priority_queue<int> colaFieles;
    queue<Dios> colaDioses;
    Dios dioses[] = {Maluma, Anuel, Javier, Enrique, Jeremy};


    colaDeDioses.crearPrioridad(dioses, &colaFieles);
    colaDeDioses.pushDioses(dioses, &colaFieles, &colaDioses);
    colaDeDioses.imprimirCola(&colaDioses);



}