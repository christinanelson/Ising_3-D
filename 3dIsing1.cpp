#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#define USE_MATH_DEFINES
#include <cstdlib>
#include <cmath>

using namespace std;
#define seed 500767 //68111

double energy(int array[]);

main()
{
  ofstream outfile1, outfile2, outfile3, outfile4;
  
  outfile1.open("specific-heat.dat");
  //outfile2.open("energy.dat");
  outfile3.open("magnetization_T3.dat");
  //outfile4.open("susceptibility.dat");

  srand48(seed);

  int N=2000, Ni=20, Nj=20, Nk=20, i, j, k, l, n1;
  double sum, E, M, M2, U, U2, C, Chi, Energy, Magnetization, kT, random;
  double a[22][22][22];

for(kT= 0.5; kT<=8.0; kT+=0.10)
{
  //energy
  U  = 0.0;
  U2 = 0.0;

  //magenetization
  M  = 0.0;
  M2 = 0.0;

  //set up init lattice config
  for(i=1; i<Ni; i++)
    {
      for (j = 1; j<Nj; j++)
	{
	  for(k = 1; k<Nk; k++)
	    {
	      a[i][j][k] = 1.0;
	    }
	}
    }

  //init energy and magnetization
  Energy = 0.0;
  Magnetization = 0.0;
  for(i=1; i<Ni; i++)
    {
      for(j=1; j<Nj; j++)
	{
	  for(k=1; k<Nk; k++)
	    {
	      //sum of nearest neighbors
	      sum = 0.0;
	      //periodic boundary conditions
	      if (i > 1)  sum = sum + a[i-1][j][k];
	      if (i < Ni) sum = sum + a[i+1][j][k];

	      if (j > 1)  sum = sum + a[i][j-1][k];
	      if (j < Nj) sum = sum + a[i][j+1][k];

	      if (k > 1)  sum = sum + a[i][j][k-1];
	      if (k < Nk) sum = sum + a[i][j][k+1];

	      
	      Energy = Energy -sum * a[i][j][k];
	      Magnetization = Magnetization - a[i][j][k];
	    }
	}
    }

  //correct the energy
  Energy = Energy/2.;
  
  for(l=1; l<N; l++)
    {
      for(n1=1; n1<(Ni*Nj*Nk); n1++)
	{
	  i = drand48()*Ni+1;
	  j = drand48()*Nj+1;
	  k = drand48()*Nk+1;
	  
	  sum = 0.0;
	  //calculate change in energy when flipped
	  if(i>1)  sum = sum + a[i-1][j][k];
	  if(i<Ni) sum = sum + a[i+1][j][k];
	  if(j>1)  sum = sum + a[i][j-1][k];
	  if(j<Nj) sum = sum + a[i][j+1][k];
	  if(k>1)  sum = sum + a[i][j][k-1];
	  if(k<Nk) sum = sum + a[i][j][k+1];
	  
	  //energy change
	  E = 2.0*sum*a[i][j][k];

	  if( (E<0.)||(exp(-E/kT)>drand48()) )
	    {
	      a[i][j][k] = -a[i][j][k]; //flip the spin
	      Energy = Energy+E;
	      Magnetization = Magnetization - 2.0 * a[i][j][k];
	    }	  
	}

      M  = M + Magnetization;
      M2 = M2 + Magnetization * Magnetization;
      U  = U + Energy;
      U2 = U2 + Energy * Energy;

      if((l % (N-1)) == 0)
	{
	  //average energy
	  U   = U/ l/Ni/Nj/Nk;
	  U2  = U2 / l/Ni/Nj/Nk/Ni/Nj/Nk;
	  //specific heat
	  C   = (U2-U*U)/kT/kT;
	  //average magnetization
	  M   = M / l/Ni/Nj/Nk;
	  M2  = M2 / l/Ni/Nj/Nk/Ni/Nj/Nk;
	  //susceptibility
	  Chi = (M2-M*M)/kT; 
	  
	  outfile1 << kT << " " << C << endl;       //specific heat
	  //outfile2 << kT << " " << U << endl;       //average energy
	  outfile3 << kT << " " << abs(M) << endl;  //magnetization
	  //outfile4 << kT << " " << Chi << endl;     //susceptibility
	}
    }
  }
 outfile1.close();
//outfile2.close();
  outfile3.close();
  //outfile4.close();
}
