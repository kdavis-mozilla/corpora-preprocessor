#ifndef number_h
#define number_h


#include <freeling.h>
#include <unordered_set>
#include <string>


/**
 * This class is a utility class used to encapsulate number
 * related functionality.
 * 
 */
class Number
{
public:
 /**
  * Obtains an instance of the Number singelton
  *
  * \return The Number singelton
  */
  static const Number& getNumber();

 /**
  * Returns a bool indicating if the word is number
  *
  * \param wort The word to check
  * \return A bool indicating if the word is number
  */
  bool is_number(const freeling::word& wort) const;

private:
  /** Private constructor as is a singelton */
  Number();

  /** Private destructor as is a singelton */
  ~Number();

  /** Number tags */
  std::unordered_set<std::wstring> m_number_tags;
};

#include "number-inl.h"


#endif
