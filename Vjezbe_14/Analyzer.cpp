#include "Analyzer.h"
#include <TH2F.h>
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
#include<TRandom3.h>
using namespace std;

Analyzer :: Analyzer()  
{
   
}
 

void Analyzer :: Distribution()
{
	double masa;
	fit->SetParameter(0,286);
	fit->FixParameter(1,100);
	int i,j,m;
	double mm;
	for(i=0;i<1000;i++)
	{
    TH1F* exp_pdf=new TH1F("test","test",200,0,700); 		
	for(j=0;j<100000;j++)
	{
		masa=r3->Exp(100);
		exp_pdf->Fill(masa);
	}
	for(m=10;m<=690;m+=5)
	{
	    mm=m*1.0;
		exp_pdf->Fit(fit,"q","",mm-10,mm+10);
		double a=fit->GetChisquare();
		Chi_master->Fill(a);
	}
	}
	TCanvas* canvas= new TCanvas("","",1600,900);
	Chi_master->Draw();
	canvas->SaveAs("fit.pdf");
}
void Analyzer :: p_scan()
{	
	TGraph *graph=new TGraph();
	int k=1,i,m;
	double mm;
	for(m=10;m<=690;m+=5)
	{
		TH1F* Higgs_distribution=new TH1F("test","test",200,0,700);
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
		double p_value=Chi_master->Integral(Chi_master->FindBin(x),200)/Chi_master->Integral();
		graph->SetPoint(k,m,p_value);
		k++;
		cout<<p_value<<endl;
	}
	TCanvas* canvas1= new TCanvas("","",1600,900);
	gPad->SetLogy();
	//graph->SetMinimum(pow(10,-40));
	graph->Draw("APL");
    canvas1->SaveAs("p_value.pdf");
}






