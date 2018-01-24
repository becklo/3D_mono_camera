#include <iostream>
#include <stdio.h>
#include "var.h"

int reconstruction_error(int rec_error_tab[IMG_WIDTH+16][IMG_HEIGHT+16],int i, int j){
  int rec_error = 0;
  for (int l = i - 5; l < i+5; l++){
    for(int c = j - 5; c < j+5; c++ ){
      rec_error += rec_error_tab[c][l]*rec_error_tab[c][l];

    }
  }
  if (rec_error < 255){
    return rec_error ;
  }
  else {return 255;}
}
