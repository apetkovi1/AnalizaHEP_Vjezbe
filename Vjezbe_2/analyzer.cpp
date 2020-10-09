#include <iostream>
#include <string>
#include "ElementaryParticle.h"
using namespace std;
int main() {

    ElementaryParticle Higgsov_bozon("Higgsov bozon",125,true);
    ElementaryParticle Top_kvark("Top kvark",173,false);
	ElementaryParticle *pokZ;
	pokZ=new ElementaryParticle("Z bozon",91,true);
	cout << pokZ->ime<<" "<< pokZ->masa <<"Gev "<< pokZ->jeli_bozon <<endl;
    Higgsov_bozon.printInfo(); 
    Top_kvark.printInfo();
    return 0;
}