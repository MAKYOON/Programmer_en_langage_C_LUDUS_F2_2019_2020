#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5
#define PI 3.14
#define NOM "LI"
#define CAR 'x'

//PARTIE COURS

/*#define ou #include correspondent à des MACROS qui seront utilisés lors de la compilation par le pré-processeur, cela signifie
qu'à chaque appel de la macro, il devra faire référence au fichier ou à la donnée décrite dans cette macro.
La compilation consiste à traduire le programme source en langage machine en faisant appel à un programme nommé "compilateur"
En langage C, compte tenu de l'existence d'un pré processeur, cette opération de compilation comporte deux étapes : la première étant
le traitement par le pré processeur. Ce dernier exécute les directives qui le concernent. On les reconnaît du fait qu'ils commencent par le caractère "#"
Il produit en résultat un programme source en langage C. C'est un fichier qui reste au format texte et contient le code en C.
La compilation est proprement dit la traduction du langage texte fourni par le pré processeur en langage machine.
Le résultat de la compilation porte le nom du module .o (fichier objet).
Le module object crée par l'ordinateur n'est pas tout de suite exécutable. Il lui manque au moins les différents modules correspondant aux fonctions prédéfinies utilisées par le programme (printf, scanf...).
C'est effectivement le rôle de l'éditeur de liens d'aller chercher dans la bibliothèque les modules objets nécessaires.
Le résultat de cette édition de lien est ce que l'on appel un EXECUTABLE ; càd un ensemble autonome d'instructions en langage machine.
*/

//#define NOM VALEUR_NUMRIQUE = définir une constante (NFOIS sera égale à 5)

//Pour notre nomenclature :
//- pour les entiers : préfixe de n (na ou n_a ou nA)
int main()
{
    //Les variables en C

    //Entiers
    short int n_a; //short. pour le démarquer d'un standard : sn_a
    int n_b;
    long int n_c; //long. pour le démarquer : ln_a

    printf("Taille de a : %d\n", sizeof(n_a));
    printf("Taille de b : %d\n", sizeof(n_b));
    printf("Taille de c : %d\n", sizeof(n_c));

    //Réels
    float fltReelSimple;
    double dblReelDouble;

    printf("Taille de fltReelSimple : %d\n", sizeof(fltReelSimple));
    printf("Taille de dblReelDouble : %d\n", sizeof(dblReelDouble));

    //Caractères

    char c_Caractere;
    printf("Taille de c_Caractere : %d\n", sizeof(c_Caractere));

    //Constantes

    const int cnT=10;
    //la différence entre le #define et le mot clé "const" et le fait que
    //à l'éxécution du programme, le prog va remplacer le mot clé du #define par la valeur
    //alors qu'à la compilation, tout ce qui est déclaré sous la forme "const" sera automatiquement évaluée en mémoire

    static int n_d; //le mot clé static permet de rendre une variable persistente (par exemple une variable qui
                    //est normalement détruite à la sortie d'une méthode)

    volatile int n_VolB; //Le préfixe volatile est notamment utilisé quand la variable d'un programme peut être modifiée par un autre programme

    //Tester Define
    printf("Ici on va afficher NFOIS : %d\n", NFOIS);
    printf("Ici on va afficher PI : %f\n", PI);
    printf("Ici on va afficher le NOM : %s\n", NOM);
    printf("Ici on va afficher le CAR : %c\n", CAR);

    //Opérateurs
    int n_i=0;
    ++n_i; //pré incrémentation => avant le déroulement des instructions
    n_i++; //post incrémentation => après
    // modulo : %
    // division : /  ATTENTION : diviser 5/2 donne 2, mais 5.0/2.0 donne 2.5

    //Cast
    long double ldbl_LongDouble=105.89378973;
    printf("Valeur de ldbl_LongDouble : %lf", (double)ldbl_LongDouble); //la on cast le long double en double

    //Opérateurs relationnels
    //Concrètement même chose qu'en JS

    // <
    // >
    // >=
    // <=
    // ==
    // !=

    //Opérateurs logiques
    //Pareil qu'en JS

    // &&
    // ||
    // ! (NOT)

    //Factorisations opérateurs
    // +=
    // -=
    // /=
    // *=
    // &=...

    //Structures Conditions et Boucles

    int i=0;
    int taille = 10;

    for (int i = 0; i < taille; i++)
    {
        if (i%2 == 0)
        {
            printf("%d est un multiple de 2\n", i);
        }
        else
        {
            printf("%d n'est pas un multiple de 2\n", i);
        }
    }

    while (i<taille)
    {
        if ((i*2 < taille) && (i*2 > (taille/2)))
        {
            printf("%d multiplie par 2 est egal a %d ce qui est inferieur a %d\n",i,i*2,taille/2);
        }
        i++;
    }

    taille = 10;
    i = 10;

    do
    {
        taille+=i;
        printf("taille est egal a %d\n", taille);
        ++i;
    } while (i<10);

    //opérateur ternaire, fonctionne comme un if else mais en une ligne (le double point : signifie else)
    int n_hp = 100;
    printf("Le joueur est : %s\n", (n_hp>0) ? "en vie" : "mort");

    //Switch case

    int choix= -1;

    printf("Veuillez entrer votre choix\n");
    scanf("%d",&choix);
    switch(choix)
    {
        case 0: printf("Quitter\n");
        break;
        case 1: printf("Calculer\n");
        break;
        case 2: printf("Jouer\n");
        break;
        default: printf("Default\n");
        break; //pas obligé
    }
    return 0;

    //Break dans une boucle : stop la boucle immédiatement
    //Continue : arrête l'itération actuelle et passe à la prochaine
}
