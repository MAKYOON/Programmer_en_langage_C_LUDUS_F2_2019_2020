#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define TAILLE 100

//LES POINTEURS

//En héxadécimal, les valeurs sont de 0 à 9 et de A à F
//255(10) => 1(2^3) 1(2^2) 1(2^1) 1(2^0) / 1(2^3) 1(2^2) 1(2^1) 1(2^0)
//  2^3 + 2^2 + 2^1 + 2^0 = 8+4+2+1 = 15(F) / 15(F)
// Donc 255 en hexadécimal = FF


//PROTOTYPES
int sommeEntier(int,int);
void somme2Entier (int, int ,int *);
void f1();
void f2(int);
int f3(int);
void f4();

int main()
{
    //DECLARATION POINTEUR
    //UN POINTEUR DOIT POINTER SUR UNE REFERENCE MEMOIRE
    //UN POINTEUR, LORS DE SON INITIALISATION, DOIT AVOIR UNE REFERENCE NULL
    int *pn_pointeurEntier=NULL;

    //Le pointeur pointe sur la référence de n_entier
    int n_entier=10;
    pn_pointeurEntier = &n_entier;
    *pn_pointeurEntier = 88;

    //fonction de la somme
    n_entier=sommeEntier(10,88);
    printf("%d\n", n_entier );

    n_entier = 55;

    //utilisation de la procédure avec un pointeur
    int n_resSomme=0;
    somme2Entier(56,12,&n_resSomme);

    //int **ppn_entier=&pn_pointeurEntier;


    //POINTEUR DE CARACTERES
    char *p_char = NULL;
    char c_Chaine[TAILLE]="Nicolas";

    p_char=c_Chaine;
 

    
    printf("\n");
    //APPEL DES FONCTIONS EXERCICES EN C
    f1();
    f2(2);
    f3(3);

    //EXERCICE 3
    long int n_i=0;
    while (n_i<217000)
    {
        f4();
        n_i++;
    }


return 0;
}

//fonction d'une somme
int sommeEntier(int n_a, int n_b)
{
    return n_a+n_b;
}
//procédure pour réaliser une somme mais en utilisant un pointeur
// => passage d'argument par adresse
void somme2Entier (int n_a, int n_b, int *pn_res)
{
    *pn_res = n_a + n_b;
}

//EXERCICE DE C

void f1()
{
    printf("Bonjour\n");
}

void f2(int a)
{
    for (int i = 0; i < a; i++)
    {
       printf("Bonjour\n");
    }
}

int f3(int a)
{
    for (int i = 0; i < a; i++)
    {
       printf("Bonjour\n");
    }

    return 0;
}

//EXERCICE 2
//Le programme va afficher 5 puis 3

//EXERCICE 3

void f4()
{
    static long int ln_nbAppel=0;
    static long int ln_appel=1;
    ln_nbAppel++;
    if (ln_nbAppel == ln_appel)
    {
        printf("*** %ld fois ***\n", ln_nbAppel );
        ln_appel*=10;
    }
}