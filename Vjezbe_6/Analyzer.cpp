#define Analyzer_cxx
#include "Analyzer.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include <vector>
#include<TLorentzVector.h>
#include<TLegend.h>

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
      cout<<LepPt->at(0);
      // if (Cut(ientry) < 0) continue;
   }
}
void Analyzer::PlotHistogram()
{
  TH1* Histo1 = new TH1F("pt_1", "Trasversal_momentum", 30, 0.0, 160);  
  TH1* Histo2 = new TH1F("pt_2", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo3 = new TH1F("pt_3", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo4 = new TH1F("pt_4", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo5 = new TH1F("eta_1", "Pseudorapidity", 30, 0.0, 3);  
  TH1* Histo6 = new TH1F("eta_2", "Pseudorapidity", 30, 0.0, 3);
  TH1* Histo7 = new TH1F("eta_3", "Pseudorapidity", 30, 0.0, 3);
  TH1* Histo8 = new TH1F("eta_4", "Pseudorapidity", 30, 0.0, 3);
  TH1* Histo9 = new TH1F("phi_1", "Azimuthal_angle", 30, 0.0, 6);  
  TH1* Histo10 = new TH1F("phi_2", "Azimuthal_angle", 30, 0.0, 6);
  TH1* Histo11 = new TH1F("phi_3", "Azimuthal_angle", 30, 0.0, 6);
  TH1* Histo12 = new TH1F("phi_4", "Azimuthal_angle", 30, 0.0, 6);
  TH1* Histo13 = new TH1F("BDT_1", "BDT", 30, 0.0, 12);  
  TH1* Histo14 = new TH1F("BDT_2", "BDT", 30, 0.0, 12);
  TH1* Histo15 = new TH1F("BDT_3", "BDT", 30, 0.0, 12);
  TH1* Histo16 = new TH1F("BDT_4", "BDT", 30, 0.0, 12);
  TH1* Histo17 = new TH1F("M", "Higgs_mass (unweighted)", 25, 90, 140);
  TH1* Histo18 = new TH1F("Mw", "Higgs_mass (weighted)", 25, 90, 140);
  //TH1* Histo2 = new TH1F("m", "Higgs", 100, 0.0, 270);
   double w,sum_w;
   TLorentzVector P1,P2,P3,P4,P;
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      P1.SetPtEtaPhiM(LepPt->at(0),LepEta->at(0),LepPhi->at(0),0);
      P2.SetPtEtaPhiM(LepPt->at(1),LepEta->at(1),LepPhi->at(1),0); 
      P3.SetPtEtaPhiM(LepPt->at(2),LepEta->at(2),LepPhi->at(2),0);
      P4.SetPtEtaPhiM(LepPt->at(3),LepEta->at(3),LepPhi->at(3),0);
      P=P1+P2+P3+P4; 
      Histo1->Fill(LepPt->at(0));
	  Histo2->Fill(LepPt->at(1));
	  Histo3->Fill(LepPt->at(2));
	  Histo4->Fill(LepPt->at(3));
	  Histo5->Fill(LepEta->at(0));
	  Histo6->Fill(LepEta->at(1));
	  Histo7->Fill(LepEta->at(2));
	  Histo8->Fill(LepEta->at(3));
	  Histo9->Fill(LepPhi->at(0));
	  Histo10->Fill(LepPhi->at(1));
	  Histo11->Fill(LepPhi->at(2));
	  Histo12->Fill(LepPhi->at(3));
	  Histo13->Fill(LepBDT->at(0));
	  Histo14->Fill(LepBDT->at(1));
	  Histo15->Fill(LepBDT->at(2));
	  Histo16->Fill(LepBDT->at(3));
      Histo17->Fill(P.M());
      w=137000*xsec*overallEventWeight/h1->GetBinContent(40);
      Histo18->Fill(P.M(),w);
	  }
	  Histo1->SetLineColor(kRed);
	  Histo2->SetLineColor(kBlue);
	  Histo3->SetLineColor(kGreen);
	  Histo4->SetLineColor(kOrange);
	  Histo5->SetLineColor(kRed);
	  Histo6->SetLineColor(kBlue);
	  Histo7->SetLineColor(kGreen);
	  Histo8->SetLineColor(kOrange);
	  Histo9->SetLineColor(kRed);
	  Histo10->SetLineColor(kBlue);
	  Histo11->SetLineColor(kGreen);
	  Histo12->SetLineColor(kOrange);
	  Histo13->SetLineColor(kRed);
	  Histo14->SetLineColor(kBlue);
	  Histo15->SetLineColor(kGreen);
	  Histo16->SetLineColor(kOrange);
	  Histo17->SetLineColor(kRed);
	  Histo17->SetFillColor(kOrange);
	  Histo18->SetLineColor(kRed);
	  Histo18->SetFillColor(kOrange);
	  Histo1->GetXaxis()->SetTitle("p_t/GeV");
      Histo1->GetYaxis()->SetTitle("Number of events");
	  Histo5->GetXaxis()->SetTitle("eta");
      Histo5->GetYaxis()->SetTitle("Number of events");
	  Histo9->GetXaxis()->SetTitle("phi");
      Histo9->GetYaxis()->SetTitle("Number of events");
	  Histo13->GetXaxis()->SetTitle("BDT");
      Histo13->GetYaxis()->SetTitle("Number of events");
	  Histo17->GetXaxis()->SetTitle("m_H/GeV");
      Histo17->GetYaxis()->SetTitle("Number of events");
	  Histo18->GetXaxis()->SetTitle("m_H/GeV");
      Histo18->GetYaxis()->SetTitle("Number of events");
	  gStyle->SetOptStat(0);
	  TLegend* legend1 = new TLegend(0.75,0.75,0.9,0.9);
	  TLegend* legend2 = new TLegend(0.75,0.75,0.9,0.9);
	  TLegend* legend3 = new TLegend(0.75,0.75,0.9,0.9);
	  TLegend* legend4 = new TLegend(0.75,0.75,0.9,0.9);
	  legend1->SetHeader("4 Leptons","C");
	  legend1->AddEntry(Histo1,"pt_1","f");
	  legend1->AddEntry(Histo2,"pt_2","f");
	  legend1->AddEntry(Histo3,"pt_3","f");
	  legend1->AddEntry(Histo4,"pt_4","f");
	  legend2->SetHeader("4 Leptons","C");
	  legend2->AddEntry(Histo5,"eta_1","f");
	  legend2->AddEntry(Histo6,"eta_2","f");
	  legend2->AddEntry(Histo7,"eta_3","f");
	  legend2->AddEntry(Histo8,"eta_4","f");
	  legend3->SetHeader("4 Leptons","C");
	  legend3->AddEntry(Histo9,"phi_1","f");
	  legend3->AddEntry(Histo10,"phi_2","f");
	  legend3->AddEntry(Histo11,"phi_3","f");
	  legend3->AddEntry(Histo12,"phi_4","f");
	  legend4->SetHeader("4 Leptons","C");
	  legend4->AddEntry(Histo13,"BDT_1","f");
	  legend4->AddEntry(Histo14,"BDT_2","f");
	  legend4->AddEntry(Histo15,"BDT_3","f");
	  legend4->AddEntry(Histo16,"BDT_4","f");
	  Histo1->GetYaxis()->SetRangeUser(0, 45000); // range y osi (dovoljno je postavit za 1 histogram, ne trebam ponavljat histo2,3,4)
	  Histo5->GetYaxis()->SetRangeUser(0, 5000);
	  cout<<Histo18->Integral()<<endl; // ukupan broj dogadaja
	  TCanvas *cs = new TCanvas("cs","cs",1600,800);
	  TCanvas *c1 = new TCanvas("c1","c1",1600,800);
	  TCanvas *c2 = new TCanvas("c2","c2",1600,800);
	  cs->Divide(2,2);
	  cs->cd(1); Histo1->Draw();
	  cs->cd(1); Histo2->Draw("SAME");
	  cs->cd(1); Histo3->Draw("SAME");
	  cs->cd(1); Histo4->Draw("SAME");
	  legend1->Draw();
	  cs->cd(2); Histo5->Draw();
	  cs->cd(2); Histo6->Draw("SAME");
	  cs->cd(2); Histo7->Draw("SAME");
	  cs->cd(2); Histo8->Draw("SAME");
	  legend2->Draw();
	  cs->cd(3); Histo9->Draw();
	  cs->cd(3); Histo10->Draw("SAME");
	  cs->cd(3); Histo11->Draw("SAME");
	  cs->cd(3); Histo12->Draw("SAME");
	  legend3->Draw();
	  cs->cd(4); Histo13->Draw();
	  cs->cd(4); Histo14->Draw("SAME");
	  cs->cd(4); Histo15->Draw("SAME");
	  cs->cd(4); Histo16->Draw("SAME");
	  legend4->Draw();
	  c1->cd(); Histo17->Draw(); //novo platno za novi graf
	  c2->cd(); Histo18->Draw("HIST SAME E2"); //stavim argument jer inace ne oboja pravokutnike
  cs->SaveAs("histogram_4l.pdf");
  cs->SaveAs("histogram_4l.png");
  cs->SaveAs("histogram_4l.root");
  c1->SaveAs("histogram_Higgs_unweighted.pdf");
  c1->SaveAs("histogram_Higgs_unweighted.png");
  c1->SaveAs("histogram_Higgs_unweighted.root");
  c2->SaveAs("histogram_Higgs_weighted.pdf");
  c2->SaveAs("histogram_Higgs_weighted.png");
  c2->SaveAs("histogram_Higgs_weighted.root");
}
