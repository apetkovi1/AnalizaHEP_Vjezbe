#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include<TF1.h>
#include<TMath.h>
#include<TGraph.h>
#include<TGraphErrors.h>
#include<TAxis.h>
#include<THStack.h>
#include<TColor.h>
#include<TLine.h>
#include<TLatex.h>
#include<time.h>
#include<TMultiGraph.h>
#include<TLegend.h>
using namespace std ;
void Analyzer::Rec_mass()
{
	
   TLorentzVector P,P1,P2;
   fit->SetParameter(0,286);
   fit->FixParameter(1,100);
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      P1.SetPxPyPzE(particle1_px,particle1_py,particle1_pz,particle1_E);
	  P2.SetPxPyPzE(particle2_px,particle2_py,particle2_pz,particle2_E);
	  P=P1+P2;
	  rec_mass->Fill(P.M());
   }
   rec_mass->Fit(fit,"q","",0,700);
   rec_mass->SetTitle("Reconstructed mass");
   rec_mass->GetYaxis()->SetTitle("Events");
   rec_mass->GetXaxis()->SetTitle("m/Gev");
   TCanvas* canvas= new TCanvas("","",1600,900);
   rec_mass->SetMarkerStyle(20);
   rec_mass->SetMarkerSize(0.6);
   rec_mass->Draw("ep");
   canvas->SaveAs("rec_mass.pdf");
}  
   
void Analyzer :: p_scan()   
{  
    TH1F* Higgs_distribution=new TH1F("test2","test2",200,0,700); 
    TLegend *legend=new TLegend(0.7,0.1,0.9,0.2);
    TGraph *graph_p_expected=new TGraph();
	TGraph *graph_p_observed=new TGraph();
    TH1F* Chi_master=new TH1F("test1","test1",200,0,50);
	TH1F* exp_pdf=new TH1F("test","test",200,0,700);
	int i,j,m;
	double mm;
	
	for(i=0;i<1000;i++)
	{
     		
	for(j=0;j<100000;j++)
	{
		double masa=r3->Exp(100);
		exp_pdf->Fill(masa);
	}
	for(m=10;m<=690;m+=5)
	{
	    mm=m*1.0;
		exp_pdf->Fit(fit,"q","",mm-10,mm+10);
		double a=fit->GetChisquare();
		Chi_master->Fill(a);
	}
	exp_pdf->Reset();
	}
   
    int k=1;
    for(m=10;m<=690;m+=5)
	{
		
		for(i=0;i<10000;i++)
		{
			double b=-1*pow(m-190,2)+0.5;
			if(r3->Rndm()<b)
				Higgs_distribution->Fill(r3->Gaus(m,0.0236*m));
			if(r3->Rndm()>b)
				Higgs_distribution->Fill(r3->Exp(100));
		}
		mm=m*1.0;
		
		Higgs_distribution->Fit(fit,"q","",mm-10,mm+10);
		double x=fit->GetChisquare();
		double p_value_exp=Chi_master->Integral(Chi_master->FindBin(x),200)/Chi_master->Integral();

		rec_mass->Fit(fit,"q","",mm-10,mm+10);
		double y=fit->GetChisquare();
		double p_value_obs=Chi_master->Integral(Chi_master->FindBin(y),200)/Chi_master->Integral();
		graph_p_expected->SetPoint(k,m,p_value_exp);
		graph_p_observed->SetPoint(k,m,p_value_obs);
		k++;
		Higgs_distribution->Reset();
	}
	TMultiGraph *mg = new TMultiGraph();
	mg->SetTitle("p value scan;m/GeV; p value");
	legend->AddEntry(graph_p_observed,"p observed");
    legend->AddEntry(graph_p_expected,"p expected");
	graph_p_observed->SetLineColor(kRed);
	graph_p_expected->SetLineColor(kBlue);
    mg->Add(graph_p_observed,"lp");
    mg->Add(graph_p_expected,"cp");
	TCanvas* canvas1= new TCanvas("","",1600,900);
	gPad->SetLogy();
	mg->Draw("apl");
	legend->Draw();
    canvas1->SaveAs("p_obsVSexp.pdf");
   
}
