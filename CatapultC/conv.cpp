#include <iostream>
#include <stdio.h>
#include <stdint.h>

#include "var.h"

void conv(int image_in[IMG_WIDTH][IMG_HEIGHT], int image_out[IMG_WIDTH][IMG_HEIGHT]){

  int rows = IMG_HEIGHT, cols = IMG_WIDTH;

  for(int i=0; i < rows; ++i){              // rows
      for(int j=0; j < cols; ++j){          // columns
                        image_out[j][i] = 255-image_in[j][i]; 
      }
  }
}
