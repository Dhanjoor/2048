#ifndef DAMIER_H
#define DAMIER_H
#include <iostream>
using namespace std;

class damier
{
public:
    damier();
    void Init(int value);
    void Set(int x, int y, int value);
    void Print();
private:
    int D[4][4];
};

#endif // DAMIER_H
