#define Analyzer_cxx
#include "Analyzer.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include<TH2F.h>
#include<TF1.h>
#include <vector>
#include<TLorentzVector.h>
#include<TLegend.h>
#include<THStack.h>
#include<TGraph.h>
#include<TGraphPainter.h>
#include<TMath.h>
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
void Analyzer::PlotHistogram(TString s)
{
  TFile *f; //dodano
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.  
      f = new TFile(s);
      TDirectory * dir = (TDirectory*)f->Get(s+":/ZZTree");
      dir->GetObject("candTree",tree);

   
   Init(tree);
   h1 = (TH1F*)f->Get("ZZTree/Counters"); //dodano (radi citanja iz Countersa)
   double w,sum_w;
   TLorentzVector P1,P2,P3,P4,P;
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  w=137000*xsec*overallEventWeight/h1->GetBinContent(40);
	  P1.SetPtEtaPhiM(LepPt->at(0),LepEta->at(0),LepPhi->at(0),0);
      P2.SetPtEtaPhiM(LepPt->at(1),LepEta->at(1),LepPhi->at(1),0); 
      P3.SetPtEtaPhiM(LepPt->at(2),LepEta->at(2),LepPhi->at(2),0);
      P4.SetPtEtaPhiM(LepPt->at(3),LepEta->at(3),LepPhi->at(3),0);
      P=P1+P2+P3+P4; 
      if(s.Contains("ggH125"))
	  {
		  Histo19->Fill(P.M(),w);
          Histo21->Fill(P.M(),w);		  
	  }	  
      if(s.Contains("qqZZ"))
	  {
		  Histo20->Fill(P.M(),w);
          Histo22->Fill(P.M(),w);		  
      }
	  }
	  Histo19->SetLineColor(kRed-7);
	  Histo19->SetFillColor(kRed-7);
	  Histo20->SetLineColor(kBlue-7);
	  Histo20->SetFillColor(kBlue-7);
  }
   
 
void Analyzer :: Chi_Square_Fit()
{
	 gStyle->SetOptFit(1111);
     TH1* SIG_BKG = new TH1F("SIG_BKG", "SIG_BKG_fit", 40, 110, 150);
     SIG_BKG->Add(Histo19);
     SIG_BKG->Add(Histo20);
     TCanvas *plot=new TCanvas("plot","plot",1600,900);
	 TLegend* legend = new TLegend(0.75,0.75,0.9,0.9);
     plot->Divide(2,1);
     TF1 *BW = new TF1("BW","[0]*[1]/(pow(x*x-[2]*[2],2)+0.25*pow([1],2))",110,150);
     BW->SetParameter(0,1.04449e+04);
     BW->SetParameter(1,8.46395e+02);
     BW->SetParameter(2,1.24564e+02);
     BW->SetLineColor(kRed);
     TF1 *Q=new TF1("Q","[0]+[1]*x+[2]*x*x",110,150);
     Q->SetParameter(0,4.28639e+01);
     Q->SetParameter(1,-5.77342e-01);
     Q->SetParameter(2,2.25558e-03);
     Q->SetLineColor(kGreen);
     TF1 *BWQ=new TF1("BWQ","[0]*[1]/(pow(x*x-[2]*[2],2)+0.25*pow([1],2))+[3]+[4]*x+[5]*x*x",110,150);
     BWQ->SetParameter(0,1.04449e+04);
     BWQ->SetParameter(1,8.46395e+02);
     BWQ->SetParameter(2,1.24564e+02);
     BWQ->SetParameter(3,4.28639e+01);
     BWQ->SetParameter(4,-5.77342e-01);
     BWQ->SetParameter(5,2.25558e-03);
	 BWQ->SetParName(0,"D");
	BWQ->SetParName(1,"#Gamma");
	BWQ->SetParName(2,"M");
	BWQ->SetParName(3,"C");
	BWQ->SetParName(4,"B");
	BWQ->SetParName(5,"A");
	 plot->cd(1);
     BWQ->SetLineColor(kBlue);
	BW->SetTitle("Higgs_mass_theory");
	BW->SetMaximum(60);
	BW->GetXaxis()->SetTitle("m/GeV");
	BW->GetYaxis()->SetTitle("Events");
	BW->Draw();
	Q->Draw("SAME");
	BWQ->Draw("SAME");
	 SIG_BKG->GetYaxis()->SetTitle("Events");
	 SIG_BKG->GetXaxis()->SetTitle("m/GeV");
	 SIG_BKG->SetTitle("Higgs_mass_experiment");
	 legend->AddEntry(BW,"BW","f");
	 legend->AddEntry(Q,"Q","f");
	 legend->AddEntry(BWQ,"BW+Q","f");
	 legend->Draw();
     //plot->cd(2); SIG_BKG->Draw();
	 plot->cd(2); SIG_BKG->Fit(BWQ); //kad stavim fit on odma nacrta
     plot->SaveAs("Chi_Square_Fit.pdf");
}
void Analyzer :: ML_Fit()
{
	 gStyle->SetOptFit(1111);
     TH1* SIG_BKG = new TH1F("SIG_BKG", "SIG_BKG_fit", 50, 70, 170);
     SIG_BKG->Add(Histo21);
     SIG_BKG->Add(Histo22);
     TCanvas *plot=new TCanvas("plot","plot",1600,900);
	 TF1* BWQ=new TF1("BWQ","([0]*[1])/((x*x-[2]*[2])*(x*x-[2]*[2])+0.25*[1]*[1])+([3]+[4]*x+[5]*x*x)+([6]*[7])/((x*x-[8]*[8])*(x*x-[8]*[8])+0.25*[7]*[7])",70,170);
	 BWQ->SetParName(0,"D_{ggH}");
	 BWQ->SetParName(1,"#Gamma_{ggH}");
	 BWQ->SetParName(2,"M_{ggH}");
	 BWQ->SetParName(3,"C");
	 BWQ->SetParName(4,"B");
	 BWQ->SetParName(5,"A");
	 BWQ->SetParName(6,"D_{qqZZ}");
	 BWQ->SetParName(7,"#Gamma_{qqZZ}");
	 BWQ->SetParName(8,"M_{qqZZ}");
	 BWQ->SetParameter(0,2.04150e+04);
	 BWQ->SetParameter(1,8.29916e+02);
	 BWQ->SetParameter(2,1.24443e+02);
	 BWQ->SetParameter(3,5.18016e+01);
	 BWQ->SetParameter(4,-6.21281e-01);
	 BWQ->SetParameter(5, 2.45073e-03);
	 BWQ->SetParameter(6,4.27919e+04);
	 BWQ->SetParameter(7,8.90531e+02);
	 BWQ->SetParameter(8,9.08734e+01);
	 SIG_BKG->GetYaxis()->SetTitle("Events");
	 SIG_BKG->GetXaxis()->SetTitle("m/GeV");
	 SIG_BKG->SetTitle("Higgs_mass_experiment");
	 SIG_BKG->Fit(BWQ);
	 plot->SaveAs("ML_Fit.pdf");
}

