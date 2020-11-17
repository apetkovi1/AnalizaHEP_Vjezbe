#include<iostream>
#include<fstream>
#include "PDFGenerator.h"
#include<cstdlib>
#include<math.h>
#include <string>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
using namespace std;
PDFGenerator :: PDFGenerator()
{
	 
}
double PDFGenerator ::  GenerateQuadraticPDF()
{
	double f=2;
	double x,u=300000;
	while(u*1./100>f)
	{
		x=-100+rand()%201;
	    f=-0.75*(x*1.0/100)*(x*1.0/100)+0.75;
	    u=rand()%76;
	}
	return x*1.0/100;
}
void PDFGenerator :: ConvertTxtToRootFile(string s)
{
   double x;
  string s1=s.substr(0,s.find_last_of('.'))+".root";
  FILE *fp = fopen(s.c_str(),"r");
  TFile *hfile = hfile = TFile::Open(s1.c_str(),"RECREATE");
  TTree *tree = new TTree("Tree","Distribution");
   tree->Branch("x",&x,"x");
   char line[20];
   while (fgets(line,20,fp)) {
      sscanf(&line[0],"%f",&x);
      tree->Fill();
   }
   tree->Print();
   tree->Write();

   fclose(fp);
   delete hfile;
}
