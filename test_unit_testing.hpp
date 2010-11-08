/// \file  TidBits_Cpp/tidbits/unit_testing/test_unit_testing.hpp
/// \brief Unit test code for UnitTesting

/** \file  TidBits_Cpp/tidbits/unit_testing/test_unit_testing.hpp
 *  Header file needed to run the automated unit tests on the UnitTesting tidbit
 *  Inspired by code from the Flood3 Library by Roberto Lopez.
 *  http://www.cimne.com/flood/
 *  Flood3 is under GNU Lesser General Public License
 *
 *
 *  These tests are using this unit testing framework to test itself.
 *  There is some paradox in this because if the framework does not function correctly
 *  the results of these tests will not be reliable. However, the chance of this code
 *  accidently outputting a sensible result with no tests failed if there are any bugs
 *  is rather small, so it is still useful to run them and better than nothing.
 *
 */


#ifndef Guard_CF0AC456_191B_4290_B30F_0176F6DDFE5D
#define Guard_CF0AC456_191B_4290_B30F_0176F6DDFE5D
#define test_unit_testing_hpp

#include <tidbits/unit_testing.hpp>


namespace tidbits
{


class TestUnitTesting : public UnitTesting
{
	public:

		explicit TestUnitTesting()	{}	;
		virtual ~TestUnitTesting()	{}	;


		// Constructor and destructor methods

		void test_constructor();

		// Unit testing methods

		void test_assert_true_true_literal		();
		void test_assert_true_false_literal		();
		void test_assert_false_true_literal		();
		void test_assert_false_false_literal	();


		// Unit testing methods

		void run_test_case();

};





/*--------------------------------------------------------------
 *
 * The Tests
 *--------------------------------------------------------------*/



// test the constructor

void
TestUnitTesting::test_constructor()
{
   message += "   test constructor\n";

   TestUnitTesting test;

   assert_true( test.message					.empty()	, LOG )	;
   assert_true( test.tests_count 			== 0		, LOG )	;
   assert_true( test.tests_passed_count 	== 0		, LOG )	;
   assert_true( test.tests_failed_count 	== 0		, LOG )	;
   assert_true( test.display 					== true	, LOG )	;
}


// Pass true to assert_true( bool expr, std::string msg )

void
TestUnitTesting::test_assert_true_true_literal()
{
   message += "   test pass true  to assert_true ()\n";

   TestUnitTesting test;

   test.assert_true( true, LOG );

   assert_true( test.get_tests_count			() == 1, LOG )	;
   assert_true( test.get_tests_passed_count	() == 1, LOG )	;
   assert_true( test.get_tests_failed_count	() == 0, LOG )	;
}




// Pass false to assert_true( bool expr, std::string msg )

void
TestUnitTesting::test_assert_true_false_literal()
{
   message += "   test pass false to assert_true ()\n";

   TestUnitTesting test;

   test.assert_true( false, LOG );

   assert_true( test.get_tests_count			() == 1, LOG )	;
   assert_true( test.get_tests_passed_count	() == 0, LOG )	;
   assert_true( test.get_tests_failed_count	() == 1, LOG )	;
}




// Pass true to assert_false( bool expr, std::string msg )

void
TestUnitTesting::test_assert_false_true_literal()
{
   message += "   test pass true  to assert_false()\n";

   TestUnitTesting test;

   test.assert_false( true, LOG );

   assert_true( test.get_tests_count			() == 1, LOG )	;
   assert_true( test.get_tests_passed_count	() == 0, LOG )	;
   assert_true( test.get_tests_failed_count	() == 1, LOG )	;
}




// Pass false to assert_false( bool expr, std::string msg )

void
TestUnitTesting::test_assert_false_false_literal()
{
   message += "   test pass false to assert_false()\n";

   TestUnitTesting test;

   test.assert_false( false, LOG );

   assert_true( test.get_tests_count			() == 1, LOG )	;
   assert_true( test.get_tests_passed_count	() == 1, LOG )	;
   assert_true( test.get_tests_failed_count	() == 0, LOG )	;
}



// Runs all tests

void TestUnitTesting::run_test_case()
{
   message += "\nRunning unit testing test case...\n";

   // Constructor and destructor methods

   test_constructor();


   // Unit testing methods

	test_assert_true_true_literal		();
	test_assert_true_false_literal	();
	test_assert_false_true_literal	();
	test_assert_false_false_literal	();
}




}		 // namespace tidbits
#endif /*Guard_CF0AC456_191B_4290_B30F_0176F6DDFE5D*/

