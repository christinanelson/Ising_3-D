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

void eplot()
{

  TCanvas *c1 = new TCanvas("c1", "phys305_assign2", 100, 20, 1200, 800);

  TGraph * g1 = new TGraph("energy.dat");
 
  g1->SetMarkerColor(kRed);
  g1->SetMarkerStyle(2);
  g1->SetLineColor(kRed);

  g1->Draw("APL");
  
  g1->GetYaxis()->SetTitle("Energy, (J)");
  g1->GetXaxis()->SetTitleSize(0.055);
  g1->GetXaxis()->SetTitleOffset(0.88);
  g1->GetXaxis()->SetTitle("#propto T, (K)");
  g1->GetYaxis()->SetTitleSize(0.055);
  g1->GetYaxis()->SetTitleOffset(0.95);
  
  //g1->SetMaximum(1.0);
  //g1->SetMinimum(-2.5);
  //g1->GetXaxis()->SetRangeUser(0, 8);

  g1->SetTitle("3D simulation with Ising lattice");
  gStyle->SetTitleFontSize(0.07);
  
  g1->GetXaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetLabelSize(0.05);
  
  //TLegend* l = new TLegend(.65,0.75,0.95,0.9);
  ///l->AddEntry(g1, "Energy", "l");
  //l->AddEntry(g2, "Magnetization", "l");
  //l->SetTextSize(0.06);
  //l->Draw();
  
  //c1->SetLogy();
  //c1->SetLogx();
  c1->SetGrid();
  c1->Update();
  c1->SaveAs("energy.eps");

}
