#ifndef _DIOSES_
#define _DIOSES_ 0

#include <iostream>
#include <string>

using namespace std;

class Dios:{
    
    private:
        String name;
        int fieles;


    public:

        void setName(String pName){
            this.name = pName;
        }

        void setFieles(int pFieles){
            this.fieles = pFieles;
        }

        String getName(){
            return this.name;
        }

        int getFieles(){
            return this.fieles;
        }




}



#endif