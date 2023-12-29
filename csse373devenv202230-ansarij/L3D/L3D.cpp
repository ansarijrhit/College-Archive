#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L3D
{
	TEST_CLASS(L3D)
	{
	public:
		

		//********************************************
		// Unit tests for Debug mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List2()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01Constructor)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01Constructor: List2();");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Verify ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT01Constructor


		// -----------------------------------------------------------------------------------
		// clear
		// -----------------------------------------------------------------------------------
		//! clears self
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT02Clear)
		{
			IntegerList s1;
			Text x1;


			Logger::WriteMessage(L"UT02Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT02Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT03Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT021Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;


			Logger::WriteMessage(L"UT021Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<29>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

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

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT021Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT022Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;


			Logger::WriteMessage(L"UT022Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 19;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT022Clear

		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<44>)");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<44>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<44>]", x1, true, L"s1's internal rep = [<>,<44>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT04TransferFrom

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT041TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT041TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<44>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s1.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT041TransferFrom

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT042TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT042TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<44>) and s2 = (<42>,<43>)");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<42>,<43>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s1.addRightFront(k);
			k = 43;
			s2.addRightFront(k);
			k = 42;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<42>,<43>]", x1, true, L"s1's internal rep = [<42>,<43>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT042TransferFrom


		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT05Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<17>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<17>) and s2 = (<>,<17>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<17>]", x1, true, L"s1's internal rep = [<>,<17>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<17>]", x1, true, L"s2's internal rep = [<>,<17>]");
		} // UT05Assignment

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT051Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT051Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<17>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 17;
			s1.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT051Assignment

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT052Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT052Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<12>,<17>) and s2 = (<13>,<18>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13>,<18>) and s2 = (<13>,<18>)");

			// Test set up
			k = 17;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);
			s1.advance();

			k = 18;
			s2.addRightFront(k);
			k = 13;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<13>,<18>]", x1, true, L"s1's internal rep = [<13>,<18>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<13>,<18>]", x1, true, L"s2's internal rep = [<13>,<18>]");
		} // UT052Assignment

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT053Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT053Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<12>,<17>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 12;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT053Assignment

		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35>), k = 0");

			// Test set up
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<35>]", x1, true, L"s1's internal rep = [<>,<35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT16AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<21>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35,21>), k = 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<35,21>]", x1, true, L"s1's internal rep = [<>,<35,21>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT16AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT17AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<29>), k = 23");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19>,<23,29>), k = 0");

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
			Assert::AreEqual(L"[<13,17,19>,<23,29>]", x1, true, L"s1's internal rep = [<13,17,19>,<23,29>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT17AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT18AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19,23>,<>), k = 29");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19,23>,<29>), k = 0");

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
			Assert::AreEqual(L"[<13,17,19,23>,<29>]", x1, true, L"s1's internal rep = [<13,17,19,23>,<29>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT18AddRightFront

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
		TEST_METHOD(UT07RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<33,55,77,99>), k = 11");

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
			Assert::AreEqual(L"[<>,<33,55,77,99>]", x1, true, L"s1's internal rep = [<>,<33,55,77,99>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 11, L"k = 11");
		} // UT07RemoveRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT071RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT071RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>), k = 11");

			//setup test
			k = 11;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 11, L"k = 11");
		} // UT071RemoveRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT072RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT072RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<14>,<18,11>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<14>,<11>), k = 18");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 18;
			s1.addRightFront(k);
			k = 14;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<14>,<11>]", x1, true, L"s1's internal rep = [<14>,<11>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 18, L"k = 18");
		} // UT072RemoveRightFront

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT08Advance)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08Advance: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>)");
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
			Assert::AreEqual(L"[<11,33>,<55,77,99>]", x1, true, L"s1's internal rep = [<11,33>,<55,77,99>]");
		} // UT08Advance

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT081Advance)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT081Advance: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[<11>,<>]", x1, true, L"s1's internal rep = [<11>,<>]");
		} // UT081Advance

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT09MoveToStart)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT09MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>)");
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
			Assert::AreEqual(L"[<>,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [<>,<11,33,55,77,99>]");
		} // UT09MoveToStart

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT091MoveToStart)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT091MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,33>)");

			//setup test
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
			Assert::AreEqual(L"[<>,<11,33>]", x1, true, L"s1's internal rep = [<>,<11,33>]");
		} // UT091MoveToStart

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT092MoveToStart)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT092MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT092MoveToStart

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT093MoveToStart)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT093MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11>)");

			// setup test
			k = 11;
			s1.addRightFront(k);

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11>]", x1, true, L"s1's internal rep = [<>,<11>]");
		} // UT093MoveToStart

		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT10MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>)");
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
			Assert::AreEqual(L"[<11,33,55,77,99>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77,99>,<>]");
		} // UT10MoveToFinish

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT101MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT101MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>)");
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
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55,77,99>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77,99>,<>]");
		} // UT101MoveToFinish

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT102MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT102MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33>,<>]", x1, true, L"s1's internal rep = [<11,33>,<>]");
		} // UT102MoveToFinish

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT103MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT103MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT103MoveToFinish

		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11ReplaceRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11ReplaceRightFront: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<200,77,99>), k = 55");

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
			Assert::AreEqual(L"[<11,33>,<200,77,99>]", x1, true, L"s1's internal rep = [<11,33>,<200,77,99>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT11ReplaceRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT111ReplaceRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT111ReplaceRightFront: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<55>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<200>), k = 55");

			//setup test
			k = 55;
			s1.addRightFront(k);
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<200>]", x1, true, L"s1's internal rep = [<>,<200>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT111ReplaceRightFront

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> is prefix of self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT12RightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RightFront: s1.rightFront();");
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
			Assert::AreEqual(L"[<3,7>,<11>]", x1, true, L"s1's internal rep = [<3,7>,<11>]");
		} // UT12RightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT121RightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT121RightFront: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 11, L"k = 11");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11>]", x1, true, L"s1's internal rep = [<>,<11>]");
		} // UT121RightFront

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT13SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRights: s1.swapRights(s2);");
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
			Assert::AreEqual(L"[<3,7>,<55,77,99>]", x1, true, L"s1's internal rep = [<3,7>,<55,77,99>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<11>]",  x1, true, L"s2's internal rep = [<>,<11>]");
		} // UT13SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT131SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT131SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<>) and s2 = (<>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<55,77,99>) and s2 = (<>,<>)");

			//setup test
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
			Assert::AreEqual(L"[<3,7>,<55,77,99>]", x1, true, L"s1's internal rep = [<3,7>,<55,77,99>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT131SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT132SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT132SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>) and s2 = (<13>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<>) and s2 = (<13>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();

			k = 13;
			s2.addRightFront(k);
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<3,7>,<>]", x1, true, L"s1's internal rep = [<3,7>,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<13>,<11>]", x1, true, L"s2's internal rep = [<13>,<11>]");
		} // UT132SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT133SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT133SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");


			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT133SwapRights


		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14LeftLength: s1.leftLength();");
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
			Assert::AreEqual(L"[<11,33>,<>]", x1, true, L"s1's internal rep = [<11,33>,<>]");
		} // UT14LeftLength

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT141LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT141LeftLength: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,13>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,13>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 0, L"s1.leftLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11,33>]", x1, true, L"s1's internal rep = [<>,<11,33>]");
		} // UT141LeftLength



		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RightLength: s1.rightLength();");
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
			Assert::AreEqual(L"[<11>,<33,55,77>]", x1, true, L"s1's internal rep = [<11>,<33,55,77>]");
		} // UT15RightLength

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT151RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT151RightLength: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 0, L"s1.rightLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<11>,<>]", x1, true, L"s1's internal rep = [<11>,<>]");
		} // UT15RightLength
	};
}
