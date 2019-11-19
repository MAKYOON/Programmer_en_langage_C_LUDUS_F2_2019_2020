#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAILLE 10


int main()
{
    struct t_point2 new_point3;

    t_point new_point;
    t_point *p_newPoint =&new_point; //on peut également pointer sur des types structurés

    new_point.n_x=0;
    new_point.n_y=0;

    p_newPoint->n_x=10;
    p_newPoint->n_y=20;

    //formalisme du pointeur
    (*p_new_point).n_x=50;
    (*p_new_point).n_y=50;

    //Initialisation

    t_point new_point2={0,0};

    return 0;
}*/

/* /////// COURS ////////// */

//PROTOTYPES

/*char *tab_car (char c_chaine[100]);
int *n_tabInt (int n_entier[100]);
int *n_tabInt2D (int n_entier[10][10]);

// *(p_int)++; //incrémentation de la référence
// (*p_int)++; //incrémentation de l'entier stocké



int main()
{
    //UTILISATION DU TABLEAU DE CARACTERES

    char c_saisie[100]={"Votre Nom"}; //Déclaration tableau de caractères, l'utilisation de {} permet de passer sur chaque valeur
    // si on fait c_saisie[100] = {0} alors on affecte 0 à toutes les valeurs

    char *c_nom;

    //Formalisme tableau
    c_nom=tab_car(c_saisie);

    printf("Votre Nom %s\n", c_nom);


    //UTILISATION DU TABLEAU D'ENTIERS

    int n_entier[100]={0};
    n_tabInt(n_entier); //ici chaque index de référence sera séparé de 4 car un entier est codé sur 4 octet contrairement au char qui est de 1

    int n_entier2[10][10];
    int *p_int=n_tabInt2D(n_entier2);

    int n_i;
    int *p;
    for (n_i = 0; n_i < 100; n_i++)
    {
        printf("%d", *(p_int)++ );
        p=p_int;
    }


}

char * tab_car (char c_chaine[100])
{
    printf("Entrez votre nom\n");
    scanf("%s",c_chaine);

    return c_chaine;
}

int * n_tabInt(int n_entier[100])
{
    int n_i;

    //formalisme pointeur
    for (n_i = 0; n_i < 100; n_i++)
    {
        *(n_entier+n_i)=0; //revient à écrire n_entier[i]=0; le pointeur pointe sur la première référence, et on accède ensuite au reste  en incrémentant i
    }

    return n_entier;
}

int * n_tabInt2D (int n_entier[10][10])
{
    int n_i, n_j;

    //formalisme pointeur
    for (n_i = 0; n_i < 10; n_i++)
    {
        for (n_j = 0; n_j < 10; n_j++)
        {
            *(*(n_entier+n_i)+n_j)=10; // n_entier[i][j] = 10;
        }
    }

    return (int*)n_entier;
}*/

/* ////// EXERCICES ////////// */


//EXERCICE 1

//FORMALISME TABLEAU

/*int main()
{
    int n_i;
    int n_tabInt[10] = {5,27,34,59,104,14,36,85,74,2};
    int n_min = n_tabInt[0];
    int n_max = n_tabInt[0];

    for (n_i = 0; n_i < 10; n_i++)
    {
        if (n_tabInt[n_i] < n_min)
            n_min = n_tabInt[n_i];
        if (n_tabInt[n_i] > n_max)
            n_max = n_tabInt[n_i];
    }

    printf("La valeur la plus petite est %d\n", n_min );
    printf("La valeur la plus grande est %d\n", n_max );


    return 0;
}

//FORMALISME POINTEUR

int main()
{
    int n_i;
    int n_tabInt[10] = {5,27,34,59,104,14,36,85,74,2};
    int n_min = n_tabInt[0];
    int n_max = n_tabInt[0];

    for (n_i = 0; n_i < 10; n_i++)
    {
        if (*(n_tabInt+n_i) < n_min)
            n_min = *(n_tabInt+n_i);
        if (*(n_tabInt+n_i) > n_max)
            n_max = *(n_tabInt+n_i);
    }

    printf("La valeur la plus petite est %d\n", n_min );
    printf("La valeur la plus grande est %d\n", n_max );


    return 0;
}*/

//EXERCICE 2

/*void minAndMaxValue(int n_tabInt[], int n_taille, int *n_min, int *n_max);

int main()
{
    int n_i;
    int n_tabInt[TAILLE];

    printf("Donnez %d valeurs\n", TAILLE );
    for (n_i = 0; n_i < TAILLE; n_i++)
    {
      scanf("%d",&n_tabInt[n_i]);
    }
    int n_min = n_tabInt[0];
    int n_max = n_tabInt[0];

    minAndMaxValue(n_tabInt,10,&n_min,&n_max);
    printf("Min value : %d\n", n_min);
    printf("Max value : %d\n", n_max);

    return 0;
}

void minAndMaxValue(int n_tabInt[], int n_taille, int *n_min, int *n_max)
{
    int n_i;
    for (n_i = 0; n_i < n_taille; n_i++)
    {
        if (n_tabInt[n_i] < *n_min)
            *n_min = n_tabInt[n_i];
        if (n_tabInt[n_i] > *n_max)
            *n_max = n_tabInt[n_i];

    }
}*/

//EXERCICE 3

/*int * n_triTabInt (int n_tabInt[], int n_taille);

int main()
{
    int n_i;
    int n_tabInt[TAILLE];

    printf("Donnez %d valeurs\n", TAILLE );
    for (n_i = 0; n_i < TAILLE; n_i++)
    {
      scanf("%d",&n_tabInt[n_i]);
    }

    n_triTabInt(n_tabInt,10);

    for (n_i = 0; n_i < TAILLE; n_i++)
    {
        printf("Voici les valeurs classees en ordre croissant\n");
        printf("%d\n", n_tabInt[n_i]);
    }


    return 0;
}

int * n_triTabInt (int n_tabInt[], int n_taille)
{
    int n_i, n_j;
    int temp;

    for (n_i = 0; n_i < n_taille; n_i++)
    {
        for (n_j = 0; n_j < (n_taille - n_i - 1); n_j++)
        {
            if (n_tabInt[n_j] > n_tabInt[n_j + 1])
            {
                temp = n_tabInt[n_j];
                n_tabInt[n_j] = n_tabInt[n_j + 1];
                n_tabInt[n_j + 1] = temp;
            }
        }
    }

    return n_tabInt;
}*/

//EXERCICE 4
/*double * d_sommeMatrice(double n_matriceUne[TAILLE][TAILLE],double n_matriceDeux[TAILLE][TAILLE], double n_matriceTrois[TAILLE][TAILLE]);

int main()
{
    double n_matriceUne[TAILLE][TAILLE];
    double n_matriceDeux[TAILLE][TAILLE];
    double n_matriceTrois[TAILLE][TAILLE];
    int i,j;
    srand(time(NULL));

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
              n_matriceUne[i][j]=rand()%11;
              n_matriceDeux[i][j]=rand()%11;
        }
    }

    d_sommeMatrice(n_matriceUne,n_matriceDeux,n_matriceTrois);

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
             printf("%f + %f = %f \n", n_matriceUne[i][j], n_matriceDeux[i][j], n_matriceTrois[i][j]);
        }
    }
  
    return 0;
}

double * d_sommeMatrice(double n_matriceUne[TAILLE][TAILLE],double n_matriceDeux[TAILLE][TAILLE], double n_matriceTrois[TAILLE][TAILLE])
{
    int i,j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
              n_matriceTrois[i][j] = n_matriceUne[i][j]+n_matriceDeux[i][j];
        }
    }

    return *n_matriceTrois;
}*/


