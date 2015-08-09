#ifndef date_h
#define date_h


#include <freeling.h>
#include <unordered_set>
#include <string>


/**
 * This class is a utility class used to encapsulate date
 * related functionality.
 * 
 */
class Date
{
public:
 /**
  * Obtains an instance of the Date singelton
  *
  * \return The Date singelton
  */
  static const Date& getDate();

 /**
  * Returns a bool indicating if the word is date
  *
  * \param wort The word to check
  * \return A bool indicating if the word is date
  */
  bool is_date(const freeling::word& wort) const;

private:
  /** Private constructor as is a singelton */
  Date();

  /** Private destructor as is a singelton */
  ~Date();

  /** Date tags */
  std::unordered_set<std::wstring> m_date_tags;
};

#include "date-inl.h"


#endif
