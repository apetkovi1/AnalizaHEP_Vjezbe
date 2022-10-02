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

using namespace std;

Analyzer :: Analyzer()  
{
   
}
 
int Analyzer :: factoriel(int n)
{
  int i,product=1;
  if(n==0)
   return 1;
   else{
  for(i=1;i<=n;i++)
   product*=i;
   return product;}
}

double Analyzer :: binomial(int r,double p, int N)
{  
   double b=factoriel(N)/(factoriel(r)*factoriel(N-r))*pow(p,r)*pow(1-p,N-r);
   return b;
}

double Analyzer :: confidence_d(int m)
{
  int r,N=10;
  double suma1=0,cl=0.6827,p=1,suma=0;
  while(suma<(1-cl)/2.)
  {
  for(r=m+1;r<=N;r++)
  suma1+=binomial(r,p,N);
  suma=1-suma1;
  p-=0.001;
  //cout<<suma<<endl;
  suma1=0;
  }
  return p;
}

double Analyzer :: confidence_l(int m)
{
   int r,N=10;
  double suma1=0,cl=0.6827,p=1,suma=500;
  if(m==0)
	  return 0;
  else{
  while(suma>(1-cl)/2.)
  {
  for(r=0;r<=m-1;r++)
  suma1+=binomial(r,p,N);
  suma=1-suma1;
  p-=0.001;
  //cout<<suma<<endl;
  suma1=0;
  }
  return p;}
}

void Analyzer :: confidence_belt()
{
	gStyle->SetOptStat(0000);
	int m;
	for(m=1;m<=10;m++)
		cout<<confidence_l(m)<<"  "<<confidence_d(m)<<endl;
	
	TH1F* Histo_up = new TH1F("up", "up", 10, 0, 10);
	TH1F* Histo_down = new TH1F("down", "down", 10, 0, 10);
	TLine *line1=new TLine(6,0,6,confidence_d(6));
	TLine *line2=new TLine(0,confidence_d(6),6,confidence_d(6));
	TLine *line3=new TLine(0,confidence_l(6),6,confidence_l(6));
	TLatex *t1=new TLatex(3,confidence_d(6)+0.05,"p_{+} for m=6");
	TLatex *t2=new TLatex(3,confidence_l(6)+0.05,"p_{-} for m=6");
	line1->SetLineStyle(kDashed);
	line2->SetLineStyle(kDashed);
	line3->SetLineStyle(kDashed);
	for(m=1;m<=10;m++)
	{
		Histo_up->SetBinContent(m,confidence_d(m));
		Histo_down->SetBinContent(m,confidence_l(m));
	}
	TCanvas *belt = new TCanvas("c1","Clopper-Pearson belt",1600,900);
	Histo_up->GetYaxis()->SetRangeUser(0.0,1.1);
	Histo_down->GetYaxis()->SetRangeUser(0.0,1.1);
	Histo_up->SetLineColor(kRed+2);
	Histo_down->SetLineColor(kRed+2);
	Int_t ci = TColor::GetFreeColorIndex();  // ovo napravim da crvena ne prebrise bijelu (bijela se ponasa kao obicna boja)
    TColor *color = new TColor(ci, 1., 1., 1.); // ovo napravim da crvena ne prebrise bijelu (bijela se ponasa kao obicna boja)
	Histo_up->SetFillColor(kOrange+7);
	Histo_down->SetFillColor(ci); // ovo napravim da crvena ne prebrise bijelu (bijela se ponasa kao obicna boja)
	Histo_up->SetTitle("Clopper-Pearson confidence belt for 10 trials");
	Histo_up->GetYaxis()->SetTitle("P (Probablity)");
	Histo_up->GetXaxis()->SetTitle("m (Number of successes)");
	Histo_up->Draw();
	Histo_down->Draw("SAME");
	line1->Draw("SAME");
	line2->Draw("SAME");
	line3->Draw("SAME");
	t1->Draw("SAME");
	t2->Draw("SAME");
	belt->SaveAs("CP_belt.pdf");
        belt->SaveAs("CP_belt.root");
}
void Analyzer :: Game()
{
	int i,j,br,br1=0;
	srand (time(NULL));
	for(j=0;j<1000;j++)
	{
		br=0;
	for(i=0;i<6;i++)
	{
		
		if(rand()%6+1==6)
			br++;
	}
	if(confidence_d(br)>=1.0/6 && confidence_l(br)<=1.0/6)
		br1++;
	}
	cout<<br1<<endl; //990 dogadaja za cl=0.6827 , 1000 dogadaja za cl=0.95 ->prekonzervativno
}






