/// \file  unittesting.cpp
/// \This is the source file for a base class for automated unit tests

/** \file  unittesting.cpp
 * Code comes from the Flood3 library by Roberto Lopez and is under the GNU Lesser General Public License
 * http://www.cimne.com/flood/
 */

#include"unittesting.hpp"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <time.h>



namespace tidbits
{

// GENERAL CONSTRUCTOR

/// General constructor. It constructs a test case with default values:
/// <ul>
/// <li> Message: empty
/// <li> Tests count: 0
/// <li> Tests passed: 0
/// <li> Tests failed: 0
/// <li> Display: true
/// </ul>

UnitTesting::UnitTesting(void)
{
   message 					= ""		;

   tests_count 			= 0		;
   tests_passed_count 	= 0		;
   tests_failed_count 	= 0		;

   display 					= true	;
}


/// Destructor.

UnitTesting::~UnitTesting()
{
}


// METHODS

/// This method returns the number of tests which have been performed by the test case.

int
UnitTesting::get_tests_count()
{
   return( tests_count );
}


/// This method returns the number of tests which have passed the test case.

int
UnitTesting::get_tests_passed_count()
{
   return( tests_passed_count );
}


/// This method returns the number of tests which have failed the test case.

int
UnitTesting::get_tests_failed_count()
{
   return( tests_failed_count );
}


/// This method returns a reference to the test case information message.

std::string&
UnitTesting::get_message()
{
   return( message );
}


/// This method returns the display messages to the screen value of this object.

bool
UnitTesting::get_display()
{
   return( display );
}


/// This method sets a new value for the number of tests performed by the test case.
/// @param new_tests_count Number of tests performed.

void
UnitTesting::set_tests_count( int new_tests_count )
{
   // Control sentence (if debug)

   #ifdef _DEBUG

   if( new_tests_count < 0 )
   {
      std::cout << "Flood Warning: UnitTesting class." << std::endl
                << "void set_tests_count(int) method." << std::endl
                << "Test count must be equal or greater than zero." << std::endl;
   }

   #endif

   tests_count = new_tests_count;
}


/// This method sets a new value for the number of tests which have passed the test case.
/// @param new_tests_passed_count Number of tests passed.

void
UnitTesting::set_tests_passed_count( int new_tests_passed_count )
{
   // Control sentence (if debug)

   #ifdef _DEBUG

   if( new_tests_passed_count < 0 )
   {
      std::cout << "Flood Warning: UnitTesting class." << std::endl
                << "void set_tests_passed_count(int) method." << std::endl
                << "Test pased count must be equal or greater than zero." << std::endl;
   }

   #endif

   tests_passed_count = new_tests_passed_count;
}


/// This method sets a new value for the number of tests which have failed the test case.
/// @param new_tests_failed_count Number of tests failed.

void
UnitTesting::set_tests_failed_count( int new_tests_failed_count )
{
   // Control sentence (if debug)

   #ifdef _DEBUG

   if( new_tests_failed_count < 0 )
   {
      std::cout << "Flood Warning: UnitTesting class." << std::endl
                << "void set_tests_failed_count(int) method." << std::endl
                << "Test failed count must be equal or greater than zero." << std::endl;
   }
   #endif

   tests_failed_count = new_tests_failed_count;
}


/// This method sets a new test case information message.
/// @param new_message Information message.

void
UnitTesting::set_message( const std::string& new_message )
{
   message = new_message;
}


/// This method sets a new display value to this object.
/// @param new_display Display value.

void
UnitTesting::set_display( bool new_display )
{
   display = new_display;
}


/// This method checks that a condition is true.
/// It increases the number of tests by one.
/// It increases the number of tests passed by one if the condition is true.
/// It increases the number of tests failed by one if the condition is false.
/// It appends to the information message an error message is the condition is not satisfied.
/// @param condition Expression of the condition to be tested.
/// @param error_message Error message to be appended to the information message,
/// typically the file name and the line where the condition has been tested.

void
UnitTesting::assert_true( bool condition, const std::string& error_message )
{
   tests_count++;

   if( condition )

   	tests_passed_count++;

   else
   {
      message += "void assert_true(bool, const std::string&) method failed\n";
      message += error_message;
      tests_failed_count++;
   }
}


/// This method checks that a condition is false.
/// It increases the number of tests by one.
/// It increases the number of tests passed by one if the condition is false.
/// It increases the number of tests failed by one if the condition is true.
/// It appends to the information message an error message is the condition is not satisfied.
/// @param condition Expression of the condition to be tested.
/// @param error_message Error message to be appended to the information message,
/// typically the file name and the line where the condition has been tested.

void
UnitTesting::assert_false( bool condition, const std::string& error_message )
{
   tests_count++;

   if( !condition )

   	tests_passed_count++;

   else
   {
      message += "void assert_false(bool, const std::string&) method failed\n";
      message += error_message;
      tests_failed_count++;
   }
}


/// This method prints the test case results to the screen:
/// <ul>
/// <li> Information message.
/// <li> Number of tests performed.
/// <li> Number of tests passed.
/// <li> Number of tests failed.
/// <li> Concluding remarks.
/// </ul>

void
UnitTesting::print_results()
{
   run_test_case();

   std::cout << message << std::endl;

   std::cout << "Tests run: " << tests_count << std::endl;
   std::cout << "Tests passed: " << tests_passed_count << std::endl;
   std::cout << "Tests failed: " << tests_failed_count << std::endl;

   if( tests_failed_count == 0 )

      std::cout << "Test case OK." << std::endl;

   else

      std::cout << "Test case NOT OK: " << tests_failed_count << " tests failed."  << std::endl;

}

} // namespace tidbits
