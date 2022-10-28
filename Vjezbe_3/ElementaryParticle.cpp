#include<ElementaryParticle.h>

ElementaryParticle::ElementaryParticle(string _name, float _mass, bool _isBoson)
{
  name=_name;
  mass=_mass;
  isBoson=_isBoson;
}
ElementaryParticle::ElementaryParticle()
{
  name="";
  mass=0;
  isBoson=0;
}
ElementaryParticle::~ElementaryParticle()
{
}
void ElementaryParticle::printInfo()
{
  cout<<"Particle properties"<<endl<<"name:"<<name<<endl<<"mass:"<<mass<<endl<<"isBoson:"<<isBoson<<endl;
}
void ElementaryParticle::SetMomentumComponents(float _px, float _py, float _pz)
{
  px=_px;
  py=_py;
  pz=_pz;
  E=sqrt(pow(px,2)+pow(py,2)+pow(pz,2)+pow(mass,2));
}
void ElementaryParticle::PrintTransverseMomentum()
{
  cout<<"pT="<<sqrt(pow(px,2)+pow(py,2))<<"GeV"<<endl;
}
void ElementaryParticle::SetVariables(string _name, float _mass, bool _isBoson)
{
  name=_name;
  mass=_mass;
  isBoson=_isBoson;
}
void ElementaryParticle::bosonDecay(ElementaryParticle *decayParticle_1, ElementaryParticle *decayParticle_2)
{
  if(!isBoson)
  cout<<"Raspad nije moguc"<<endl;
  else {
  int random = rand()%1001;
  if(random<=214)
  {
  decayParticle_1->SetVariables("W+",80.4,1);
  decayParticle_2->SetVariables("W-",80.4,1);
  }
  else if(random>214 && random<=278)
  {
  decayParticle_1->SetVariables("tau+",1.78,0);
  decayParticle_2->SetVariables("tau-",1.78,0);
  }
  else if(random>278 && random<=304)
  {
  decayParticle_1->SetVariables("Z",91.2,1);
  decayParticle_2->SetVariables("Z",91.2,1);
  }
  else
  {
  decayParticle_1->SetVariables("b_quark",4.18,0);
  decayParticle_2->SetVariables("b_quark",4.18,0);
  }
  decayParticle_1->SetMomentumComponents(-150+rand()%301,-150+rand()%301,-150+rand()%301); // not stated in exercise but constrain components to a reasonable range
  decayParticle_2->SetMomentumComponents(px-decayParticle_1->px, py-decayParticle_1->py, pz-decayParticle_1->pz);
  }
}
