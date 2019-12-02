#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 20

int main ()
{
  FILE * pFile;
  /* Mode texte */
  char cSaisie[TAILLE];
  char cAutre[TAILLE];


  //Saisie utilisateur
  printf("Veuillez saisir un texte a inserer\n");
  fgets(cSaisie,TAILLE,stdin);
  //Ouverture du fichier
  pFile = fopen("myfile.txt", "w");

  //Ecriture dans le fichier
  if (pFile != NULL) {
    fprintf(pFile,"%s\n",cSaisie);
    fclose (pFile);
  }

  pFile = fopen("myfile.txt","r");
  printf("Le fichier contient :\n");

  //Lecture du fichier
  if (pFile != NULL) {
    fgets(cAutre,TAILLE,pFile);
    printf("%s",cAutre);
    fclose (pFile);
  }


  /*Mode binaire */
  int nSaisie;
  int nAutre;

  printf("Veuillez saisir un entier a inserer\n");
  scanf("%d",&nSaisie);
  //fgets(cSaisie,TAILLE,stdin);
  pFile = fopen("myfile.bin","wb");
  if (pFile != NULL ) {
    fwrite(&nSaisie,sizeof(int),sizeof(nSaisie),pFile);
    fclose(pFile);
  }
  printf("Le fichier contient :\n");
  pFile = fopen("myfile.bin","rb");
  if (pFile != NULL) {
    fread(&nAutre,sizeof(int),sizeof(nSaisie),pFile);
    printf("%d",nAutre);
    fclose(pFile);
  }

  return 0;
}

