#ifndef GRID_H
#define GRID_H

//#include <QObject>
//#include <QWidget>



class Grid
{
private :

    int nbCell = 4  ;
    int cellTab[4][4] ;

public:
    Grid();
    void display();
};

#endif // GRID_H
