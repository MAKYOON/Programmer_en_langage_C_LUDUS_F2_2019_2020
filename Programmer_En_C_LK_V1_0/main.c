#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define TAILLE 10

//Prototypes
void initMatrice(int[][TAILLE], int); //on peut factoriser l'écriture en enlevant le nom des variables et en enlevant la première taille du tableau
void afficheMatrice(int[][TAILLE]); //mais la deuxième dimension est tjrs obligatoire
void initMatrice2(int [][TAILLE], int, int);
int n_sommeEltMatrice (int[][TAILLE], int);

int main()
{
  int n_matriceEntier[TAILLE][TAILLE];
  int n_matriceEntier2[5][TAILLE];

  initMatrice(n_matriceEntier,5);
  initMatrice2(n_matriceEntier2,5,10);
  afficheMatrice(n_matriceEntier);

    int i,j;

    //Affichage Matrice
    for ( i = 0; i < 5; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            printf("%3d", n_matriceEntier2[i][j] );
        }
        printf("\n");
    }

  int n_resSommeMatrice = n_sommeEltMatrice(n_matriceEntier2,5);
  printf("Resultat de la somme de notre matrice : %d\n", n_resSommeMatrice ); 



return 0;
}

//Implémentation des fonctions

//Procédures

void initMatrice(int n_matriceEntier[][TAILLE], int n_valInt)
{
     //Tableau 2 dimensions Entiers
    int i,j;

    //Initialisation Matrice
    for ( i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            n_matriceEntier[i][j] = n_valInt;
        }
    }
}

void afficheMatrice(int n_matriceEntier[TAILLE][TAILLE])
{
    int i,j;

    //Affichage Matrice
    for ( i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            printf("%3d", n_matriceEntier[i][j] );
        }
        printf("\n");
    }

}

void initMatrice2(int n_matriceEntier[][TAILLE], int n_nval, int n_valInt)
{
     //Tableau 2 dimensions Entiers
    int i,j;

    //Initialisation Matrice
    for ( i = 0; i < n_nval; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            n_matriceEntier[i][j] = n_valInt;
        }
    }
}
//Calcul

int n_sommeEltMatrice (int n_matriceEntier[][TAILLE], int n_nval)
{
    int n_resSommeMatrice=0;
    int i,j;

    for ( i = 0; i < n_nval; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            n_resSommeMatrice+=n_matriceEntier[i][j];
        }
    }

    return n_resSommeMatrice;
}
