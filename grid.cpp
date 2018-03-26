#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    this->initValues();
    this->initRandomSpot();
    this->initRandomSpot();
}

Grid::Grid(const Grid &grid){ // constructeur de copie
    for(int i=0; i< nbCell ; i++)
    {
        for(int j=0; j< nbCell; j++)
        {
           cellTab[i][j] = grid.cellTab[i][j] ;
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

       cellTab[i][j+1]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }
  this->shiftRight();
  if(cellShiftedRight ) {
      initRandomSpot();
  }
  //this->checkDeath();
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

       cellTab[i][j-1]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftLeft();
  if( cellShiftedLeft ){
      initRandomSpot();
  }
  //this->checkDeath();
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

       cellTab[i-1][j]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftUp();
  if(cellShiftedUp) {
      initRandomSpot();
  }
  //this->checkDeath();
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

       cellTab[i+1][j]  = 2*cellTab[i][j];
       cellTab[i][j] = 0 ;
      }
    }
  }

  shiftDown();
  if(cellShiftedDown){
    initRandomSpot();
  }
  //this->checkDeath();
}

void Grid::checkDeath() {

    //Grid *gridTest(0); // pointeur initialisé sur rien
    //gridTest = new Grid(*this) ;
    //Grid gridTest = Grid(*this) ; // on copie la grille

    Grid gridTest = Grid() ;

    gridTest.fusionDown(); // on test chaque possibilité dans la copie
    gridTest.fusionLeft();
    gridTest.fusionRight();
    gridTest.fusionUp();

    if(!gridTest.cellShiftedRight && !gridTest.cellShiftedLeft && !gridTest.cellShiftedUp && !gridTest.cellShiftedDown) {
        cout <<"******"<<" Game Over" << "*****"<< endl;
    } else {
       cellShiftedRight = false;
       cellShiftedLeft = false;
       cellShiftedUp = false;
       cellShiftedDown = false;
    }

    //delete gridTest ;
}








