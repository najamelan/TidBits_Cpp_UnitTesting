// local includes
#include <tidbits/unit_testing/test_unit_testing.hpp>

// system includes
#include <iostream>

using namespace tidbits;

int main()
{
   std::cout << "TidBits Library. Test Unit Testing Application." << std::endl;

   TestUnitTesting test;

   test.print_results();

   std::cin.get()	;
	return 0			;
}
