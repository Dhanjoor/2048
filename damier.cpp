#include "damier.h"
#include <iostream>
using namespace std;


damier::damier()
{

}

void damier::Init(int value){
    for(int i=0; i<4; i++)
        for(int j=0; j<5; j++)
            D[i][j]=value;
}


void damier::Set(int x, int y, int value) {
    D[x][y]=value;
}

void damier::Print(){
    for(int i=0; i<4; i++) {
        cout << endl;
        for(int j=0; j<5; j++){
            cout << D[i][j] << ", ";
        }
    }
}
