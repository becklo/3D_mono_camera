#include <iostream>
#include "coef_filtre.h"
#define FILTER_NUM_1 (17*17)
#define FILTER_NUM_2 (15*15)
#define FILTER_NUM_3 (15*15)
#define FILTER_NUM_4 (13*13)
#define FILTER_NUM_5 (13*13)
#define FILTER_NUM_6 (11*11)
#define FILTER_NUM_7 (9*9)
#define FILTER_NUM_8 (9*9)
#define FILTER_NUM_9 (9*9)


void calcul_min(double *coef,int num_filtre){
  double min,max;
  min = coef[0];
  max = coef[0];
  for(int i = 1; i<num_filtre;i++){
    if (min > coef[i]) min = coef[i];
    if (max < coef[i]) max = coef[i];
  }
  std::cout << "min : " << min << " max : " << max << '\n';
}

int main(){
  std::cout << "calcul min/max filtre 1" << '\n';
  calcul_min(coeffs_double_1,FILTER_NUM_1);
  std::cout << "calcul min/max filtre 2" << '\n';
  calcul_min(coeffs_double_2,FILTER_NUM_2);
  std::cout << "calcul min/max filtre 3" << '\n';
  calcul_min(coeffs_double_3,FILTER_NUM_3);
  std::cout << "calcul min/max filtre 4" << '\n';
  calcul_min(coeffs_double_4,FILTER_NUM_4);
  std::cout << "calcul min/max filtre 5" << '\n';
  calcul_min(coeffs_double_5,FILTER_NUM_5);
  std::cout << "calcul min/max filtre 6" << '\n';
  calcul_min(coeffs_double_6,FILTER_NUM_6);
  std::cout << "calcul min/max filtre 7" << '\n';
  calcul_min(coeffs_double_7,FILTER_NUM_7);
  std::cout << "calcul min/max filtre 8" << '\n';
  calcul_min(coeffs_double_8,FILTER_NUM_8);
  std::cout << "calcul min/max filtre 9" << '\n';
  calcul_min(coeffs_double_9,FILTER_NUM_9);
}
