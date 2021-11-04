
#ifndef _JUEGO_
#define _JUEGO_ 0

#include "cartas.h"
#include "dioses.h"
#include "pila.h"
#include "cola.h"
#include "avl.h"

#include <windows.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <iostream>

#define KEY_X 120

bool juego = true;

void ejecutar(Pila<Carta> pMazoCartas, Cola pColaDioses,vector<avl*>* pBosque){ 

    while(juego & pColaDioses.getPQSize()!=0){

        Carta pSiguiente = pMazoCartas.getCarta(); 
        
        if(pSiguiente.getTipo() == "Milagro"){

            CartaMilagro jugada = CartaMilagro();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;

            jugada.realizaraccion(&diosA,&diosB);

            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);

        }
        else if (pSiguiente.getTipo()=="Traicion"){

            CartaTraicion jugada = CartaTraicion();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            jugada.realizaraccion(&diosA,&diosB);
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);
        }

        else if (pSiguiente.getTipo()=="Anarquia"){

            CartaAnarquia jugada = CartaAnarquia();

            Dios diosA = pColaDioses.getDios();

            cout << "----------------------------" << endl;

            cout << " ANARQUIA" << endl;

            jugada.realizaraccion(&diosA,pBosque);
            
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
        }

        else if (pSiguiente.getTipo()=="Union"){

            CartaUnion jugada = CartaUnion();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            
            jugada.realizaraccion(&diosA, &diosB, pBosque);

            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);
        }

        else if (pSiguiente.getTipo()=="NuevoDios"){

            CartaNuevoDios jugada = CartaNuevoDios();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            jugada.realizaraccion(&diosA,&diosB,&pColaDioses,pBosque);
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);
        }

        else if (pSiguiente.getTipo()=="Retorno"){

            CartaRetorno jugada = CartaRetorno();
            
            cout << "----------------------------" << endl;
            cout << "             RETORNO        " << endl;
            jugada.realizaraccion(&pMazoCartas);
            cout << "----------------------------" << endl;
        }

        else if (pSiguiente.getTipo()=="Muerte"){

            CartaMuerte jugada = CartaMuerte();

            Dios diosA = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            jugada.realizaraccion(&diosA);
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
        }
        else{
        }
        Sleep(3000);
    }
}

void finalizar(vector<avl*>* pBosque){
    
    char key = getch();
    int value = key;

    if(value == KEY_X){

        juego = false;

        avl_tree arbol;

        int cont = 0;

        for (vector<avl*>::iterator it = pBosque->begin() ; cont<pBosque->size();it++,cont++){
            
            cout << "Postorden arbol de dioses: " << endl;
            
            arbol.postorder(*it);   
        }
        cout<<endl;
        cout << "Juego finalizado" << endl;
    }
};

#endif