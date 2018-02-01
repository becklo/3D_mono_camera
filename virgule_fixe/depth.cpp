#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "var.h"
#include "ac_fixed.h"
#include "ac_int.h"
#include "coef_filtre.h"

void conv(int image[IMG_WIDTH][IMG_HEIGHT], int rows, int cols, int num_filtre, ac_fixed<28,10,true> sortie[IMG_WIDTH][IMG_HEIGHT]){//[IMG_WIDTH+16][IMG_HEIGHT+16]){
  int mm,nn,ii,jj,kCols,kRows;

  switch (num_filtre) {
    case 1:
      kCols = 17;
      kRows = 17;
      break;
    case  2 :
      kCols = 15;
      kRows = 15;
      break;
    case  3 :
      kCols = 15;
      kRows = 15;
      break;
    case 4 :
      kCols = 13;
      kRows = 13;
      break;
    case 5 :
      kCols = 13;
      kRows = 13;
      break;
    case 6:
      kCols = 11;
      kRows = 11;
      break;
    case 7 :
      kCols = 9;
      kRows = 9;
      break;
    case 8 :
      kCols = 9;
      kRows = 9;
      break;
    case 9 :
      kCols = 9;
      kRows = 9;
      break;
  }
  // find center position of kernel (half of kernel size)
  int kCenterX = kCols / 2;
  int kCenterY = kRows / 2;

  for(int i=0; i < rows; i++){              // rows
      for(int j=0; j < cols; j++){          // columns
        if (i<8 && i>IMG_HEIGHT+8 && j<8 && j>IMG_WIDTH+8){
          sortie[j][i] = 0;
        }
        else{
          for(int m=0; m < kRows; ++m){     // kernel rows
              mm = kRows - 1 - m;      // row index of flipped kernel
              for(int n=0; n < kCols; ++n){ // kernel columns
                  nn = kCols - 1 - n;  // column index of flipped kernel

                  // index of input signal, used for checking boundary
                  ii = i + (m - kCenterY);
                  jj = j + (n - kCenterX);

                  // ignore input samples which are out of bound
                  if( ii >= 0 && ii < rows && jj >= 0 && jj < cols ){
                    switch (num_filtre) {
                      case 1 :
                        sortie[j][i] += image[jj][ii] * coeffs_double_1[17*nn+mm];
                        break;
                      case  2 :
                        sortie[j][i] += image[jj][ii] * coeffs_double_2[15*nn+mm];
                        break;
                      case  3 :
                        sortie[j][i] += image[jj][ii] * coeffs_double_3[15*nn+mm];
                        break;
                      case  4 :
                        sortie[j][i] += image[jj][ii] * coeffs_double_4[13*nn+mm];
                        break;
                      case 5:
                        sortie[j][i] += image[jj][ii] * coeffs_double_5[13*nn+mm];
                        break;
                      case 6:
                        sortie[j][i] += image[jj][ii] * coeffs_double_6[11*nn+mm];
                        break;
                      case 7:
                        sortie[j][i] += image[jj][ii] * coeffs_double_7[9*nn+mm];
                        break;
                      case 8:
                        sortie[j][i] += image[jj][ii] * coeffs_double_8[9*nn+mm];
                        break;
                      case 9:
                        sortie[j][i] += image[jj][ii] * coeffs_double_9[9*nn+mm];
                        break;
                    }
                  }

              }
          }
        }
      }
  }
}

void creation_error(int image_floue[IMG_WIDTH][IMG_HEIGHT], int image_net[IMG_WIDTH][IMG_HEIGHT],
                    int num_filtre, int rec_error_tab[IMG_WIDTH][IMG_HEIGHT]){//[IMG_WIDTH+16][IMG_HEIGHT+16]){

  ac_fixed<28,10,true> result_conv[IMG_WIDTH][IMG_HEIGHT];
  // double **result_conv = (double**)malloc(sizeof(*result_conv) * (IMG_WIDTH));
  //
  // for (int i = 0; i < IMG_WIDTH; i++){
  //   result_conv[i] = (double*)malloc(sizeof(**result_conv) * (IMG_HEIGHT));
  // }

  conv(image_net,IMG_HEIGHT,IMG_WIDTH,num_filtre,result_conv);
//  std::cout << "conv done" << '\n';
  for(int i = 0 ; i < IMG_HEIGHT; i++){
    for (int j = 0; j < IMG_WIDTH; j++) {
      if (i<8 && i>IMG_HEIGHT+8 && j<8 && j>IMG_WIDTH+8){
        rec_error_tab[j][i] = 0;
      }
      rec_error_tab[j][i] = image_floue[j][i] - result_conv[j][i].to_int();
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
  for (int l = i - SIZE_WI; l < i + SIZE_WI; l++){
    for(int c = j - SIZE_WI; c < j + SIZE_WI; c++ ){
      rec_error += (int)(rec_error_tab[c][l])*(int)(rec_error_tab[c][l]);
    }
   }
//  std::cout << "rec_error : " << rec_error << '\n';
  if (rec_error>0){
    rec_error_tab[j][i]=rec_error;
  }
  else {
    rec_error_tab[j][i]=2147483647+rec_error;
  }
//  std::cout << "rec_error_tab : " << rec_error_tab[j][i] << '\n';
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
 //   std::cout << "calcul min fini" << '\n';
  }