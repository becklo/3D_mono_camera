//
//  Lecture.cpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Lecture.hpp"


void lecture_image(int image[1694][1107],char* name){
    FILE *fichier=fopen(name,"r");
    if (fichier == NULL){
	      std::cout <<"Erreur a l'ouverture de l'image \n"	;
       	exit(0);
	     }
	  else	std::cout <<"Image ouverte avec succes \n";
    fgets(taille,256,fichier);
    sscanf(taille,"%s", format);
    std::cout << format << std::endl;
    /* Lit la ligne qui contient la taille */
    fgets(taille,256,fichier);
    std::cout << taille << std::endl;
    /* mais passe les commentaires */
    while (taille[0]=='#'){
      fgets(taille,256,fichier);
      std::cout << taille << std::endl;
    }
    // lit la taille dans la chaine
    sscanf(taille,"%d %d", &tx, &ty);
    std::cout << "tx " << tx << " ty " << ty << std::endl;
    // recupere la valeur du max : blanc
    fgets(taille,256,fichier);
    sscanf(taille,"%d", &max);
    std::cout << max << std::endl;


    for(int i=0; i<ty ; i++){
      for(int j=0; j<tx; j++){
        fgets(taille,256,fichier);
        sscanf(taille,"%d", &image[j][i]);
      }
    }
    fclose(fichier);
}

void lecture_filtre(double filtre[17][17]){
  FILE *fichier=fopen("filtre_test.txt","r");
  if (fichier == NULL){
      std::cout <<"Erreur a l'ouverture de l'image \n"	;
      exit(0);
     }
  else	std::cout <<"Image ouverte avec succes \n";
  for(int i=0; i<17 ; i++){
    for(int j=0; j<17; j++){
      fgets(taille,128,fichier);
      sscanf(taille,"%lf", &filtre[i][j]);
    }
    //std::cout << filtre[i][0] << std::endl;
  }
  fclose(fichier);
}
