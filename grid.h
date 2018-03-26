#ifndef GRID_H
#define GRID_H

//#include <QObject>
//#include <QWidget>



class Grid
{
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

    Grid();
    Grid( const Grid &grid );

    void display();
    void checkDeath();

    void fusionRight();
    void fusionLeft();
    void fusionUp();
    void fusionDown();

    void shiftRight();
    void shiftLeft();
    void shiftUp();
    void shiftDown();
};

#endif // GRID_H
