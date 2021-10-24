
#ifndef _JUEGO_
#define _JUEGO_ 0

#include "cartas.h"
#include "dioses.h"
#include "pila.h"
#include "cola.h"

#include <windows.h>
#include <time.h>
#include <iostream>

void ejecutar(Pila pMazoCartas, priority_queue<Dios, vector<Dios>, CompareAge> *pMazoDioses){

    while(!pMazoDioses->empty()){

        Carta pSiguiente = pMazoCartas.getCarta();
        if(pSiguiente.getTipo() == "Muerte"){
            Dios A = pMazoDioses->top();
            pMazoDioses->pop();

            cout << "----------------------------" << endl;
            cout << A.getFieles() << " / " << A.getName() << endl;
            pSiguiente.realizaraccion(&A,&A);
            cout << A.getFieles() << " / " << A.getName() << endl;
            cout << "----------------------------" << endl;

        }else{

            Dios A = pMazoDioses->top();
            pMazoDioses->pop();
            Dios B = pMazoDioses->top();
            pMazoDioses->pop();

            cout << "----------------------------" << endl;
            cout << A.getFieles() << " / " << A.getName() << "---------" << B.getFieles() << " / " << B.getName() << endl;
            pSiguiente.realizaraccion(&A,&B);
            cout << A.getFieles() << " / " << A.getName() << "---------" << B.getFieles() << " / " << B.getName() << endl;
            cout << "----------------------------" << endl;
        }

        Sleep(3000);    
        
    }
}


#endif