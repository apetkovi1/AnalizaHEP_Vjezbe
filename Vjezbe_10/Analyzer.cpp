#include "Analyzer.h"
#include <TH2F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include<TF1.h>
#include<TMath.h>
#include<TGraph.h>
#include<TGraphErrors.h>
#include<TLine.h>
#include<TLatex.h>

using namespace std;

Analyzer :: Analyzer()  
{
   
}
void Analyzer::Chi_square()
{
	int i=0;
   double sum1=0,sum2=0;
   gStyle->SetOptFit(1111);
	gStyle->SetStatY(0.95);                
	gStyle->SetStatX(0.38);
	gStyle->SetStatW(0.15);                
	gStyle->SetStatH(0.15); 	
   double a[5]={9.8,21.2,34.5,39.9,48.5};
   double a_sigma[5]={1,1.9,3.1,3.9,5.1};
   double F[5]={1,2,3,4,5};
   double F_sigma[5]={0,0,0,0,0};
   TCanvas *graph = new TCanvas("c1","c1",1600,900);
   TGraphErrors* gr = new TGraphErrors(5,F,a,F_sigma,a_sigma);
   TF1 *fit1=new TF1("fit1","1.0/[0]*x",0,6);
   fit1->SetParameter(0,0.1);
   fit1->SetParName(0,"m");
   gr->Fit(fit1);
   gr->SetTitle("Least square fit");
   gr->GetXaxis()->SetTitle("F/N");
   gr->GetYaxis()->SetTitle("a/(m/s^2)");
   gr->Draw("ap");
   graph->SaveAs("Least_square_fit.pdf");
   for(i=0;i<4;i++)
   {
	   sum1+=F[i]*a[i]/pow(a_sigma[i],2);
       sum2+=pow(F[i],2)/pow(a_sigma[i],2);
   }
   cout<<"m="<<sum2/sum1<<"±"<<1/sqrt(sum2)/(pow(sum1/sum2,2))<<" kg"<<endl;
   TF1 *chi=new TF1("chi","pow(9.8-x*1,2)/pow(1,2)+pow(21.2-x*2,2)/pow(1.9,2)+pow(34.5-x*3,2)/pow(3.1,2)+pow(39.9-x*4,2)/pow(3.9,2)+pow(48.5-x*5,2)/pow(5.1,2)",5,15);
   chi->GetYaxis()->SetRangeUser(0., 8.);
   chi->GetXaxis()->SetRangeUser(9., 11.);
   double theta=chi->GetMinimumX();
   double theta_l=chi->GetMinimumX()-chi->GetX(chi->GetMinimum()+1,8,10);
   double theta_d=chi->GetX(chi->GetMinimum()+1,10.5,12)-chi->GetMinimumX();
   cout<<"Treca metoda: theta="<<theta<<"-"<<theta_l<<"+"<<theta_d<<endl;
   cout<<"Treca metoda: m="<<1./theta<<"-"<<theta_l/pow(theta,2)<<"+"<<theta_d/pow(theta,2)<<" kg"<<endl;
   TCanvas *graph1 = new TCanvas("c2","c2",1600,900);
   TLine *line1=new TLine(chi->GetX(chi->GetMinimum()+1,8,10),0,chi->GetX(chi->GetMinimum()+1,8,10),chi->GetMinimum()+1);
   TLine *line2=new TLine(chi->GetX(chi->GetMinimum()+1,10.5,12),0,chi->GetX(chi->GetMinimum()+1,10.5,12),chi->GetMinimum()+1);
   TLine *line3=new TLine(theta,0,theta,chi->GetMinimum());
   TLine *line4=new TLine(chi->GetX(chi->GetMinimum()+1,8,10),chi->GetMinimum()+1,chi->GetX(chi->GetMinimum()+1,10.5,12),chi->GetMinimum()+1);
   chi->SetTitle("Chi-square function");
   chi->GetYaxis()->SetTitle("#Chi");
   chi->GetXaxis()->SetTitle("#theta");
   line1->SetLineStyle(kDashed);
   line2->SetLineStyle(kDashed);
   line3->SetLineStyle(kDashed);
   line4->SetLineStyle(kDashed);
   TLatex *t1=new TLatex(chi->GetX(chi->GetMinimum()+1,8,10)-0.06,1.5,"#theta-#sigma_{#theta}");
	t1->SetTextAngle(90);
	t1->SetTextColor(1);
	t1->SetTextSize(0.05);
   TLatex *t2=new TLatex(theta-0.02,1,"#theta");
	t2->SetTextAngle(90);
	t2->SetTextColor(1);
	t2->SetTextSize(0.05);
   TLatex *t3=new TLatex(chi->GetX(chi->GetMinimum()+1,10.5,12)-0.06,1.5,"#theta+#sigma_{#theta}");
	t3->SetTextAngle(90);
	t3->SetTextColor(1);
	t3->SetTextSize(0.05);
   chi->Draw();
   line1->Draw();
   line2->Draw();
   line3->Draw();
   line4->Draw();
   t1->Draw();
   t2->Draw();
   t3->Draw();
   graph1->SaveAs("Chi_square_function.pdf");
   
}
