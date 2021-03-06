//	Astrophysics Science Division,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman

#ifndef FITSERROR_H
#define FITSERROR_H 1
#include <exception>
#include <iostream>
//#include <exception>
//#include <iostream>
//#include <stl.h>
#include <string>
using std::string;


namespace CCfits {

  /*! \class FitsException

        @ingroup FITSexcept
        @brief FitsException is the base class for all exceptions thrown by this library.

        All exceptions derived from this class can be caught by a single 'catch' clause
        catching FitsException by reference (which is the point of this base class design).


        A static "verboseMode" parameter is provided by the FITS class to 
        control diagnostics - if FITS::verboseMode() is true, all diagnostics
        are printed (for debugging purposes). If not, then a boolean <I>silent</I>
        determines printing of messages. Each exception derived from FitsException
        must define a default value for the <I>silent</I> parameter.

  */

  /*! \fn  FitsException::FitsException(const string& diag, bool& silent)

        \param diag A diagnostic string to be printed optionally.
        \param silent A boolean controlling the printing of messages
  */      

  /*! \fn const string& FitsException::message () const

       \brief returns the error message

       This returns the diagnostic error message associated with the
       exception object, and which is accessible regardless of the verboseMode
       and silent flag settings.  
  */     

    /*! \class FitsError

        @ingroup FITSexcept
        @brief FitsError is the exception thrown by non-zero cfitsio status codes.


  */

  /*! \fn  FitsError::FitsError(int errornum, bool silent)

        \brief ctor for cfitsio exception: translates status code into cfitsio error message

        The exception prefixes the string "Fits Error: " to the message printed by cfitsio.

        \param errornum The cfitsio status code produced by the error.
        \param silent A boolean controlling the printing of messages
  */      

  /*! \class FitsFatal

        @ingroup FITSexcept
        @brief [potential] base class for exceptions to be thrown on internal library error.

        As of this version there are no subclasses. This error requests that the
        user reports this circumstance to HEASARC.

  */

  /*! \fn  FitsFatal::FitsFatal(const string& diag)

        \brief Prints a message starting "*** CCfits Fatal Error: ..." and calls <i>terminate()</i>

        \param diag A diagnostic string to be printed identifying the context of the error.
  */ 
  //	Base class for exceptions generated by CCfits that don't
  //	return FITS error codes (for example, array errors or seek errors).



  class FitsException 
  {
    public:
        FitsException (const string& msg, bool& silent);

        const string& message () const;

    protected:
        void addToMessage (const string& msgQual);

    private:
    private: //## implementation
      // Data Members for Class Attributes
        string m_message;

  };



  class FitsError : public FitsException  //## Inherits: <unnamed>%399170BD017D
  {
    public:
        FitsError (int errornum, bool silent = true);

    protected:
    private:
        void printMsg (int error);

    private: //## implementation
  };



  class FitsFatal 
  {
    public:
        FitsFatal (const string& diag);

    protected:
    private:
    private: //## implementation
  };

  // Class CCfits::FitsException 

  inline const string& FitsException::message () const
  {
     return m_message;
  }

  // Class CCfits::FitsError 

  // Class CCfits::FitsFatal 

} // namespace CCfits


#endif
