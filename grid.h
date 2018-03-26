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

public:
    Grid();
    int twoOrFour();
    void display();
    void initRandomSpot() ;
    void initValues();

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
