#include <iostream>
#include <stdio.h>
#include "var.h"


int ty_mask = IMG_WIDTH+16;
int tx_mask = 1694+16;

void creation_mask(int mask[IMG_WIDTH+16][IMG_HEIGHT+16]){
  for(int i = 0; i<ty_mask ; i++){
    for(int j = 0; j<tx_mask ; j++){
      if ((i<8 || i>(IMG_WIDTH-8)) && (j<8 || j>(IMG_HEIGHT-8))){
        mask[i][j] = 0;
      }
      else mask[i][j] = 1;
    }
  }
}
