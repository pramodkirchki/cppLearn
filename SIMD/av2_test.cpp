#include <xmmintrin.h>
#include <smmintrin.h>
#include <immintrin.h>
#include <iostream>

#define LOAD_SIMD_FX    _mm256_load_si256

void printValues(std::ostream & os, int* val)
{
  for (int i = 0; i < 1; i+=8)
  {
    os << std::hex << val[i] << " ";
  }
  os << std::endl;
}

int main()
{
#ifdef __AVX2__
    std::cout << "**AVX2**\n";
#elif defined __SSE2__
    std::cout << "**SSE2**\n";
#endif
    __m256i values[32];
    for (int i = 0; i < 32; i++)
    {
      values[i] = _mm256_set1_epi32(i);
    }

    // auto valinit = (int*)&values;
    // std::cout << "valinit : "; printValues(std::cout, valinit);
    
    __m256i* copy_p_input = &values[0];
    uint32_t constN = 2;

        __m256i a = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i b = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i c = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i d = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i e = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i f = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i g = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i h = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i i = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i j = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i k = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i l = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i m = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i n = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i o = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;
        __m256i p = LOAD_SIMD_FX(copy_p_input); copy_p_input += constN;

        __m256i a_0_15_b_0_15   = _mm256_unpacklo_epi8(a, b);
        __m256i a_16_31_b_16_31 = _mm256_unpackhi_epi8(a, b);
        __m256i c_0_15_d_0_15   = _mm256_unpacklo_epi8(c, d);
        __m256i c_16_31_d_16_31 = _mm256_unpackhi_epi8(c, d);
        __m256i e_0_15_f_0_15   = _mm256_unpacklo_epi8(e, f);
        __m256i e_16_31_f_16_31 = _mm256_unpackhi_epi8(e, f);
        __m256i g_0_15_h_0_15   = _mm256_unpacklo_epi8(g, h);
        __m256i g_16_31_h_16_31 = _mm256_unpackhi_epi8(g, h);
        __m256i i_0_15_j_0_15   = _mm256_unpacklo_epi8(i, j);
        __m256i i_16_31_j_16_31 = _mm256_unpackhi_epi8(i, j);
        __m256i k_0_15_l_0_15   = _mm256_unpacklo_epi8(k, l);
        __m256i k_16_31_l_16_31 = _mm256_unpackhi_epi8(k, l);
        __m256i m_0_15_n_0_15   = _mm256_unpacklo_epi8(m, n);
        __m256i m_16_31_n_16_31 = _mm256_unpackhi_epi8(m, n);
        __m256i o_0_15_p_0_15   = _mm256_unpacklo_epi8(o, p);
        __m256i o_16_31_p_16_31 = _mm256_unpackhi_epi8(o, p);
        

    printValues(std::cout, (int*)&a_0_15_b_0_15);
    printValues(std::cout, (int*)&a_16_31_b_16_31);
    printValues(std::cout, (int*)&c_0_15_d_0_15);
    printValues(std::cout, (int*)&c_16_31_d_16_31);
    printValues(std::cout, (int*)&e_0_15_f_0_15);
    printValues(std::cout, (int*)&e_16_31_f_16_31);
    printValues(std::cout, (int*)&g_0_15_h_0_15);
    printValues(std::cout, (int*)&g_16_31_h_16_31);
    printValues(std::cout, (int*)&i_0_15_j_0_15);
    printValues(std::cout, (int*)&i_16_31_j_16_31);
    
    std::cout << "finished!" << std::endl;
    return 0;
}