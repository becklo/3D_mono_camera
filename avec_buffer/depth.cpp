#include <iostream>
#include <stdio.h>
#include <math.h>
#include "var.h"
#include "conv.cpp"
#include "ecriture.cpp"

void creation_error(int image_floue[BUFF_WIDTH][BUFF_HEIGHT], int image_net[BUFF_WIDTH][BUFF_HEIGHT],
                    int num_filtre, int rec_error_tab[BUFF_WIDTH][BUFF_HEIGHT]){//[IMG_WIDTH+16][IMG_HEIGHT+16]){

  ac_fixed<28,10,true> result_conv[BUFF_WIDTH][BUFF_HEIGHT];

  // double **result_conv = (double**)malloc(sizeof(*result_conv) * (IMG_WIDTH));
  //
  // for (int i = 0; i < IMG_WIDTH; i++){
  //   result_conv[i] = (double*)malloc(sizeof(**result_conv) * (IMG_HEIGHT));
  // }

  conv(image_net,BUFF_HEIGHT,BUFF_WIDTH,num_filtre,result_conv);
  std::cout << "conv done" << '\n';
  for(int i = 0 ; i < BUFF_HEIGHT; i++){
    for (int j = 0; j < BUFF_WIDTH; j++) {
      if (i<8 && i>BUFF_HEIGHT+8 && j<8 && j>BUFF_WIDTH+8){
        rec_error_tab[j][i] = 0;
      }
      rec_error_tab[j][i] = image_floue[j][i] - (int)result_conv[j][i];
    }
  }
}

int reconstruction_error(int rec_error_tab[BUFF_WIDTH][BUFF_HEIGHT]){
  int rec_error = 0;
//  for (int l = i - SIZE_WI; l < i + SIZE_WI; l++){
//    for(int c = j - SIZE_WI; c < j + SIZE_WI; c++ ){
  for (int l = 0; l < BUFF_HEIGHT; l++){
    for(int c = 0; c < BUFF_WIDTH; c++ ){
      if (rec_error_tab[c][l]>46340) {
        rec_error_tab[c][l]=46340;
        }
      if (rec_error_tab[c][l]<-46340) {
        rec_error_tab[c][l]=-46340;
        }
        rec_error += (int)rec_error_tab[c][l]*(int)rec_error_tab[c][l];
    }
   }
  
  return (int)rec_error;
  // if (rec_error > 0){
  //  rec_error_tab[j][i]=(int)rec_error;
  // }
  // else {
  //   rec_error_tab[j][i]=2147483647+rec_error;
  // }

}

/*void depth(int image_depht[BUFF_WIDTH][BUFF_HEIGHT],int rec_error_tab1[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab2[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab3[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab4[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab5[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab6[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab7[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab8[BUFF_WIDTH][BUFF_HEIGHT],\
                            int rec_error_tab9[BUFF_WIDTH][BUFF_HEIGHT]
                          ){*/

int depth(int tempo[9]) {

  int tempo[9];
  int mini,mini_rank;
/*  for (int i = 0; i < BUFF_HEIGHT; i++) {
    for (int j = 0; j < BUFF_WIDTH; j++) {
      tempo[0]= rec_error_tab1[j][i];
      tempo[1]= rec_error_tab2[j][i];
      tempo[2]= rec_error_tab3[j][i];
      tempo[3]= rec_error_tab4[j][i];
      tempo[4]= rec_error_tab5[j][i];
      tempo[5]= rec_error_tab6[j][i];
      tempo[6]= rec_error_tab7[j][i];
      tempo[7]= rec_error_tab8[j][i];
      tempo[8]= rec_error_tab9[j][i];*/

      mini = tempo[0];
      mini_rank = 0;
      for (int m = 1; m < 9; m++) {
        if (tempo[m]<mini) {
          mini = tempo[m];
          mini_rank = m;
          }
        }
      ret = mini_rank*((int)(255/9));
      if (ret>255) {
        ret=255;
        }
      if (ret<0) {
        ret=0;
        }
     return ret;
}
