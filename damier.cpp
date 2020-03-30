#include "damier.h"
#include <iostream>
using namespace std;


damier::damier(QObject *parent) : QObject(parent)
{
    alloc(4,4);
    init(0);
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

void damier::random(){
    int cpt=0;
    for (int i=0; i<L; i++){
        for (int j=0; j<C; j++){
            if (T[i][j]==0){
                cpt++;
            }
        }
    }
    if (cpt!=0){
        int nbcase;
        srand(time(NULL));
        nbcase=rand()%cpt;
        int parcours=0;
        int condition=0;
        while ((T[parcours/4][parcours%4]!=0)||(condition<nbcase)){
            if (T[parcours/4][parcours%4]==0){
                condition++;
            }
            parcours++;
        }
        set(parcours/4, parcours%4, 2);
    }
    damierChanged();
}

void damier::gotoleft(){
    for (int i=0; i<4; i++){    //on navigue ligne par ligne
        for (int j=3; j>0; j--){          //on navigue de droite à gauche dans la ligne
            if (T[i][j-1]==0){                //si une case vide
                for (int k=j-1; k<3;k++){
                    set(i,k,T[i][k+1]);      //on décale toute la ligne vers la gauche
                }
                set(i,3,0);                   //puis on retrouve un zéro en fin de ligne
            }
        }
        for (int j=0; j<3; j++){
            if (T[i][j]==T[i][j+1]){     //si 2 cases égales cote à cote
                set(i,j,2*T[i][j]);      //on "fusionne" les deux cases
                set(i,j+1,0);
            }
        }
        for (int j=3; j>0; j--){
            if (T[i][j-1]==0){                //puis on redécalle toutes
                for (int k=j-1; k<3;k++){     //les cases vers la gauche
                    set(i,k,T[i][k+1]);       //au cas où un trou
                }                              //serait apparu
                set(i,3,0);
            }
        }
    }
    //damierChanged();
    random();    //enfin on fait réapparaitre un 2
}


QString damier::readDamier1(){
    return QString::number(T[0][0]);
}

QString damier::readDamier2(){
    return QString::number(T[0][1]);
}
QString damier::readDamier3(){
    return QString::number(T[0][2]);
}
QString damier::readDamier4(){
    return QString::number(T[0][3]);
}
QString damier::readDamier5(){
    return QString::number(T[1][0]);
}
QString damier::readDamier6(){
    return QString::number(T[1][1]);
}
QString damier::readDamier7(){
    return QString::number(T[1][2]);
}
QString damier::readDamier8(){
    return QString::number(T[1][3]);
}
QString damier::readDamier9(){
    return QString::number(T[2][0]);
}
QString damier::readDamier10(){
    return QString::number(T[2][1]);
}
QString damier::readDamier11(){
    return QString::number(T[2][2]);
}
QString damier::readDamier12(){
    return QString::number(T[2][3]);
}
QString damier::readDamier13(){
    return QString::number(T[3][0]);
}
QString damier::readDamier14(){
    return QString::number(T[3][1]);
}
QString damier::readDamier15(){
    return QString::number(T[3][2]);
}
QString damier::readDamier16(){
    return QString::number(T[3][3]);
}
