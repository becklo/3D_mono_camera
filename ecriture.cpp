#include <iostream>
#include <stdio.h>
#include <fstream>

int ecriture_image_norm(char * image, int image_test[1694][1107]){
    std::ofstream fichier(image, std::ios::out | std::ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

         if(fichier)
         {
           fichier << "P2" << std::endl;
           fichier << "1694 " << "1107" << std::endl;
            for (int i=0; i< 1107;i++){
              for (int j = 0; j< 1694; j++){
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

int ecriture_image_grand(char * image, int image_test[1710][1123]){
    std::ofstream fichier(image, std::ios::out | std::ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

         if(fichier)
         {
           fichier << "P2" << std::endl;
           fichier << "1710 " << "1123" << std::endl;
            for (int i=0; i< 1107+16;i++){
              for (int j = 0; j< 1694+16; j++){
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
