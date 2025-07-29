#include <iostream>
#include <string>
#include <ctype>
using namespace std; 
const int nombre_surat = 114;
struct Quran
{
   string verset;
   string surat;
   int num_verset;
   Quran *suivant;
};

class HachQuran{
 private:
   Quran **tete;
   Quran **courant;
   string* nomDesSurat;
   public:
   HachQuran();
   ~HachQuran();
   void ajouter(string& , int);
   void lecteur();
};