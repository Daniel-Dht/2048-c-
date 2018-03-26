#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    for(int i=0; i< nbCell ; i++)
    {
        for(int j=0; j< nbCell; j++)
        {
           cellTab[i][j] = 0 ;
        }
    }
}

void Grid::display() //affiche sous forme matricielle
{
    for(int i=0; i< nbCell; i++)
    {
        cout  <<"|"<< " "  ;
        for(int j=0; j< nbCell; j++)
        {
            cout  << cellTab[i][j]<<" "  ;
        }
        cout <<"|"<< endl;
    }
}
