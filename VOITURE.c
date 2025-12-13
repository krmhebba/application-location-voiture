#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOITURES 777
#define MAX_CLIENTS 777
#define MAX_LOCATIONS 777

typedef struct voiture {
    char marque[30];
    int annee;
    char matricule[30];
    int kilometrage;
    char etat[30];
} voiture;

typedef struct client {
    char nom[30];
    char adresse[30];
    int telephone;
    char identite[30];
} client;
typedef struct location {
    char identite[30];
    int datelocation;
    char matriculev[30];
    int dateretour;
    float montant;
    float avance;
    float reste;
} location;

void afficherMenuPrincipal() {
    printf(" ----------------------------------------------------------------------\n");
    printf("|                           MENU PRINCIPAL                             |\n");
    printf(" ----------------------------------------------------------------------\n");
    printf("| 1. Gestion des Voitures                                              |\n");
    printf("| 2. Gestion des Clients                                               |\n");
    printf("| 3. Gestion des Locations                                             |\n");
    printf("| 4. QUITTER                                                           |\n");
    printf("|                                                            Choix:_   |\n");
    printf(" ----------------------------------------------------------------------\n");
}

void afficherMenuGestionVoitures() {
    printf(" ----------------------------------\n");
    printf("|     MENU GESTION DES VOITURES    |\n");
    printf(" ----------------------------------\n");
    printf("| 1. Ajout d'une voiture           |\n");
    printf("| 2. Modification                  |\n");
    printf("| 3. Suppression                   |\n");
    printf("| 4. Recherche                     |\n");
    printf("| 5. Liste des voitures            |\n");
    printf("| 6. MENU PRINCIPAL                |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuGestionClients() {
    printf(" ----------------------------------\n");
    printf("|     MENU GESTION DES CLIENTS     |\n");
    printf(" ----------------------------------\n");
    printf("| 1. Ajout d'un client             |\n");
    printf("| 2. Modification                  |\n");
    printf("| 3. Suppression                   |\n");
    printf("| 4. Recherche                     |\n");
    printf("| 5. Liste des clients             |\n");
    printf("| 6. MENU PRINCIPAL                |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuModificationVoitures() {
    printf(" ----------------------------------\n");
    printf("| 1. Marque                        |\n");
    printf("| 2. Annee                         |\n");
    printf("| 3. Matricule                     |\n");
    printf("| 4. Kilometrage                   |\n");
    printf("| 5. Etat                          |\n");
    printf("| 6. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuModificationClients() {
    printf(" ----------------------------------\n");
    printf("| 1. Nom                           |\n");
    printf("| 2. Adresse                       |\n");
    printf("| 3. Identite                      |\n");
    printf("| 4. Telephone                     |\n");
    printf("| 5. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuSuppressionVoitures() {
    printf(" ----------------------------------\n");
    printf("| 1. Un par Un                     |\n");
    printf("| 2. Tout                          |\n");
    printf("| 3. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuSuppressionClients() {
    printf(" ----------------------------------\n");
    printf("| 1. Un par Un                     |\n");
    printf("| 2. Tout                          |\n");
    printf("| 3. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuRechercheVoitures() {
    printf(" ----------------------------------\n");
    printf("| 1. Par marque                    |\n");
    printf("| 2. Par annee                     |\n");
    printf("| 3. Par matricule                 |\n");
    printf("| 4. Par intervalle de kilometrage |\n");
    printf("| 5. Par etat                      |\n");
    printf("| 6. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

void afficherMenuRechercheClients() {
    printf(" ----------------------------------\n");
    printf("| 1. Par Nom                       |\n");
    printf("| 2. Par adresse                   |\n");
    printf("| 3. Par Identite                  |\n");
    printf("| 4. Par Telephone                 |\n");
    printf("| 5. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

int ajoutVoiture(voiture *v, int n)
{
    int valid,i;
    do{
            valid=0;
    printf("Matricule:\n");
    scanf("%s", v[n].matricule);
    for(i=0;i<n;i++)
    {
        if(strcmp(v[n].matricule,v[i].matricule)==0)
        {
            valid=-1;
        }
    }
    }while(valid!=0);
    printf("Marque:\n");
    scanf("%s", v[n].marque);
    printf("Annee:\n");
    scanf("%d", &v[n].annee);
    printf("Kilometrage:\n");
    scanf("%d", &v[n].kilometrage);
    getchar();
    do
    {
        printf("Etat (disponible/en cours de location):\n");
        fgets(v[n].etat, 30, stdin);
        v[n].etat[strcspn(v[n].etat, "\n")] = 0; // Enlever le '\n' de la fin
    }
    while (strcmp(v[n].etat, "disponible") != 0 && strcmp(v[n].etat, "en cours de location") != 0);
    fflush(stdin);
    return ++n;
}

int ajoutClient(client *c, int n) {
    int valid,i;
    printf("Nom:\n");
    scanf("%s", c[n].nom);
    printf("Adresse:\n");
    scanf("%s", c[n].adresse);
    printf("Telephone:\n");
    scanf("%d", &c[n].telephone);
    do
    {printf("Identite:\n");
    scanf("%s", c[n].identite);
    valid=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(c[n].identite,c[i].identite)==0)
        {
            valid=-1;
        }
    }
    }while(valid!=0);
    return ++n;
}

void modificationMarque(voiture *v, int pos) {
    printf("Entrer la nouvelle marque:\n");
    scanf("%s", v[pos].marque);
}

void modificationNom(client *c, int pos) {
    printf("Entrer le nouveau nom:\n");
    scanf("%s", c[pos].nom);
}

void modificationAnnee(voiture *v, int pos) {
    printf("Entrer la nouvelle annee:\n");
    scanf("%d", &v[pos].annee);
}

void modificationTelephone(client *c, int pos) {
    printf("Entrer le nouveau telephone:\n");
    scanf("%d", &c[pos].telephone);
}

void modificationMatricule(voiture *v, int pos) {
    printf("Entrer la nouvelle matricule:\n");
    scanf("%s", v[pos].matricule);
}

void modificationAdresse(client *c, int pos) {
    printf("Entrer la nouvelle adresse:\n");
    scanf("%s", c[pos].adresse);
}

void modificationKilometrage(voiture *v, int pos) {
    printf("Entrer le nouveau kilometrage:\n");
    scanf("%d", &v[pos].kilometrage);
}

void modificationEtat(voiture *v, int pos) {
    printf("Entrer le nouvel etat:\n");
    scanf("%s", v[pos].etat);
}

void modificationIdentite(client *c, int pos) {
    printf("Entrer la nouvelle identite:\n");
    scanf("%s", c[pos].identite);
}

int suppressionVoiture(int p, voiture *v, int n) {
    for (int i = p; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    return --n;
}

int suppressionClient(int p, client *c, int n) {
    for (int i = p; i < n - 1; i++) {
        c[i] = c[i + 1];
    }
    return --n;
}
int loginc(char logv[],int motv)
{char log[20];
int c;
    printf("login:");
        scanf("%s",log);
        printf("code:");
        scanf("%d",&c);
        if(strcmp(log,logv)==0)
        {
            printf("correction reussie!\n");
            return 1;
        }
        else
        {
            printf("login ou mot de passe incorrecte!`\n");
            return 0;
        }

}

int suppressionToutesVoitures(voiture *v,char login[],int code, int n) {
   if(loginc(login,code)==1)
   n=0;
    return n;


}

int suppressionTousClients(client *c, int n,char login [],int code) {
    if(loginc(login,code)==1)
   n=0;
    return n;
}

void rechercheVoitureParMarque(voiture *v, int n) {
    char marque[30];
    printf("Entrer la marque:\n");
    scanf("%s", marque);
    for (int i = 0; i < n; i++) {
        if (strcmp(marque, v[i].marque) == 0) {
            printf("%s\t%d\t%s\t%d\t%s\n", v[i].marque, v[i].annee, v[i].matricule, v[i].kilometrage, v[i].etat);
        }
    }
}

void rechercheClientParNom(client *c, int n) {
    char nom[30];
    printf("Entrer le nom:\n");
    scanf("%s", nom);
    for (int i = 0; i < n; i++) {
        if (strcmp(nom, c[i].nom) == 0) {
            printf("%s\t%s\t%s\t%d\n", c[i].nom, c[i].adresse, c[i].identite, c[i].telephone);
        }
    }
}

void afficherVoitures(voiture *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%s\t%d\t%s\n", v[i].marque, v[i].annee, v[i].matricule, v[i].kilometrage, v[i].etat);
    }
}

void afficherClients(client *c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n", c[i].nom, c[i].adresse, c[i].identite, c[i].telephone);
    }
}
void afficherMenuGestionLocation() {
     printf(" ----------------------------------\n");
    printf("|     MENU GESTION DES LOCATIONS    |\n");
    printf(" ----------------------------------\n");
    printf("| 1. Ajout dune location            |\n");
    printf("| 2. Prolongement                   |\n");
    printf("| 3. Suppression                    |\n");
    printf("| 4. Recherche                      |\n");
    printf("| 5. Liste des locations            |\n");
    printf("| 6. MENU PRINCIPAL                 |\n");
    printf("|                           Choix:_ |\n");
    printf(" ------------------------------------\n");
}



void mpl() {
    printf(" ----------------------------------\n");
    printf("| 1. par numero d'ouvrage          |\n");
    printf("| 2. par numero d'adherent         |\n");
    printf("| 2. par date                      |\n");
    printf("| 3. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}
void afficherMenuRechercheLocations() {
    printf(" ----------------------------------\n");
    printf("| 1. Par identite                  |\n");
    printf("| 2. Par matricule                 |\n");
    printf("| 3. Par date de location          |\n");
    printf("| 4. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}
int ajoutlocation(location *l, int n,voiture *v,int m,client *c,int j ) {
    int comp1,comp2,i,k;
    do
    {comp1=-1;
    printf("Matricule:\n");
    scanf("%s",l[n].matriculev);
    for(i=0;i<m;i++)
    {if(strcmp(l[n].matriculev,v[i].matricule)!=0&&strcmp(v[i].etat,"en cours de location")!=0)
    {

    }                comp1=0;

    }
    }while(comp1!=0);
    do{
    comp2=-1;
    printf("l'identite :\n");
    scanf("%s",l[n].identite);
    for(k=0;k<j;k++)
   {if(strcmp(l[n].identite,c[i].identite)!=0)
    {
    comp2=0;
    }
    }
    }while(comp2!=0);
    printf("Date de location:\n");
    scanf("%d", &l[n].datelocation);
    printf("Date de retour:\n");
    scanf("%d", &l[n].dateretour);
    printf("Montant:\n");
    scanf("%f", &l[n].montant);
    printf("Avance:\n");
    scanf("%f", &l[n].avance);
    l[n].reste=(l[n].montant)-(l[n].avance);
    printf("Reste:%f\n",l[n].reste);
    return n++;
}

void prolongementno(location *l ,int duree,int n) {
    int i,valid;
    char mat[30];
    do
    {printf("entrer la matricule a comparer");
    scanf("%s",mat);
    valid=-1;
    for(i=0;i<n;i++)
        {if(strcmp(mat,l[i].matriculev)!=0)
             {l[i].dateretour+=duree;
            printf("la nouvelle date de retour est %d:\n",l[i].dateretour);
            valid=0;
            }
       }

    }while(valid!=0);
}
void prolongementnad(location *l,int duree,int n) {
    char ide[20];
    int i,valid;
    do
    {
        printf("entrer l'identite a comparer");
        scanf("%s",ide);
        valid=-1;
    for(i=0;i<n;i++)
         {
             if(strcmp(l[i].identite,ide)!=0)
             {l[i].dateretour+=duree;
            printf("la nouvelle date de retour est %d:\n",l[i].dateretour);
            valid=0;
            }

          }
    }while(valid==-1);
}

void prolongementdate(location *l,int duree,int n) {
    int i;
    int date ;
    do
    {
        printf("entrer la date:");
        scanf("%d",&date);
    }while(date<=0);
    for(i=0;i<n;i++)
    {if(date==l[i].dateretour)
      {l[i].dateretour+=duree;
      printf("la nouvelle date de retour est %d",l[i].dateretour);}
}
}

void rechercheidentiteloca(location *l, int n) {
    char identite[30];
    printf("entrer l'identite de client:\n");
    scanf("%s", identite);
    for (int i = 0; i < n; i++) {
        if (strcmp(identite, l[i].identite) == 0) {
            printf("%s\t%d\t%s\t%d\t%f\t%f\t%f\n", l[i].identite, l[i].datelocation, l[i].matriculev, l[i].dateretour, l[i].montant,l[i].avance,l[i].reste);
        }
    }
}

void recherchematloca(location *l, int n) {
 char matricule [30];
    printf("entrer la:\n");
    scanf("%s", matricule);
    for (int i = 0; i < n; i++) {
        if (strcmp(matricule, l[i].matriculev) == 0) {
printf("%s\t%d\t%s\t%d\t%f\t%f\t%f\n", l[i].identite, l[i].datelocation, l[i].matriculev, l[i].dateretour, l[i].montant,l[i].avance,l[i].reste);
        }
    }
}

void recherchedatel(location *l, int n) {
    int date;
    printf("entrer la date de location:\n");
    scanf("%d", &date);
    for (int i = 0; i < n; i++) {
        if (date == l[i].datelocation) {
printf("%s\t%d\t%s\t%d\t%f\t%f\t%f\n", l[i].identite, l[i].datelocation, l[i].matriculev, l[i].dateretour, l[i].montant,l[i].avance,l[i].reste);

        }
    }
}

void affichelocation(location *l, int n) {
    int i;
    for (int i =0; i < n; i++) {
        printf("La location numero %d\t:%s\t%d\t%s\t%d\t%f\t%f\t%f\n",i+1, l[i].identite, l[i].datelocation, l[i].matriculev, l[i].dateretour, l[i].montant,l[i].avance,l[i].reste);

        }
}
int suppressionlocation(int pl, location *l, int n) {
    for (int i = pl; i < n - 1; i++) {
        l[i] = l[i + 1];

   }
    return n--;
}
char confirm()
{
  char accord[10];
    printf("voulez-vous supprimer?");
    do
    {
        scanf("%s",accord);
    }while (strcmp(accord,"oui")!=0&&strcmp(accord,"non")!=0);
    return accord;
}
int suppressiont(location*l, int n,char login,int mp) {
    if(loginc(login,mp)==1)
   n=0;
    return n;
}
void afficherMenuSuppressionlocations()
{
    printf(" ----------------------------------\n");
    printf("| 1. Un par Un                     |\n");
    printf("| 2. Tout                          |\n");
    printf("| 3. Retour                        |\n");
    printf("|                           Choix:_|\n");
    printf(" ----------------------------------\n");
}

int main()
{
    int i = 0, j = 0, choix, pos,C1, numVoitures = 0, numClients = 0,numLocation=0;
    char login[10]="hhf";
    int mot_de_passe=1234;
    voiture voitures[MAX_VOITURES];
    client clients[MAX_CLIENTS];
    location locations[MAX_LOCATIONS];
 int duree;

    do {
        afficherMenuPrincipal();
        scanf("%d", &C1);
        switch (C1) {
            case 1:
                do {
                    afficherMenuGestionVoitures();
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            numVoitures = ajoutVoiture(voitures, numVoitures);
                            break;
                        case 2:
                            afficherVoitures(voitures, numVoitures);
                            printf("Position à modifier :\n");
                            scanf("%d", &pos);
                            afficherMenuModificationVoitures();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1: modificationMarque(voitures, pos); break;
                                case 2: modificationAnnee(voitures, pos); break;
                                case 3: modificationMatricule(voitures, pos); break;
                                case 4: modificationKilometrage(voitures, pos); break;
                                case 5: modificationEtat(voitures, pos); break;
                            }
                            break;
                        case 3:
                            afficherVoitures(voitures, numVoitures);
                            afficherMenuSuppressionVoitures();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1:
                                    printf("Position à supprimer :\n");
                                    scanf("%d", &pos);
                                    numVoitures = suppressionVoiture(pos, voitures, numVoitures);
                                    break;
                                case 2:
                                    printf("%s",confirm());
                                    numVoitures = suppressionToutesVoitures(voitures,login,mot_de_passe, numVoitures);
                                    break;
                            }
                            break;
                        case 4:
                            afficherMenuRechercheVoitures();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1: rechercheVoitureParMarque(voitures, numVoitures); break;
                                // Ajouter d'autres options de recherche si nécessaire
                            }
                            break;
                        case 5:
                            afficherVoitures(voitures, numVoitures);
                            break;
                    }
                } while (choix != 6);
                break;
            case 2:
                do {
                    afficherMenuGestionClients();
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            numClients = ajoutClient(clients, numClients);
                            break;
                        case 2:
                            afficherClients(clients, numClients);
                            printf("Position à modifier :\n");
                            scanf("%d", &pos);
                            afficherMenuModificationClients();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1: modificationNom(clients, pos); break;
                                case 2: modificationAdresse(clients, pos); break;
                                case 3: modificationIdentite(clients, pos); break;
                                case 4: modificationTelephone(clients, pos); break;
                            }
                            break;
                        case 3:
                            afficherClients(clients, numClients);
                            afficherMenuSuppressionClients();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1:
                                    printf("Position à supprimer :\n");
                                    scanf("%d", &pos);
                                    numClients = suppressionClient(pos, clients, numClients);
                                    break;
                                case 2:
                                    numClients = suppressionTousClients(clients, numClients,login,mot_de_passe);
                                    break;
                            }
                            break;
                        case 4:
                            afficherMenuRechercheClients();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1: rechercheClientParNom(clients, numClients); break;
                                // Ajouter d'autres options de recherche si nécessaire
                            }
                            break;
                        case 5:
                            afficherClients(clients, numClients);
                            break;
                    }
                } while (choix != 6);
                break;
            case 3:
                   do {
                        afficherMenuGestionLocation();
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            numLocation = ajoutlocation(locations, numLocation,voitures,numVoitures,clients,numClients);
                            break;
                        case 2:

                            mpl();
                            scanf("%d", &choix);
                            switch (choix) {
                                do
                                {
                                    printf("entrer la duree a ajouter");
                                    scanf("%d",&duree);
                                }while(duree<=0);


                                case 1:prolongementno(locations,duree,numVoitures); break;
                                case 2: prolongementnad(locations,duree,numClients); break;
                                case 3: prolongementdate(locations,numLocation,duree ); break;
                                case 4: prolongementdate(locations,duree,numLocation); break;
                            }
                            break;
                        case 3:
                            affichelocation(locations, numLocation);
                            afficherMenuSuppressionlocations();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1:
                                    do{printf("Position à supprimer :\n");
                                 scanf("%d", &pos);}while(pos<1||pos>numLocation);
                                    pos--;


                                    numLocation = suppressionlocation(pos, locations, numLocation);
                                    break;
                                case 2:
                                    printf("%s",confirm());
                                    suppressiont( locations,numLocation,login,mot_de_passe);
                                    break;
                            }
                            break;
                        case 4:
                            afficherMenuRechercheLocations();
                            scanf("%d", &choix);
                            switch (choix) {
                                case 1: rechercheidentiteloca(locations, numLocation); break;
                                case 2: recherchematloca(locations, numLocation); break;
                                case 4: recherchedatel(locations, numLocation); break;
                            }
                            break;
                        case 5:
                            affichelocation(locations,numLocation);
                            break;
                    }
                } while (choix != 6);
                break;
        }
        }while (C1!=4);
        return 0;
    }
