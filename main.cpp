//
//  main.cpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//

#include <iostream>
#include "mask.cpp"
#include "depth.cpp"
#include "var.h"

int main(
    int mask[IMG_WIDTH+16][IMG_HEIGHT+16],
    double filtre[17][17],
    int image_net[IMG_WIDTH][IMG_HEIGHT],
    int image_floue[IMG_WIDTH][IMG_HEIGHT],
    int image_error[IMG_WIDTH+16][IMG_HEIGHT+16],
    int depth[IMG_WIDTH][IMG_HEIGHT]
    //,double sortie[IMG_WIDTH+16][IMG_HEIGHT+16]
    ){

    for (int i = 0;i<IMG_HEIGHT+16;i++){
      for(int j = 0; j<IMG_WIDTH+16;j++){
        if ((i<8 || i>(IMG_HEIGHT+8)) && (j<8 || j>(IMG_WIDTH+8))){
          image_error[j][i] = 0;
        }
        else {
          image_error[j][i] = (image_floue[j][i] - image_net[j][i]);
        }
      }
    }
    for (int i = 0;i<IMG_HEIGHT;i++){
      for(int j = 0; j<IMG_WIDTH;j++){
        depth[j][i] = reconstruction_error(image_error,i+8, j+8);
      }
    }
}
