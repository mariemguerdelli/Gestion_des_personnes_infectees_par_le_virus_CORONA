#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include<string.h>
typedef char chaine[20];

typedef struct{
char nommaladie;
int nbrannee;
}maladie;

typedef struct CelluleMaladie{
maladie m;
struct CelluleMaladie* suivant;
}CelluleMaladie;

typedef CelluleMaladie* ListeMaladie;

typedef struct {
int jour;
int mois;
int annee;
}date;

typedef struct{
chaine CIN;
chaine Nom;
chaine Prenom;
chaine numTel;
chaine nationalite;
int age;
date dateInfection;
int Decede;
CelluleMaladie* maladies;
}PersonneInfecte;

typedef struct Cellule{
PersonneInfecte p;
struct Cellule* suivant;
}Cellule;

typedef Cellule* ListePersonnesInfectees;

ListePersonnesInfectees charger_Personnes (chaine nomFichierPersonnes, chaine nomFichierMaladies){
FILE* k;
FILE* f;
ListePersonnesInfectees L=NULL;
ListePersonnesInfectees nouveau=NULL;
ListePersonnesInfectees courant =NULL;
ListeMaladie nouveau1,courant1;
PersonneInfecte p;
maladie m;
chaine CIN;
k= fopen(nomFichierPersonnes, "r") ;
if(k==NULL)
printf("impossible d'ouvrir le fichier de personne");
else{
while(!feof(k)){
fscanf(k,"%s",p.CIN);
fscanf(k,"%s",p.Nom);
fscanf(k,"%s",p.Prenom);
fscanf(k,"%s",p.numTel);
fscanf(k,"%s",p.nationalite);
fscanf(k,"%d",&p.age);
fscanf(k,"%d",&p.dateInfection.jour);
fscanf(k,"%d",&p.dateInfection.mois);
fscanf(k,"%d",&p.dateInfection.annee);
fscanf(k,"%d\n",&p.Decede);
p.maladies=NULL;
if(L==NULL){
nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
nouveau->p=p;
nouveau->suivant=NULL;
L=nouveau;

}else{
courant=L;
while(courant->suivant!=NULL)
courant=courant->suivant;
nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
nouveau->p=p;
courant->suivant=nouveau;
nouveau->suivant=NULL;

}

}

fflush(stdin);
}
fclose(k);

//getch();
f=fopen(nomFichierMaladies,"r");
if(f==NULL)
printf("impossible d'ouvrir le fichier de maladies");
else{
  while(!feof(f)){
    fscanf(f,"%s",CIN);
    fscanf(f,"%s",m.nommaladie);
    fscanf(f,"%d\n",&m.nbrannee);
   courant=L;
   while(courant!=NULL && strcmp(CIN,courant->p.CIN)!=0)
   courant=courant->suivant;
 if(courant!=NULL){
courant1=courant->p.maladies;
if(courant->p.maladies==NULL){
nouveau1=(ListeMaladie)malloc(sizeof(CelluleMaladie));
nouveau1->m=m;
nouveau1->suivant=NULL;
courant->p.maladies=nouveau1;
}else{
while(courant1->suivant!=NULL)
courant1=courant1->suivant;
nouveau1=(ListeMaladie)malloc(sizeof(CelluleMaladie));
nouveau1->m=m;
nouveau1->suivant=NULL;
courant1->suivant=nouveau1;
}

}


  }

}fclose(f);
fflush(stdin);
//getch();
return L;
}
void AfficherPersonnesInfectees(ListePersonnesInfectees L){
ListePersonnesInfectees courant=L;
ListeMaladie mm1;
if(L==NULL)
    printf("liste est vide ");
else

   while(courant!=NULL){
        printf("%s %s %s %s %s ",courant->p.CIN,courant->p.Nom,courant->p.Prenom,courant->p.numTel,courant->p.nationalite);
        printf(" %d %d %d %d %d ",courant->p.age,courant->p.dateInfection.jour,courant->p.dateInfection.mois,courant->p.dateInfection.annee,courant->p.Decede);
        mm1=courant->p.maladies;
        while(mm1!=NULL){
            printf(" %s %d ",mm1->m.nommaladie,mm1->m.nbrannee);
            mm1=mm1->suivant;

        }
        printf("\n\n");
        courant=courant->suivant;

    }


}
ListePersonnesInfectees Ajouter (ListePersonnesInfectees L){
PersonneInfecte p;
ListePersonnesInfectees courant=L;
ListePersonnesInfectees nouveau;
ListeMaladie n,c;
maladie m;
int i,nm;
printf("CIN : ");
scanf("%s",p.CIN);
printf("NOM :");
scanf("%s",p.Nom);
printf("PRENOM :");
scanf("%s",p.Prenom);
printf("NUM_TEL : ");
scanf("%s",p.numTel);
printf("NATIONALITE : ");
scanf("%s",p.nationalite);
printf("AGE :");
scanf("%d",&p.age);
printf("JOUR_INFECTION :");
scanf("%d",&p.dateInfection.jour);
printf("MOIS_INFECTION : ");
scanf("%d",&p.dateInfection.mois);
printf("ANNEE_INFECTION : ");
scanf("%d",&p.dateInfection.annee);
printf("DECEDE : ");
scanf("%d",&p.Decede);
p.maladies=NULL;
printf("NBR_MALADIE : ");
scanf("%d",&nm);
for(i=0;i<nm;i++){
        c=p.maladies;
        printf("DONNER NOM_MALADIE : ");
        scanf("%s",m.nommaladie);
        printf("DONNER NBR_ANNEE_MALADIE : ");
        scanf("%d",&m.nbrannee);
        if(c==NULL){
            n=(ListeMaladie)malloc(sizeof(CelluleMaladie));
            n->m=m;
            n->suivant=NULL;
            p.maladies=n;
        }else{
        while(c->suivant!=NULL)
            c=c->suivant;
            n=(ListeMaladie)malloc(sizeof(CelluleMaladie));
            n->m=m;
            n->suivant=NULL;
            c->suivant=n;
            }
}
if(L==NULL){
    nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
    nouveau->p=p;
    nouveau->suivant=NULL;
    L=nouveau;
}else{
            while(courant->suivant!=NULL)
               courant=courant->suivant;
    nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
    nouveau->p=p;
    nouveau->suivant=NULL;
    courant->suivant=nouveau;
}

return L;


}
ListePersonnesInfectees supprimer (ListePersonnesInfectees L, char* CIN){

ListePersonnesInfectees courant=L;
ListePersonnesInfectees precedent;
if(L==NULL)
    printf("liste vide \n");
else{
    if(strcmp(L->p.CIN,CIN)==0){
   L=L->suivant;
   free(courant);
   }
    else{
    while(courant!=NULL&&(strcmp(courant->p.CIN,CIN)!=0)){
        precedent=courant;
        courant=courant->suivant;
    }
    if(courant==NULL)

    printf("Le personne n'existe pas ");

    else{
        precedent->suivant=courant->suivant;
        free(courant);
        printf("Suppression éffectuée\n");
    }


    }
}

return L;

}
ListePersonnesInfectees AjouterMaladie ( ListePersonnesInfectees L,char* CIN, char maladie, int annees){
ListePersonnesInfectees courant;
ListeMaladie c,n;
courant=L;
   while(courant!=NULL && strcmp(CIN,courant->p.CIN)!=0)
    courant=courant->suivant;
   if(courant==NULL)
    printf("CIN n'existe pas");
   else{
    c=courant->p.maladies;
    if(courant->p.maladies==NULL){
        n=(ListeMaladie)malloc(sizeof(CelluleMaladie));
        n->m.nbrannee=annees;
        n->m.nommaladie,maladie;
        n->suivant=NULL;
        courant->p.maladies=n;
    }else{
        while(c->suivant!=NULL)
            c=c->suivant;
        n=(ListeMaladie)malloc(sizeof(CelluleMaladie));
        n->m.nbrannee=annees;
       // n->m.nommaladie=nmaladie;
        n->suivant=NULL;
        c->suivant=n;
    }
   }

return L;

}

ListePersonnesInfectees modifierDeces(ListePersonnesInfectees L, char *CIN){
ListePersonnesInfectees courant=L;
if(L==NULL)
    printf("La liste est vide \n");

else{
    while(courant!=NULL&&(strcmp(courant->p.CIN,CIN)!=0))
        courant=courant->suivant;
    if(courant==NULL)
    printf("ERREUR, CIN n'existe pas;");

    else{
        courant->p.Decede=1;
        printf("Modification avec succés\n");
    }


    }
    return L;
}
void afficherParNationalite(ListePersonnesInfectees L, char* Nationalite){
ListePersonnesInfectees courant=L;
ListeMaladie cr1;
if(L==NULL)
    printf("La liste est vide");
else

do{
    if(strcmp(Nationalite,courant->p.nationalite)==0){
        printf("%s %s %s %s %s",courant->p.CIN,courant->p.Nom,courant->p.Prenom,courant->p.numTel,courant->p.nationalite);
        printf(" %d %d %d %d %d ",courant->p.age,courant->p.dateInfection.jour,courant->p.dateInfection.mois,courant->p.dateInfection.annee,courant->p.Decede);
        cr1=courant->p.maladies;
        while(cr1!=NULL){
            printf("%s %d",cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;
        }}
        printf("\n");
    courant=courant->suivant;

}while(courant!=NULL);

}



void afficherPersonnesDecedes (ListePersonnesInfectees L){
    ListePersonnesInfectees k=L;
    float t=0,d=0;
if(L==NULL)
    printf("La liste est vide");
else
do{
        if(k->p.Decede)
        {
            printf("%s\t%s\n",k->p.Nom,k->p.Prenom);
            d++;
        }
        k=k->suivant;
        t++;

}while(k!=0);
if(d==0)
    printf("le pourcentage de dece est 0\n");
else
    printf("le pourcentage de dece est %f\n",(d/t)*100);

 }


const int nbreJrsParMois[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

int nbreAnneeBisextile (date d)
{
  int years = d.annee;

  if (d.mois<= 2)
    years--;

  return years / 4 - years / 100 + years / 400;
}

int diffrenceDates (date dt1, date dt2)
{
    long int n1 = dt1.annee*365 + dt1.jour;
    int i;

    for ( i=0; i<dt1.mois - 1; i++)
        n1 += nbreJrsParMois[i];

    n1 += nbreAnneeBisextile(dt1);


    long int n2 = dt2.annee*365 + dt2.jour;
    for ( i=0; i<dt2.mois - 1; i++)
        n2 += nbreJrsParMois[i];
    n2 += nbreAnneeBisextile(dt2);

    return (n2 - n1);
}

void afficherPersonnesEnQuarantaine (ListePersonnesInfectees L, date DateEncours)
{
  Cellule* courant = L;
  int diffDate = 0;
  if (L == NULL)
  {
    printf ("La Liste est vide\n");
  }
  else
  {
    while (courant != NULL)
    {

      diffDate = diffrenceDates (courant->p.dateInfection, DateEncours);
      if (diffDate < 14)
      {
        printf("%s\t%s\n", courant->p.Nom, courant->p.Prenom);
      }


      courant = courant->suivant;
    }
    if (diffDate >= 14){
        printf("Aucune personne en quarantine\n");
    }
  }
}


void AfficherPersonnesARisque (ListePersonnesInfectees L)
{
  Cellule* courant = L;
  CelluleMaladie* courantM;

  int risque = 0;

  if (L == NULL)
    printf("La liste est vide\n");
  else
  {
    printf ("***** Personnes a risque *****\n");
    while (courant != NULL)
    {
      if(courant->p.age > 70)
      {
        risque += 20;
      }
      else if ( (courant->p.age <= 70) && (courant->p.age > 50) )
      {
        risque += 10;
      }

      courantM = courant->p.maladies;
      while (courantM != NULL)
      {
        if ( strcmp("DIABETE", courantM->m.nommaladie) == 0)
        {
          risque += 15;
        }
        else if ( strcmp ("HYPERTENSION",courantM->m.nommaladie) == 0)
        {
          risque += 20;
        }
        else if ( strcmp ("ASTHME",courantM->m.nommaladie) == 0)
        {
          risque += 20;
        }

        courantM = courantM->suivant;
      }

      if (risque != 0)
      {
        printf ("%s\t%s\t risque = %d%%\n", courant->p.Nom, courant->p.Prenom, risque);
      }

      courant = courant->suivant;
      risque = 0;

    }
  }

}






void annim_ex1()
{


int kit,count=1;


for(kit=0;kit<35;kit++)
{
printf("*");
Sleep(60);
}

printf("\n");

printf("      \t\t\t                        *                                 *\n");
Sleep(60);
printf("                                                *            AFFICHAGE            *\n");
Sleep(60);
printf("      \t\t\t                        *                                 *\n\t");
Sleep(60);



printf("                                        ");

for(kit=0;kit<35;kit++)
{
printf("*");
Sleep(60);
}
printf("\n\n");

printf("\n\n\n");

}

void enregistrement(ListePersonnesInfectees l,char * nomFichier,char * nomFichier1){
    FILE *fp;
    FILE *fp1;
    ListePersonnesInfectees courant=l;
    ListeMaladie cr1;
    //FILE *fp1;
    fp=fopen(nomFichier,"w");
    fp1=fopen(nomFichier1,"w");

 while(courant!=NULL){
      fprintf(fp,"%s %s %s %s %s %d %d %d %d %d\n",courant->p.CIN,courant->p.Nom,courant->p.Prenom,courant->p.numTel,courant->p.nationalite,courant->p.age,courant->p.dateInfection.jour,courant->p.dateInfection.mois,courant->p.dateInfection.annee,courant->p.Decede);
        cr1=courant->p.maladies;
        while(cr1!=NULL){
            fprintf(fp1,"%s %s %d\n",courant->p.CIN,cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;

        }
        printf("\n\n");
        courant=courant->suivant;

    }
fclose(fp);
fclose(fp1);
}



#endif // GESTION_H_INCLUDED
