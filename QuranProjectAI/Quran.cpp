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

void HachQuran::ajouter(string& str , int i , string& nomSurat){
    Quran *m = new Quran ;
    m->surat = nomSurat;
     if(courant[i] != nullptr)
       m->num_verset = courant[i]->num_verset + 1;
     else
     m->num_verset = 1;
      m->verset = str;
      m->suivant = nullptr;
      if(tete[i] == nullptr) courant[i] = tete[i] = m;
      else{
      courant[i]->suivant = m;
      courant[i] = m;
    }
}

void HachQuran::lecteur(){
  for(int i = 0 ; i < nombre_surat ; i++){
     FILE *fic = fopen
  }

}