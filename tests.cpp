//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <stdexcept>

// Include your .h files
#include "DNAStrand.h"

using namespace std;

TEST_CASE("Length based constructor, getLength")
{
  cout << "1a: Length based contructor & getLength..." << endl;
  // This does NOT test to see if constructor stores the correct chars, just if
  // it sets length
  DNAStrand str1(8);
  REQUIRE(str1.getLength() == 8);

  DNAStrand str2(4);
  REQUIRE(str2.getLength() == 4);
}

TEST_CASE("String Constructor, getLength")
{
  cout << "1b: String contructor & getLength..." << endl;
  // This does NOT test to see if constructor stores the correct chars, just if
  // it sets length

  DNAStrand str1("ACGTAGCT");
  REQUIRE(str1.getLength() == 8);

  DNAStrand str2("AACC");
  REQUIRE(str2.getLength() == 4);
}

TEST_CASE("at")
{
  cout << "2a: at basics" << endl;
  DNAStrand str1("ACGTACGTACGT");
  REQUIRE(str1.at(0) == DNAStrand::Base::A);
  REQUIRE(str1.at(5) == DNAStrand::Base::C);

  DNAStrand str2("TTTT");
  REQUIRE(str2.at(0) == DNAStrand::Base::T);
  REQUIRE(str2.at(2) == DNAStrand::Base::T);

  // length based constructor should initialize all memory to DNAStrand::Base::A
  DNAStrand str3(3);
  REQUIRE(str3.at(0) == DNAStrand::Base::A);
  REQUIRE(str3.at(1) == DNAStrand::Base::A);
  REQUIRE(str3.at(2) == DNAStrand::Base::A);
}

TEST_CASE("at")
{
  cout << "2b: at exceptions" << endl;

  DNAStrand str2("TTTT");

  // Check that excpetion is thrown if bad index provided
  int exceptionsCaught = 0;

  try {
    DNAStrand::Base b = str2.at(-1);
    cout << DNAStrand::baseToChar(b); // never should get here
  } catch (out_of_range& e) {
    exceptionsCaught++;
  }

  try {
    DNAStrand::Base b = str2.at(4);
    cout << DNAStrand::baseToChar(b); // never should get here
  } catch (out_of_range& e) {
    exceptionsCaught++;
  }

  REQUIRE(exceptionsCaught == 2);
}

TEST_CASE("toString")
{
  cout << "3: toString" << endl;
  DNAStrand str1("AAC");
  DNAStrand str2("GT");

  REQUIRE(str1.toString() == "AAC");
  REQUIRE(str2.toString() == "GT");
}

TEST_CASE("== test 1")
{
  cout << "4a: operator ==" << endl;

  DNAStrand strand1("ACGTAGCT");
  DNAStrand strand2("ACGTAGCT");

  bool isMatch = (strand1 == strand2);
  REQUIRE(isMatch);

  DNAStrand strand3("AACC");
  DNAStrand strand4("AAGC");

  bool isMatch2 = (strand3 == strand4);
  REQUIRE(!isMatch2);
}

TEST_CASE("== test 2")
{
  cout << "4b: More == tests..." << endl;

  DNAStrand str("AACC");
  DNAStrand str2("AAC");
  DNAStrand str3("AACCT");
  // Make sure unequal length stands don't cause == issues
  bool isMatch1 = (str == str2);
  bool isMatch2 = (str == str3);
  REQUIRE(!isMatch1);
  REQUIRE(!isMatch2);
}

TEST_CASE("Copy constructor")
{
  cout << "5: Copy constructor..." << endl;
  DNAStrand str1("ACGTAGCT");

  {
    // new scope
    DNAStrand str2(str1); // Call copy ctor

    string test2s = str2.toString();

    bool isMatch = (str1 == str2);
    REQUIRE(isMatch);
    // str2 goes away when we leave this block...
  }

  bool isMatch2 = (str1 == DNAStrand("ACGTAGCT"));
  REQUIRE(isMatch2);
}

// TEST_CASE("Assignment Operator")
// {
//   cout << "6: Assignment Operator..." << endl;
//   DNAStrand str1("ACGTAGCT");

//   {
//     // new scope
//     DNAStrand str2("AA");
//     str2 = str1; // Use assignment op

//     bool isMatch = (str2 == DNAStrand("ACGTAGCT"));
//     REQUIRE(isMatch);
//     // str2 goes away when we leave this block...
//   }

//   // Make sure str1 was not changed
//   bool isMatch2 = (str1 == DNAStrand("ACGTAGCT"));
//   REQUIRE(isMatch2);

//   // Verify self-assignment does no harm:
//   {
//     str1 = str1;
//   }
//   bool isMatch3 = (str1 == DNAStrand("ACGTAGCT"));
//   REQUIRE(isMatch3);
// }

// TEST_CASE("getComplement")
// {
//   cout << "7: getComplement..." << endl;
//   DNAStrand str1("ACTGG");
//   DNAStrand str2 = str1.getComplement();
//   bool isMatch1 = (str2 == DNAStrand("TGACC"));
//   REQUIRE(isMatch1);

//   DNAStrand str3 = str2.getComplement(); // should be back where we started
//   bool isMatch2 = (str3 == DNAStrand("ACTGG"));
//   REQUIRE(isMatch2);
// }

// TEST_CASE("operator+")
// {
//   cout << "8: Operator +..." << endl;
//   DNAStrand str1("AATT");
//   DNAStrand str2("CCGG");
//   DNAStrand str3 = str1 + str2;

//   bool isMatch = (str3 == DNAStrand("AATTCCGG"));
//   REQUIRE(isMatch);

//   // Check originals aren't broken
//   bool isMatch2 = (str1 == DNAStrand("AATT"));
//   bool isMatch3 = (str2 == DNAStrand("CCGG"));
//   REQUIRE(isMatch2);
//   REQUIRE(isMatch3);
// }
