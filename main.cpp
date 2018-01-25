//
//  main.cpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//

#include <iostream>
#include "Lecture.cpp"
#include "depth.cpp"
#include "ecriture.cpp"
#include "var.h"

int image_net[IMG_WIDTH][IMG_HEIGHT];
int image_floue[IMG_WIDTH][IMG_HEIGHT];

int main(){

    lecture_image(image_net,"image/trees_deb.pgm");
    lecture_image(image_floue,"image/trees_inp.pgm");

    int **im_depth = (int**)malloc(sizeof(*im_depth) * (IMG_WIDTH));
    for (int i = 0; i < IMG_WIDTH+16; i++){
      im_depth[i] = (int*)malloc(sizeof(**im_depth) * (IMG_HEIGHT));
    }

    //init tab1
    int **rec_error_tab1 = (int**)malloc(sizeof(*rec_error_tab1) * (IMG_WIDTH+16));
    int **rec_error_tab2 = (int**)malloc(sizeof(*rec_error_tab2) * (IMG_WIDTH+16));
    int **rec_error_tab3 = (int**)malloc(sizeof(*rec_error_tab3) * (IMG_WIDTH+16));
    int **rec_error_tab4 = (int**)malloc(sizeof(*rec_error_tab4) * (IMG_WIDTH+16));
    int **rec_error_tab5 = (int**)malloc(sizeof(*rec_error_tab5) * (IMG_WIDTH+16));
    int **rec_error_tab6 = (int**)malloc(sizeof(*rec_error_tab6) * (IMG_WIDTH+16));
    int **rec_error_tab7 = (int**)malloc(sizeof(*rec_error_tab7) * (IMG_WIDTH+16));
    int **rec_error_tab8 = (int**)malloc(sizeof(*rec_error_tab8) * (IMG_WIDTH+16));
    int **rec_error_tab9 = (int**)malloc(sizeof(*rec_error_tab9) * (IMG_WIDTH+16));

    for (int i = 0; i < IMG_WIDTH+16; i++){
      rec_error_tab1[i] = (int*)malloc(sizeof(**rec_error_tab1) * (IMG_HEIGHT+16));
      rec_error_tab2[i] = (int*)malloc(sizeof(**rec_error_tab2) * (IMG_HEIGHT+16));
      rec_error_tab3[i] = (int*)malloc(sizeof(**rec_error_tab3) * (IMG_HEIGHT+16));
      rec_error_tab4[i] = (int*)malloc(sizeof(**rec_error_tab4) * (IMG_HEIGHT+16));
      rec_error_tab5[i] = (int*)malloc(sizeof(**rec_error_tab5) * (IMG_HEIGHT+16));
      rec_error_tab6[i] = (int*)malloc(sizeof(**rec_error_tab6) * (IMG_HEIGHT+16));
      rec_error_tab7[i] = (int*)malloc(sizeof(**rec_error_tab7) * (IMG_HEIGHT+16));
      rec_error_tab8[i] = (int*)malloc(sizeof(**rec_error_tab8) * (IMG_HEIGHT+16));
      rec_error_tab9[i] = (int*)malloc(sizeof(**rec_error_tab9) * (IMG_HEIGHT+16));
    }

    //remplissage des tables d'erreur entre floue et conv
    creation_error(image_floue,image_net,1,rec_error_tab1);
    creation_error(image_floue,image_net,2,rec_error_tab2);
    creation_error(image_floue,image_net,3,rec_error_tab3);
    creation_error(image_floue,image_net,4,rec_error_tab4);
    creation_error(image_floue,image_net,5,rec_error_tab5);
    creation_error(image_floue,image_net,6,rec_error_tab6);
    creation_error(image_floue,image_net,7,rec_error_tab7);
    creation_error(image_floue,image_net,8,rec_error_tab8);
    creation_error(image_floue,image_net,9,rec_error_tab9);
    //moyennage de l'erreur
    for (int i = 0; i<IMG_HEIGHT;i++){
      for (int j = 0; j < IMG_WIDTH; j++) {
        if (i > (SIZE_WI) && i < IMG_HEIGHT - (SIZE_WI) && j > (SIZE_WI) && j < IMG_WIDTH -(SIZE_WI)){
          reconstruction_error(rec_error_tab1,i+8,j+8);
          reconstruction_error(rec_error_tab2,i+8,j+8);
          reconstruction_error(rec_error_tab3,i+8,j+8);
          reconstruction_error(rec_error_tab4,i+8,j+8);
          reconstruction_error(rec_error_tab5,i+8,j+8);
          reconstruction_error(rec_error_tab6,i+8,j+8);
          reconstruction_error(rec_error_tab7,i+8,j+8);
          reconstruction_error(rec_error_tab8,i+8,j+8);
          reconstruction_error(rec_error_tab9,i+8,j+8);
        }
        else{
          rec_error_tab1[j][i] = 0;
          rec_error_tab2[j][i] = 0;
          rec_error_tab3[j][i] = 0;
          rec_error_tab4[j][i] = 0;
          rec_error_tab5[j][i] = 0;
          rec_error_tab6[j][i] = 0;
          rec_error_tab7[j][i] = 0;
          rec_error_tab8[j][i] = 0;
          rec_error_tab9[j][i] = 0;
        }
      }
    }

    //retour de la profondeur
    depth(im_depth,rec_error_tab1,rec_error_tab2,\
      rec_error_tab3,\
      rec_error_tab4,\
      rec_error_tab5,\
      rec_error_tab6,\
      rec_error_tab7, \
      rec_error_tab8,\
      rec_error_tab9
    );



    // ecriture_image_norm("image_net.pgm", image_net);
    // std::cout << "Image net print" << '\n';
    // ecriture_image_norm("image_floue.pgm",image_floue);
    // std::cout << "Image floue print" << '\n';
    ecriture_image_norm_mal("image_fin.pgm", im_depth);
    std::cout << "Image fin print" << '\n';


}
