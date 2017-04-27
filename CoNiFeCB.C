void CoNiFeCB() {

   TCanvas *c1 = new TCanvas("c1","CoNiFeCB", 100, 20, 1200, 800);

   c1->SetGrid();  
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);


   TGraph * g2 = new TGraph("magnetization.dat");
   g2->SetLineColor(kGreen+2);
   
 
   const Int_t n = 30;

   // Temperature 
   Float_t x[n]  = {  20.,  40.,   63.,  84., 103., 121., 164., 184., 205., 224.,
		      240., 260., 281., 307., 319., 348., 360., 392., 403., 420., 
		      443., 463., 481., 500., 521., 541., 558., 587., 604., 620.};

   // delta M (magnetization)
   Float_t y[n]  = {221., 212., 220., 216., 212., 218., 206., 211., 208., 209.,
		    207., 204., 197., 195., 199., 188., 186., 183., 179., 181.,
                    168., 160., 150., 147., 135., 114.,  72.,  26.,  23.,  29.};
                   
   Float_t ex[n] = {0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
                    0., 0., 0., 0., 0., 0., 0., 0., 0., 0.};

   Float_t ey[n] = {2.21, 2.12, 2.20, 2.16, 2.12, 2.18, 2.06, 2.11, 2.08, 2.09,
		    2.07, 2.04, 1.97, 1.95, 1.99, 1.88, 1.86, 1.83, 1.79, 1.81,
                    1.68, 1.60, 1.50, 1.47, 1.35, 1.14, 0.72, 0.26, 0.23, 0.29};

   
   TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);

   gr->SetTitle("Measured Data and Scaled Simulation");
   gStyle->SetTitleFontSize(0.07);
   gr->GetYaxis()->SetTitle("M (J T^{-1}m^{-3})");
   gr->GetYaxis()->SetTitleSize(0.055);
   gr->GetYaxis()->SetTitleOffset(0.84);
   gr->GetYaxis()->SetLabelSize(0.05);
   gr->GetXaxis()->SetTitle("T ( ^{o}C )");
   gr->GetXaxis()->SetTitleSize(0.055);
   gr->GetXaxis()->SetTitleOffset(0.94);
   gr->GetXaxis()->SetLabelSize(0.05);
   gr->SetMarkerColor(kBlue);
   gr->Draw("AL");

   for(int i=0; i<g2->GetN(); i++)
     {
       g2->GetX()[i] *=120.;
       g2->GetY()[i] *= 253.;
     }

  g2->Draw("L");

  TLegend *l = new TLegend(0.65, 0.75, 0.9, 0.9);
  l->AddEntry(gr, "CoNiFeCB", "l");
  l->AddEntry(g2, "simulation", "l");
  l->SetTextSize(0.06);
  l->Draw();

   c1->Update();
   c1->SaveAs("CoNiFeCB.eps");
}
