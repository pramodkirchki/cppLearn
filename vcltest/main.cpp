#include <iostream>
#include "vcl.h"

using namespace vcl;

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
   
  float Mopt[4][4] = 
  {{0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f}};
  
  float M[4][4] = 
  {{0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f},
   {0.0f, 0.0f, 0.0f, 0.0f}};
   
void matrixmulOpt(float A[4][4], float B[4][4], float M[4][4])
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

void matrixMulNaive(float A[4][4], float B[4][4], float M[4][4])
{
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      M[i][j] += A[i][j] * B[j][i];
    }
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
   
  matrixmulOpt(A, B, Mopt);
  matrixMulNaive(A, B, M);
  
  std::cout << "Vectorized matrix mul: \n";
  for(auto const &row:Mopt)
  {
    for(auto const &col:row)
    {
      std::cout << col << ", ";
    }
    std::cout << "\n";
  }
  
  std::cout << "Naive matrix mul: \n";
  for(auto const &row:M)
  {
    for(auto const &col:row)
    {
      std::cout << col << ", ";
    }
    std::cout << "\n";
  }
    std::cout << "\n";
  return 0;
}