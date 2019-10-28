#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define NOM 100
#define PRENOM 100
#define ADRESSE 255
#define CP 10
#define VILLE 100
#define CONTINUE 100


int main()
{
   //LES TABLEAUX

    /*int n_tabInteger[TAILLE];
    float flt_tabFloat[TAILLE];
    double dbl_tabDouble[TAILLE];

    char c_tabCar[TAILLE];

    int n_i;

    for (n_i = 0; n_i < TAILLE; n_i++)
    {
       n_tabInteger[n_i]=0;
       flt_tabFloat[n_i]=0.0;
       dbl_tabDouble[n_i]=0.0;
       c_tabCar[n_i]='\0'; // '\0' correspond au caractère de fin de chaîne de caractères
    }*/


    static int n_ID=0; //static permet de rendre persistent la variable : si déclarée dans une procédure, elle pourra exister tout au long du programme
    char c_tabNom[NOM];
    char c_tabPrenom[PRENOM];
    char c_tabAdresse[ADRESSE];
    char c_tabCP[CP];
    char c_tabVille[VILLE];

    const char FinDeSaisie='n';
    char c_tabContinue[CONTINUE];

    do 
    {
        printf("Programme Carte Identite\n");
        printf("Veuillez rentrer votre NOM\n");
        fgets(c_tabNom,NOM,stdin);
        fflush(stdin);
        printf("Veuillez rentrer votre Prenom\n");
        fgets(c_tabPrenom,NOM,stdin);
        fflush(stdin);
        printf("Veuillez rentrer votre adresse\n");
        fgets(c_tabAdresse,ADRESSE,stdin);
        fflush(stdin);
        printf("Veuillez rentrer votre code postal\n");
        //fgets(c_tabCP,CP,stdin);
        scanf("%5s",c_tabCP);
        fflush(stdin);  
        printf("Veuillez rentrer votre ville\n");
        fgets(c_tabVille,VILLE,stdin);
        fflush(stdin);
        ++n_ID;

        //Affichage
        printf("ID : %d\n", n_ID );
        printf("Nom :%s", c_tabNom );
        printf("Prenom :%s", c_tabPrenom);
        printf("Adresse :%s", c_tabAdresse );
        printf("CP :%s\n", c_tabCP );
        printf("Ville :%s", c_tabVille );

        do 
        {
            printf("Saisir une autre carte d'identite o/n ?\n");
            scanf("%s",c_tabContinue);
            fflush(stdin);
        } while(strcmp(c_tabContinue,"o")&& strcmp(c_tabContinue,"n"));

    } while(c_tabContinue[0]!=FinDeSaisie);


    return 0;

}

