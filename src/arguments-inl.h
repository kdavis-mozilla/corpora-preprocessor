#ifndef arguments_inl_h
#define arguments_inl_h


#include <cstdlib>
#include <freeling.h>


Arguments::Arguments(int argc, char **argv)
: m_message()
, m_is_valid(true)
, m_language_code()
, m_freeling_share()
{
  if ( (2 != argc) && (std::getenv("FREELINGSHARE")) ) {
    m_is_valid = false;
    m_message = L"usage: preprocessor language_code < unprocessed.text > preprocessed.text";
   return;
  }

  m_language_code = freeling::util::wstring_from(argv[1]);
  m_freeling_share = freeling::util::wstring_from(std::getenv("FREELINGSHARE")); 
}

inline bool Arguments::is_valid() const
{
    return m_is_valid;
}

inline const std::wstring& Arguments::get_message() const
{
    return m_message;
}

inline int Arguments::get_return_code() const
{
    return m_is_valid ? 0 : 1;
}

inline const std::wstring& Arguments::get_language_code() const
{
    return m_language_code;
}

inline const std::wstring& Arguments::get_freeling_share() const
{
    return m_freeling_share;
}


#endif
