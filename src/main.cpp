#include <freeling.h>

#include "arguments.h"
#include "preprocessor.h"


int main(int argc, char **argv)
{
  // Set locale to an UTF8 compatible locale 
  freeling::util::init_locale(L"default");

  // Initialize the user arguments
  Arguments arguments(argc,argv);

  // Determine if arguments is not valid
  if(!arguments.is_valid()) 
  {
      // Print error message for invalid arguments
      std::wcout << arguments.get_message() << std::endl;
      
      // Return error
      return arguments.get_return_code();
  }

  // Create preprocessor
  Preprocessor preprocessor(arguments);

  // Preprocess text corpora
  preprocessor.preprocess();

  // Return success
  return 0;
}
