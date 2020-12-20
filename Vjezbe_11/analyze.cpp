#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Analyzer.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"

using namespace std;

int main()
{
  Analyzer* object1;
  object1=new Analyzer();
  //object1->PlotHistogram(); 
  //cout<<object1->factoriel(3)<<endl;
  //cout<<object1->binomial(7,0.5,7)<<endl;
  //object1->confidence_d(1);
  //object1->confidence_l(1);
  object1->confidence_belt();
  object1->Game();
}
