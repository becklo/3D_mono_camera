//
//  main.cpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//

#include <iostream>
#include "Lecture.cpp"
#include "mask.cpp"
#include "conv.cpp"
#include "depth.cpp"
#include "ecriture.cpp"

int mask[1694+16][1107+16];
double filtre[17][17];
int image_net[1694][1107];
int image_floue[1694][1107];
int image_error[1694+16][1107+16];
int depth[1694][1107];
double sortie[1694+16][1107+16];

int main(){

    lecture_image(image_net,"trees_deb.pgm");
    lecture_image(image_floue,"trees_inp.pgm" );
    for (int i = 0;i<1107+16;i++){
      for(int j = 0; j<1694+16;j++){
        if ((i<8 || i>(1107+8)) && (j<8 || j>(1694+8))){
          image_error[j][i] = 0;
        }
        else {
          image_error[j][i] = (image_floue[j][i] - image_net[j][i]);
        }
      }
    }
    for (int i = 0;i<1107;i++){
      for(int j = 0; j<1694;j++){
        depth[j][i] = reconstruction_error(image_error,i+8, j+8);
      }
    }
    ecriture_image_norm("image_net.pgm", image_net);
    std::cout << "Image net print" << '\n';
    ecriture_image_norm("image_floue.pgm",image_floue);
    std::cout << "Image floue print" << '\n';
    ecriture_image_norm("test.pgm", depth);
    std::cout << "depth print" << '\n';
}
