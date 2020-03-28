#include "damier.h"
#include <iostream>
using namespace std;


damier::damier(QObject *parent) : QObject(parent)
{
    alloc(4,4);
    init(5);
}


damier::~damier(){
    if (T != NULL) {
        free();
        T = NULL;
    }
}

void damier::free(){
    for (int i=0; i<L; i++) {
        delete [] T[i];
    }
    delete [] T;
}

void damier::alloc(int l, int c){
    L = l;
    C = c;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
}

void damier::init(int value){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j]=value;
    damierChanged();
}

void damier::set(int x, int y, int value) {
    T[x][y]=value;
    damierChanged();
}

QString damier::readDamier(){
    return QString::number(T[0][0]);
}
