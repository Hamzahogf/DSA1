#include  <omp.h>
#include  <iostream>
int  main(int  argc,  char  *argv[])
{
/*  sequential  code  */

omp_set_num_threads(4);

#pragma  omp  parallel
{
std::cout << "I am a parallel region." << std::endl;
}
/*  sequential  code  */
return  0;
}