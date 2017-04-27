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

void plot3()
{

  TCanvas *c1 = new TCanvas("c1", "phys305_assign2", 10, 20, 1200, 800);

  TGraph2D * g1 = new TGraph2D("spin-upup-three.dat");
 
  g1->SetMarkerColor(kBlack);
  g1->SetMarkerStyle(4);
  g1->Draw("P0");

  gStyle->SetTitleFontSize(0.07);
  g1->SetTitle("3D Spin-#uparrow map");
  g1->GetXaxis()->SetRangeUser(0,400);
  g1->GetXaxis()->SetTitleSize(0.055);
  g1->GetXaxis()->SetTitle("Iteration, (time)");
  g1->GetXaxis()->SetTitleOffset(1.6);
  g1->GetYaxis()->SetTitleSize(0.055);
  g1->GetYaxis()->SetTitleOffset(1.8);
  g1->GetYaxis()->SetTitle("Position");
  g1->GetZaxis()->SetTitleSize(0.055);
  g1->GetZaxis()->SetTitle("Position");
  
  g1->GetXaxis()->SetLabelSize(0.05);
  g1->GetYaxis()->SetLabelSize(0.05);
  g1->GetZaxis()->SetLabelSize(0.05);
  
  /*TLegend* l = new TLegend(.75,0.6,0.9,0.9);
  l->AddEntry(g1, "1 div", "l");
  l->AddEntry(g2, "2 div", "l");
  l->AddEntry(g3, "5 div", "l");
  l->AddEntry(g4, "10 div", "l");
  l->SetTextSize(0.06);
  l->Draw();
  */
  //c1->SetLogy();
  //c1->SetLogx();
  c1->SetGrid();
  c1->Update();
  c1->SaveAs("spin-map.eps");
  c1->SaveAs("spin-map.png");

}
