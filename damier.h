#ifndef DAMIER_H
#define DAMIER_H
#include <iostream>
#include <QObject>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class damier : public QObject
{
    Q_OBJECT
public:
    explicit damier(QObject *parent = nullptr);
    ~damier();

    void alloc(int l, int c);
    void free();
    bool possible_left();
    bool possible_right();
    bool possible_up();
    bool possible_down();

    Q_INVOKABLE void init(int value);
    Q_INVOKABLE void set(int x, int y, int value);
    Q_INVOKABLE void random();
    Q_INVOKABLE void gotoleft();
    Q_INVOKABLE void gotoright();
    Q_INVOKABLE void gotoup();
    Q_INVOKABLE void gotodown();
    Q_INVOKABLE void nouvellepartie();
    Q_INVOKABLE bool possible_jouer();

    Q_PROPERTY(QString damier1QML READ readDamier1 NOTIFY damierChanged)
    QString readDamier1();
    Q_PROPERTY(QString damier2QML READ readDamier2 NOTIFY damierChanged)
    QString readDamier2();
    Q_PROPERTY(QString damier3QML READ readDamier3 NOTIFY damierChanged)
    QString readDamier3();
    Q_PROPERTY(QString damier4QML READ readDamier4 NOTIFY damierChanged)
    QString readDamier4();
    Q_PROPERTY(QString damier5QML READ readDamier5 NOTIFY damierChanged)
    QString readDamier5();
    Q_PROPERTY(QString damier6QML READ readDamier6 NOTIFY damierChanged)
    QString readDamier6();
    Q_PROPERTY(QString damier7QML READ readDamier7 NOTIFY damierChanged)
    QString readDamier7();
    Q_PROPERTY(QString damier8QML READ readDamier8 NOTIFY damierChanged)
    QString readDamier8();
    Q_PROPERTY(QString damier9QML READ readDamier9 NOTIFY damierChanged)
    QString readDamier9();
    Q_PROPERTY(QString damier10QML READ readDamier10 NOTIFY damierChanged)
    QString readDamier10();
    Q_PROPERTY(QString damier11QML READ readDamier11 NOTIFY damierChanged)
    QString readDamier11();
    Q_PROPERTY(QString damier12QML READ readDamier12 NOTIFY damierChanged)
    QString readDamier12();
    Q_PROPERTY(QString damier13QML READ readDamier13 NOTIFY damierChanged)
    QString readDamier13();
    Q_PROPERTY(QString damier14QML READ readDamier14 NOTIFY damierChanged)
    QString readDamier14();
    Q_PROPERTY(QString damier15QML READ readDamier15 NOTIFY damierChanged)
    QString readDamier15();
    Q_PROPERTY(QString damier16QML READ readDamier16 NOTIFY damierChanged)
    QString readDamier16();
    Q_PROPERTY(QString scoreQML READ readScore NOTIFY damierChanged)
    QString readScore();
    Q_PROPERTY(int opacityQML READ readFinDePartie NOTIFY damierChanged)
    int readFinDePartie();
    Q_PROPERTY(QString resultatQML READ readResultat NOTIFY damierChanged)
    QString readResultat();


signals:
    void damierChanged();

public slots:

private:
    int L;
    int C;
    int** T;
    int score;
};

#endif // DAMIER_H
