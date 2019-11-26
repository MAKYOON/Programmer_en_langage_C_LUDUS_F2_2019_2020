#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


#define TAILLE 4
#define VERT 2
#define JAUNE 1
#define ROUGE 0

//PROTOTYPES
void generateCode(int n_nbADeviner[]);
int isValidCode(char inputUser[]);
void promptInput(char c_nbUser[]);
void inputToArrayInt(char c_nbUser[], int n_nbUser[]);
void color(int t,int f);
void verifCode (int n_code[], int n_nbUser[]);


//programme principal
int main()
{
    char c_nbUser[TAILLE]= {0}; //input de l'utilisateur sous forme d'un tableau de caractères
    int n_nbUser[TAILLE]= {0}; //input transformé en tableau d'entiers
    int i;
    int n_code[TAILLE]; //code secret à trouver

    int n_essais = 0;
    int n_finPartie = 0; //booleen => 0 pour FAUX et 1 pour VRAI

    //Génération du code
    srand(time(NULL)); //permet d'initialiser le random
    generateCode(n_code); //on génère le code aléatoire en passant l'adresse du tableau pour le modifier directement

    //CODE A DECOMMENTER SI ON VEUT VOIR LE NOMBRE GENERE AFFICHE SUR LA CONSOLE
    /*printf("Le nombre aleatoire est : ");
    for (i = 0; i < TAILLE; i++)
    {
        printf("%d", n_code[i] );
    }
    printf("\n");*/

    //CODE PRINCIPAL DU JEU
    do
    {
        color(15,0); //couleur de base pour écrire
        promptInput(c_nbUser); //on récupère l'input de l'utilisateur sous formes d'un tableau de caractères
        inputToArrayInt(c_nbUser,n_nbUser); //on le transforme en tableau d'entiers pour le manipuler plus facilement
        verifCode(n_code,n_nbUser); //fonction qui vérifie le code et qui le colore si les nombres sont trouvés ou non
        n_essais++; //on incrémente le compteur d'essais
        //Comparaison des deux tableaux d'entiers (le code saisi par l'utilisateur, et le code à trouver)
        if (memcmp(n_nbUser, n_code, sizeof(n_nbUser)) == 0) //s'ils sont égaux, cela retourne 0, donc on arrête la partie
        {
            n_finPartie = 1;
            color(15,0); //on remet la couleur de base pour écrire
            printf("\nBravo vous avez trouve le code : " );
            for (i = 0; i < TAILLE; i++)
            {
                printf("%d", n_code[i] );
            }
            printf(" en %d essais ", n_essais);
        }
        color(15,0); //on remet la couleur de base pour écrire
        printf("\nNombre essais : %d sur 12\n", n_essais );
        if (n_essais==12)
        {
            printf("Dommage ! vous ferez mieux la prochaine fois\n");
            n_finPartie = 1;
        }
    } while (n_finPartie != 1);

return 0;
}

//On génère individuellement les chiffres, cela permet d'avoir un meilleur résultat que de générer un random d'un gros nombre
void generateCode(int n_nbADeviner[TAILLE])
{
    int i, j;
    int n_doublon = 0;
    for (i=0; i<TAILLE; i++)
    {
        do
        {
            n_doublon =0;
            n_nbADeviner[i]= rand()%10; //génère un chiffre entre 0 et 9
            //on vérifie qu'il n'y ait pas de doublons dans le code, auquel cas on regénère le chiffre qui existe en double
            for (j=0; j<i; j++)
            {
                if (n_nbADeviner[i] == n_nbADeviner[j])
                    n_doublon = 1;
            }
        } while (n_doublon == 1);
    }
}

//Fonction qui va vérifier si le code rentré est bien constitué d'uniquement 4 chiffres (et rejette le reste)
int isValidCode(char c_inputUser[TAILLE])
{
    int i;
    int n_compteur=0;
    for (i = 0; i < TAILLE; i++)
    {
        if ((c_inputUser[i] >= 48) && (c_inputUser[i] <= 57)) //on vérifie si les codes ASCII des input sont bien compris entre 0 et 9
             n_compteur++; //dans ce cas on incrémente le compteur
    }

    if (n_compteur == TAILLE) //si le compteur est égal à TAILLE (donc 4 = la taille du code) alors on retourne 1
        return 1;
    else
        return 0; //sinon on retourne 0
}

//cette fonction va demander à l'utilisateur de saisir le code, et on modifie le tableau passé en argument
void promptInput(char c_nbUser[TAILLE])
{
    do
    {
        printf("Veuillez rentrer un code a 4 chiffres\n");
        scanf("%s",c_nbUser); //on récupère d'abord l'input de l'utilisateur et on le stocke dans le tableau de caractères
    }
    while ((isValidCode(c_nbUser) == 0) || (strlen(c_nbUser) != 4)); //on continue tant que la saisie n'est pas égale à 4 chiffres
}

//Transforme l'input de l'utilisateur (tableau de caractères) en tableau d'entiers
void inputToArrayInt(char c_nbUser[TAILLE], int n_nbUser[TAILLE])
{
    int i;
    for (i = 0; i < TAILLE; i++)
    {
        n_nbUser[i]=c_nbUser[i] - '0'; //en soustrayant 0, on transforme le char en int
        // (car 0 = 48 en ASCII, et par exemple si l'utilisateur rentre 5 = 53 en ASCII alors 53-48 = 5) et on stocke la valeur dans le tableau d'int
    }
}

//Fonction qui gère la couleur du texte
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

/*Procédure qui vérifie le code, et print les indicateurs (chiffres colorés)
J'ai essayé à plusieurs reprises, mais je n'ai pas réussi à faire en sorte de gérer les doublons de l'input utilisateur
Exemple : Le code est 1234, l'utilisateur rentre 1111, et la console ressort Vert, Rouge, Rouge, Rouge

Le code en commentaire gère bien les cas particuliers (exemple ci-dessus) mais ne gère plus les chiffres mal placés (en jaune normalement)
Autre exemple : Le code est 1234, l'utilisateur peut rentrer 1212, la console ressort Vert, Vert, Rouge, Rouge. 
*/

void verifCode (int n_code[TAILLE], int n_nbUser[TAILLE])
{
    int i,j;
    int n_resultat = 0; //permettra de faire les vérifications (prendra la valeur VERT,JAUNE ou ROUGE qui valent respectivement 2, 1 et 0)

    //Vérification du code
    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {

            if ((n_nbUser[i] == n_code[j]) && (i == j)) //si le chiffre est placé au bon endroit alors on le colorie en vert
            {
                n_resultat = VERT;
                break;
            } else if (((n_nbUser[i] == n_code[j]) && (i != j))) //si le chiffre existe mais n'est pas placé au bon endroit, on le colorie en jaune
            {
                n_resultat = JAUNE;
                break;
            } else //sinon il n'existe pas alors on le met en rouge
            {
                n_resultat = ROUGE;
            }
        }

        //ici on traite juste la coloration du texte en fonction du résultat, qu'on traite avant la prochaine itération pour colorer le bon chiffre
        if (n_resultat == VERT)
        {
            color(2,0);
            printf("%d", n_nbUser[i] );
        } else if (n_resultat == JAUNE)
        {
            color(14,0);
            printf("%d", n_nbUser[i] );
        } else
        {
            color(12,0);
            printf("%d", n_nbUser[i] );
        }
    }
}

   /* for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (n_nbUser[j] == n_nbUser[i])
            {
                    if ((n_nbUser[j] == n_code[i]) && (j == i)) //si le chiffre est placé au bon endroit alors on le colorie en vert
                    {
                        n_resultat = VERT;
                        break;
                    }
                    else
                        n_resultat = ROUGE;
            }
            else
            {
                for (int k = 0; k < TAILLE; k++)
                {
                    if ((n_nbUser[i] == n_code[k]) && (i == k)) //si le chiffre est placé au bon endroit alors on le colorie en vert
                    {
                        n_resultat = VERT;
                        break;
                    } else if (((n_nbUser[i] == n_code[k]) && (i != k))) //si le chiffre existe mais n'est pas placé au bon endroit, on le colorie en jaune
                    {
                        n_resultat = JAUNE;
                        break;
                    }
                    else //sinon il n'existe pas alors on le met en rouge
                    {
                        n_resultat = ROUGE;
                    }
                }
            }


        }
        //ici on traite juste la coloration du texte en fonction du résultat, qu'on traite avant la prochaine itération pour colorer le bon chiffre
        if (n_resultat == VERT)
        {
            color(2,0);
            printf("%d", n_nbUser[i] );
        } else if (n_resultat == JAUNE)
        {
            color(14,0);
            printf("%d", n_nbUser[i] );
        } else
        {
            color(12,0);
            printf("%d", n_nbUser[i] );
        }
    }
}*/


