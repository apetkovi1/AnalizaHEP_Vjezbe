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
 void printInfo() {
         cout << ime<<" "<< masa <<"Gev "<< jeli_bozon <<endl;
    }
};

int main() {

    // create object of Room class
    ElementaryParticle Higgsov_bozon("Higgsov bozon",125,true);
    ElementaryParticle Top_kvark("Top kvark",173,false);
	ElementaryParticle *pokZ;
	pokZ=new ElementaryParticle("Z bozon",91,true);
	cout << pokZ->ime<<" "<< pokZ->masa <<"Gev "<< pokZ->jeli_bozon <<endl;
    Higgsov_bozon.printInfo(); 
    Top_kvark.printInfo();
    return 0;
}