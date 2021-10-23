#ifndef _COLA_
#define _COLA_ 0

#include <functional>
#include <queue>
#include <vector>
#include "dioses.h"

struct CompareAge {
    bool operator()(Dios & p1, Dios & p2) {
        return p1.getFieles() < p2.getFieles();
    }
};

class Cola{

    public:

    void imprimirCola(priority_queue<Dios, vector<Dios>, CompareAge> pColaPrueba)
    {
        while (!pColaPrueba.empty())
        {
            //cout << pColaPrueba.top().getName()<< endl; //está dando errores
            pColaPrueba.pop();
        }
    }

    //Dios getTwoDioses(){
        //debe devolver dos dioses
    //}

    //Dios getOneDios(){
        //debe retornar un dios
    //}



};


#endif