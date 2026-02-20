//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef DNAStrand_H
#define DNAStrand_H

#include <iostream>
#include <string>

class DNAStrand
{
public:
  // Enumerated type to represent the 4 bases of DNA
  // Internal to class
  // Outside of class refer to as DNAStrand::Base, DNAStrand::Base::A, DNAStrand::Base::B...
  enum class Base
  {
    A,
    C,
    G,
    T
  };

  /**
   * @brief baseToChar - converts a Base enumerated value to its corresponding
   * char
   * @param b Base to convert
   * @return char value 'A', 'C', 'G', or 'T'
   *
   * Throws a logic_error exception if the Base has an invalid value
   * Outside of class call as DNAStrand::baseToChar
   */
  static char baseToChar(Base b);

  /**
   * @brief baseToChar - converts a char to its corresponding Base
   * @param c Should be the char 'A', 'C', 'G', or 'T'
   * @return Base::A, Base::C, Base::G, Base::T
   *
   * Throws a logic_error exception if the char is not 'A', 'C', 'G', or 'T'
   * Outside of class call as DNAStrand::charToBase
   */
  static Base charToBase(char c);

  /**
   * @brief Builds a DNAStrand with all 'A's of the given length
   * @param lengthValue Size DNA String to create
   *
   * This would likely be a private method and only used internally
   * We are making it public just so it can be tested
   */
  DNAStrand(int lengthValue);

  /**
   * @brief Builds a DNAStrand using the given string
   * @param startingString A string representation of the Bases to initialize
   * with
   */
  DNAStrand(const std::string &startingString);

  /**
   * @brief getLength gets length of string
   * @return length
   */
  int getLength() const;

  /**
   * @brief Destructor
   */
  ~DNAStrand();

  /**
   * @brief at Access individual nucleotide from DNAStrand
   * @param index location to access
   * @return Base value at index.
   *
   * Throws an out_of_range exception if the index is less than 0 or too large
   */
  Base at(int index) const;

  /**
   * @brief toString returns string form of this DNAStrand
   * @return "AAT" for strand containing A,A,T
   */
  std::string toString() const;

  /**
   * @brief operator == Check if two DNAStrands have same contents
   * @param other DNAStrand to compate to
   * @return true if identical, false if not
   */
  bool operator==(const DNAStrand &other) const;

  /**
   * @brief DNAStrand Copy Ctor
   * @param other DNAStrand to copy
   */
  DNAStrand(const DNAStrand &other);

  /**
   * @brief operator = Assignment Operator for DNAStrand
   * @param other DNAStrand to duplicate
   * @return Reference to the string that was copied into
   */
  DNAStrand &operator=(const DNAStrand &other);

  /**
   * @brief operator + Combine two DNAStrands
   * @param other DNAStrand to merge with this
   * @return DNAStrand with contents of current DNAStrand followed by contents
   * of other
   */
  DNAStrand operator+(const DNAStrand &other) const;

  /**
   * @brief getComplement gets Complement of the DNAStrand
   * @return DNAStrand that is complement of this
   *
   * The complement is the DNAStrand that pairs with this one to make a double
   * strand. Any A's in originals must become T's in complement and vice verse
   * C's become G's and vice verse.
   *
   * Original:    ACCTG
   * Complement:  TGGAC
   */
  DNAStrand getComplement() const;

private:
  Base *m_bases = nullptr; /// Tracks array containing an array of Bases
  int m_length = 0;        /// Length of the char array and DNAStrand
};

#endif
