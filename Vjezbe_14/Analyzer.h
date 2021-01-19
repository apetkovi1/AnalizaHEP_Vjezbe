#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TF1.h>
#include<TRandom3.h>
#include<iostream>
#include <string>
using namespace std;

class Analyzer
{ 
   public:
   Analyzer();
   void Distribution();
   void p_scan();
   TH1F* Chi_master=new TH1F("test1","test1",200,0,50);
   TF1 *fit = new TF1("fit","[0]*exp(-x*1.0/[1])",0,700);
   TRandom3 *r3 = new TRandom3();
};




 
