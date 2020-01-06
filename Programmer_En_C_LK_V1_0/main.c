#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE 100


int main ()
{



//Les fichiers


/* string containing a file access mode. It can be:
"r" read: Open file for input operations. The file must exist.
"w" write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
"a" append: Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it.
            Repositioning operations (fseek, fsetpos, rewind) are ignored. The file is created if it does not exist.
"r+" read/update: Open a file for update (both for input and output). The file must exist.
"w+" write/update: Create an empty file and open it for update (both for input and output).
                    If a file with the same name already exists its contents are discarded and the file is treated as a new empty file.
"a+" append/update: Open a file for update (both for input and output) with all output operations writing data at the end of the file.
                    Repositioning operations (fseek, fsetpos, rewind) affects the next input operations, but output operations move the position back to the end of file. The file is created if it does not exist.
*/
int saisie(char cSaisie[100],int nTaille);



int main()
{

    char cnomFichier[TAILLE];
    FILE *fSortie=NULL;//Descripteur de fichier
    FILE *fEntree=NULL;//Descripteur de fichier

    //Les fichiers txt

    char cSaisie[100];//chaine de saisie
    int errnum=0;
    int nVal=0;
    int nNombreVal=0;
    int nOccurence=0;


    //Saisie de valeurs numeriques dans le fichier
   /* printf("Donnez le nom du fichier a creer : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);
    if((fSortie=fopen(cnomFichier,"w"))==NULL){//Ouverture en ecriture
            fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));
            //Gestion des erreurs
    }else{
            do{
                    printf("donnez un entier : \n");
                    scanf("%d",&nVal);//Saisie de notre entier
                    if(nVal!=0){
                        fprintf(fSortie,"%d\n",nVal);//Ecriture formate dans le fichier
                        nOccurence++;//Compte le nombre de valeurs saisies
                    }
            }while(nVal);
    }
    fclose(fSortie);//fermeture du descripteur de fichier
    printf("Donnez le nom du fichier a lister : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);
    if((fEntree=fopen(cnomFichier,"r"))==NULL){
            fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));
             //Gestion des erreurs
    }else{
            while(nNombreVal<nOccurence){
                fscanf(fEntree,"%d",&nVal);// lecture formate dans le fichier, affectation de la valeur  dans nVal
                printf("%d",nVal);//Affichage a l'ecran de la valeur
                nNombreVal++;
            }
    }
    fclose(fEntree);//fermeture du descripteur fichier*/



   /* printf("Donnez le nom du fichier a creer : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);
    if((fSortie=fopen(cnomFichier,"w"))==NULL){
            fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));
             //Gestion des erreurs
    }else{
            //do{
            //    fgets(cSaisie,sizeof(cSaisie),stdin);
            //    fputs(cSaisie,fSortie);
            //}while(positionEntree=strchr(cSaisie,'\n'),positionEntree!=NULL?*positionEntree='\0':fflush(stdin),strcmp(cSaisie,":q")!=0)
            //suppression du carcatere de saut ligne et test si chaine equivalente a :q
            while(saisie(cSaisie,100)&&strcmp(cSaisie,":q")){
                fputs(cSaisie,fSortie); //Ecriture de la chaine dans le fichier
                fputc('\n',fSortie);//Ajout du caractere saut de ligne pour chaque ligne du fichier
            }
    }
    fclose(fSortie);//fermeture du descripteur fichier
    printf("Donnez le nom du fichier a lister : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);
    if((fEntree=fopen(cnomFichier,"r"))==NULL){
            fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));
             //Gestion des erreurs
    }else{
        while (fgets(cSaisie, 100, fEntree) != NULL) // On lit les chaines de caracteres tant que la reference est differente de NULL
        {
            printf("%s", cSaisie); // On affiche la chaine que nous venons de lire
        }
    }
    fclose(fEntree);//fermeture du descripteur fichier*/



    //Les Fichiers Binaires


    printf("Donnez le nom du fichier a creer : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);


    if((fSortie=fopen(cnomFichier,"wb"))==NULL){

          fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));//Gestion des erreurs
    }else{

        do{
            printf("donnez un entier : \n");
            scanf("%d",&nVal);

            if(nVal)
                fwrite(&nVal,sizeof(int),1,fSortie);//Ecriture dans le fichier en mode binaire
            //Cette fonction permet d'écrire un certain nombre d'octets vers le flux
            //spécifié en quatrième paramètre.
            //Les octets à écrire seront stockés dans le buffer passé en premier paramètre. Pour spécifier le nombre d'octets à écrire,
            //il faut jouer sur deux paramètres : le nombre de bloc d'octets à lire
            //ainsi que la taille de chacun des blocs.
        }while(nVal);


    }


    fclose(fSortie);

    printf("Donnez le nom du fichier a lister : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);

    if((fEntree=fopen(cnomFichier,"rb"))==NULL){

         fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));//Gestion des erreurs
    }else{


    //Cette fonction permet de lire un certain nombre d'octets à partir
    //d'un flux. L'ensemble des octets lu seront stockés dans un buffer
    //passé en premier paramètre : il faut donc être certain que le buffer
    // est bien de taille suffisante, par rapport à la taille des données
    // demandées. Pour spécifier le nombre d'octets à lire,
    //il faut jouer sur deux paramètres : le nombre de bloc d'octets
    //à lire ainsi que la taille de chacun des blocs.
    //La taille totale du buffer à allouer sera donc le produit de
    //ces deux tailles précédentes.
        while(fread(&nVal,sizeof(int),1,fEntree)&&!feof(fEntree))//Lecture dans le fichier en mode binaire
            printf("\n%d",nVal);

    }

    fclose(fEntree);

    // do{
    //     fread(&nVal,sizeof(int),1,fEntree);
    //      if(!feof(fEntree))
    //        printf("\n%d",nVal);

    //}while(!feof(fEntree));


    printf("\nDonnez le nom du fichier a consulter : \n");
    scanf("%20s",cnomFichier);
    fflush(stdin);


    if((fEntree=fopen(cnomFichier,"rb"))==NULL){

        fprintf(stderr,"Erreur ouverture fichier :%s\n",strerror(errnum));//Gestion des erreurs
    }else{

        long nNum;
        printf("\nEntrez le numero de l'entier cherche :\n");
        scanf("%ld",&nNum);


        while(nNum){

            fseek(fEntree,sizeof(int)*(nNum-1),SEEK_SET);//Deplacement du crusor dans le fichier à la position sizeof(int)*(nNum-1)
            fread(&nVal,sizeof(int),1,fEntree);//Lit les entiers du fichiers(4 octets), et stock la valeur à la référence de nVal.
            printf("valeur : %d\n",nVal);



            printf("Entrez le numero de l'entier cherche :\n");
            scanf("%ld",&nNum);


        }

    }


    fclose(fEntree);


   return 0;
}


int saisie(char cSaisie[100],int nTaille){

    char *positionEntree = NULL;


    if(fgets(cSaisie,nTaille,stdin)!=NULL){

        positionEntree=strchr(cSaisie,'\n');

        positionEntree!=NULL?*positionEntree='\0':fflush(stdin);

        return 1;
    }else{

        fflush(stdin);
        return 0;

    }


}
}

