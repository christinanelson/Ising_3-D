
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#define USE_MATH_DEFINES
#include <cstdlib>
#include <cmath>

using namespace std;

#define max 500
#define kt 1.0  //100
#define J -1
//#define seed 68111
//#define seed 500767
#define seed 94180717

double energy(int array[]);

main()
{
  int i, j, element, array[max+1];
  double olden, newen;
  double energy(int array[]);
  
  FILE *output1, *output2;
  output1 = fopen("spin-up-3.dat", "w");
  output2 = fopen("spin-down-3.dat", "w");
  srand48(seed);
  
  for(i=0; i<max; i++) array[i]=1;
  
  for(i=0; i<=1000; i++)
    {
      olden = energy(array);
      element = drand48()*max;
      array[element] += -1;
      newen = energy(array);
      
      if( (newen>olden) && (exp((-newen+olden)/kt) <= drand48()) )
	{
	  array[element] = array[element]*(-1);
	}
      for(j=0; j<max; j++)
	{
	  if(array[j] ==  1) fprintf(output1, "%d %d\n", i, j);
	  if(array[j] == -1) fprintf(output2, "%d %d\n", i, j);
	}
    }

  fclose(output1);
  fclose(output2);
  printf("data saved in spin-up-3.dat, spin-down-3.dat \n");
}


double energy(int array[])
{
  int i;
  double sum = 0.;
  for(i=0; i<(max-1); i++)
    {
      sum += array[i]*array[i+1];      
    }
  return (J*sum);
}
