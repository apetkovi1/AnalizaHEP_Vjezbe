#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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
  TH1* Histo1 = new TH1F("pt", "Trasversal momentum of electron", 60, 0.0, 120);
  TH2* Histo2 = new TH2F("pt vs eta","Trasverse momentum and pseudorapidity of electron",60,0,120,10,-3,3); //2D histogram
  Histo1->SetLineColor(kRed);
  Histo1->GetYaxis()->SetTitle("Number of events");
  Histo1->GetXaxis()->SetTitle("Transversal momentum");
  Histo2->GetYaxis()->SetTitle("Pseudorapidity");
  Histo2->GetXaxis()->SetTitle("Transversal momentum");
  if (fChain == 0) return;

   //Long64_t nentries = fChain->GetEntriesFast();
     Long64_t nentries = 100000;
   Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      Histo1->Fill(ele_pt);
      Histo2->Fill(ele_pt, scl_eta);
      }
      gStyle->SetOptStat(0);
      TCanvas* cs = new TCanvas("cs","cs",1900,800);
      cs->Divide(2,1);
      cs->cd(1); gPad->SetLeftMargin(0.15); Histo1->Draw();
      cs->cd(2);  Histo2->Draw("COLZ");
      cs->SaveAs("histo.pdf");
}
