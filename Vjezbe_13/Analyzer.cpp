#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<TRandom.h>
#include<TMath.h>
#include<TLegend.h>
#include<TLine.h>
#include<TLatex.h>
#include <TStyle.h>
#include<iostream>
using namespace std;

void Analyzer::Loop()
{
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
void Analyzer :: Simulation()
{
	int i,j;
	double suma,avg=0;
	gStyle->SetOptStat(0);
	TH1F* Histo_test_France=new TH1F("test","test",100,160,170);
	TRandom *a = new TRandom();
	for(j=0;j<1000000;j++)
	{
		suma=0;
	for(i=0;i<100;i++)
	{
		suma=suma+a->Gaus(164.7,7.1);
	}
	suma=suma/100;
	Histo_test_France->Fill(suma);
	}
	Histo_test_France->Scale(1/Histo_test_France->Integral());
	TCanvas* canvas= new TCanvas("","",1600,900);
	Histo_test_France->GetXaxis()->SetTitle("height/cm");
	Histo_test_France->GetYaxis()->SetTitle("distribution");
	Histo_test_France->SetTitle("Simulation_France");
	Histo_test_France->Draw();
	canvas->SaveAs("Simulation_France.pdf");
	
	if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  avg+=height;
   }
   avg=avg/100;
   cout<<"Srednja visina uzorka je:"<<avg<<endl;
     int b_France=Histo_test_France->FindBin(avg);
	 double p_value=Histo_test_France->Integral(b_France,100);
	 cout<<"p vrijednost za Francusku je:"<<p_value<<endl;
	 double z_score = TMath::Sqrt(2)*TMath::ErfcInverse(2*p_value);
	 cout<<"Signifikantnost za Francusku je:"<<z_score<<endl;
	 
	 
	 
	 //ZDK_2
	TH1F* Histo_test_Spain=new TH1F("test1","test1",100,160,176);
	TH1F* Histo_test_Italy=new TH1F("test2","test2",100,160,176);
	TH1F* Histo_test_Holland=new TH1F("test3","test3",100,160,176);
	double suma_Spain=0,suma_Italy=0,suma_Holland=0;
	for(j=0;j<1000000;j++)
	{
		suma_Spain=0;
		suma_Italy=0;
		suma_Holland=0;
	for(i=0;i<100;i++)
	{
		suma_Spain=suma_Spain+a->Gaus(168,7);
		suma_Italy=suma_Italy+a->Gaus(166.1,6.5);
		suma_Holland=suma_Holland+a->Gaus(170.3,7.5);
	}
	suma_Spain=suma_Spain/100;
	suma_Italy=suma_Italy/100;
	suma_Holland=suma_Holland/100;
	Histo_test_Spain->Fill(suma_Spain);
	Histo_test_Italy->Fill(suma_Italy);
	Histo_test_Holland->Fill(suma_Holland);
	}
	Histo_test_Spain->Scale(1/Histo_test_Spain->Integral());
	Histo_test_Italy->Scale(1/Histo_test_Italy->Integral());
	Histo_test_Holland->Scale(1/Histo_test_Holland->Integral());
	
	TCanvas* canvas1= new TCanvas("","",1600,900);
	TLegend* legend1 = new TLegend(0.75,0.75,0.9,0.9);
	TLine *line=new TLine(avg,0,avg,0.1);
	TLatex *t=new TLatex(avg-0.2,0.03,"Measured height");
	t->SetTextAngle(90);
	t->SetTextColor(1);
	t->SetTextSize(0.03);
	Histo_test_Spain->GetYaxis()->SetRangeUser(0,0.1);
	Histo_test_Spain->GetXaxis()->SetTitle("height/cm");
	Histo_test_Spain->GetYaxis()->SetTitle("distribution");
	Histo_test_Spain->SetTitle("H0vsH1");
	Histo_test_Spain->SetLineColor(kRed);
	Histo_test_Italy->SetLineColor(kBlue);
	Histo_test_Holland->SetLineColor(kOrange);
	Histo_test_France->SetLineColor(kGreen);
	legend1->SetHeader("Simulation");
	legend1->AddEntry(Histo_test_Spain,"Spain","f");
	legend1->AddEntry(Histo_test_Italy,"Italy","f");
	legend1->AddEntry(Histo_test_Holland,"Holland","f");
	legend1->AddEntry(Histo_test_France,"France","f");
	Histo_test_Spain->Draw("HIST C");
	Histo_test_Holland->Draw("HIST C SAME");
	Histo_test_France->Draw("HIST C SAME");
	Histo_test_Italy->Draw("HIST C SAME");
	line->Draw();
	t->Draw();
	legend1->Draw();
	canvas1->SaveAs("HOvsH1.pdf");
	
	
	int b_Spain=Histo_test_Spain->FindBin(avg);
	int b_Italy=Histo_test_Italy->FindBin(avg);
	int b_Holland=Histo_test_Holland->FindBin(avg);
	double CL_Spain_France=1-Histo_test_France->Integral(Histo_test_France->FindBin(avg),100)/Histo_test_Spain->Integral(1,Histo_test_Spain->FindBin(avg));
	double CL_Spain_Italy=1-Histo_test_Italy->Integral(Histo_test_Italy->FindBin(avg),100)/Histo_test_Spain->Integral(1,Histo_test_Spain->FindBin(avg));
	double CL_Spain_Holland=1-Histo_test_Holland->Integral(1,Histo_test_Holland->FindBin(avg))/Histo_test_Spain->Integral(Histo_test_Spain->FindBin(avg),100);
	cout<<"Odbacujem francusku hipotezu u odnosu na spanjolsku sa pouzdanosti:"<<CL_Spain_France<<endl;
	cout<<"Odbacujem talijansku hipotezu u odnosu na spanjolsku sa pouzdanosti:"<<CL_Spain_Italy<<endl;
	cout<<"Odbacujem nizozemsku hipotezu u odnosu na spanjolsku sa pouzdanosti:"<<CL_Spain_Holland<<endl;
	 
}
