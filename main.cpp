#include <QCoreApplication>
#include <iostream>
#include "grid.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand(time(NULL));
    Grid grid1 = Grid() ;

    grid1.display();


    grid1.fusionRight();
    grid1.display();


//    int number = 2;
//    int proba ;

//    for(int i =0 ; i <100 ; i++) {
//        proba = rand()%5; ;
//         cout <<proba<< endl;
//    }




    return a.exec();
}
