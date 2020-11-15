#define Analyzer_cxx
#include "Analyzer.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include<TH2F.h>
#include <vector>
#include<TLorentzVector.h>
#include<TLegend.h>
#include<THStack.h>
#include<TGraph.h>
#include<TGraphPainter.h>
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
  TH1* Histo1 = new TH1F("pt_1", "Trasversal_momentum", 30, 0.0, 160);  
  TH1* Histo2 = new TH1F("pt_2", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo3 = new TH1F("pt_3", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo4 = new TH1F("pt_4", "Transversal_momentum", 30, 0.0, 160);
  TH1* Histo5 = new TH1F("eta_1", "Pseudorapidity", 60, -3, 3);  
  TH1* Histo6 = new TH1F("eta_2", "Pseudorapidity", 60, -3, 3);
  TH1* Histo7 = new TH1F("eta_3", "Pseudorapidity", 60, -3, 3);
  TH1* Histo8 = new TH1F("eta_4", "Pseudorapidity", 60, -3, 3);
  TH1* Histo9 = new TH1F("phi_1", "Azimuthal_angle", 60, -4, 4);  
  TH1* Histo10 = new TH1F("phi_2", "Azimuthal_angle", 60, -4, 4);
  TH1* Histo11 = new TH1F("phi_3", "Azimuthal_angle", 60, -4, 4);
  TH1* Histo12 = new TH1F("phi_4", "Azimuthal_angle", 60, -4, 4);
  TH1* Histo13 = new TH1F("BDT_1", "BDT", 30, 0.0, 12);  
  TH1* Histo14 = new TH1F("BDT_2", "BDT", 30, 0.0, 12);
  TH1* Histo15 = new TH1F("BDT_3", "BDT", 30, 0.0, 12);
  TH1* Histo16 = new TH1F("BDT_4", "BDT", 30, 0.0, 12);
  TH1* Histo17 = new TH1F("M", "Higgs_mass (unweighted)", 25, 90, 140);
  TH1* Histo18 = new TH1F("Mw", "Higgs_mass (weighted)", 25, 90, 140);
  //TH1* Histo21 = new TH1F("D1", "D1", 20, 0, 0.01);
  //TH1* Histo22 = new TH1F("D2", "D2", 20, 0, 1);
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
	  w=137000*xsec*overallEventWeight/h1->GetBinContent(40);
      Histo1->Fill(LepPt->at(0),w);
	  Histo2->Fill(LepPt->at(1),w);
	  Histo3->Fill(LepPt->at(2),w);
	  Histo4->Fill(LepPt->at(3),w);
	  Histo5->Fill(LepEta->at(0),w);
	  Histo6->Fill(LepEta->at(1),w);
	  Histo7->Fill(LepEta->at(2),w);
	  Histo8->Fill(LepEta->at(3),w);
	  Histo9->Fill(LepPhi->at(0),w);
	  Histo10->Fill(LepPhi->at(1),w);
	  Histo11->Fill(LepPhi->at(2),w);
	  Histo12->Fill(LepPhi->at(3),w);
	  Histo13->Fill(LepBDT->at(0),w);
	  Histo14->Fill(LepBDT->at(1),w);
	  Histo15->Fill(LepBDT->at(2),w);
	  Histo16->Fill(LepBDT->at(3),w);
      Histo17->Fill(P.M());
      Histo18->Fill(P.M(),w);
      if(s.Contains("ggH125"))
	  {
		  Histo19->Fill(P.M(),w);
		  Histo21->Fill(1.0/(1+(1*p_QQB_BKG_MCFM)/p_GG_SIG_ghg2_1_ghz1_1_JHUGen)); 
          Histo23->Fill(P.M(),1.0/(1+(1*p_QQB_BKG_MCFM)/p_GG_SIG_ghg2_1_ghz1_1_JHUGen),w);		  
	  }	  
      if(s.Contains("qqZZ"))
	  {
		  Histo20->Fill(P.M(),w);
		  Histo22->Fill(1.0/(1+(70*p_QQB_BKG_MCFM)/p_GG_SIG_ghg2_1_ghz1_1_JHUGen));
          Histo24->Fill(P.M(),1.0/(1+(70*p_QQB_BKG_MCFM)/p_GG_SIG_ghg2_1_ghz1_1_JHUGen),w);		  
      }
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
	  Histo19->SetLineColor(kRed-7);
	  Histo19->SetFillColor(kRed-7);
	  Histo20->SetLineColor(kBlue-7);
	  Histo20->SetFillColor(kBlue-7);
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
	  if(s.Contains("ggH125"))
	  {
		  Histo1->GetYaxis()->SetRangeUser(0, 70); // range y osi (dovoljno je postavit za 1 histogram, ne trebam ponavljat histo2,3,4), ispsivanje izvan range-a na histogram moze se rjesit i na nacin da prvo na histogram ispisem vrijednosti sa manjim y
	      Histo5->GetYaxis()->SetRangeUser(0, 9);
	  }
	  if(s.Contains("qqZZ"))
	  {
		  Histo1->GetYaxis()->SetRangeUser(0, 500); // range y osi (dovoljno je postavit za 1 histogram, ne trebam ponavljat histo2,3,4), ispsivanje izvan range-a na histogram moze se rjesit i na nacin da prvo na histogram ispisem vrijednosti sa manjim y
	      Histo5->GetYaxis()->SetRangeUser(0, 160);
	  }
	  cout<<Histo18->Integral()<<endl; // ukupan broj dogadaja
	  TCanvas *cs = new TCanvas("cs","cs",1600,800);
	  TCanvas *c1 = new TCanvas("c1","c1",1600,800);
	  TCanvas *c2 = new TCanvas("c2","c2",1600,800);
	  TCanvas *c5 = new TCanvas("c5","c5",1600,800);
	  TCanvas *c6 = new TCanvas("c6","c6",1600,800);
	  cs->Divide(2,2);
	  cs->cd(1); Histo1->Draw("HIST");
	  cs->cd(1); Histo2->Draw("HIST SAME");
	  cs->cd(1); Histo3->Draw("HIST SAME");
	  cs->cd(1); Histo4->Draw("HIST SAME");
	  legend1->Draw();
	  cs->cd(2); Histo5->Draw("HIST");
	  cs->cd(2); Histo6->Draw("HIST SAME");
	  cs->cd(2); Histo7->Draw("HIST SAME");
	  cs->cd(2); Histo8->Draw("HIST SAME");
	  legend2->Draw();
	  cs->cd(3); Histo9->Draw("HIST");
	  cs->cd(3); Histo10->Draw("HIST SAME");
	  cs->cd(3); Histo11->Draw("HIST SAME");
	  cs->cd(3); Histo12->Draw("HIST SAME");
	  legend3->Draw();
	  cs->cd(4); Histo13->Draw("HIST");
	  cs->cd(4); Histo14->Draw("HIST SAME");
	  cs->cd(4); Histo15->Draw("HIST SAME");
	  cs->cd(4); Histo16->Draw("HIST SAME");
	  legend4->Draw();
	  c1->cd(); Histo17->Draw(); //novo platno za novi graf
	  c2->cd(); Histo18->Draw("HIST SAME E2"); //stavim argument jer inace ne oboja pravokutnike
	  if(s.Contains("qqZZ"))
  {
  cs->SaveAs("histogram_4l_bkg.pdf");
  cs->SaveAs("histogram_4l_bkg.png");
  cs->SaveAs("histogram_4l_bkg.root");
  c1->SaveAs("histogram_Higgs_unweighted_bkg.pdf");
  c1->SaveAs("histogram_Higgs_unweighted_bkg.png");
  c1->SaveAs("histogram_Higgs_unweighted_bkg.root");
  c2->SaveAs("histogram_Higgs_weighted_bkg.pdf");
  c2->SaveAs("histogram_Higgs_weighted_bkg.png");
  c2->SaveAs("histogram_Higgs_weighted_bkg.root");
  }
  	  if(s.Contains("ggH125"))
  {
  cs->SaveAs("histogram_4l_signal.pdf");
  cs->SaveAs("histogram_4l_signal.png");
  cs->SaveAs("histogram_4l_signal.root");
  c1->SaveAs("histogram_Higgs_unweighted_signal.pdf");
  c1->SaveAs("histogram_Higgs_unweighted_signal.png");
  c1->SaveAs("histogram_Higgs_unweighted_signal.root");
  c2->SaveAs("histogram_Higgs_weighted_signal.pdf");
  c2->SaveAs("histogram_Higgs_weighted_signal.png");
  c2->SaveAs("histogram_Higgs_weighted_signal.root");
  }
}   
void Analyzer::PlotHistogram_new()
{ 
   THStack *hs = new THStack("hs"," ;E/GeV;Number of events"); // Za THStack u konstruktoru trebam navesti ime x i y osi odvojenih sa ; ako to zelim
   hs->Add(Histo19);
   hs->Add(Histo20);
   legend5->AddEntry(Histo19,"ggH125","f");
   legend5->AddEntry(Histo20,"qqZZ","f");
   TCanvas *c4 = new TCanvas("c4","c4",1600,800); 
   hs->Draw("hist");
   legend5->Draw();
   c4->SaveAs("BKG_Signal.pdf");
}
void Analyzer::PlotHistogram_Discriminator()
{
	int i;
	double SIGNAL[1000], BKG[1000];
	TCanvas *KD=new TCanvas("KD","KD",1600,800);
	TLegend* legend7 = new TLegend(0.4,0.75,0.6,0.9);
	legend7->AddEntry(Histo21,"ggH125","f");
    legend7->AddEntry(Histo22,"qqZZ","f");
	Histo21->GetXaxis()->SetTitle("Kinematic Discriminator");
    Histo21->GetYaxis()->SetTitle("Number of events");
	Histo21->SetLineColor(kRed);
	Histo22->SetLineColor(kBlue);
	Histo21->Scale(1/Histo21->Integral());
	Histo22->Scale(1/Histo22->Integral());
	for(i=1;i<=1000;i++)
	{	
      SIGNAL[i]=1-Histo21->Integral(1,i); 
	  BKG[i]=1-Histo22->Integral(1,i); 
	}
	TGraph* ROC = new TGraph(1000,BKG,SIGNAL);
	ROC->SetTitle("ROC");
	ROC->GetXaxis()->SetTitle("BKG_eff");
	ROC->GetYaxis()->SetTitle("Signal_eff");
	ROC->SetMinimum(0.9);
	ROC->SetMaximum(1.02);
	Histo23->SetMinimum(-0.01);
	Histo24->SetMinimum(-0.01);
	Histo23->GetXaxis()->SetTitle("m_4l_BKG");
	Histo23->GetYaxis()->SetTitle("Kinematic_Discriminant_BKG");
	Histo24->GetXaxis()->SetTitle("m_4l_Signal");
	Histo24->GetYaxis()->SetTitle("Kinematic_Discriminant_Signal");
	KD->Divide(2,2);
	KD->cd(1); Histo21->Draw("HIST SAME");
	KD->cd(1); Histo22->Draw("HIST SAME");
	KD->cd(1); legend7->Draw();
	KD->cd(2);  gPad->SetLeftMargin(0.15);
	KD->cd(2); ROC->Draw("ap");
	KD->cd(3);   Histo23->Draw("COLZ");
	KD->cd(4);  gPad->SetLeftMargin(0.15);  Histo24->Draw("COLZ"); 
	KD->SaveAs("Kinematic_Discriminant_Mass.pdf");
}


