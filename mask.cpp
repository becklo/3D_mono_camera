#include <iostream>
#include <stdio.h>


int ty_mask = 1107+16;
int tx_mask = 1694+16;

void creation_mask(int **mask){
  for(int i = 0; i<ty_mask ; i++){
    for(int j = 0; j<tx_mask ; j++){
      if ((i<8 || i>(1107-8)) && (j<8 || j>(1694-8))){
        mask[i][j] = 0;
      }
      else mask[i][j] = 1;
    }
  }
}
