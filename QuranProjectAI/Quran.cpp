#include "Quran.h"

HachQuran::HachQuran(){
    tete = new Quran*[nombre_surat];
    courant = new Quran*[nombre_surat];
    if(!tete){
        cout<<"erreur d'allocation de memoire ";
        exit(-1);
    }
    if(!courant){
        cout<<"erreur d'allocation de memoire ";
        exit(-1);
    }
    
    for (int i = 0; i < nombre_surat; i++)
      courant[i] = tete[i] = NULL;
    nomDesSurat = {"Fatiha","Baqara"};  
  
}

void HachQuran::ajouter(char* str , int i ,int numV, char* nomSurat){
    Quran *m = new Quran ;
    strcpy(m->surat,nomSurat);
     m->num_verset = numV;
      strcpy(m->verset, str);
      m->suivant = nullptr;
      if(tete[i] == nullptr) courant[i] = tete[i] = m;
      else{
      courant[i]->suivant = m;
      courant[i] = m;
    }
}

void HachQuran::lecteur(){
  for(int i = 0 ; i < nombre_surat ; i++){
    char *nomFic = strcat(nomDesSurat[i],".txt");
    FILE *fic = fopen(nomFic , "r");
     if(fic == nullptr){
       cerr<< "erreur d'ouverture du fichier "<<nomFic<<endl;
       exit(i);
    }
   int buff ;
    //al Baqara compte 286 verset et c'est le plus long des surat
    //et le verset le plus long est le verset 282 de surat al Baqara 128 lettre arabe et de 2000 a 2500 lettre en francais
     char versets[286][3000];
     int numVerset;
     numVerset = fgetc(fic);
     int point = fgetc(fic);
      int row = 0 , col = 0;
    while((buff=fgetc(fic)) != EOF){
      if(!isdigit(buff))
        versets[row][col++]=(char)buff;
      else{

        ajouter(versets[row] , i,numVerset , nomDesSurat[i]);
         numVerset = buff;
         point = fgetc(fic);
         row++;
        }
    }
  }

}
