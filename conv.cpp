#include <iostream>
#include <stdio.h>
#include <stdint.h>

int kCols = 17;
int kRows = 17;

// find center position of kernel (half of kernel size)
int kCenterX = kCols / 2;
int kCenterY = kRows / 2;


void conv(int image[300][200], int rows, int cols, int kernel[17][17], long sortie[300+16][200+16]){
  int mm,nn,ii,jj;
  for(int i=0; i < rows; ++i){              // rows
      for(int j=0; j < cols; ++j){          // columns
          for(int m=0; m < kRows; ++m){     // kernel rows
              mm = kRows - 1 - m;      // row index of flipped kernel
              for(int n=0; n < kCols; ++n){ // kernel columns
                  nn = kCols - 1 - n;  // column index of flipped kernel

                  // index of input signal, used for checking boundary
                  ii = i + (m - kCenterY);
                  jj = j + (n - kCenterX);

                  // ignore input samples which are out of bound
                  if( ii >= 0 && ii < rows && jj >= 0 && jj < cols )
                      sortie[i][j] += image[ii][jj] * kernel[mm][nn];
              
              }
          }
      }
  }
}
