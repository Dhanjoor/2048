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
    score = 0;
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

bool damier::possible_left(){
    bool flag=false;
    int i=0;
    while (i<4 and not(flag)){        // on test chaque ligne
        for (int j=0; j<3; j++){       // on verifie qu'une des ligne peut permettre un mouvement:
            if (T[i][j]==0 and T[i][j+1]>0){            // 1: ligne possédant un vide avec une case remplie à sa droite
                flag=true;
            }
        }
        if (not flag){        // 2: ligne ne possédant pas de vide suivie d'une case
            for (int j=0; j<3; j++){
                if (T[i][j]==T[i][j+1] and T[i][j]!=0){        // mais avec une possibilité de fusion
                    flag=true;
                }
            }
        }
        i+=1;
    }
    return flag;
}

bool damier::possible_right(){
    bool flag=false;
    int i=0;
    while (i<4 and not flag){        // on test chaque ligne
        for (int j=0; j<3; j++){       // on verifie qu'une des ligne peut permettre un mouvement:
            if (T[i][j]>0 and T[i][j+1]==0){            // 1: ligne possédant un vide avec une case remplie à sa gauche
                flag=true;
            }
        }
        if (not flag){        // 2: ligne ne possédant pas de vide suivie d'une case
            for (int j=0; j<3; j++){
                if (T[i][j]==T[i][j+1] and T[i][j]!=0){        // mais avec une possibilité de fusion
                    flag=true;
                }
            }
        }
        i+=1;
    }
    return flag;
}

bool damier::possible_up(){
    bool flag=false;
    int j=0;
    while (j<4 and not flag){        // on test chaque colonne
        for (int i=0; i<3; i++){       // on verifie qu'une des colonnes peut permettre un mouvement:
            if (T[i][j]==0 and T[i+1][j]>0){            // 1: colonne possédant un vide avec un case remplie en dessous
                flag=true;
            }
        }
        if (not flag){        // 2: colonne ne possédant pas de vide suivie d'une case
            for (int i=0; i<3; i++){
                if (T[i][j]==T[i+1][j] and T[i][j]!=0){        // mais avec une possibilité de fusion
                    flag=true;
                }
            }
        }
        j+=1;
    }
    return flag;
}

bool damier::possible_down(){
    bool flag=false;
    int j=0;
    while (j<4 and not flag){        // on test chaque colonne
        for (int i=0; i<3; i++){       // on verifie qu'une des colonnes peut permettre un mouvement:
            if (T[i][j]>0 and T[i+1][j]==0){            // 1: colonne possédant un vide avec un case remplie au dessus
                flag=true;
            }
        }
        if (not flag){        // 2: colonne ne possédant pas de vide suivie d'une case
            for (int i=0; i<3; i++){
                if (T[i][j]==T[i+1][j] and T[i][j]!=0){        // mais avec une possibilité de fusion
                    flag=true;
                }
            }
        }
        j+=1;
    }
    return flag;
}

bool damier::possible_jouer(){                   //test si il reste au moins une possibilité pour jouer
    return (possible_up() or possible_down() or possible_left() or possible_right());
}

void damier::gotoleft(){
    if (possible_left()){
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
                    score = score + T[i][j];
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

}

void damier::gotoright(){
    if (possible_right()){
        for (int i=0; i<4; i++){    //on navigue ligne par ligne
            for (int j=0; j<3; j++){          //on navigue de gauche à droite dans la ligne
                if (T[i][j+1]==0){                //si une case vide
                    for (int k=j+1; k>0;k--){
                        set(i,k,T[i][k-1]);      //on décale toute la ligne vers la droite
                    }
                    set(i,0,0);                   //puis on retrouve un zéro en début de ligne
                }
            }
            for (int j=3; j>0; j--){
                if (T[i][j]==T[i][j-1]){     //si 2 cases égales cote à cote
                    set(i,j,2*T[i][j]);      //on "fusionne" les deux cases
                    set(i,j-1,0);
                    score = score + T[i][j];
                }
            }
            for (int j=0; j<3; j++){
                if (T[i][j+1]==0){                //puis on redécalle toutes
                    for (int k=j+1; k>0;k--){     //les cases vers la droite
                        set(i,k,T[i][k-1]);       //au cas où un trou
                    }                              //serait apparu
                    set(i,0,0);
                }
            }
        }
        //damierChanged();
        random();    //enfin on fait réapparaitre un 2
    }
}


void damier::gotoup(){
   if (possible_up()){
       for (int j=0; j<4; j++){    //on navigue colonne par colonne
           for (int i=3; i>0; i--){          //on navigue de bas en haut dans la colonne
               if (T[i-1][j]==0){                //si une case vide
                   for (int k=i-1; k<3;k++){
                       set(k,j,T[k+1][j]);      //on décale toute la ligne vers le haut
                   }
                   set(3,j,0);                   //puis on retrouve un zéro en fin de colonne
               }
           }
           for (int i=0; i<3; i++){
               if (T[i][j]==T[i+1][j]){     //si 2 cases égales cote à cote
                   set(i,j,2*T[i][j]);      //on "fusionne" les deux cases
                   set(i+1,j,0);
                   score = score + T[i][j];
               }
           }
           for (int i=3; i>0; i--){
               if (T[i-1][j]==0){                //puis on redécalle toutes
                   for (int k=i-1; k<3;k++){     //les cases vers le haut
                       set(k,j,T[k+1][j]);       //au cas où un trou
                   }                              //serait apparu
                   set(3,j,0);
               }
           }
       }
       //damierChanged();
       random();    //enfin on fait réapparaitre un 2
   }
}

void damier::gotodown(){
    if (possible_down()){
        for (int j=0; j<4; j++){    //on navigue colonne par colonne
            for (int i=0; i<3; i++){          //on navigue de haut en bas dans la colonne
                if (T[i+1][j]==0){                //si une case vide
                    for (int k=i+1; k>0;k--){
                        set(k,j,T[k-1][j]);      //on décale toute la ligne vers le bas
                    }
                    set(0,j,0);                   //puis on retrouve un zéro en début de colonne
                }
            }
            for (int i=3; i>0; i--){
                if (T[i][j]==T[i-1][j]){     //si 2 cases égales cote à cote
                    set(i,j,2*T[i][j]);      //on "fusionne" les deux cases
                    set(i-1,j,0);
                    score = score + T[i][j];
                }
            }
            for (int i=0; i<3; i++){
                if (T[i+1][j]==0){                //puis on redécalle toutes
                    for (int k=i+1; k>0;k--){     //les cases vers le bas
                        set(k,j,T[k-1][j]);       //au cas où un trou
                    }                              //serait apparu
                    set(0,j,0);
                }
            }
        }
        //damierChanged();
        random();    //enfin on fait réapparaitre un 2
    }
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

QString damier::readScore(){
    return QString::number(score);
}
