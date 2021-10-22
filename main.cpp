#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "Dioses.h"


int main(){

    Dios Maluma("Maluma",10);
    Dios Anuel("Anuel",50);
    Dios Javier("Javier", 15);
    Dios Enrique("Enrique",40);
    Dios Jeremy("Jeremy",5);
    Dios Ana("Ana",5);

    priority_queue<int> colaFieles;
    queue<Dios> colaDioses;
    Dios dioses[] = {Maluma, Anuel, Javier, Enrique, Jeremy, Ana};

    for( Dios n : dioses){
        colaFieles.push(n.getFieles());
    }

    while(!colaFieles.empty()){

        for (int i = 0; i < 6; i++)
        {
            if(dioses[i].getFieles() == colaFieles.top()){
                colaDioses.push(dioses[i]);
            }
        } 
        colaFieles.pop();
    }

    while(!colaDioses.empty()){
        cout << colaDioses.front().getName() << endl;
        colaDioses.pop();
    }
}