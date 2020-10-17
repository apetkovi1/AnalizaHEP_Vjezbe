#include <iostream>
#include <string>
using namespace std;

// create a class
class ElementaryParticle {

   public:
     double masa;
	 string ime;
     bool jeli_bozon;
	 double P[4]; 
	public:
ElementaryParticle(string a,double b, bool c);
ElementaryParticle();
 void printInfo();  
 void Energy();
 void p_T();
 void bosonDecay(ElementaryParticle object1,ElementaryParticle object2);
};