#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

/*
   Replace your newly created L4D.cpp with this L4D.cpp file
   The test cases below have been created based on the internal representation
   used in List3.hpp. To understand these test cases better, see List3.hpp's
   internal data member declarations and correspondence clause.

   The L4D project will build if you have correctly done the following:
   1) Configured L4D's project properties correctly for unit testing
   2) Created the IntegerList.h and placed it in CppDevSp21\L4D folder

   When you run the tests using Test Explorer, 13 of the 18 tests will fail
   Start implementing the List3 operations in order to get to 18 out of 18 passing

 */

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L4D
{
	TEST_CLASS(L4D)
	{
	public:


		//********************************************
		// Unit tests for Debug mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List3()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: List3();");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Verify ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT01ConstructorV1 


		// -----------------------------------------------------------------------------------
		// clear
		// -----------------------------------------------------------------------------------
		//! clears self
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT02ClearV1)
		{
			IntegerList s1;
			Text x1;


			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT02ClearV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03ClearV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03ClearV2: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT03ClearV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03ClearV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03ClearV3: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT03ClearV3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03ClearV4)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03ClearV4: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);
			s1.advance();
			k = 11;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT03ClearV4

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03ClearV5)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03ClearV5: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33,11>,<12,24>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 12;
			s1.addRightFront(k);
			k = 24;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT03ClearV5


		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<44>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<44>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[1,<44>]", x1, true, L"s1's internal rep = [1,<44>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT04TransferFromv1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV2: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<>) and s2 = (<>,<>)");

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT04TransferFromv2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV3)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV3: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<44>) and s2 = (<>,<>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT04TransferFromv3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV4)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV4: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<44>) and s2 = (<12>,<>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<12>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			k = 12;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[0,<12>]", x1, true, L"s1's internal rep = [0,<12>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT04TransferFromv4

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV5)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV5: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<44>) and s2 = (<12,13>,<14>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<12,13>,<14>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			k = 14;
			s2.addRightFront(k);
			k = 13;
			s2.addRightFront(k);
			k = 12;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[1,<14,12,13>]", x1, true, L"s1's internal rep = [1,<14,12,13>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT04TransferFromv5


		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT05AssignmentV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<17>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<17>) and s2 = (<>,<17>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s1's internal rep = [1,<17>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s2's internal rep = [1,<17>]");
		} // UT05AssignmentV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT05AssignmentV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05AssignmentV2: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<12>,<14>) and s2 = (<>,<17>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<17>) and s2 = (<>,<17>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);

			k = 14;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s1's internal rep = [1,<17>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s2's internal rep = [1,<17>]");
		} // UT05AssignmentV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT05AssignmentV3)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05AssignmentV3: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<12>,<14>) and s2 = (<>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 14;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s2's internal rep = [0,<>]");
		} // UT05AssignmentV3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT05AssignmentV4)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05AssignmentV4: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<12>,<14>) and s2 = (<19,20>,<17,18>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<19,20>,<17,18>) and s2 = (<19,20>,<17,18>)");

			// Test set up
			k = 18;
			s2.addRightFront(k);
			k = 17;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			k = 19;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			k = 14;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[2,<17,18,19,20>]", x1, true, L"s1's internal rep = [2,<17,18,19,20>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[2,<17,18,19,20>]", x1, true, L"s2's internal rep = [2,<17,18,19,20>]");
		} // UT05AssignmentV4

		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06AddRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFrontV1: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 35 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35>), k = 0");

			// Test set up
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<35>]", x1, true, L"s1's internal rep = [1,<35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06AddRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFrontV2: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<35>), k = 34 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<34,35>), k = 0");

			// Test set up
			k = 35;
			s1.addRightFront(k);
			k = 34;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<34,35>]", x1, true, L"s1's internal rep = [2,<34,35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFrontV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06AddRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFrontV3: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<35>,<>), k = 34 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<35>,<34>), k = 0");

			// Test set up
			k = 35;
			s1.addRightFront(k);
			k = 34;
			s1.advance();

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<34,35>]", x1, true, L"s1's internal rep = [1,<34,35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFrontV3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06AddRightFrontV4)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFrontV4: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<35>,<34>), k = 33 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<35>,<33,34>), k = 0");

			// Test set up
			k = 34;
			s1.addRightFront(k);
			k = 35;
			s1.addRightFront(k);
			k = 33;
			s1.advance();

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<33,34,35>]", x1, true, L"s1's internal rep = [2,<33,34,35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFrontV4

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT16AddRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16AddRightFrontV2: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<21>), k = 35 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35,21>), k= 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<35,21>]", x1, true, L"s1's internal rep = [2,<35,21>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT16AddRightFrontV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT17AddRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17AddRightFrontV3: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<29>), k = 23 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19>,<23,29>), k= 0");

			// Test set up
			k = 29;
			s1.addRightFront(k);
			k = 19;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			k = 23;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<23,29,13,17,19>]", x1, true, L"s1's internal rep = [2,<23,29,13,17,19>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT17AddRightFrontV3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT18AddRightFrontV4)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18AddRightFrontV4: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19,23>,<>), k = 29 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19,23>,<29>), k= 0");

			// Test set up
			k = 23;
			s1.addRightFront(k);
			k = 19;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			k = 29;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<29,13,17,19,23>]", x1, true, L"s1's internal rep = [1,<29,13,17,19,23>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT18AddRightFrontV4

		// -----------------------------------------------------------------------------------
		// RemoveRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! replaces x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and 
		//!          self.right = #self.right[1,|#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT07RemoveRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07RemoveRightFrontV1: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<33,55,77,99>), k= 11");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[4,<33,55,77,99>]", x1, true, L"s1's internal rep = [4,<33,55,77,99>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 11, L"k = 11");
		} // UT07RemoveRightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT07RemoveRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07RemoveRightFrontV2: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<33>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>), k= 33");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 33, L"k = 33");
		} // UT07RemoveRightFrontV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT07RemoveRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07RemoveRightFrontV3: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<33>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>), k= 33");

			//setup test
			k = 33;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 33, L"k = 33");
		} // UT07RemoveRightFrontV3

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT08AdvanceV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AdvanceV1: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[3,<55,77,99,11,33>]", x1, true, L"s1's internal rep = [3,<55,77,99,11,33>]");
		} // UT08AdvanceV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT08AdvanceV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AdvanceV1: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<55>)");

			//setup test
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[1,<55,11,33>]", x1, true, L"s1's internal rep = [1,<55,11,33>]");
		} // UT08AdvanceV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT08AdvanceV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AdvanceV3: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33>]", x1, true, L"s1's internal rep = [0,<11,33>]");
		} // UT08AdvanceV3

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT09MoveToStartV1)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT09MoveToStartV1: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,33,55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[5,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [5,<11,33,55,77,99>]");
		} // UT09MoveToStartV1


		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT10MoveToFinishV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10MoveToFinishV1: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33,55,77,99>,<>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [0,<11,33,55,77,99>]");
		} // UT10MoveToFinishV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT10MoveToFinishV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10MoveToFinishV2: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT10MoveToFinishV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT10MoveToFinishV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10MoveToFinishV3: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<11>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33>]", x1, true, L"s1's internal rep = [0,<11,33>]");
		} // UT10MoveToFinishV3



		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11ReplaceRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11ReplaceRightFrontV1: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>), k = 200 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<200,77,99>),k = 55");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[3,<200,77,99,11,33>]", x1, true, L"s1's internal rep = [3,<200,77,99,11,33>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT11ReplaceRightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT11ReplaceRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11ReplaceRightFrontV2: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<55>), k = 200 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<200>),k = 55");

			//setup test
			k = 55;
			s1.addRightFront(k);
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[1,<200>]", x1, true, L"s1's internal rep = [1,<200>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT11ReplaceRightFrontV2

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> is prefix of self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT12RightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RightFrontV1: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 11, L"k = 11");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[1,<11,3,7>]", x1, true, L"s1's internal rep = [1,<11,3,7>]");
		} // UT12RightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT12RightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RightFrontV2: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<3>)");

			//setup test
			k = 3;
			s1.addRightFront(k);

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 3, L"k = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[1,<3>]", x1, true, L"s1's internal rep = [1,<3>]");
		} // UT12RightFrontV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT12RightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RightFrontV3: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3.4>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<3,4>)");

			//setup test
			k = 4;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 3, L"k = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[2,<3,4>]", x1, true, L"s1's internal rep = [2,<3,4>]");
		} // UT12RightFrontV3

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT13SwapRightsV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV1: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>) and s2 = (<>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<55,77,99>) and s2 = (<>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();

			k = 99;
			s2.addRightFront(k);
			k = 77;
			s2.addRightFront(k);
			k = 55;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[3,<55,77,99,3,7>]", x1, true, L"s1's internal rep = [3,<55,77,99,3,7>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[1,<11>]", x1, true, L"s2's internal rep = [1,<11>]");
		} // UT13SwapRightsV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV2: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s2's internal rep = [0,<>]");
		} // UT13SwapRightsV2
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV3)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV3: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[1,<11>]", x1, true, L"s2's internal rep = [1,<11>]");
		} // UT13SwapRightsV3
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV4)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV4: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,12>) and s2 = (<>,<13>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<13>) and s2 = (<>,<11,12>)");

			//setup test
			k = 12;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			k = 13;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<13>]", x1, true, L"s1's internal rep = [1,<11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<11,12>]", x1, true, L"s2's internal rep = [2,<11,12>]");
		} // UT13SwapRightsV4
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV5)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV5: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,12>) and s2 = (<13>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<13>,<11,12>)");

			//setup test
			k = 12;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			k = 13;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<11,12,13>]", x1, true, L"s2's internal rep = [2,<11,12,13>]");
		} // UT13SwapRightsV5
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV6)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV6: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,12>) and s2 = (<13>,<14>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<14>) and s2 = (<13>,<11,12>)");

			//setup test
			k = 12;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			k = 14;
			s2.addRightFront(k);
			k = 13;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<14>]", x1, true, L"s1's internal rep = [1,<14>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<11,12,13>]", x1, true, L"s2's internal rep = [2,<11,12,13>]");
		} // UT13SwapRightsV6
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV7)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV7: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>) and s2 = (<>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s2's internal rep = [0,<>]");
		} // UT13SwapRightsV7
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV8)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV8: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>) and s2 = (<>,<12>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<12>) and s2 = (<>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			k = 12;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<12,11>]", x1, true, L"s1's internal rep = [1,<12,11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s2's internal rep = [0,<>]");
		} // UT13SwapRightsV8
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV9)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV9: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>) and s2 = (<12>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>) and s2 = (<12>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			k = 12;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<12>]", x1, true, L"s2's internal rep = [0,<12>]");
		} // UT13SwapRightsV9
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV10)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV10: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>) and s2 = (<12>,<13,14>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<13,14>) and s2 = (<12>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			
			k = 14;
			s2.addRightFront(k);
			k = 13;
			s2.addRightFront(k);
			k = 12;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<13,14,11>]", x1, true, L"s1's internal rep = [2,<13,14,11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<12>]", x1, true, L"s2's internal rep = [0,<12>]");
		} // UT13SwapRightsV10
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV11)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV11: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<13,14>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>) and s2 = (<>,<13,14>)");

			//setup test
			k = 14;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);

			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<13,14>]", x1, true, L"s2's internal rep = [2,<13,14>]");
		} // UT13SwapRightsV11
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV12)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV12: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<13,14>) and s2 = (<5,6>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>) and s2 = (<5,6>,<13,14>)");

			//setup test
			k = 14;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			k = 6;
			s2.addRightFront(k);
			k = 5;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();


			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<13,14,5,6>]", x1, true, L"s2's internal rep = [2,<13,14,5,6>]");
		} // UT13SwapRightsV12
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT13SwapRightsV13)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV13: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<13,14>) and s2 = (<5,6>,<7,8>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<7,8>) and s2 = (<5,6>,<13,14>)");

			//setup test
			k = 14;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			
			k = 8;
			s2.addRightFront(k);
			k = 7;
			s2.addRightFront(k);
			k = 6;
			s2.addRightFront(k);
			k = 5;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();


			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<7,8,11>]", x1, true, L"s1's internal rep = [2,<7,8,11>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[2,<13,14,5,6>]", x1, true, L"s2's internal rep = [2,<13,14,5,6>]");
		} // UT13SwapRightsV13


		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14LeftLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14LeftLengthV1: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test 
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 2, L"s1.leftLength() = 2");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33>]", x1, true, L"s1's internal rep = [<0,<11,33>]");
		} // UT14LeftLengthV1
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT14LeftLengthV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14LeftLengthV2: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,33>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 0, L"s1.leftLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[2,<11,33>]", x1, true, L"s1's internal rep = [<2,<11,33>]");
		} // UT14LeftLengthV2
		  
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT14LeftLengthV3)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14LeftLengthV3: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<33>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 1, L"s1.leftLength() = 2");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[1,<33,11>]", x1, true, L"s1's internal rep = [<1,<33,11>]");
		} // UT14LeftLengthV3



		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RightLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RightLengthV1: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<33,55,77>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<33,55,77>)");

			//setup test
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 3, L"s1.rightLength() = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[3,<33,55,77,11>]", x1, true, L"s1's internal rep = [3,<33,55,77,11>]");
		} // UT15RightLengthV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RightLengthV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RightLengthV2: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 0, L"s1.rightLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33>]", x1, true, L"s1's internal rep = [0,<11,33>]");
		} // UT15RightLengthV2

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RightLengthV3)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RightLengthV3: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<33>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 1, L"s1.rightLength() = 1");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[1,<11,33>]", x1, true, L"s1's internal rep = [1,<11,33>]");
		} // UT15RightLengthV3
	};
}
