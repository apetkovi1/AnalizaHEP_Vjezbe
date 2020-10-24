#include <iostream>
#include <string>
#include<fstream>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
#include "Analyzer.h"
using namespace std;

Analyzer::Analyzer()
{
  
  
}

void Analyzer::Read()
{
   ifstream file;
   file.open("analysis.txt");
   string line;
   string name1;
   string name2;
   string name3;
   double a,b,c,d,e,f,g,h,x,y;
   if(file.is_open())
   {
     while(getline(file,line))
     {
       stringstream linestream(line);
       linestream >> name1 >> name3 >> a >> b >> c >> d >> x >> name2 >> e >> f >>  g >> h >> y;
       cout << c << endl;
     }
   }
}
void Analyzer :: ConvertTxtToRootFile(string s)
{
	double E1,px1,py1,pz1,pt1,E2,px2,py2,pz2,pt2;
  char Particle[20],DecayParticle_1[20],DecayParticle_2[20];
  string s1=s.substr(0,s.find_last_of('.'))+".root";
    //ofstream file;
    //file.open(s1.c_str(), ios::app);
  FILE *fp = fopen(s.c_str(),"r");
  TFile *hfile = hfile = TFile::Open(s1.c_str(),"RECREATE");
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
}
