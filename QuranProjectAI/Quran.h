#include <iostream>
#include <cstring>
#include <cctype>
using namespace std; 
const int nombre_surat = 114;
struct Quran
{
  char verset[3000];
   char surat[50];
   int num_verset;
   Quran *suivant;
};

class HachQuran{
 private:
   Quran **tete;
   Quran **courant;
   char nomDesSurat[114][50];
   public:
   HachQuran();
   ~HachQuran();
   void ajouter(char* , int,int , char*);
   void lecteur();
   void rechercheMot(char *);
};
