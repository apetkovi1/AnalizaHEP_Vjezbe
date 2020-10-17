#include <iostream>
#include <string>
#include "ElementaryParticle.h"
#include<cstdlib>
#include<cstdio>
# define n 10000 //broj cestica
using namespace std;
int main() 
{
    int i=0;
	srand (time(NULL));
    //ElementaryParticle Higgsov_bozon("Higgsov bozon",125,true);
	ElementaryParticle Higgsov_bozon[n];
    std::fill(Higgsov_bozon, Higgsov_bozon+n, ElementaryParticle("Higgsov bozon",125,true)); //kreiram polje objekata
    //ElementaryParticle Top_kvark("Top kvark",173,false);
	//ElementaryParticle *pokZ;
	//pokZ=new ElementaryParticle("Z bozon",91,true);
	ElementaryParticle decayParticle_1;
	ElementaryParticle decayParticle_2;
	//cout << pokZ->ime<<" "<< pokZ->masa <<"Gev "<< pokZ->jeli_bozon <<endl;
    //Higgsov_bozon.printInfo(); 
    //Top_kvark.printInfo();
	//Higgsov_bozon.Energy();
	//Higgsov_bozon.p_T();
	char filename[] = "analysis.txt";
	remove(filename); // prije unosenja podataka iz datoteke izbrisem prethodne podatke
	for(i=0;i<n;i++)
		Higgsov_bozon[i].bosonDecay(decayParticle_1,decayParticle_2);
	//Higgsov_bozon.bosonDecay(decayParticle_1,decayParticle_2);
    return 0;
}