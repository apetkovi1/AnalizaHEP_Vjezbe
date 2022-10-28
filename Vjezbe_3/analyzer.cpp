#include<ElementaryParticle.h>
#include <fstream>
int main()
{
  // Zad 2
  /*ElementaryParticle *Higgs = new ElementaryParticle("Higgs boson",125,1);
  Higgs->SetMomentumComponents(40,30,60);
  ElementaryParticle *decayParticle_1 = new ElementaryParticle();
  ElementaryParticle *decayParticle_2 = new ElementaryParticle();
  Higgs->bosonDecay(decayParticle_1,decayParticle_2);
  cout<<decayParticle_1->name<<" "<<decayParticle_1->px<<" "<<decayParticle_1->py<<" "<<decayParticle_1->pz<<endl;
  cout<<decayParticle_2->name<<" "<<decayParticle_2->px<<" "<<decayParticle_2->py<<" "<<decayParticle_2->pz<<endl;*/

  // Zad 3
  ofstream myfile;
  myfile.open ("Analysis.txt");
  srand((unsigned) time(NULL));
  myfile << "DecayParticle1_Name DecayParticle1_isBoson DecayParticle1_mass DecayParticle1_E DecayParticle1_px DecayParticle1_py DecayParticle1_pz"<<" "
         << "DecayParticle2_Name DecayParticle2_isBoson DecayParticle2_mass DecayParticle2_E DecayParticle2_px DecayParticle2_py DecayParticle2_pz" << endl;
  ElementaryParticle *Higgs, *decayParticle_1, *decayParticle_2;
  for(int i=1;i<=10000;i++)
  {
    Higgs = new ElementaryParticle("Higgs boson",125,1);
    Higgs->SetMomentumComponents(-100+rand()%201,-100+rand()%201,-100+rand()%201);
    decayParticle_1 = new ElementaryParticle();
    decayParticle_2 = new ElementaryParticle();
    Higgs->bosonDecay(decayParticle_1,decayParticle_2);
    myfile << decayParticle_1->name<<" "<<decayParticle_1->isBoson<<" "<<decayParticle_1->mass<<" "<<decayParticle_1->E
           <<" "<<decayParticle_1->px<<" "<<decayParticle_1->py<<" "<<decayParticle_1->pz<<" "
           <<decayParticle_2->name<<" "<<decayParticle_2->isBoson<<" "<<decayParticle_2->mass<<" "<<decayParticle_2->E
           <<" "<<decayParticle_2->px<<" "<<decayParticle_2->py<<" "<<decayParticle_2->pz<<endl;
  }

  Higgs->~ElementaryParticle();
  decayParticle_1->~ElementaryParticle();
  decayParticle_2->~ElementaryParticle();

  myfile.close();
  return 0;
}
