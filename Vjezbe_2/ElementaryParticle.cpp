#include <iostream>
#include <string>
#include "ElementaryParticle.h"
using namespace std;

void ElementaryParticle :: printInfo() { //Pošto sam funkciju printInfo definirao izvan klase, moram dodati ime klase na koju se fukcija odnosi(ElementaryParticle) i dodatni znak ::
         cout << ime<<" "<< masa <<"Gev "<< jeli_bozon <<endl;
    }