#include <iostream>
#include <stdio.h>
#include <math.h>
#include "var.h"
#include "conv.cpp"
#include "ecriture.cpp"


void creation_error(int image_floue[IMG_WIDTH][IMG_HEIGHT], int image_net[IMG_WIDTH][IMG_HEIGHT],
                    int num_filtre, int rec_error_tab[IMG_WIDTH][IMG_HEIGHT]){//[IMG_WIDTH+16][IMG_HEIGHT+16]){

  double result_conv[IMG_WIDTH][IMG_HEIGHT];
  // double **result_conv = (double**)malloc(sizeof(*result_conv) * (IMG_WIDTH));
  //
  // for (int i = 0; i < IMG_WIDTH; i++){
  //   result_conv[i] = (double*)malloc(sizeof(**result_conv) * (IMG_HEIGHT));
  // }

  conv(image_net,IMG_HEIGHT,IMG_WIDTH,num_filtre,result_conv);
  std::cout << "conv done" << '\n';
  for(int i = 0 ; i < IMG_HEIGHT; i++){
    for (int j = 0; j < IMG_WIDTH; j++) {
      if (i<8 && i>IMG_HEIGHT+8 && j<8 && j>IMG_WIDTH+8){
        rec_error_tab[j][i] = 0;
      }
      rec_error_tab[j][i] = image_floue[j][i] - (int)result_conv[j][i];
    }
  }
}

void reconstruction_error(int rec_error_tab[IMG_WIDTH][IMG_HEIGHT],int i, int j){
  int rec_error = 0;
  for (int l = i - SIZE_WI; l < i + SIZE_WI; l++){
    for(int c = j - SIZE_WI; c < j + SIZE_WI; c++ ){
      if (rec_error_tab[c][l]>46340) {
        rec_error_tab[c][l]=46340;
        }
      if (rec_error_tab[c][l]<-46340) {
        rec_error_tab[c][l]=-46340;
        }
        rec_error += (int)rec_error_tab[c][l]*(int)rec_error_tab[c][l];
    }
   }
   std::cout << "rec_error before: " << rec_error << '\n';
  // if (rec_error > 0){
    rec_error_tab[j][i]=(int)rec_error;
  // }
  // else {
  //   rec_error_tab[j][i]=2147483647+rec_error;
  // }

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
      image_depht[j][i]= mini_rank*((int)(255/9));
      if (image_depht[j][i]>255) {
        image_depht[j][i]=255;
        }
      if (image_depht[j][i]<0) {
        image_depht[j][i]=0;
        }
      }
    }
    std::cout << "calcul min fini" << '\n';
  }
