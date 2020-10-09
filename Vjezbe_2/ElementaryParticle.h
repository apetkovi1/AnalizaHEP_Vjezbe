#include <iostream>
#include <string>
using namespace std;

// create a class
class ElementaryParticle {

   public:
     double masa;
	 string ime;
     bool jeli_bozon;
	public:
ElementaryParticle(string a,double b, bool c)
 {
	 ime=a;
	 masa=b;
	 jeli_bozon=c;
 }
 void printInfo(); //funkciju cu definirati izvan klase, ovdje je samo deklariram
};