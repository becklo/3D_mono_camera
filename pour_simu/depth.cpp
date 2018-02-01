#include <iostream>
#include <stdio.h>
#include <math.h>

#include "var.h"
#include "conv.cpp"
#include "ac_fixed.h"
#include "ac_int.h"


void creation_error(int image_floue[IMG_WIDTH][IMG_HEIGHT], int image_net[IMG_WIDTH][IMG_HEIGHT],
                    int num_filtre, int rec_error_tab[IMG_WIDTH][IMG_HEIGHT]){

  ac_fixed<32,10,true> result_conv[IMG_WIDTH][IMG_HEIGHT];
  //convolution de l'image net avec un filtre
  conv(image_net,IMG_HEIGHT,IMG_WIDTH,num_filtre,result_conv);
  // enregistrement des valeurs d'erreur dans le buffer d'erreur
  for(int i = 0 ; i < IMG_HEIGHT; i++){
    for (int j = 0; j < IMG_WIDTH; j++) {
      if (i<8 && i>IMG_HEIGHT+8 && j<8 && j>IMG_WIDTH+8){
        rec_error_tab[j][i] = 0;
      }
      rec_error_tab[j][i] = image_floue[j][i] - result_conv[j][i].to_int();
      // limite des valeurs a cause des limites constatées en utilisant des
      // les doubles
      if (rec_error_tab[j][i]>255) {
        rec_error_tab[j][i]=255;
        }
      if (rec_error_tab[j][i]<-255) {
        rec_error_tab[j][i]=-255;
        }
    }
  }
}

void reconstruction_error(int rec_error_tab[IMG_WIDTH][IMG_HEIGHT],int i, int j){
  int rec_error = 0;
  // moyenne des valeurs sur une fenetre de largeur SIZE_WI
  // cast en int car on ne cherche pas necessairement la precision ici
  for (int l = i - SIZE_WI; l < i + SIZE_WI; l++){
    for(int c = j - SIZE_WI; c < j + SIZE_WI; c++ ){
      rec_error += (int)(rec_error_tab[c][l])*(int)(rec_error_tab[c][l]);
    }
   }
  // limite pour les valeurs absurdes des fois observés en utilisant des doubles
  if (rec_error>0){
    rec_error_tab[j][i]=rec_error;
  }
  else {
    rec_error_tab[j][i]=2147483647+rec_error;
  }
}

void depth(int image_depht[IMG_WIDTH][IMG_HEIGHT],int rec_error_tab1[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab2[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab3[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab4[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab5[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab6[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab7[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab8[IMG_WIDTH][IMG_HEIGHT],\
                            int rec_error_tab9[IMG_WIDTH][IMG_HEIGHT]
                          ){
  //comparaison du minimum d'erreur pour determiner quelle echelle correspond
  // a tel pixel
  int tempo[9];
  int mini,mini_rank;
  for (int i = 0; i < IMG_HEIGHT; i++) {
    for (int j = 0; j < IMG_WIDTH; j++) {
      tempo[0]= rec_error_tab1[j][i];
      tempo[1]= rec_error_tab2[j][i];
      tempo[2]= rec_error_tab3[j][i];
      tempo[3]= rec_error_tab4[j][i];
      tempo[4]= rec_error_tab5[j][i];
      tempo[5]= rec_error_tab6[j][i];
      tempo[6]= rec_error_tab7[j][i];
      tempo[7]= rec_error_tab8[j][i];
      tempo[8]= rec_error_tab9[j][i];
      mini = tempo[0];
      mini_rank = 0;
      for (int m = 1; m < 9; m++) {
        if (tempo[m]<mini) {
          mini = tempo[m];
          mini_rank = m;
          }
        }
      // pour affichage ensuite, 9 echelles de gris
      image_depht[j][i]= mini_rank*((int)(255/9));
      if (image_depht[j][i]>255) {
        image_depht[j][i]=255;
        }
      if (image_depht[j][i]<0) {
        image_depht[j][i]=0;
        }
      }
    }
  }
