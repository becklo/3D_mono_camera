/* Fichier contenant les constantes de l' algorithme, les types à virgule fixe,
 * ainsi que l'instantiation des tables trigonométriques.
 * Note : certaine constantes ne sont plus utilisées
 */


#ifndef CONSTANTES_H
#define CONSTANTES_H

#define DEFAULT_VAL_PIX 128	/* couleure de fond de l'image de sortie */
#define TMATRIX 3		// taille des matric d'homographie

#define M_PI 3.14159265359

#define NB_CAMERAS 4	// Nombre de caméras
#define FOCAL_LENGTH_Y 0.0036	// Focal des caméras
#define FOCAL_LENGTH_X 0.0036
#define INV_PIXEL_SIZE 88183.43	// Inverse de la taille d'un pixel (pixel size = 1.1416626e-05)

#define AOV_DEG 40 // Angle de vue de la caméra (on peut mettre l'angle de vue max, y a une détection des dépassements de bord faite)

#define WIDTH_INTER 140
#define HEIGHT_INTER 160

/* resolution et semi resolution des images provenant des cameras */
#define RES_X 320
#define HALF_RES_X 160
#define RES_Y 240
#define HALF_RES_Y 120
  
#define WIDTH_OUT 640	// Longueur de l'image de sortie

#define HEIGHT_OUT 480  // Hauteur de l'image de sortie
#define THETA_MAX 3.14159265359/4  // Angle max suivant le parcours de theta (correspond à width)
#define THETA_MIN -3.14159265359/4	// Angle min suivant le parcours de theta
#define THETA_STEP ((THETA_MAX-THETA_MIN)/WIDTH_OUT)	// Le pas suivant theta = l'amplitude de theta / longueur sortie, K_teta dans le rapport
#define PHI_MAX (3.14159265359/4)	// Idem pour phi ...
#define PHI_MIN -(3.14159265359/4)
#define PHI_STEP ((PHI_MAX-PHI_MIN)/480) // K_alpha dans le rapport

/* Compilation en virgule fixe */
#ifdef VIRGULE_FIXE
#ifndef TB_CATA
#include "vfheaders/ac_fixed.h"
#include "vfheaders/ac_int.h"
#include "vfheaders/ac_channel.h"
#else
#include "ac_fixed.h"
#include "ac_int.h"
#include "ac_channel.h"
#endif

// Précisions des variables

#define VF_INV_PIXEL_SIZE ac_fixed < 32,20,false,AC_RND,AC_SAT > // Variable stockant l'inverse de la taille d' un pixel
#define VF_ANGLES_DEG ac_fixed <12,10,true,AC_RND,AC_SAT > // Variables d'angles theta, phi en degrés
#define VF_ANGLES ac_fixed <17,3,true,AC_RND,AC_SAT > // Correction du type
#define VF_COORD_IN_PIXEL ac_fixed <18,12,true,AC_RND,AC_SAT > // Correction du type
#define VF_COORD_IN_METRIC ac_fixed <20,1,true,AC_RND,AC_SAT > // Variable stockant les coordonnées d'un point en metres
#define VF_VECTOR ac_fixed <20,10,true,AC_RND,AC_SAT > // Variable représentant un vecteur d'angle theta phi

#define VF_LUM ac_int< 8, false > // Variable de la luminance (valeur d'un pixel)
#define VF_SUM_POND ac_fixed < 40,16,true,AC_RND,AC_SAT > // Variable stockant la somme pondérée (c'est à dire le quotient de la pondération)
#define VF_SUM_LUMS ac_fixed < 60, 30,false,AC_RND,AC_SAT > // Variable de la somme des valeurs pondérées

#define VF_CORRECTION ac_fixed < 16,2,true,AC_RND,AC_SAT >  // Variable inutilisée, pourrait l'être pour faire pondération gaussienne (cf papiers)
#define VF_FOCAL_LENGTH_SIZE ac_fixed < 16,1,true,AC_RND,AC_SAT > // Variable représentant la distance focale

#define VF_CONV_RAD ac_fixed<15,0,false,AC_RND,AC_SAT>  // Variable de conversion degrés -> radians
#define VF_INVERSE_RI ac_fixed<12+5,5,true,AC_RND,AC_SAT> // Variable stockant l'inverse de r_i pour la pondération

#define VF_GAIN ac_fixed<15,8,false,AC_RND,AC_SAT> // pour le gain est la multiplication

// Tables et précisions des tables

#define VF_PRECISION_COS ac_fixed < 21,1,true,AC_RND,AC_SAT > // Précision de la table des cosinus
#define VF_PRECISION_SIN ac_fixed < 21,1,true,AC_RND,AC_SAT > // Précision de la table des sinus
#define VF_PRECISION_INV_R ac_fixed < 13,3,true,AC_RND,AC_SAT >

#else  /* VIRGULE_FIXE n'est pas définie, on compile en flottant */

#define VF_INV_PIXEL_SIZE double
#define VF_ANGLES_DEG double
#define VF_ANGLES double
#define VF_COORD_IN_PIXEL double
#define VF_COORD_IN_METRIC double
#define VF_VECTOR double

#define VF_LUM int
#define VF_SUM_POND double
#define VF_SUM_LUMS double

#define VF_CORRECTION double
#define VF_FOCAL_LENGTH_SIZE double

#define VF_CONV_RAD double
#define VF_INVERSE_RI double

#define VF_GAIN double

// Tables et précisions des tables

#define VF_PRECISION_COS double
#define VF_PRECISION_SIN double
#define VF_PRECISION_INV_R double

#endif //VIRGULE_FIXE

static const VF_GAIN gain[NB_CAMERAS] = {1.6, 1.6, 1.6, 1.0};

static const VF_PRECISION_COS cos_tables[501] = {
#include "./python/cos_tables_test.txt"
};
static const VF_PRECISION_SIN sin_tables[501] = {
#include "./python/sin_tables_test.txt"
};

#endif //CONSTANTES

