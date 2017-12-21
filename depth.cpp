#include <iostream>
#include <stdio.h>
#include <math.h>

int reconstruction_error(int rec_error_tab[1694+16][1107+16],int i, int j){
  int rec_error = 0;
  for (int l = i - 5; l < i+5; l++){
    for(int c = j - 5; c < j+5; c++ ){
      rec_error += pow(rec_error_tab[c][l],2);

    }
  }
  if (rec_error < 255){
    return rec_error ;
  }
  else {return 255;}
}
