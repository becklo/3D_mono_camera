//
//  main.cpp
//  Test
//
//  Created by Loula Beck on 05/12/2017.
//  Copyright © 2017 Loula Beck. All rights reserved.
//

#include <iostream>
#include "depth.cpp"
#include "var.h"

int image_net[IMG_WIDTH][IMG_HEIGHT];
int image_floue[IMG_WIDTH][IMG_HEIGHT];

int im_depth[IMG_WIDTH][IMG_HEIGHT];

int rec_error_tab1[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab2[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab3[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab4[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab5[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab6[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab7[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab8[IMG_WIDTH][IMG_HEIGHT];
int rec_error_tab9[IMG_WIDTH][IMG_HEIGHT];

int main(){

	    //remplissage des tables d'erreur entre floue et conv
	    creation_error(image_floue,image_net,1,rec_error_tab1);
	    creation_error(image_floue,image_net,2,rec_error_tab2);
	    creation_error(image_floue,image_net,3,rec_error_tab3);
	    creation_error(image_floue,image_net,4,rec_error_tab4);
	    creation_error(image_floue,image_net,5,rec_error_tab5);
	    creation_error(image_floue,image_net,6,rec_error_tab6);
	    creation_error(image_floue,image_net,7,rec_error_tab7);
	    creation_error(image_floue,image_net,8,rec_error_tab8);
	    creation_error(image_floue,image_net,9,rec_error_tab9);
	    //moyennage de l'erreur
	    for (int i = 0; i<IMG_HEIGHT;i++){
	      for (int j = 0; j < IMG_WIDTH; j++) {
		if (i > (SIZE_WI) && i < IMG_HEIGHT - (SIZE_WI) && j > (SIZE_WI) && j < IMG_WIDTH -(SIZE_WI)){
		  reconstruction_error(rec_error_tab1,i,j);
		  reconstruction_error(rec_error_tab2,i,j);
		  reconstruction_error(rec_error_tab3,i,j);
		  reconstruction_error(rec_error_tab4,i,j);
		  reconstruction_error(rec_error_tab5,i,j);
		  reconstruction_error(rec_error_tab6,i,j);
		  reconstruction_error(rec_error_tab7,i,j);
		  reconstruction_error(rec_error_tab8,i,j);
		  reconstruction_error(rec_error_tab9,i,j);
		}
		else{
		  rec_error_tab1[j][i] = 0;
		  rec_error_tab2[j][i] = 0;
		  rec_error_tab3[j][i] = 0;
		  rec_error_tab4[j][i] = 0;
		  rec_error_tab5[j][i] = 0;
		  rec_error_tab6[j][i] = 0;
		  rec_error_tab7[j][i] = 0;
		  rec_error_tab8[j][i] = 0;
		  rec_error_tab9[j][i] = 0;
		}
	      }
	    }

	    //retour de la profondeur
	    depth(im_depth,rec_error_tab1,rec_error_tab2,\
	      rec_error_tab3,\
	      rec_error_tab4,\
	      rec_error_tab5,\
	      rec_error_tab6,\
	      rec_error_tab7, \
	      rec_error_tab8,\
	      rec_error_tab9
	    );


}
