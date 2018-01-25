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
#include "var.h"

char format [2];
char taille [256] ;
int max;

int tx,ty;


void lecture_image(int image[IMG_WIDTH][IMG_HEIGHT],char* name);
//void lecture_filtre(double filtre[17][17],int taille,char* name);

#endif /* Lecture_hpp */
