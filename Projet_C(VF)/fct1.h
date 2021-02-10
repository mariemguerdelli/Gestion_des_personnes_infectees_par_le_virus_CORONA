#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include<string.h>
typedef char chaine[20];
typedef struct{
chaine nommaladie;
int nbrannee;
}maladie;
typedef struct cellulemaladie{
maladie m;
struct cellulemaladie* suivant;
}cellulemaladie;
typedef cellulemaladie* ListeMaladie;
typedef struct {
int jour;
int mois;
int annee;
}date;
typedef struct{
chaine Cin;
chaine Nom;
chaine Prenom;
chaine numTel;
chaine nationalite;
int age;
date dateInfection;
int Decede;
cellulemaladie* maladies;
}PersonneInfecte;
typedef struct Cellule{
PersonneInfecte p1;
struct Cellule* suivant;
}Cellule;
typedef Cellule* ListePersonnesInfectees;

ListePersonnesInfectees charger_Personnes (chaine nomFichierPersonnes, chaine nomFichierMaladies){
FILE* k;
FILE* t;
ListePersonnesInfectees l=NULL;
ListePersonnesInfectees noveau=NULL;
ListePersonnesInfectees courant =NULL;
ListeMaladie noveau1,courant1;
PersonneInfecte p1;
maladie m;
chaine Cin;
k= fopen(nomFichierPersonnes, "r") ;
if(k==NULL)
printf("impossible d'ouvrir le fichier de person");
else{
while(!feof(k)){
fscanf(k,"%s",p1.Cin);
fscanf(k,"%s",p1.Nom);
fscanf(k,"%s",p1.Prenom);
fscanf(k,"%s",p1.numTel);
fscanf(k,"%s",p1.nationalite);
fscanf(k,"%d",&p1.age);
fscanf(k,"%d",&p1.dateInfection.jour);
fscanf(k,"%d",&p1.dateInfection.mois);
fscanf(k,"%d",&p1.dateInfection.annee);
fscanf(k,"%d\n",&p1.Decede);
p1.maladies=NULL;
if(l==NULL){
noveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
noveau->p1=p1;
noveau->suivant=NULL;
l=noveau;
}else{
courant=l;
while(courant->suivant!=NULL)
courant=courant->suivant;
noveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
noveau->p1=p1;
courant->suivant=noveau;
noveau->suivant=NULL;

}

}

fflush(stdin);
}
fclose(k);

//getch();
t=fopen(nomFichierMaladies,"r");
if(t==NULL)
printf("impossible d'ouvrir le fichier de maladies");
else{
  while(!feof(t)){
    fscanf(t,"%s",Cin);
    fscanf(t,"%s",m.nommaladie);
    fscanf(t,"%d\n",&m.nbrannee);
   courant=l;
   while(courant!=NULL && strcmp(Cin,courant->p1.Cin)!=0)
   courant=courant->suivant;
 if(courant!=NULL){
courant1=courant->p1.maladies;
if(courant->p1.maladies==NULL){
noveau1=(ListeMaladie)malloc(sizeof(cellulemaladie));
noveau1->m=m;
noveau1->suivant=NULL;
courant->p1.maladies=noveau1;
}else{
while(courant1->suivant!=NULL)
courant1=courant1->suivant;
noveau1=(ListeMaladie)malloc(sizeof(cellulemaladie));
noveau1->m=m;
noveau1->suivant=NULL;
courant1->suivant=noveau1;
}

}


  }

}fclose(t);
fflush(stdin);
//getch();
return l;
}
void AfficherPersonnesInfectees(ListePersonnesInfectees l){
ListePersonnesInfectees courant=l;
ListeMaladie cr1;
if(l==NULL)
    printf("liste est vide ");
else

   while(courant!=NULL){
        printf("%s %s %s %s %s ",courant->p1.Cin,courant->p1.Nom,courant->p1.Prenom,courant->p1.numTel,courant->p1.nationalite);
        printf(" %d %d %d %d %d ",courant->p1.age,courant->p1.dateInfection.jour,courant->p1.dateInfection.mois,courant->p1.dateInfection.annee,courant->p1.Decede);
        cr1=courant->p1.maladies;
        while(cr1!=NULL){
            printf(" %s %d ",cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;

        }
        printf("\n\n");
        courant=courant->suivant;

    }



}
ListePersonnesInfectees Ajouter (ListePersonnesInfectees l){
PersonneInfecte p;
ListePersonnesInfectees courant=l;
ListePersonnesInfectees noveau;
ListeMaladie n,c;
maladie m;
int i,nm;
printf("CIN : ");
scanf("%s",p.Cin);
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
        printf("NOM_MALADIE : ");
        scanf("%s",m.nommaladie);
        printf("NBR_ANNEE_MALADIE : ");
        scanf("%d",&m.nbrannee);
        if(c==NULL){
            n=(ListeMaladie)malloc(sizeof(cellulemaladie));
            n->m=m;
            n->suivant=NULL;
            p.maladies=n;
        }else{
        while(c->suivant!=NULL)
            c=c->suivant;
            n=(ListeMaladie)malloc(sizeof(cellulemaladie));
            n->m=m;
            n->suivant=NULL;
            c->suivant=n;
            }
}
if(l==NULL){
    noveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
    noveau->p1=p;
    noveau->suivant=NULL;
    l=noveau;
}else{
            while(courant->suivant!=NULL)
               courant=courant->suivant;

    noveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
    noveau->p1=p;
    noveau->suivant=NULL;
    courant->suivant=noveau;
}

return l;


}
ListePersonnesInfectees supprimer (ListePersonnesInfectees l, char* CIN){

ListePersonnesInfectees courant=l;
ListePersonnesInfectees presedant;
if(l==NULL)
    printf("liste vide \n");
else{
    if(strcmp(l->p1.Cin,CIN)==0){
   l=l->suivant;
   free(courant);
   }
    else{
    while(courant!=NULL&&(strcmp(courant->p1.Cin,CIN)!=0)){
        presedant=courant;
        courant=courant->suivant;
    }
    if(courant==NULL)

    printf("person n existe pas");

    else{
        presedant->suivant=courant->suivant;
        free(courant);
        printf("le person a supprimer\n");
    }


    }
}

return l;

}
ListePersonnesInfectees AjouterMaladie ( ListePersonnesInfectees l,char* CIN, chaine nmaladie, int annees){
ListePersonnesInfectees courant;
ListeMaladie c,n;
courant=l;
   while(courant!=NULL && strcmp(CIN,courant->p1.Cin)!=0)
    courant=courant->suivant;
   if(courant==NULL)
    printf("cin n'exist pas");
   else{
    c=courant->p1.maladies;
    if(courant->p1.maladies==NULL){
        n=(ListeMaladie)malloc(sizeof(cellulemaladie));
        n->m.nbrannee=annees;
        n->m.nommaladie,nmaladie;
       // n->m.nommaladie=nmaladie;
        n->suivant=NULL;
        courant->p1.maladies=n;
    }else{
        while(c->suivant!=NULL)
            c=c->suivant;
        n=(ListeMaladie)malloc(sizeof(cellulemaladie));
        n->m.nbrannee=annees;
       // n->m.nommaladie=nmaladie;
        n->suivant=NULL;
        c->suivant=n;
    }
   }

return l;


}
ListePersonnesInfectees modifierDeces(ListePersonnesInfectees l, chaine CIN){
ListePersonnesInfectees courant=l;
if(l==NULL)
    printf("liste vide \n");

else{
    while(courant!=NULL&&(strcmp(courant->p1.Cin,CIN)!=0))
        courant=courant->suivant;
    if(courant==NULL)
    printf("ERREUR, CIN n'existe pas;");

    else{
        courant->p1.Decede=1;
        printf("Modification avec succés\n");
    }


    }
    return l;
}
void afficherParNationalite(ListePersonnesInfectees l, char* Nationalite){
ListePersonnesInfectees courant=l;
ListeMaladie cr1;
if(l==NULL)
    printf("liste vide");
else

/*while (strcmp(Nationalite,courant->p1.nationalite)!=0){
            printf("erreur");
            printf("donner nationalite : ");
            scanf("%s",Nationalite);}*/
   /* if (strcmp(Nationalite,courant->p1.nationalite)!=0){
    printf("erreur");
    courant=courant->suivant;
}*/


do{
    if(strcmp(Nationalite,courant->p1.nationalite)==0){
        printf("%s %s %s %s %s",courant->p1.Cin,courant->p1.Nom,courant->p1.Prenom,courant->p1.numTel,courant->p1.nationalite);
        printf(" %d %d %d %d %d ",courant->p1.age,courant->p1.dateInfection.jour,courant->p1.dateInfection.mois,courant->p1.dateInfection.annee,courant->p1.Decede);
        cr1=courant->p1.maladies;
        while(cr1!=NULL){
            printf("%s %d",cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;
        }}
        printf("\n");
    courant=courant->suivant;

}while(courant!=NULL);

/*do{
    if(strcmp(Nationalite,courant->p1.nationalite)!=0){
        printf("erreur");}
        printf("\n");
    courant=courant->suivant;

}while(courant!=NULL);*/
}



void afficherPersonnesDecedes (ListePersonnesInfectees l){
    ListePersonnesInfectees k=l;
    float t=0,d=0;
if(l==NULL)
    printf("liste vide");
else
do{
        if(k->p1.Decede)
        {
            printf("%s\t%s\n",k->p1.Nom,k->p1.Prenom);
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

// Cette fonction compte le nombre des années bisexitile avant une date donnée
int nbreAnneeBisextile (date d)
{
  int years = d.annee;

  // Vérifier si l'année courante doit être considéré pour le comptage des années bisextile ou pas
  if (d.mois<= 2)
    years--;

  // Une année est bisextile si elle est multiple de 4, multiple de 400 et non multiple de 100
  return years / 4 - years / 100 + years / 400;
}

// Cette fonction retourne le nombre des jours entre 2 dates données
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

void afficherPersonnesEnQuarantaine (ListePersonnesInfectees l, date DateEncours)
{
  Cellule* courant = l;
  int diffDate = 0;
  if (l == NULL)
  {
    printf ("Liste vide\n");
  }
  else
  {
    while (courant != NULL)
    {

      diffDate = diffrenceDates (courant->p1.dateInfection, DateEncours);
      if (diffDate < 14)
      {
        printf("%s\t%s\n", courant->p1.Nom, courant->p1.Prenom);
      }


      courant = courant->suivant;
    }
    if (diffDate >= 14){
        printf("aucune personne en quarantine\n");
    }
  }
}

/*void AfficherPersonnesARisque (ListePersonnesInfectees l){
ListePersonnesInfectees courant=l;
ListeMaladie cr1;
//int risque=0;
do{
if (courant->p1.age <70){
       float  rr = 0+0.2;
        printf("%f %s %s\n",rr,courant->p1.Prenom,courant->p1.Nom);
         if(cr1->m.nommaladie == "diabete"){
     float  rr1 = rr+ 0.15;
    printf("%f %s %s\n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
 else
 if(cr1->m.nommaladie == "hypertension"){
     float  rr1 = rr+ 0.2;
    printf("%f %s %s \n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
 else
 if(cr1->m.nommaladie=="asthme"){
     float  rr1 = rr+ 0.2;
    printf("%f %s %s \n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
}

else
if(50< courant->p1.age <70){
    float  rr = 0+ 0.1;
    printf("%f %s %s\n",rr,courant->p1.Prenom,courant->p1.Nom);

 if(cr1->m.nommaladie == "diabete"){
     float  rr1 = rr+ 0.15;
    printf("%f %s %s\n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
 else
 if(cr1->m.nommaladie == "hypertension"){
     float  rr1 = rr+ 0.2;
    printf("%f %s %s \n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
 else
 if(cr1->m.nommaladie=="asthme"){
     float  rr1 = rr+ 0.2;
    printf("%f %s %s \n",rr1,courant->p1.Prenom,courant->p1.Nom);
 }
}
 courant=courant->suivant;
 }while(courant!=NULL);
}*/
void AfficherPersonnesARisque (ListePersonnesInfectees l)
{
  Cellule* courant = l;
  cellulemaladie* courantM;

  int risque = 0;

  if (l == NULL)
    printf("liste vide\n");
  else
  {
    printf ("***** Personnes à risque *****\n");
    while (courant != NULL)
    {
      if(courant->p1.age > 70)
      {
        risque += 20;
      }
      else if ( (courant->p1.age <= 70) && (courant->p1.age > 50) )
      {
        risque += 10;
      }

      //getchar();

      courantM = courant->p1.maladies;
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
        printf ("%s\t%s\t risque = %d%%\n", courant->p1.Nom, courant->p1.Prenom, risque);
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
      fprintf(fp,"%s %s %s %s %s %d %d %d %d %d\n",courant->p1.Cin,courant->p1.Nom,courant->p1.Prenom,courant->p1.numTel,courant->p1.nationalite,courant->p1.age,courant->p1.dateInfection.jour,courant->p1.dateInfection.mois,courant->p1.dateInfection.annee,courant->p1.Decede);
        cr1=courant->p1.maladies;
        while(cr1!=NULL){
            fprintf(fp1,"%s %s %d\n",courant->p1.Cin,cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;

        }
        printf("\n\n");
        courant=courant->suivant;

    }
fclose(fp);
fclose(fp1);
}



#endif // GESTION_H_INCLUDED
