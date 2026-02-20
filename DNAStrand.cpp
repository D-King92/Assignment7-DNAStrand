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
  switch (b) {
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
  switch (c) {
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

DNAStrand::DNAStrand(int lengthValue)
{
  m_length = lengthValue;
  m_bases = new Base[lengthValue];
  for (int i = 0; i < lengthValue; i++) {
    m_bases[i] = Base::A;
  }
}

DNAStrand::DNAStrand(const std::string& startingString)
{
  m_length = static_cast<int>(startingString.size());
  m_bases = new Base[m_length];
  for (int i = 0; i < m_length; ++i) {
    m_bases[i] = charToBase(startingString.at(i));
  }
}

int DNAStrand::getLength() const
{
  return m_length;
}

DNAStrand::~DNAStrand()
{
  delete[] m_bases;
}

DNAStrand::Base DNAStrand::at(int index) const
{
  if (index >= 0 && index < m_length) {
    return m_bases[index];
  } else {
    throw out_of_range("Index out of Bounds.");
  }
}

string DNAStrand::toString() const
{
  string output;
  for (int i = 0; i < m_length; ++i) {
    output += baseToChar(m_bases[i]);
  }
  return output;
}

bool DNAStrand::operator==(const DNAStrand& other) const
{
  if (m_length != other.m_length) {
    return false;
  } else {
    for (int i = 0; i < m_length; ++i) {
      if (m_bases[i] != other.m_bases[i]) {
        return false;
      }
    }
  }
  return true;
}

DNAStrand::DNAStrand(const DNAStrand& other)
{
  m_length = other.m_length;
  m_bases = new Base[m_length];
  for (int i  = 0; i < m_length; ++i) {
    m_bases[i] = other.m_bases[i];
  }
}

DNAStrand &DNAStrand::operator=(const DNAStrand &other) {
  
}