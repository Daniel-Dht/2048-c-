#include <QCoreApplication>
#include <iostream>
#include "grid.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Grid grid1 = Grid() ;
    grid1.display();

    return a.exec();
}
