#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define TAILLE 3 //taille du morpion

//PROTOTYPES
void initMorpion(char [][TAILLE]);
void afficheMorpion (char [][TAILLE]);
char choixSymbole();
void tourJoueur(int, char[][TAILLE], char);
int isOccupied(int, int, char[][TAILLE]);
int isAligned(char [][TAILLE], char);

//programme principal
int main()
{
 char c_symboleUtilisateur; //symbole du joueur 1
 char c_symboleUtilisateur2; // symbole du joueur 2
 char c_tabMorpion[TAILLE][TAILLE]; //le tableau du morpion
 int n_fin=0; //sera la condition de sortie de la boucle, si n_fin =0 on continue, si n_fin=1 on arr�te le jeu (victoire ou match nul)
 int n_casesVide=0; //permet de v�rifier si le tableau est rempli et donc match nul si pas de victoire
 int n_i,n_j; //i et j servent � parcourir le tableau
 int n_joueur=1; //on initialise le joueur1 en premier


 c_symboleUtilisateur = choixSymbole(); //on appelle la fonction qui va permettre � l'utilisateur de choisir le symbole
 fflush(stdin); //on vide le buffer au cas o� pour �viter des probl�mes
 initMorpion(c_tabMorpion); //on appelle la proc�dure qui initialise le morpion
 afficheMorpion(c_tabMorpion); //et on l'affiche vide pour le moment


//on d�termine le symbole de l'utilisateur 2 en fonction de celui de l'utilisateur 1
 if (c_symboleUtilisateur == 'X')
    c_symboleUtilisateur2 = 'O';
 else
    c_symboleUtilisateur2 = 'X';

 //boucle principale du jeu
do
{
    if(n_joueur==1) //tour joueur1
    {
         tourJoueur(n_joueur,c_tabMorpion,c_symboleUtilisateur); //tourJoueur prend en param�tre l'indice du joueur (1 ou 2), le tableau, et le symbole du joueur
         afficheMorpion(c_tabMorpion); //on r�actualise le tableau � chaque fois
         n_joueur = 2;  //on passe au joueur2
    } else //tour joueur2
    {
         tourJoueur(n_joueur,c_tabMorpion,c_symboleUtilisateur2);
         afficheMorpion(c_tabMorpion); //on r�actualise le tableau � chaque fois
         n_joueur = 1;  //on passe au joueur1
    }

    //Les condition de fin de partie (victoire ou match nul) :

    //cette boucle va parcourir le tableau et compter les cases vides
    //si � l'issue de cette boucle, il y a 0 cases vides, on peut consid�rer que la partie est finie et qu'il y a match nul
    n_casesVide=0; //on remet la variable � 0 pour �craser celle d'avant
     for (n_i = 0; n_i < TAILLE; n_i++)
    {
        for (n_j = 0; n_j < TAILLE; n_j++)
        {
            if (c_tabMorpion[n_i][n_j] == '_')
                n_casesVide++;
        }
    }
    //on v�rifie si les 3 symboles ont �t� align�s, et tout � la fin on regarde si le n_casesVide est bien �gal � 0.
    if (isAligned(c_tabMorpion,c_symboleUtilisateur) == 1) //la fonction isAligned renvoie 1 si 3 symboles sont align�s, 0 sinon
        n_fin = 1; // du coup si elle renvoie 1, 3 symbole sont align�s, on arr�te la partie
    else if (n_casesVide==0) //sinon si le nb de cases vides est �gale � 0, donc le tableau est rempli et personne n'a gagn�, on arr�te la partie
    {
        printf("Match nul !\n");
        n_fin = 1;
    }
    else //si pas de victoire et pas de match nul alors on continue la partie
        n_fin = 0;

} while (n_fin == 0);

return 0;
}

void initMorpion(char c_tabMorpion[TAILLE][TAILLE])
//BUT : proc�dure qui va initialiser tout le tableau du morpion avec des '_'
//ENTREE : le tableau de caract�res
//SORTIE : le tableau initialis�
{
    int n_i,n_j;
    for (n_i = 0; n_i < TAILLE; n_i++)
    {
        for (n_j = 0; n_j < TAILLE; n_j++)
        {
            c_tabMorpion[n_i][n_j] = '_';
        }

    }
}

void afficheMorpion (char c_tabMorpion[TAILLE][TAILLE])
//BUT : proc�dure qui nous permet d'afficher le morpion
//ENTREE : le tableau de caract�res
//SORTIE : le tableau affich�
{
    int n_i,n_j;
    printf("\n"); //juste pour espacer un peu le tableau des lignes de commande
    for (n_i = 0; n_i < TAILLE; n_i++)
    {
        for (n_j = 0; n_j < TAILLE; n_j++)
        {
            printf("%2c", c_tabMorpion[n_i][n_j]);
        }
        printf("\n");
    }
    printf("\n"); //juste pour espacer un peu le tableau des lignes de commande
}

char choixSymbole()
//BUT : cette fonction demande � l'utilisateur(consid�r� comme joueur1) quel symbole il va choisir pour la partie, et le renvoie
//ENTREE : rien
//SORTIE : le caract�re de l'utilisateur (joueur1)
{
    char c_symboleUtilisateur;
     do
     {
        printf("Joueur1, quel symbole voulez-vous utiliser ? X ou O\n");
        scanf("%c",&c_symboleUtilisateur);
        fflush(stdin);
     } while ((c_symboleUtilisateur != 'X') && (c_symboleUtilisateur != 'O')); //on boucle tant qu'il ne rentre pas X ou O

    return c_symboleUtilisateur; //et on retourne le caract�re du joueur 1
}


void tourJoueur(int n_joueur, char c_tabMorpion[TAILLE][TAILLE], char c_symboleUtilisateur)
//BUT : cette proc�dure g�re les tours des joueurs : elle demande les coordon�es x et y de l� o� le joueur veut placer son symbole, et v�rifie si la cellulle
//est d�j� occup�e ou non. si non, on place le symbole, si oui, on lui redemande des coordon�es
//ENTREE : n_joueur d�termine le joueur 1 ou 2, on passe le tableau du morpion ainsi que le symbole de l'utilisateur
//SORTIE : le caract�re de l'utilisateur (joueur1)
{
    int n_x,n_y;
    if (n_joueur==1) //si c'est le tour du joueur 1
    {
        do
        {
            printf("Joueur1, (%c) veuillez saisir la ligne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
            scanf("%d",&n_x);
            fflush(stdin); //on vide le buffer pour �tre s�r que rien ne viendra perturber le bon fonctionnement du programme
        } while ((n_x < 1) || (n_x>3));
        n_x--; //pour �tre plus user-friendly, on lui permet de saisir entre 1 et 3, mais on d�cr�mente afin de g�rer les indices de tableaux correctement
        do
        {
            printf("Joueur1, (%c) veuillez saisir la colonne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
            scanf("%d",&n_y);
            fflush(stdin);
        } while ((n_y < 1) || (n_y>3));
        n_y--; //pour �tre plus user-friendly, on lui permet de saisir entre 1 et 3, mais on d�cr�mente afin de g�rer les indices de tableaux correctement
        if (isOccupied(n_x,n_y,c_tabMorpion) == 0) //fonction isOccupied renvoie 0 si case non occup�e, et 1 si occup�e.
            c_tabMorpion[n_x][n_y] = c_symboleUtilisateur; //on met le symbole du joueur 1
        else //is la case est occup�e, on continue de lui redemander des coordonn�es...
        {
            printf("Desole, cellule deja occupee\n");
            do
            {
                do
                {
                    printf("Joueur1, (%c) veuillez saisir la ligne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
                    scanf("%d",&n_x);
                    fflush(stdin);
                } while ((n_x < 1) || (n_x>3));
                n_x--;
                do
                {
                    printf("Joueur1, (%c) veuillez saisir la colonne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
                    scanf("%d",&n_y);
                    fflush(stdin);
                } while ((n_y < 1) || (n_y>3));
                n_y--;
            } while (isOccupied(n_x,n_y,c_tabMorpion) != 0);//... jusqu'� qu'elles soient valides
            c_tabMorpion[n_x][n_y] = c_symboleUtilisateur; // et on place le symbole
        }
    } else //sinon tour joueur 2, la seule chose qui change �tant le symbole, mais les op�rations restent les m�mes
    {
        do
        {
            printf("Joueur2, (%c) veuillez saisir la ligne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
            scanf("%d",&n_x);
            fflush(stdin);
        } while ((n_x < 1) || (n_x>3));
        n_x--;
        do
        {
            printf("Joueur2, (%c) veuillez saisir la colonne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
            scanf("%d",&n_y);
            fflush(stdin);
        } while ((n_y < 1) || (n_y>3));
        n_y--;
        if (isOccupied(n_x,n_y,c_tabMorpion) == 0)
            c_tabMorpion[n_x][n_y] = c_symboleUtilisateur;
        else
        {
            printf("Desole, cellule deja occupee\n");
            do
            {
                do
                {
                    printf("Joueur2, (%c) veuillez saisir la ligne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
                    scanf("%d",&n_x);
                    fflush(stdin);
                } while ((n_x < 1) || (n_x>3));
                n_x--;
                do
                {
                    printf("Joueur2, (%c) veuillez saisir la colonne ou vous allez placer votre symbole\n", c_symboleUtilisateur);
                    scanf("%d",&n_y);
                    fflush(stdin);
                } while ((n_y < 1) || (n_y>3));
                n_y--;
            } while (isOccupied(n_x,n_y,c_tabMorpion) != 0);
            c_tabMorpion[n_x][n_y] = c_symboleUtilisateur;
        }
    }
}

int isOccupied(int n_x, int n_y, char c_tabMorpion[TAILLE][TAILLE])
//BUT : fonction qui va v�rifier si la cellule est occup�e. renvoie 0 si non, et 1 si la case est occup�e.
//ENTREE : coordonn�es x et y � v�rifier, et le tableau
//SORTIE : 1 si case occup�e, 0 sinon.
{
    if (c_tabMorpion[n_x][n_y] == '_') //le tableau �tant initialis� avec que des '_', cela nous permet de v�rifier si la case est occup�e ou non
         return 0;
    else
         return 1;
}


int isAligned(char c_tabMorpion[TAILLE][TAILLE], char c_symboleUtilisateur)
//BUT : //fonction qui va v�rifier si 3 symboles sont align�s
//ENTREE : le tableau, et le symbole pour d�terminer qui est le vainqueur
//SORTIE : 1 si quelqu'un a gagn� et donc fin de partie, 0 sinon.
{
    // on v�rifie le cas suivant : x x x
    //                             _ _ _
    //                             _ _ _
        if ((c_tabMorpion[0][0]) == (c_tabMorpion[0][1]) && ((c_tabMorpion[0][0]) == (c_tabMorpion[0][2])) && c_tabMorpion[0][0] != '_')
    {
        if (c_tabMorpion[0][0] == c_symboleUtilisateur) //on regarde si le symbole appartient au joueur 1 ou 2 pour d�terminer le vainqueur
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : _ _ _
    //                             x x x
    //                             _ _ _
    else if (((c_tabMorpion[1][0]) == (c_tabMorpion[1][1])) && ((c_tabMorpion[1][0]) == (c_tabMorpion[1][2])) && c_tabMorpion[1][0] != '_')
    {
        if (c_tabMorpion[1][0] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : _ _ _
    //                             _ _ _
    //                             x x x
    else if (((c_tabMorpion[2][0]) == (c_tabMorpion[2][1])) && ((c_tabMorpion[2][0]) == (c_tabMorpion[2][2])) && c_tabMorpion[2][0] != '_')
    {
        if (c_tabMorpion[2][0] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : x _ _
    //                             x _ _
    //                             x _ _
    else if (((c_tabMorpion[0][0]) == (c_tabMorpion[1][0])) && ((c_tabMorpion[0][0]) == (c_tabMorpion[2][0])) && c_tabMorpion[0][0] != '_')
    {
        if (c_tabMorpion[0][0] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : _ x _
    //                             _ x _
    //                             _ x _
    else if (((c_tabMorpion[0][1]) == (c_tabMorpion[1][1])) && ((c_tabMorpion[0][1]) == (c_tabMorpion[2][1])) && c_tabMorpion[0][1] != '_')
    {
        if (c_tabMorpion[0][1] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : _ _ x
    //                             _ _ x
    //                             _ _ x
    else if (((c_tabMorpion[0][2]) == (c_tabMorpion[1][2])) && ((c_tabMorpion[0][2]) == (c_tabMorpion[2][2])) && c_tabMorpion[0][2] != '_')
    {
        if (c_tabMorpion[0][2] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : x _ _
    //                             _ x _
    //                             _ _ x
    else if (((c_tabMorpion[0][0]) == (c_tabMorpion[1][1])) && ((c_tabMorpion[0][0]) == (c_tabMorpion[2][2])) && c_tabMorpion[0][0] != '_')
    {
        if (c_tabMorpion[0][0] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    // on v�rifie le cas suivant : _ _ x
    //                             _ x _
    //                             x _ _
    else if (((c_tabMorpion[0][2]) == (c_tabMorpion[1][1])) && ((c_tabMorpion[0][2]) == (c_tabMorpion[2][0])) && c_tabMorpion[0][2] != '_')
    {
        if (c_tabMorpion[0][2] == c_symboleUtilisateur)
            printf("Joueur 1 a gagne !\n");
        else
            printf("Joueur 2 a gagne ! \n");
        return 1;//on arr�te la partie si les symboles sont align�s
    }
    else
        return 0;
}
