#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5
#define PI 3.14
#define NOM "LI"
#define CAR 'x'

//PARTIE COURS

/*#define ou #include correspondent � des MACROS qui seront utilis�s lors de la compilation par le pr�-processeur, cela signifie
qu'� chaque appel de la macro, il devra faire r�f�rence au fichier ou � la donn�e d�crite dans cette macro.
La compilation consiste � traduire le programme source en langage machine en faisant appel � un programme nomm� "compilateur"
En langage C, compte tenu de l'existence d'un pr� processeur, cette op�ration de compilation comporte deux �tapes : la premi�re �tant
le traitement par le pr� processeur. Ce dernier ex�cute les directives qui le concernent. On les reconna�t du fait qu'ils commencent par le caract�re "#"
Il produit en r�sultat un programme source en langage C. C'est un fichier qui reste au format texte et contient le code en C.
La compilation est proprement dit la traduction du langage texte fourni par le pr� processeur en langage machine.
Le r�sultat de la compilation porte le nom du module .o (fichier objet).
Le module object cr�e par l'ordinateur n'est pas tout de suite ex�cutable. Il lui manque au moins les diff�rents modules correspondant aux fonctions pr�d�finies utilis�es par le programme (printf, scanf...).
C'est effectivement le r�le de l'�diteur de liens d'aller chercher dans la biblioth�que les modules objets n�cessaires.
Le r�sultat de cette �dition de lien est ce que l'on appel un EXECUTABLE ; c�d un ensemble autonome d'instructions en langage machine.
*/

//#define NOM VALEUR_NUMRIQUE = d�finir une constante (NFOIS sera �gale � 5)

//Pour notre nomenclature :
//- pour les entiers : pr�fixe de n (na ou n_a ou nA)
int main()
{
    //Les variables en C

    //Entiers
    short int n_a; //short. pour le d�marquer d'un standard : sn_a
    int n_b;
    long int n_c; //long. pour le d�marquer : ln_a

    printf("Taille de a : %d\n", sizeof(n_a));
    printf("Taille de b : %d\n", sizeof(n_b));
    printf("Taille de c : %d\n", sizeof(n_c));

    //R�els
    float fltReelSimple;
    double dblReelDouble;

    printf("Taille de fltReelSimple : %d\n", sizeof(fltReelSimple));
    printf("Taille de dblReelDouble : %d\n", sizeof(dblReelDouble));

    //Caract�res

    char c_Caractere;
    printf("Taille de c_Caractere : %d\n", sizeof(c_Caractere));

    //Constantes

    const int cnT=10;
    //la diff�rence entre le #define et le mot cl� "const" et le fait que
    //� l'�x�cution du programme, le prog va remplacer le mot cl� du #define par la valeur
    //alors qu'� la compilation, tout ce qui est d�clar� sous la forme "const" sera automatiquement �valu�e en m�moire

    static int n_d; //le mot cl� static permet de rendre une variable persistente (par exemple une variable qui
                    //est normalement d�truite � la sortie d'une m�thode)

    volatile int n_VolB; //Le pr�fixe volatile est notamment utilis� quand la variable d'un programme peut �tre modifi�e par un autre programme

    //Tester Define
    printf("Ici on va afficher NFOIS : %d\n", NFOIS);
    printf("Ici on va afficher PI : %f\n", PI);
    printf("Ici on va afficher le NOM : %s\n", NOM);
    printf("Ici on va afficher le CAR : %c\n", CAR);

    //Op�rateurs
    int n_i=0;
    ++n_i; //pr� incr�mentation => avant le d�roulement des instructions
    n_i++; //post incr�mentation => apr�s
    // modulo : %
    // division : /  ATTENTION : diviser 5/2 donne 2, mais 5.0/2.0 donne 2.5

    //Cast
    long double ldbl_LongDouble=105.89378973;
    printf("Valeur de ldbl_LongDouble : %lf", (double)ldbl_LongDouble); //la on cast le long double en double

    //Op�rateurs relationnels
    //Concr�tement m�me chose qu'en JS

    // <
    // >
    // >=
    // <=
    // ==
    // !=

    //Op�rateurs logiques
    //Pareil qu'en JS

    // &&
    // ||
    // ! (NOT)

    //Factorisations op�rateurs
    // +=
    // -=
    // /=
    //

}
