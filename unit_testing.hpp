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
#include <string>


// Macro definitions

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

} 			// namespace tidbits
#endif 	// Guard_D7CCE5F4_056F_4762_8365_510F33C9711A
