//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include "DNAStrand.h"
#include <stdexcept>
#include <string>
using namespace std;

char DNAStrand::baseToChar(Base b)
{
  switch (b)
  {
  case Base::A:
    return 'A';
  case Base::C:
    return 'C';
  case Base::G:
    return 'G';
  case Base::T:
    return 'T';
  default:
    throw logic_error("Invalid base");
  }
}

DNAStrand::Base DNAStrand::charToBase(char c)
{
  switch (c)
  {
  case 'A':
    return Base::A;
  case 'C':
    return Base::C;
  case 'G':
    return Base::G;
  case 'T':
    return Base::T;
  default:
    throw logic_error("Invalid char value for converting to base: "s + c);
  }
}

DNAStrand::DNAStrand(int lengthValue) {
  
}