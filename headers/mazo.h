#ifndef _MAZO_
#define _MAZO_ 0

#include <string>
#include <vector>
#include "cartas.h"

vector<Carta> crearmazo(){

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

    return vectorM;
}


#endif