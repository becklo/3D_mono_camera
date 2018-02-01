#include <iostream>
#include <stdio.h>
#include <fstream>
#include "var.h"

int ecriture_image_norm(char * image, int image_test[IMG_WIDTH][IMG_HEIGHT]){
    std::ofstream fichier(image, std::ios::out | std::ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

         if(fichier)
         {
           fichier << "P2" << std::endl;
           fichier << IMG_WIDTH << " " << IMG_HEIGHT << std::endl;
           fichier << "255" << std::endl;
            for (int i=0; i< IMG_HEIGHT;i++){
              for (int j = 0; j< IMG_WIDTH; j++){
                fichier << image_test[j][i] << std::endl;
              }
            }
                 fichier.close();
         }
         else{
                 std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
               }
        return 0;
}

int ecriture_image_norm_mal(char * image, int image_test[IMG_WIDTH][IMG_HEIGHT]){
    std::ofstream fichier(image, std::ios::out | std::ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

         if(fichier)
         {
           fichier << "P2" << std::endl;
           fichier << IMG_WIDTH << " " << IMG_HEIGHT << std::endl;
           fichier << "255" << std::endl;
            for (int i = 0; i< IMG_HEIGHT; i++){
              for (int j = 0; j< IMG_WIDTH; j++){
                fichier << image_test[j][i] << std::endl;
              }
            }
                 fichier.close();
         }
         else{
                 std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
               }
        return 0;
}

int ecriture_image_grand(char * image, int image_test[IMG_WIDTH+16][IMG_HEIGHT+16]){
    std::ofstream fichier(image, std::ios::out | std::ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

         if(fichier)
         {
           fichier << "P2" << std::endl;
           fichier << "1710 " << "1123" << std::endl;
            for (int i=0; i< IMG_HEIGHT+16;i++){
              for (int j = 0; j< IMG_WIDTH+16; j++){
                fichier << image_test[j][i] << std::endl;
              }
            }
                 fichier.close();
         }
         else{
                 std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
               }
        return 0;
}
