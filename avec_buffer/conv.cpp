#include <iostream>
#include <stdio.h>
#include <stdint.h>

#include "var.h"
#include "coef_filtre.h"

void conv(int image[BUFF_WIDTH][BUFF_HEIGHT], int rows, int cols, int num_filtre, ac_fixed<28,10,true> sortie[BUFF_WIDTH][BUFF_HEIGHT]){//[IMG_WIDTH+16][IMG_HEIGHT+16]){
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
        if (i<8 && i>BUFF_HEIGHT+8 && j<8 && j>BUFF_WIDTH+8){
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
