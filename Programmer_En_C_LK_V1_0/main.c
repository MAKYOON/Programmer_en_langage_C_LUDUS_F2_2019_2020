#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define TAILLE 10
#define MOT "HELLO"


int main()
{
   /* //Entrées et sorties conversationnelles

    //Affichage
    printf("%d\n", TAILLE );
    printf("%s\n", MOT );

    //Saisie
    int val;
    printf("Saisissez une valeur\n");
    scanf("%d",&val);
    fflush(stdin);  //Vidage du buffer (sinon pb de buffer : "car" prend la valeur de "val" car le buffer n'est pas vidé et auto complète)

    char car;
    printf("Saisissez un caractere\n");
    scanf("%c",&car);
    fflush(stdin);

    char tabCar[TAILLE];
    printf("Saisissez une chaine de caractere\n");
    gets(tabCar); //gets prend par défaut stdin
    //fgets(tabCar,100,stdin); //fgets = file get string, permet de get le flux d'un fichier ! fgets(chaine,taillemax,fichier)
    printf("Vous avez ecrit : %s\n",tabCar);
    //Quand on manipule une chaine en C, on finit toujours la chaîne par un \0 qui caractérise la fin de chaîne.

    //tant qu'il saisit un caractère alphabétique majuscule ou minuscule on reste dans la boucle, sinon on sort
    char c_Car;
    printf("Entrez un caractere alphabetique majuscule ou minuscule sinon la boucle s'arrete\n");
    c_Car = getchar();
    while ((c_Car >= 'a' && c_Car <= 'z') || (c_Car >= 'A' && c_Car <= 'Z'))
    {
         printf("%c\n", c_Car );
         fflush(stdin);
         c_Car=getchar();
    }
    printf("Fin car non alphabétique\n"); */

    //EXERCICE 1

    /*int n_i, n_n, n_somme;
    n_somme = 0;
    for (n_i = 0; i < 4; n_i++)
    {
        printf("Donnez un entier\n");
        scanf("%d", &n_n);
        n_somme+=n_n;
    }
    printf("Somme : %d\n", n_somme );


    n_i=0;
    n_somme=0;

    while (n_i<4)
    {
        printf("Donnez un entier\n");
        scanf("%d",&n_n);
        n_somme+=n_n;
        n_i++;
    }

     printf("Somme : %d\n", n_somme );

    n_i=0;
    n_somme=0;

    do
    {
        printf("Donnez un entier\n");
        scanf("%d",&n);
        somme += n;
        i++;
    } while (i<4);
    printf("Somme : %d\n", somme );*/

    //EXERCICE 2

    /*float flt_note,moyenne;
    int n_i=1;
    moyenne = 0;
    while (flt_note>=0)
    {
        printf("Veuillez saisir une note, et terminez par une note negative\n");
        scanf("%f",&flt_note);
        if (flt_note>0)
        {
             printf("Note %d : %.2f\n", i, flt_note);
             moyenne += flt_note;
             i++;
        }
    }
    printf("La moyenne est de : %.2f\n", moyenne/i);*/

    //CORRIGE 

    /*int n_i=0;
    float flt_moyenne,flt_note,flt_sommenote
    do
    {
        printf("Donnez votre note\n");
        scanf("%f",&flt_note);
        if (flt_note>=0)
        {
            flt_sommenote+=flt_note;
            nI++;
        }
    } while (flt_note>=0.0);

    flt_moyenne=flt_sommenote/n_i;*/

    //EXERCICE 3

   /* int n_nbl,n_i,n_j;
    printf("Entrez le nombre de lignes\n");
    scanf("%d",&n_nbl);

    for (n_i=0; n_i <= n_nbl; n_i++)
    {
        for (n_j = 0; n_j <= n_i; n_j++)
        {
            printf("*");
        }
        printf("\n");
    }*/

    //EXERCICE 4

    /*int n_nb;
    int n_premier = 1;
    printf("Veuillez rentrer un entier\n");
    scanf("%d",&n_nb);
    if (n_nb==1)
    {
        n_premier = 0;
    }
    for (int i = 2 ; i < n_nb; i++)
    {
        if (n_nb%i == 0)
        {
            n_premier = 0;
            break;
        }
    }  
    if (n_premier == 0)
        printf("Le nombre %d n'est pas premier\n", n_nb );
    else
        printf("Le nombre %d est premier\n", n_nb );*/

    //CORRIGE
    //En C, 0 = FAUX et tout ce qui est différent de 0 est VRAI

    /* int n_n, n_d;
    do{
        printf("Donnez un entier superieur a 2\n");
        scanf("%d",&n_n);
    } while (n_n<=2);

    n_d=2;
    while((n_n%n_d)&& (n_d<=sqrt(n_n)))
        n_d++;
    if(n_n%n_d)
        printf("%d est premier \n", n_n);
    else
        printf("%d pas premier \n", n_d);*/

    //Exercice 5
    /*int n_u1,n_u2,n_u3;
    int n_n, n_i;
    do{
        printf("Veuillez entrer la n-ieme valeur de la suite de Fibonacci\n");
        scanf("%d",&n_n);
    } while(n_n<3);

    n_u2 = n_u1 = 1;
    n_i = 2;

    while(n_i++<n_n)
    {
        n_u3=n_u1+n_u2;
        n_u1=n_u2;
        n_u2=n_u3;
    }

    printf("La valeur du terme du rang %d:%d\n", n_n,n_u3 );*/

    //EXERCICE 6

    const int NMAX=10;
    int n_i, n_j;
    printf("   I");
    for (n_j = 1; n_j <= NMAX; n_j++)
    {
        printf("%4d", n_j );
    }

    printf("\n");
    printf("-------");
    for (n_j = 1; n_j <= NMAX; n_j++)
    {
        printf("-------");
    }

    printf("\n");

    for (n_i = 1; n_i <= NMAX; n_i++)
    {
        printf("%4d", n_i );
        for (n_j = 1; n_j <= NMAX; n_j++)
        {
            printf("%4d", n_i*n_j);
        }
        printf("\n");
    }


    return 0;

}

