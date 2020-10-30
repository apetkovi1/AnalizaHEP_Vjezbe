#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<iostream>
#include <TH1.h>
#include<TLegend.h>
#include<THStack.h>
#include<TLorentzVector.h>
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
      //std::cout<<E1<<endl;
      // if (Cut(ientry) < 0) continue;
   }
}
void Analyzer::PlotHistogram()
{
  TH1* Histo1 = new TH1F("pt1", "Higgs boson decay particles", 100, 0.0, 270); //jedno-dimezionalni koji prima floatove  (varijabla,ime,broj binova,pocetak,kraj)
  TH1* Histo2 = new TH1F("pt2", "pt2", 100, 0.0, 270);  // broj binova=100, pocetak=0, kraj=270
  TH1* Histo= new TH1F("pt","Higgs boson",100,0.0,270);
  TLorentzVector P,P1,P2;
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      Histo1->Fill(pt1);
	  Histo2->Fill(pt2);
	  P1.SetPxPyPzE(px1,py1,pz1,E1);
	  P2.SetPxPyPzE(px2,py2,pz2,E2);
	  P=P1+P2;
	  Histo->Fill(P.Pt());	  // Pt() je funkcija koja ima output transverzalnu kolicinu gibanja
	  }
   Histo->SetFillColor(kRed);
   Histo->SetLineColor(kRed);
  Histo1->SetFillColor(kBlue);
  Histo1->SetLineColor(kBlue);
  Histo2->SetLineColor(kGreen);
  gStyle->SetOptStat(0); //micanje onog pravokutnika sa entries, mean i std
  TLegend* legend = new TLegend(0.75,0.75,0.9,0.9); //(pocetak x koordinate,pocetak y,kraj x,kraj y) , Raspon legende je od 0.1 do 0.3 u x smjeru i 0.75 do 0.9 u y smjeru
  legend->SetHeader("The Legend","C"); // option "C" allows to center the header
  legend->AddEntry(Histo1,"pt1, Simulation","f");
  legend->AddEntry(Histo2,"pt2, Simulation","f");
  Histo1->GetXaxis()->SetTitle("Transversal momentum");
  Histo1->GetYaxis()->SetTitle("Number of events");
  Histo->GetXaxis()->SetTitle("Transversal momentum");
  Histo->GetYaxis()->SetTitle("Number of events");
  TCanvas *cs = new TCanvas("cs","cs",1600,800);
  cs->Divide(2,1); // podjelim histogram na 2 stupca i jedan red
  cs->cd(1); Histo1->Draw(); //ispisivanje na lijevom djelu platoa
  cs->cd(1); Histo2->Draw("SAME"); // SAME znaci da na isti graf dodajem novi histogram
  legend->Draw();
  cs->cd(2); Histo->Draw();
  cs->SaveAs("histogram.pdf");
  cs->SaveAs("histogram.png");
  cs->SaveAs("histogram.root");
}
