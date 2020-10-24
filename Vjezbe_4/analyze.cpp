#include <iostream>
#include <string>
#include<fstream>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
#include "Analyzer.h"
using namespace std;
int main()
{
  double E1,px1,py1,pz1,pt1,E2,px2,py2,pz2,pt2;
  char Particle[20],DecayParticle_1[20],DecayParticle_2[20];
  FILE *fp = fopen("analysis.txt","r");
  TFile *hfile = hfile = TFile::Open("analysis.root","RECREATE");
  TTree *tree = new TTree("T","Decay");
   tree->Branch("Particle",&Particle,"Particle/I");
   tree->Branch("DecayParticle_1",&DecayParticle_1,"DecayParticle_1");
   tree->Branch("E1",&E1,"E1");
   tree->Branch("px1",&px1,"px1");
   tree->Branch("py1",&py1,"py1");
   tree->Branch("pz1",&pz1,"pz1");
   tree->Branch("pt1",&pt1,"pt1");
   tree->Branch("DecayParticle_2",&DecayParticle_2,"DecayParticle_2");
   tree->Branch("E1",&E2,"E2");
   tree->Branch("px2",&px2,"px2");
   tree->Branch("py2",&py2,"py2");
   tree->Branch("pz2",&pz2,"pz2");
   tree->Branch("pt2",&pt2,"pt2");
   char line[130];
   while (fgets(line,130,fp)) {
      sscanf(&line[0],"%s %s %f %f %f %f %f %s  %f %f %f %f %f",
      Particle,DecayParticle_1,&E1,&px1,&py1,&pz1,&pt1,DecayParticle_2,&E2,&px2,&py2,&pz2,&pt2);
      tree->Fill();
   }
   tree->Print();
   tree->Write();

   fclose(fp);
   delete hfile;
  Analyzer object1;
  object1.Read();
}
