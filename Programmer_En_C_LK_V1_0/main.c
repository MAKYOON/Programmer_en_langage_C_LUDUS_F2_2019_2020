#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5
//#define NOM VALEUR_NUMRIQUE = d�finir une constante (NFOIS sera �gale � 5)
int main()
{
    int i;
    float x = 10.0; //si on ne l'initialise pas, x prend la valeur qui est stock� � la r�f�rence de la m�moire qui lui est allou�e
    float racx;

    printf("Bonjour\n");
   //Il va regarder ce qui est pass� en argument en % (ici lf) par rapport � ce qui est apr�s la virgule :
    //s'il y a plusieurs %, il faut plusieurs virgules (autant de r�f�rences que de formats)
    printf("Calcul de %d racines carrees\n", NFOIS);

    for (i=0; i<NFOIS;i++)
    {
        printf("Donnez un nombre : ");
        scanf("%f",&x); //fonction servant � r�cup�rer la saisie de donn�e d'un certain type, le "&" permet de mettre la saisie de l'utilisateur � la r�f�rence de la valeur de x
        if (x<0.0) // .0 important car c'est un r�el
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
