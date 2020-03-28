#ifndef DAMIER_H
#define DAMIER_H
#include <iostream>
#include <QObject>
using namespace std;

class damier : public QObject
{
    Q_OBJECT
public:
    explicit damier(QObject *parent = nullptr);
    ~damier();

    void alloc(int l, int c);
    void free();

    Q_INVOKABLE void init(int value);
    Q_INVOKABLE void set(int x, int y, int value);
    Q_PROPERTY(QString d1QML READ readDamier NOTIFY damierChanged)
    QString readDamier();

signals:
    void damierChanged();

public slots:

private:
    int L;
    int C;
    int** T;
};

#endif // DAMIER_H
