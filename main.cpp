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
//    cout <<"*****  fusionRight   *****"<< endl;
//    grid1.fusionRight(true);
//    grid1.display();
//    cout <<"*****   fusionLeft   ****"<< endl;
//    grid1.fusionLeft(true);
//    grid1.display();
//    cout <<"*****   fusionDown   ****"<< endl;
//    grid1.fusionDown(true);
//    grid1.display();
//    cout <<"******  fusionUp   *****"<< endl;
//    grid1.fusionUp(true);
//    grid1.display();

    int i = -1 ;
    while(i!=2) {
        cin>>i ;
        if(i==4) {
            cout <<"*****   fusionLeft   ****"<< endl;
             grid1.fusionLeft(true);
             grid1.display();
        } else if(i==8) {
            cout <<"******  fusionUp   *****"<< endl;
            grid1.fusionUp(true);
            grid1.display();
        } else if(i==6) {
            cout <<"*****  fusionRight   *****"<< endl;
            grid1.fusionRight(true);
            grid1.display();
        } else if(i==5) {
            cout <<"*****   fusionDown   ****"<< endl;
            grid1.fusionDown(true);
            grid1.display();
        }

    }

    return a.exec();
}
