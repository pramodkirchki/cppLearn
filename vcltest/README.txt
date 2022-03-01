Example to try vector class library
* Requiements - 
* Cygwin installed and in PATH (c:\cygwin64\bin\)
* Compile command - g++.exe -mavx2 -mfma --std=c++17 main.cpp

* VCL requires user to do the following before including vectorclass.h -> Refer to vcl.h to understand the usage.
* 1. #define MAX_VECTOR_SIZE 256
* 2. #define VCL_NAMESPACE vcl


** TODO
* Include gtest in your repo
* Write a gtest for 4x4 matrix multiplication
* Extend 4x4 multiplication for complex numbers