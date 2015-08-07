#ifndef number_inl_h
#define number_inl_h


#include <freeling.h>
#include <list>


inline Number::Number()
: m_number_tags()
{
  // Number tags
  m_number_tags.insert(L"Z");
}

inline Number::~Number()
{
}

inline const Number& Number::getNumber()
{
  // Create a singleton Number
  static Number number;

  // Return singleton Number
  return number;
}

inline bool Number::is_number(const freeling::word& wort) const
{
  // Obtain analysis list
  std::list<freeling::analysis> analyses = wort.get_analysis();

  // Loop over analyses looking for number
  for (auto itr = analyses.begin(); itr != analyses.end(); ++itr) {
    if (m_number_tags.end() != m_number_tags.find(itr->get_tag())) {
      return true;
    }
  }

  // Return indicating not number
  return false;
}


#endif
