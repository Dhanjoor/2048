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
    n=0;
    T = new int*[L];
    for(int i=0; i<L; i++)
        T[i] = new int[C];
    mem = new int*[1000];
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

void damier::sauve(){
    mem[n]=new int [17];
    for (int i=0; i<16; i++)
        mem[n][i]=T[i%4][i/4];
    mem[n][17]=score;
}

void damier::annule(){
    if (n>0){
        n-=1;
        score=0;
        for (int i=0; i<16; i++){
            T[i%4][i/4]=mem[n][i];
        }
    score=mem[n][17];
    damierChanged();
    }
}

void damier::random(){        //rajoute un 2 ou un 4 sur une case vide
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
        cpt=rand()%10;
        if (cpt<9){
            set(parcours/4, parcours%4, 2);
        }
        else {
            set(parcours/4, parcours%4, 4);
        }
    }
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
        random();    //enfin on fait réapparaitre un 2
        n+=1;
        sauve();
        damierChanged();
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
        random();    //enfin on fait réapparaitre un 2
        n+=1;
        sauve();
        damierChanged();
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
       random();    //enfin on fait réapparaitre un 2
       n+=1;
       sauve();
       damierChanged();
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
        random();    //enfin on fait réapparaitre un 2
        n+=1;
        sauve();
        damierChanged();
    }
}

string damier::color(int v){
    if (v==2) return "#94d8db";
    if (v==4) return "#00B3BB";
    if (v==8) return "#00BB63";
    if (v==16) return "#6ADE28";
    if (v==32) return "#BBE61C";
    if (v==64) return "#ecf613";
    if (v==128) return "#f6bc13";
    if (v==256) return "#e37814";
    if (v==512) return "#d82700";
    if (v==1024) return "#d80058";
    if (v==2048) return "#d800c1";
    if (v==4096) return "#7300d8";
    if (v==8192) return "#5200d8";
    if (v==16384) return "#2100d8";
    if (v==65536) return "#020097";
    if (v==131072) return "#36384b";
    else return "#ffffff";              //cas valeur=0 et erreurs éventuelles
}

void damier::nouvellepartie(){
    init(0);
    score = 0;
    n=0;
    random();
    random();
    sauve();
}

int damier::readFinDePartie(){
    if (possible_jouer()){
        return 0;
    }
    else {
        return 1;
    }
}

QString damier::readDamier1(){
    if (T[0][0]==0){
        return " ";
    }
    else {
        return QString::number(T[0][0]);
    }
}

QString damier::readDamier2(){
    if (T[0][1]==0){
        return " ";
    }
    else {
        return QString::number(T[0][1]);
    }
}
QString damier::readDamier3(){
    if (T[0][2]==0){
        return " ";
    }
    else {
        return QString::number(T[0][2]);
    }
}
QString damier::readDamier4(){
    if (T[0][3]==0){
        return " ";
    }
    else {
        return QString::number(T[0][3]);
    }
}
QString damier::readDamier5(){
    if (T[1][0]==0){
        return " ";
    }
    else {
        return QString::number(T[1][0]);
    }
}
QString damier::readDamier6(){
    if (T[1][1]==0){
        return " ";
    }
    else {
        return QString::number(T[1][1]);
    }
}
QString damier::readDamier7(){
    if (T[1][2]==0){
        return " ";
    }
    else {
        return QString::number(T[1][2]);
    }
}
QString damier::readDamier8(){
    if (T[1][3]==0){
        return " ";
    }
    else {
        return QString::number(T[1][3]);
    }
}
QString damier::readDamier9(){
    if (T[2][0]==0){
        return " ";
    }
    else {
        return QString::number(T[2][0]);
    }
}
QString damier::readDamier10(){
    if (T[2][1]==0){
        return " ";
    }
    else {
        return QString::number(T[2][1]);
    }
}
QString damier::readDamier11(){
    if (T[2][2]==0){
        return " ";
    }
    else {
        return QString::number(T[2][2]);
    }
}
QString damier::readDamier12(){
    if (T[2][3]==0){
        return " ";
    }
    else {
        return QString::number(T[2][3]);
    }
}
QString damier::readDamier13(){
    if (T[3][0]==0){
        return " ";
    }
    else {
        return QString::number(T[3][0]);
    }
}
QString damier::readDamier14(){
    if (T[3][1]==0){
        return " ";
    }
    else {
        return QString::number(T[3][1]);
    }
}
QString damier::readDamier15(){
    if (T[3][2]==0){
        return " ";
    }
    else {
        return QString::number(T[3][2]);
    }
}
QString damier::readDamier16(){
    if (T[3][3]==0){
        return " ";
    }
    else {
        return QString::number(T[3][3]);
    }
}

QString damier::readScore(){
    return QString::number(score);
}

QString damier::readTour(){
    return QString::number(n);
}

QString damier::readDamier1col(){
    return QString::fromStdString(color(T[0][0]));
}
QString damier::readDamier2col(){
    return QString::fromStdString(color(T[0][1]));
}
QString damier::readDamier3col(){
    return QString::fromStdString(color(T[0][2]));
}
QString damier::readDamier4col(){
    return QString::fromStdString(color(T[0][3]));
}
QString damier::readDamier5col(){
    return QString::fromStdString(color(T[1][0]));
}
QString damier::readDamier6col(){
    return QString::fromStdString(color(T[1][1]));
}
QString damier::readDamier7col(){
    return QString::fromStdString(color(T[1][2]));
}
QString damier::readDamier8col(){
    return QString::fromStdString(color(T[1][3]));
}
QString damier::readDamier9col(){
    return QString::fromStdString(color(T[2][0]));
}
QString damier::readDamier10col(){
    return QString::fromStdString(color(T[2][1]));
}
QString damier::readDamier11col(){
    return QString::fromStdString(color(T[2][2]));
}
QString damier::readDamier12col(){
    return QString::fromStdString(color(T[2][3]));
}
QString damier::readDamier13col(){
    return QString::fromStdString(color(T[3][0]));
}
QString damier::readDamier14col(){
    return QString::fromStdString(color(T[3][1]));
}
QString damier::readDamier15col(){
    return QString::fromStdString(color(T[3][2]));
}
QString damier::readDamier16col(){
    return QString::fromStdString(color(T[3][3]));
}

QString damier::readResultat(){
    if (score<5000){
        return "Dommage...";
    }
    if (score>=5000 && score<1000){
        return "Pas mal";
    }
    if (score>=10000 && score<20000){
        return "Bien joué !";
    }
    if (score>=20000 && score <50000){
        return "Félicitations !!!";
    }
    else {
        return "Exceptionnel !!!!!";
    }
}
