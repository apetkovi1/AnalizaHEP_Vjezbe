#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH1.h>
#include<TF1.h>
#include<TMath.h>
#include<TGraph.h>
using namespace std;
void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

void Analyzer :: PlotHistogram()
{
	double sum=0,sum1=0;
   TH1F* Histo_lifetime = new TH1F("Lifettime", "Lifetime", 20, 0.0, 10);
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      Histo_lifetime->Fill(t);
	  sum+=t;
      }
      TF1 *function_lifetime = new TF1("fit1","[0]*1.0/[1]*exp(-x*1.0/[1])",0,10);
      function_lifetime->SetParameter(0,286);
      function_lifetime->SetParameter(1,1.299);
	  Histo_lifetime->GetXaxis()->SetTitle("t/s");
	  Histo_lifetime->GetYaxis()->SetTitle("Number of particles");
      TCanvas *plot=new TCanvas("plot","plot",1600,900);
      Histo_lifetime->Fit(function_lifetime,"l");
      plot->SaveAs("Lifetime.pdf");
	  cout<<"Iz roota: tau="<<function_lifetime->GetParameter(1)<<"±"<<function_lifetime->GetParError(1)<<endl;
      TF1 *Likelihood = new TF1("fa1","503.13/x*exp(-1.0/x)",0.1,10);
	  Likelihood->GetXaxis()->SetTitle("#tau");
	  Likelihood->GetYaxis()->SetTitle("L(#tau)");
	  Likelihood->SetTitle("Likelihood function for t=1s");
	  TCanvas *plot1=new TCanvas("plot1","plot1",1600,900);
      Likelihood->Draw();
      plot1->SaveAs("Likelihood.pdf");
	  cout<<"Analiticki: tau="<<sum/Histo_lifetime->Integral()<<"±"<<sqrt(sum/Histo_lifetime->Integral()/nentries)<<endl;
	  double tau=0.7,x[100],y[100];
	  int j=0;
	  while(tau<1.7)
	  {
		  if (fChain == 0) return;
		  nentries = fChain->GetEntriesFast();
	      nbytes = 0, nb = 0;
		 for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
		 sum1=sum1-2*log((function_lifetime->GetParameter(0)/tau)*exp(-t/tau));
      }
	  x[j]=tau;
	  y[j]=sum1;
	  sum1=0;
      j=j+1;
      tau=tau+0.01;	  
	  }
	  TCanvas *plot2=new TCanvas("plot2","plot2",1600,900);
	  TGraph* gr = new TGraph(100,x,y);
	  gr->SetTitle("Log-likelihood function");
	  gr->GetXaxis()->SetTitle("#tau");
	  gr->GetYaxis()->SetTitle("-2lnL(#tau)");
      gr->Draw("AC*");
	  plot2->SaveAs("-2lnL.pdf");
	  //cout<<sum<<" "<<nentries<<endl;
	  TF1 *lnL = new TF1("lnL","2000*log(x)+2*1235.06/x-2000*log(503.13)",0.3,3);
	  cout<<"Treca metoda: tau="<<lnL->GetMinimumX()<<"-"<<lnL->GetMinimumX()-lnL->GetX(lnL->GetMinimum()+1,0.31,1.2)<<"+"<<lnL->GetX(lnL->GetMinimum()+1,1.21,3)-lnL->GetMinimumX()<<endl;
}
