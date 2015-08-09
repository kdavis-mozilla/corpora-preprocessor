#ifndef preprocessor_h
#define preprocessor_h


#include <freeling.h>
#include <list>


// Forward declaration
class Arguments;


/**
 * This class preprocesses the text passed to it on
 * standard in an returns the preprocessed text to
 * standard out.
 *
 * The preprocessing done is that required by the
 * Cambridge Statistical Language Modeling Toolkit
 * to create language models. In particular
 * <ul>
 *  <li>Removing punctuation</li>
 *  <li>Expand abbreviations</li>
 *  <li>Clean "non-word items"</li>
 *  <li>Convert numbers to words</li>
 *  <li>Split sentences to one per line</li>
 * </ul>
 */
class Preprocessor
{
  public:
   /**
    * Constructs an instance based on the passed Arguments
    *
    * \param arguments The parsed command line arguments
    */
    Preprocessor(const Arguments& arguments);

   /**
    * This method preprocesses the text passed to it on
    * standard in an returns the preprocessed text to
    * standard out.
    */
    void preprocess();

  private:
    /** dates detection module */ 
    freeling::dates m_dates;

    /** Punctuation detection module */
    freeling::punts m_punts;

    /** Number detection module */
    freeling::numbers m_numbers;

    /** Sentence tokenization module */
    freeling::splitter m_splitter;

    /** Word tokenization module */
    freeling::tokenizer m_tokenizer;
};

#include "preprocessor-inl.h"


#endif
