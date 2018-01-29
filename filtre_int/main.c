#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	FILE* f_in;
	f_in = fopen("coef_filtre.h", "r");

	FILE* f_out;
	f_out = fopen("coef_filtre_int.h", "w");

	int i, j, test;
	char ch[1000];
	double in;
	int out;

	if (f_in != NULL && f_out != NULL) {
		printf("Traitement #define\n");
		for(i=0; i<9; i++) {
			fgets(ch, 1000, f_in);
			fputs(ch, f_out);
		}

		// boucle traitement coeff filtres
		for(i=0; i<9; i++){
			printf("Traitement coef filtre %d\n", i);

			for(j=0; j<2; j++) {
				fgets(ch, 1000, f_in);
				fputs(ch, f_out);
			}
			test = 1;
			while(test) {
				test = fscanf(f_in, "%lf", &in);
				fgets(ch, 1000, f_in);
				if(test) {
					out = (int)( in*100000000);
					fprintf(f_out, "\t%d,\n", out);
				}
			}
			fputs(ch, f_out);
		}
		//

		fclose(f_in);
		fclose(f_out);
	} else {
		printf("Echec ouverture fichier");
	}
	return (0);
}
