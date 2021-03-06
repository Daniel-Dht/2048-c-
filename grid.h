#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QList>
#include <QString>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QInputDialog>

class Grid : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> changement_couleur READ readCouleur NOTIFY cptChanged)
    Q_PROPERTY(QList<QString> changement_valeur READ readValeur NOTIFY cptChanged)

private :

    int nbCell = 4  ;
    int cellTab[4][4] ;

    bool cellShiftedDown = false;
    bool cellShiftedUp = false;
    bool cellShiftedLeft = false;
    bool cellShiftedRight = false;

    int twoOrFour();
    void initValues();
    void initRandomSpot() ;

public:

    explicit Grid(QObject *parent= nullptr);
    Q_INVOKABLE void changement(QString vecteur);
    QList<QString> readCouleur();
    QList<int> readGrid();
    Grid( const Grid &grid );

    void display();
    void checkDeath();

    QList<int> fusionRight();
    void fusionRight(bool testDeath);

    QList<int> fusionLeft();
    void fusionLeft( bool testDeath);

    QList<int> fusionUp();
    void fusionUp(   bool testDeath);
    void fusionDown( bool testDeath);

    void shiftRight();
    void shiftLeft();
    void shiftUp();
    void shiftDown();
};

#endif //
