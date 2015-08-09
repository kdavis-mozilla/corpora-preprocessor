#ifndef date_inl_h
#define date_inl_h


#include <freeling.h>
#include <list>


inline Date::Date()
: m_date_tags()
{
  // Date tags
  m_date_tags.insert(L"W");
}

inline Date::~Date()
{
}

inline const Date& Date::getDate()
{
  // Create a singleton Date
  static Date date;

  // Return singleton Date
  return date;
}

inline bool Date::is_date(const freeling::word& wort) const
{
  // Obtain analysis list
  std::list<freeling::analysis> analyses = wort.get_analysis();

  // Loop over analyses looking for date
  for (auto itr = analyses.begin(); itr != analyses.end(); ++itr) {
    if (m_date_tags.end() != m_date_tags.find(itr->get_tag())) {
      return true;
    }
  }

  // Return indicating not date
  return false;
}


#endif
