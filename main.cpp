#include <QCoreApplication>
#include <iostream>
#include "grid.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand(time(NULL));
    Grid grid1 = Grid() ;

    cout <<"*****  Initialisation   *****"<< endl;
    grid1.display();

    cout <<"*****  fusionRight   *****"<< endl;
    grid1.fusionRight();
    grid1.display();
    cout <<"*****   fusionLeft   ****"<< endl;
    grid1.fusionLeft();
    grid1.display();
    cout <<"*****   fusionDown   ****"<< endl;
    grid1.fusionDown();
    grid1.display();
    cout <<"******  fusionUp   *****"<< endl;
    grid1.fusionUp();
    grid1.display();

    grid1.checkDeath();

//    Grid *gridTest(0);
//    gridTest = new Grid(grid1) ;
//    gridTest->display();
//    delete gridTest ;


//    Grid grid2 = Grid(grid1);
//    cout <<"******  Copie   *****"<< endl;
//    grid2.display();

//    int number = 2;
//    int proba ;

//    for(int i =0 ; i <100 ; i++) {
//        proba = rand()%5; ;
//         cout <<proba<< endl;
//    }




    return a.exec();
}
