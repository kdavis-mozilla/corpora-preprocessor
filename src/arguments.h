#ifndef arguments_h
#define arguments_h


#include <string>


/**
 * This class encapsulates the command line arguments and
 * provides an interface to these arguments for the rest
 * of system.
*/
class Arguments
{
public:
    /**
     * Constructs an Arguments from the user supplied
     * command line arguments.
     *
     * \param argc The number of command line arguments
     * \param argv The command line arguments
     */
    Arguments(int argc,char *argv[]);
    
    /**
     * Returns a bool indicating if the command line
     * arguments are valid.
     *
     * \return A bool indicating argument validity
     */
    bool is_valid() const;
    
    /**
     * Returns a human readable string describing a
     * reason the command line arguments are invalid.
     * If the command line arguments are valid, the
     * empty string is returned.
     *
     * \return A string describing a problem with the
     *         command line arguments
     */
    const std::wstring& get_message() const;
    
    /**
     * Returns a return code apropos for any problems
     * that arose as a result of the command line 
     * arguments
     *
     * \return A return code apropos for command line
     *         argument problems.
     */
    int get_return_code() const;
    
    /**
     * Obtain the user supplied language code
     *
     * \return The user supplied language code
     */
    const std::wstring& get_language_code() const;
    
    /**
     * Obtain the FREELINGSHARE env variable
     *
     * \return The FREELINGSHARE env variable
     */
    const std::wstring& get_freeling_share() const;
    
private:    
    /** A string describing the problem with the args */
    std::wstring m_message;
    
    /** A bool indicating validity */
    bool m_is_valid;  
    
    /** User supplied language code */
    std::wstring m_language_code;

    /** FREELINGSHARE env variable */
    std::wstring m_freeling_share;
};

#include "arguments-inl.h"


#endif
