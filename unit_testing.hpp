/// \file  TidBits_Cpp/tidbits/unit_testing/unit_testing.hpp
/// This is the header for a base class for automated unit tests

/** \file  TidBits_Cpp/tidbits/unit_testing/unit_testing.hpp
 * Code comes from the Flood3 library by Roberto Lopez and is under the GNU Lesser General Public License
 * http://www.cimne.com/flood/
 */


#ifndef Guard_D7CCE5F4_056F_4762_8365_510F33C9711A
#define Guard_D7CCE5F4_056F_4762_8365_510F33C9711A
#define unittesting_hpp

// local includes
// this probably should remain empty because we want everything to be able to be unit tested,
// so we want this to rely on nothing

// system includes
#include <cassert>
#include <iostream>
#include <string>


// Macro definitions
// from: http://www.decompile.com/cpp/faq/file_and_line_error_string.htm
// Note that __FILE__ does not work correctly on visual studio with /ZI

#define STRING(x)		#x
#define TOSTRING(x)	STRING(x)
#define LOG				__FILE__ ":" TOSTRING(__LINE__)"\n"



namespace tidbits
{

/// This class contains a minimal set of utilities needed for automated unit testing.

class UnitTesting
{
	public:

		explicit UnitTesting();
		virtual ~UnitTesting();

		// METHODS
		// Get methods

		int 				get_tests_count			();
		int 				get_tests_passed_count	();
		int 				get_tests_failed_count	();

		std::string& 	get_message					();

		bool 				get_display					();

		// Set methods

		void 				set_tests_count			( int );
		void 				set_tests_passed_count	( int );
		void 				set_tests_failed_count	( int );

		void 				set_message( const std::string& 	);
		void 				set_display( bool						);

		// Unit testing methods

		void assert_true ( bool, const std::string& );
		void assert_false( bool, const std::string& );

		// Test case methods
		/// This method runs all the methods contained in the test case.

		virtual 	void run_test_case() = 0;
					void print_results()		;

	protected:
		int 				tests_count				;	///< Number of performed tests.
		int 				tests_passed_count	;	///< Number of tests which have passed the test case.
		int 				tests_failed_count	;	///< Number of tests which have failed the test case.
		std::string 	message					;	///< String with the test case information.
		bool 				display					;	///< True if messages from this class are to be displayed, false otherwise.
};




// Definitions


/// General constructor. It constructs a test case with default values:
/// <ul>
/// <li> Message: empty
/// <li> Tests count : 0
/// <li> Tests passed: 0
/// <li> Tests failed: 0
/// <li> Display: true
/// </ul>

UnitTesting::UnitTesting()
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
   assert( new_tests_count >= 0 );

   tests_count = new_tests_count;
}


/// This method sets a new value for the number of tests which have passed the test case.
/// @param new_tests_passed_count Number of tests passed.

void
UnitTesting::set_tests_passed_count( int new_tests_passed_count )
{
   assert( new_tests_passed_count >= 0 );

   tests_passed_count = new_tests_passed_count;
}


/// This method sets a new value for the number of tests which have failed the test case.
/// @param new_tests_failed_count Number of tests failed.

void
UnitTesting::set_tests_failed_count( int new_tests_failed_count )
{
   assert( new_tests_failed_count >= 0 );

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
      message += "void assert_false( bool, const std::string& ) method failed\n";
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

	std::cout 								<< message 					<< std::endl	;
	std::cout << "\nTest results:\n"									<< std::endl	;
   std::cout << "   Tests run   : "	<< tests_count 			<< std::endl	;
   std::cout << "   Tests passed: "	<< tests_passed_count 	<< std::endl	;
   std::cout << "   Tests failed: "	<< tests_failed_count 	<< std::endl	;


	if		 ( tests_count 			== 0 )

		std::cout << "\nSomething went wrong, nothing got tested."						<< std::endl;


	else if( tests_failed_count == 0 )

	   std::cout << "\nTest OK"																	<< std::endl;


   else

	   std::cout << "\nTest NOT OK. " << tests_failed_count << " tests failed"		<< std::endl;

}



} 			// namespace tidbits
#endif 	// Guard_D7CCE5F4_056F_4762_8365_510F33C9711A
