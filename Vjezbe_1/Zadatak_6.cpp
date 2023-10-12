#include<iostream>
#include<string>
using namespace std;
class ElementaryParticle
{
  public:
    string name;
    float mass;
    bool isBoson;
    void printInfo();
    ElementaryParticle(string _name, float _mass, bool _isBoson);
};
ElementaryParticle::ElementaryParticle(string _name, float _mass, bool _isBoson)
{
   name=_name;
   mass=_mass;
   isBoson=_isBoson;
}
void ElementaryParticle::printInfo()
{
  cout<<"Particle properties"<<endl<<"name:"<<name<<endl<<"mass:"<<mass<<endl<<"isBoson:"<<isBoson<<endl;
}
int main()
{
  ElementaryParticle Higgs("Higgs boson",125,1);
  ElementaryParticle TopQuark("Top quark",173,0);
  ElementaryParticle *Z = new ElementaryParticle("Z boson", 90,1);
  Higgs.printInfo();
  TopQuark.printInfo();
  Z->printInfo();
  delete Z;
  return 0;
}
