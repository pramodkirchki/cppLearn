#include <iostream>
#include "vcl.h"

using namespace vcl;

void matrixmul(float A[4][4], float B[4][4], float M[4][4])
{
  // calculates M = A*B
  Vec4f Brow[4], Mrow[4];
  int   i, j;
  // load B as rows
  for (i = 0; i < 4; i++)
  {
    Brow[i].load(&B[i][0]);
  }
  // loop for A and M rows
  for (i = 0; i < 4; i++)
  {
    Mrow[i] = Vec4f(0.0f);
    // loop for A columns , B rows
    for (j = 0; j < 4; j++)
    {
      Mrow[i] += Brow[j] * A[i][j];
    }
  }
  // store M
  for (i = 0; i < 4; i++)
  {
    Mrow[i].store(&M[i][0]);
  }
}

int main()
{
  std::cout << "Hello! INSTRSET is " << INSTRSET << "\n";
#if defined(__AVX2__)
  std::cout << "AVX2 defined\n";
#elif defined(__AVX__)
  std::cout << "AVX defined\n";
#endif

  float A[4][4] = 
  {{1.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 1.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 1.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 1.0f}};
   
  float B[4][4] = 
  {{2.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 2.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 2.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 2.0f}};
   
  float M[4][4] = 
  {{1.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 1.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 1.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 1.0f}};
   
   matrixmul(A, B, M);
  
  
  return 0;
}