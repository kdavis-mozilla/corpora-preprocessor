#ifndef punctuation_inl_h
#define punctuation_inl_h


#include <freeling.h>
#include <list>


inline Punctuation::Punctuation()
: m_punctuation_tags()
{
  // Punctuation tags
  m_punctuation_tags.insert(L"Faa");
  m_punctuation_tags.insert(L"Fat");
  m_punctuation_tags.insert(L"Fc");
  m_punctuation_tags.insert(L"Fca");
  m_punctuation_tags.insert(L"Fct");
  m_punctuation_tags.insert(L"Fd");
  m_punctuation_tags.insert(L"Fe");
  m_punctuation_tags.insert(L"Fg");
  m_punctuation_tags.insert(L"Fh");
  m_punctuation_tags.insert(L"Fia");
  m_punctuation_tags.insert(L"Fit");
  m_punctuation_tags.insert(L"Fla");
  m_punctuation_tags.insert(L"Flt");
  m_punctuation_tags.insert(L"Fp");
  m_punctuation_tags.insert(L"Fpa");
  m_punctuation_tags.insert(L"Fpt");
  m_punctuation_tags.insert(L"Fra");
  m_punctuation_tags.insert(L"Frc");
  m_punctuation_tags.insert(L"Fs");
  m_punctuation_tags.insert(L"Ft");
  m_punctuation_tags.insert(L"Fx");
  m_punctuation_tags.insert(L"Fz");
}

inline Punctuation::~Punctuation()
{
}

inline const Punctuation& Punctuation::getPunctuation()
{
  // Create a singleton Punctuation
  static Punctuation punctuation;

  // Return singleton Punctuation
  return punctuation;
}

inline bool Punctuation::is_punctuation(const freeling::word& wort) const
{
  // Obtain analysis list
  std::list<freeling::analysis> analyses = wort.get_analysis();

  // Loop over analyses looking for punctuation
  for (auto itr = analyses.begin(); itr != analyses.end(); ++itr) {
    if (m_punctuation_tags.end() != m_punctuation_tags.find(itr->get_tag())) {
      return true;
    }
  }

  // Return indicating not punctuation
  return false;
}


#endif
