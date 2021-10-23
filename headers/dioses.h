#ifndef _DIOSES_
#define _DIOSES_ 0

#include <iostream>
#include <string>

using namespace std;

class Dios{
    
    private:
        string name;
        int fieles;


    public:

        Dios(string pName, int pFieles){
            name = pName,
            fieles = pFieles;
        }

        void setName(string pName){
            name = pName;
        }

        void setFieles(int pFieles){
            fieles = pFieles;
        }

        string getName(){
            return name;
        }

        int getFieles(){
            return fieles;
        }

};



#endif