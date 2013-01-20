/*
 * Armageddon_test.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: dd
 */

#include "Armageddon.h"

#include <functional>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
//#define BOOST_TEST_MODULE ArmageddonTest
#include <boost/test/unit_test.hpp>

// most frequently you implement test cases as a free functions with automatic registration
BOOST_AUTO_TEST_CASE( add01 )
{
	Armageddon A;

	BOOST_CHECK( A.add(0,0) == 0 );
	BOOST_CHECK( A.add(-1,+1) == 0 );
	BOOST_CHECK( A.add(1,1) == 2 );
	BOOST_CHECK( A.add(INT_MAX,0) == INT_MAX );
	BOOST_CHECK_EQUAL( A.add( INT_MAX,INT_MAX) , INT_MAX );
	BOOST_CHECK( A.add(INT_MAX,-1) == (INT_MAX-1) );
	BOOST_CHECK( A.add(INT_MAX,-INT_MAX) == 0 );
}

int hash(const void *data, size_t len)
{
	int h, highorder;
	unsigned char* d = (unsigned char*) data;

	h = 0;
	for(unsigned long l=0; l < len; l++)
	{
		highorder = h & 0xf8000000;    // extract high-order 5 bits from h
									   // 0xf8000000 is the hexadecimal representation
									   //   for the 32-bit number with the first five
									   //   bits = 1 and the other bits = 0
		 h = h << 5;                    // shift h left by 5 bits
		 h = h ^ (highorder >> 27);     // move the highorder 5 bits to the low-order
									   //   end and XOR into h
		 h = h ^ *d;                    // XOR h and ki
		 d++;
	}
	return h;
}

BOOST_AUTO_TEST_CASE( ClassObjects )
{
	int A[] = {1,2,3,4,5};
	int B[] = {1,2,3,4,5};


	BOOST_CHECK_EQUAL( hash(A, sizeof(A)), hash(B, sizeof(B)) );

	BOOST_CHECK_EQUAL_COLLECTIONS( A, A+5, B , B+5);
}
