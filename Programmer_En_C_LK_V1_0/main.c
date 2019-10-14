#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5
//#define NOM VALEUR_NUMRIQUE = définir une constante (NFOIS sera égale à 5)
int main()
{
    int i;
    float x = 10.0; //si on ne l'initialise pas, x prend la valeur qui est stocké à la référence de la mémoire qui lui est allouée
    float racx;

    printf("Bonjour\n");
   //Il va regarder ce qui est passé en argument en % (ici lf) par rapport à ce qui est après la virgule :
    //s'il y a plusieurs %, il faut plusieurs virgules (autant de références que de formats)
    printf("Calcul de %d racines carrees\n", NFOIS);

    for (i=0; i<NFOIS;i++)
    {
        printf("Donnez un nombre : ");
        scanf("%f",&x); //fonction servant à récupérer la saisie de donnée d'un certain type, le "&" permet de mettre la saisie de l'utilisateur à la référence de la valeur de x
        if (x<0.0) // .0 important car c'est un réel
            printf("Le nombre %f ne possede pas de racine carree", x);
        else
        {
            racx=sqrt(x);
            printf("Le nombre %f a pour racine carree : %f\n",x,racx);
        }
    }
    printf("Travail Termine - Au revoir"); // Attention pas d'accent sur la console.






    return 0;
}
