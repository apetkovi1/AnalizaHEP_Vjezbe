#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TF1.h>
#include<iostream>
#include <string>
using namespace std;

class Analyzer
{ 
   public:
   Analyzer();
   void PlotHistogram();
   double binomial(int r,double p, int N);
   int factoriel(int a);
   double confidence_l(int m);
   double confidence_d(int d);
   void confidence_belt();
   void Game();
};




 
