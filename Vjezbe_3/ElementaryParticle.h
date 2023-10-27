#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class ElementaryParticle
{
   public:
   ElementaryParticle(string _name, float _mass, bool _isBoson);
   ElementaryParticle();
   ~ElementaryParticle();
   void printInfo();
   void SetMomentumComponents(float _px, float _py, float _pz);
   void PrintTransverseMomentum();
   void bosonDecay(ElementaryParticle *decayParticle_1, ElementaryParticle *decayParticle_2);
   void SetVariables(string _name, float _mass, bool _isBoson);
   string name;
   float mass, px,py,pz,E;
   bool isBoson;
};
