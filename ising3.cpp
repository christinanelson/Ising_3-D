
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#define USE_MATH_DEFINES
#include <cstdlib>
#include <cmath>

using namespace std;

#define max 100
#define kt 1.0  //100
#define J -1
//#define seed 68111
//#define seed 500767
#define seed 94180717

double energy(int array[]);

main()
{
  int i, j, k, element, array[max+1];
  double olden, newen;
  double energy(int array[]);
  
  FILE *output1, *output2;
  output1 = fopen("spin-upup-three.dat", "w");
  //output2 = fopen("spin-downup-three.dat", "w");
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
	  for(k=0; k<max; k++)
	    {
	      if(array[j] ==  1 && array[k]== 1) fprintf(output1, "%d %d %d \n", i, j, k);
	      //if(array[j] == -1) fprintf(output2, "%d %d\n", i, j);
	    }
	}
    }

  fclose(output1);
  //fclose(output2);
  //printf("data saved in spin-up-three.dat, spin-down-three.dat \n");
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
