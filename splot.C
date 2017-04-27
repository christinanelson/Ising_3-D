/*************************************************************
// Author: Tina
//
// Date: August 17, 2016
//
// Filename: plot.C
//
// Description: This file reads in the txt file output from
//              the Tektronix oscilloscope and plots the 
//              waveform.
//
 *************************************************************/

void splot()
{

  TCanvas *c1 = new TCanvas("c1", "phys305_assign2", 100, 20, 1200, 800);
  gROOT->Reset();
  //gStyle->SetPadBorderSize(2);
  //c1->SetMaxDigitsY(2)
  //c1->SetRightMargin(0.01);
  //c1->SetLeftMargin(.9);

  TGraph * g1 = new TGraph("specific-heat.dat");
  //TGraph * g1 = new TGraph("susceptibility.dat");
 
  g1->SetMarkerColor(kBlue);
  g1->SetMarkerStyle(2);
  g1->SetLineColor(kBlue);

  //g2->Draw("APL");
  g1->Draw("APL");
  
  g1->GetYaxis()->SetTitle("Specific Heat, (JK^{-1}g^{-1}) ");
  //g1->GetYaxis()->SetTitle("Susceptibility, (JT^{-2}m^{-3}) ");
  g1->GetXaxis()->SetTitleSize(0.055);
  g1->GetXaxis()->SetTitleOffset(0.88);
  g1->GetXaxis()->SetTitle("#propto T, (K)");
  g1->GetYaxis()->SetTitleSize(0.055);
  g1->GetYaxis()->SetTitleOffset(.9);
  //g1->GetYaxis()->SetTitleOffset(1.3);
  
  //g1->SetMaximum(1.0);
  //g1->SetMinimum(-2.5);
  //g1->GetXaxis()->SetRangeUser(0, 8);

  g1->SetTitle("3D simulation with Ising lattice");
  gStyle->SetTitleFontSize(0.07);
  
  g1->GetXaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetLabelSize(0.05);
  TGaxis *myY = (TGaxis*)g1->GetYaxis();
  myY->SetMaxDigits(1);
  
  //TLegend* l = new TLegend(.65,0.75,0.95,0.9);
  ///l->AddEntry(g1, "Energy", "l");
  //l->AddEntry(g2, "Magnetization", "l");
  //l->SetTextSize(0.06);
  //l->Draw();
  
  //c1->SetLogy();
  //c1->SetLogx();
  c1->SetGrid();
  c1->Update();
  c1->SetFrameBorderMode(0);
  c1->SaveAs("heatcapacity.eps");
  c1->SaveAs("heatcapacity.png");
}
