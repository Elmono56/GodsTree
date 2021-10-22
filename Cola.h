#ifndef _COLA_
#define _COLA_ 0

#include "Dioses.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

class Cola{

    public:

    void crearPrioridad(Dios pDioses[], priority_queue<int> *pColaFieles)
    {
        for (int i = 0; i < 5; i++)
        {
            pColaFieles->push(pDioses[i].getFieles());
        }
    }

    void pushDioses(Dios pDioses[], priority_queue<int> *pColaFieles, queue<Dios> *pColaDioses)
    {
        while(!pColaFieles->empty())
        {
            for (int i = 0; i < 5; i++)
            {
                if(pDioses[i].getFieles() == pColaFieles->top())
                {
                    pColaDioses->push(pDioses[i]);
                }
            }
            pColaFieles->pop();
        }
    }

    void imprimirCola(queue<Dios> *pColaDioses)
    {
        while(!pColaDioses->empty())
        {
            cout<< pColaDioses->front().getName() << endl;
            pColaDioses->pop();
        }
    }
};

#endif
