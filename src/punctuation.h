#ifndef punctuation_h
#define punctuation_h


#include <freeling.h>
#include <unordered_set>
#include <string>


/**
 * This class is a utility class used to encapsulate punctuation
 * related functionality.
 * 
 */
class Punctuation
{
public:
 /**
  * Obtains an instance of the Punctuation singelton
  *
  * \return The Punctuation singelton
  */
  static const Punctuation& getPunctuation();

 /**
  * Returns a bool indicating if the word is punctuation
  *
  * \param wort The word to check
  * \return A bool indicating if the word is punctuation
  */
  bool is_punctuation(const freeling::word& wort) const;

private:
  /** Private constructor as is a singelton */
  Punctuation();

  /** Private destructor as is a singelton */
  ~Punctuation();

  /** Punctuation tags */
  std::unordered_set<std::wstring> m_punctuation_tags;
};

#include "punctuation-inl.h"


#endif
