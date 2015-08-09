#ifndef preprocessor_inl_h
#define preprocessor_inl_h


#include <freeling.h>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "arguments.h"
#include "date.h"
#include "number.h"
#include "punctuation.h"


#define MIN_WORDS_PER_SENTENCE 6

void print_word(const freeling::word& wort);
void print_sentence(const freeling::sentence& satz);

Preprocessor::Preprocessor(const Arguments& arguments)
: m_dates(arguments.get_language_code()) 
, m_punts(arguments.get_freeling_share() + L"/common/punct.dat")
, m_numbers(arguments.get_language_code(), L".", L",") // TODO: Language is messy http://bit.ly/1DsCpJV
, m_splitter(arguments.get_freeling_share() + L"/" + arguments.get_language_code() + L"/splitter.dat")
, m_tokenizer(arguments.get_freeling_share() + L"/" + arguments.get_language_code() + L"/tokenizer.dat")
{
}

void Preprocessor::preprocess()
{
  // Define instances for parsing
  std::wstring line;
  std::list<freeling::word> words;
  std::list<freeling::sentence> sentences;

  // Open splitter session
  auto session_id = m_splitter.open_session();

  // Parse current document
  while(std::getline(std::wcin, line)) {
    // Parse current line
    m_tokenizer.tokenize(line, words);
    m_splitter.split(session_id, words, false, sentences);
    m_numbers.analyze(sentences);
    m_punts.analyze(sentences);
    m_dates.analyze(sentences);
    
    // Print current sentences
    std::for_each(sentences.begin(), sentences.end(), print_sentence);

    // Clear list for next line
    words.clear();
    sentences.clear();
  }

  // Close splitter session
  m_splitter.close_session(session_id);
}

void print_sentence(const freeling::sentence& satz)
{
  // If the sentence is to short, ignore it
  if (MIN_WORDS_PER_SENTENCE > satz.size()) {
    return;
  }  

  // Add start sentence tag
  std::wcout << L"<s> ";

  // Print words
  std::for_each(satz.begin(), satz.end(), print_word);

  // Add stop sentence tag
  std::wcout << L"</s>";

  // Add new line
  std::wcout << std::endl;
}

void print_word(const freeling::word& wort)
{
  // Obtain Punctuation utility instance
  const Punctuation& punctuation = Punctuation::getPunctuation();

  // If wort is punctuation, do not print it
  if (punctuation.is_punctuation(wort)) {
    return;
  }

  // Obtain Number utility instance
  const Number& number = Number::getNumber();

  // If wort is a number, print its normalization
  if (number.is_number(wort)) {
    std::wcout << wort.get_lemma() << " ";
    return;
  }

  // Obtain Date utility instance
  const Date& date = Date::getDate();

  // If wort is a date, print its normalization
  if (date.is_date(wort)) {
    std::wcout << wort.get_lemma() << " ";
    return;
  }

  // Otherwise print the lc form of the word
  std::wcout << wort.get_lc_form() << " ";
}


#endif
