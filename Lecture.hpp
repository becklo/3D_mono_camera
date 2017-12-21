//
//  Lecture.hpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//

#ifndef Lecture_hpp
#define Lecture_hpp

#include <stdio.h>

char format [2];
char taille [256] ;
int max;

int tx,ty;


void lecture_image(int **image);
void lecture_filtre(double **filtre);

#endif /* Lecture_hpp */
