#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    this->initValues();
    this->initRandomSpot();
    this->initRandomSpot();
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

void Grid::initValues() {
    for(int i=0; i< nbCell ; i++)
    {
        for(int j=0; j< nbCell; j++)
        {
           cellTab[i][j] = 0 ;
        }
    }
}

int Grid::twoOrFour() {
    if(rand()%1000 > 700) {
        return 4 ;
    } else {
        return 2 ;
    }
}

void Grid::initRandomSpot(){
  bool go =true ;
  while(go) {
    int i = int(rand()%5); // nombre entre 0 et 4 inclu
    int j = int(rand()%5);
    if(cellTab[j][i] == 0 ) {
      cellTab[j][i] = twoOrFour();
      go = false ;
    }
  }
}

void Grid::shiftRight() {
    // /supprime tous les 0 de la lignes et colle tout à droite
    for (int i=0; i<nbCell; i++) {
       for(int h = nbCell-2 ; h >= 0 ; h--) { // processus pour une ligne :
         int j = h ;
         if( cellTab[i][j] != 0) { // si on est sur un 0 ça ne sert à rien de le décaler vers les autres 0...
           while( j!=nbCell-1 && cellTab[i][j+1] == 0  ) { // la condition j!=n-1 doit etre placée avant la suivante care dans ce cas la grid[i][j+1] n'est pas définie (grid[i][n])

               if(!cellShiftedRight) cellShiftedRight = true ;
//             gameOverRight = false ;

             cellTab[i][j+1] = cellTab[i][j] ;   // on fait avancer les blocs vers la droite
             cellTab[i][j] = 0;
             j ++ ;

           }
         }
       }
    }
}

void Grid::fusionRight() {
// Effectue un shift, fusionne les couples les plus à droites 2 par 2, et refait un shift.
// On rajoute un 2 ou un 4 si on a pas été bloqué,  cad si fusion ou shift il y a eu.

  this->shiftRight() ;

  for (int i=0; i<nbCell; i++) {
    for(int h = nbCell-2 ; h >= 0 ; h--) {

      int j = h;
      if(cellTab[i][j+1] == cellTab[i][j] && cellTab[i][j] !=0 ) {   // tout simple

        if(!cellShiftedRight) cellShiftedRight = true ;
//       else gameOverRight = false ;

       cellTab[i][j+1]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }
  this->shiftRight();
  if(cellShiftedRight ) {
      initRandomSpot();
      cellShiftedRight = false ;
  }
  //if (countRight !=0 && !testDeath ) initRandomSpot(grid);   // si ni shift ni fusion (et si test le gameOver), on ne fait pas appraraitre de spot

}

void Grid::shiftLeft() {

    for (int i=0; i<nbCell; i++) {
       for(int h = 1 ; h <= nbCell-1 ; h++) {
         int j = h ;
         if( cellTab[i][j] != 0) {
           while( j!=0 && cellTab[i][j-1] ==0  ) {
            if(!cellShiftedLeft) cellShiftedLeft = true ;
//             gameOverLeft = false ;

             cellTab[i][j-1] = cellTab[i][j] ;
             cellTab[i][j] = 0;
             j -- ;
           }
         }
       }
    }
}

void Grid::fusionLeft() {
  shiftLeft();
  for (int i=0; i<nbCell; i++) {
    for(int h = 1 ; h <= nbCell-1 ; h++) {

      int j = h;
      if(cellTab[i][j-1] == cellTab[i][j] && cellTab[i][j] !=0  ) {

        if(!cellShiftedLeft) cellShiftedLeft = true ;
//       gameOverLeft = false ;

       cellTab[i][j-1]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftLeft();
  if( cellShiftedLeft ){
      initRandomSpot();
      cellShiftedLeft = false;
  }
  //if (countLeft !=0 && !testDeath ) initRandomSpot(grid); // si 0 fusion, on ne fait pas appraraitre de spot
}

void Grid::shiftUp() {

    for (int j=0; j<nbCell; j++) {
       for(int h = 1 ; h <= nbCell-1 ; h++) {
         int i = h ;
         if( cellTab[i][j] != 0) {
           while( i!=0 && cellTab[i-1][j] ==0  ) {
             if( !cellShiftedUp) cellShiftedUp = true;
             //gameOverUp = false ;

             cellTab[i-1][j] = cellTab[i][j] ;
             cellTab[i][j] = 0;
             i -- ;
           }
         }
       }
    }
}

void Grid::fusionUp() {
  shiftUp();
  for (int j=0; j<nbCell; j++) {
    for(int h = 1 ; h <= nbCell-1 ; h++) {

      int i = h;
      if(cellTab[i-1][j] == cellTab[i][j] && cellTab[i][j] !=0  ) {

       if( !cellShiftedUp) cellShiftedUp = true;
       //gameOverUp = false ;

       cellTab[i-1][j]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftUp();
  if(cellShiftedUp) {
      initRandomSpot();
      cellShiftedUp = false;
  }
  //if (countUp !=0 && !testDeath) initRandomSpot(grid); // si 0 fusion, on ne fait pas appraraitre de spot
}

void Grid::shiftDown() {

    for (int j=0; j<nbCell; j++) {
       for(int h = nbCell-2 ; h >= 0 ; h--) {
         int i = h ;
         if( cellTab[i][j] != 0) {
           while( i!=nbCell-1 && cellTab[i+1][j] ==0  ) {

             if(!cellShiftedDown) cellShiftedDown = true;
             //gameOverDown = false ;

             cellTab[i+1][j] = cellTab[i][j] ;
             cellTab[i][j] = 0;
             i ++ ;
           }
         }
       }
    }
}

void Grid::fusionDown() {
  shiftDown();
  for (int j=0; j<nbCell; j++) {
    for(int h = nbCell-2 ; h >= 0 ; h--) {

      int i = h;
      if(cellTab[i+1][j] == cellTab[i][j] && cellTab[i][j] !=0 ) {  // && grid[i][j] !=0 pour éviter de rentrer dans le if, bouger un 0 ne sert à rien et augmente le count

       if(!cellShiftedDown) cellShiftedDown = true;
       //gameOverDown = false ;

       cellTab[i+1][j]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftDown();
  if(cellShiftedDown){
    initRandomSpot();
    cellShiftedDown = true;
  }
  //if (countDown !=0 && !testDeath) initRandomSpot(grid); // si 0 fusion, on ne fait pas appraraitre de spot
}
