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

int image_net[IMG_WIDTH][BUFF_HEIGHT+1];
int image_floue[IMG_WIDTH][BUFF_HEIGHT+1];

int i,j;
int tab_erreur[9];

int im_depth[BUFF_WIDTH][BUFF_HEIGHT];

int rec_error_tab1[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab2[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab3[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab4[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab5[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab6[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab7[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab8[BUFF_WIDTH][BUFF_HEIGHT];
int rec_error_tab9[BUFF_WIDTH][BUFF_HEIGHT];


int main(int image_net_in, int image_floue_in){

	i++;
	j = i/IMG_WIDTH
	image_net[i%IMG_WIDTH][j%(BUFF_HEIGHT+1)] = image_net_in;	
	image_floue[i%IMG_WIDTH][j%(BUFF_HEIGHT+1)] = image_floue_in;	
	
	if(i>(IMG_WIDTH*BUFF_HEIGHT)) {

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
//		    for (int i = 0; i<BUFF_HEIGHT;i++){
//		      for (int j = 0; j < BUFF_WIDTH; j++) {
		if (i > (SIZE_WI) && i < BUFF_HEIGHT - (SIZE_WI) && j > (SIZE_WI) && j < BUFF_WIDTH -(SIZE_WI)){
			tab_erreur[0] = reconstruction_error(rec_error_tab1);
			tab_erreur[1] = reconstruction_error(rec_error_tab2);
			tab_erreur[2] = reconstruction_error(rec_error_tab3);
			tab_erreur[3] = reconstruction_error(rec_error_tab4);
			tab_erreur[4] = reconstruction_error(rec_error_tab5);
			tab_erreur[5] = reconstruction_error(rec_error_tab6);
			tab_erreur[6] = reconstruction_error(rec_error_tab7);
			tab_erreur[7] = reconstruction_error(rec_error_tab8);
			tab_erreur[8] = reconstruction_error(rec_error_tab9);
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

	} //endif

}
