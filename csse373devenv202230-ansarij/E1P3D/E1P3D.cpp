#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace E1P3D
{
	TEST_CLASS(E1P3D)
	{
	public:


		//********************************************
		// Unit tests for Debug mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List6()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01Constructor)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01Constructor: List6();");
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
			Integer k;

			Logger::WriteMessage(L"UT02Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<83>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 83;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT02Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT021Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT021Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<83>,<12,13>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 13;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);
			k = 83;
			s1.addRightFront(k);
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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<12,13>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 13;
			s1.addRightFront(k);
			k = 12;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT022Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<83>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 83;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT03Clear

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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<11>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<11>) and s2 = (<>,<>)");

			// Test set up
			k = 11;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11>]", x1, true, L"s1's internal rep = [<>,<11>]");

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
			Logger::WriteMessage(L"\tincoming: s1 = (<41,22>,<-5,33,29>) and s2 = (<10,11>,<12,13>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<10,11>,<12,13>) and s2 = (<>,<>)");

			// Test set up
			k = 13;
			s2.addRightFront(k);
			k = 12;
			s2.addRightFront(k);
			k = 10;
			s2.addRightFront(k);
			k = 11;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<-5,33,29>]", x1, true, L"s1's internal rep = [<41,22>,<-5,33,29>]");
			toText(s2, x2);
			Assert::AreEqual(L"[<10,11>,<12,13>]", x2, true, L"s2's internal rep = [<10,11>,<12,13>]");
			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<10,11>,<12,13>]", x1, true, L"s1's internal rep = [<10,11>,<12,13>]");

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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<9>) and s2 = (<10,11>,<>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<10,11>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);
			k = 11;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			k = 9;
			s1.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<10,11>,<>]", x1, true, L"s1's internal rep = [<10,11>,<>]");

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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<10>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<10>) and s2 = (<>,<10>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<10>]", x1, true, L"s1's internal rep = [<>,<10>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<10>]", x1, true, L"s2's internal rep = [<>,<10>]");
		} // UT05Assignment

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT051Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT051Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<4>,<8>) and s2 = (<11,12>,<10>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,12>,<10>) and s2 = (<11,12>,<10>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);
			k = 11;
			s2.addRightFront(k);
			k = 12;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			k = 8;
			s1.addRightFront(k);
			k = 4;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<11,12>,<10>]", x1, true, L"s1's internal rep = [<11,12>,<10>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<11,12>,<10>]", x1, true, L"s2's internal rep = [<11,12>,<10>]");
		} // UT051Assignment

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT052Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT052Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<4>,<8>) and s2 = (<>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 8;
			s1.addRightFront(k);
			k = 4;
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
		} // UT052Assignment

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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 18 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<18>), k = 0");

			// Test set up
			k = 18;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<18>]", x1, true, L"s1's internal rep = [<>,<18>]");

			// Verify clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT06AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT07AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22>), k = 83");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<83,22>), k = 0");

			// Test set up
			k = 22;
			s1.addRightFront(k);
			k = 83;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<83,22>]", x1, true, L"s1's internal rep = [<>,<83,22>]");

			// Verify clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT07AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT08AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<17,2,10>,<11>), k = 83 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<17,2,10>,<83,11>), k = 0");

			// Test set up
			k = 11;
			s1.addRightFront(k);
			k = 10;
			s1.addRightFront(k);
			k = 2;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			k = 83;
			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<10,2,17>,<83,11>]", x1, true, L"s1's internal rep = [<10,2,17>,<83,11>]");

			// Verify clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT08AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT09AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT09AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<17,2,10,83>,<>), k = 11 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<17,2,10,83>,<11>), k = 0");

			// Test set up
			k = 83;
			s1.addRightFront(k);
			k = 10;
			s1.addRightFront(k);
			k = 2;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			k = 11;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<83,10,2,17>,<11>]", x1, true, L"s1's internal rep = [<83,10,2,17>,<11>]");

			// Verify clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT09AddRightFront

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
		TEST_METHOD(UT10RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41,-5,33,29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<41,-5,33,29>), k = 22");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<41,-5,33,29>]", x1, true, L"s1's internal rep = [<>,<41,-5,33,29>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::AreEqual(22., k, true, L"k = 22");
		} // UT10RemoveRightFront

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<33,29>), k = -5");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<33,29>]", x1, true, L"s1's internal rep = [<41,22>,<33,29>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::AreEqual(-5., k, true, L"k = -5");
		} // UT11RemoveRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT12RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41,-5,33>,<29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41,-5,33>,<>), k = 29");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<33,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<33,-5,41,22>,<>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::AreEqual(29., k, true, L"k = 29");
		} // UT12RemoveRightFront

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT13Advance)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13Advance: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41,-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<-5,33,29>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<-5,33,29>]", x1, true, L"s1's internal rep = [<41,22>,<-5,33,29>]");
		} // UT13Advance

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14MoveToStart)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41,-5,33,29>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41,-5,33,29>]", x1, true, L"s1's internal rep = [<>,<22,41,-5,33,29>]");
		} // UT14MoveToStart

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15MoveToStart)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41,-5,43,39>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41,-5,33,29>)");

			//setup test
			k = 39;
			s1.addRightFront(k);
			k = 43;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41,-5,43,39>]", x1, true, L"s1's internal rep = [<>,<22,41,-5,43,39>]");
		} // UT15MoveToStart

		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT16MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41,-5,33,29>,<>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<29,33,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<29,33,-5,41,22>,<>]");
		} // UT16MoveToFinish

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT161MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT161MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<39,43,-5,41,22>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<39,43,-5,41,22>,<>)");

			//setup test
			k = 39;
			s1.addRightFront(k);
			k = 43;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<39,43,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<22,41,-5,43,39>,<>]");
		} // UT161MoveToFinish

		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT17ReplaceRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17ReplaceRightFront: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>), k = 5 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<5,33,29>), k = -5");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 5;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<5,33,29>]", x1, true, L"s1's internal rep = [<41,22>,<5,33,29>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::AreEqual(-5., k, true, L"k = -5");
		} // UT17ReplaceRightFront

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> is prefix of self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT18RightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18RightFront: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41>,<22>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41>,<22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::AreEqual(22., k, true, L"k = 22");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<41,3>,<22>]", x1, true, L"s1's internal rep = [<41,3>,<22>]");
		} // UT18RightFront

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT19SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT19SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41>,<22>) and s2 = (<>,<-5,33,29>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41>,<-5,33,29>) and s2 = (<>,<22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<41,3>,<-5,33,29>]", x1, true, L"s1's internal rep = [<41,3>,<-5,33,29>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<22>]", x1, true, L"s2's internal rep = [<>,<22>]");
		} // UT19SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT20SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT20SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41,22>,<>) and s2 = (<>,<-5,33,29>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41,22>,<-5,33,29>) and s2 = (<>,<>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();
			s1.advance();

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<22,41,3>,<-5,33,29>]", x1, true, L"s1's internal rep = [<22,41,3>,<-5,33,29>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT20SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT21SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT21SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT21SwapRights


		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT22SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT22SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3,41,22>) and s2 = (<-5,33,29>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<-5,33,29>,<3,41,22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<29,33,-5>,<3,41,22>]", x1, true, L"s1's internal rep = [<29,33,-5>,<3,41,22>]");
		} // UT22SwapRights

		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT23LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT23LeftLength: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<>)");

			//setup test
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::AreEqual(2., s1.leftLength(), true, L"s1.leftLength() = 2");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<>]", x1, true, L"s1's internal rep = [<41,22>,<>]");
		} // UT23LeftLength

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT231LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT231LeftLength: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41>)");

			//setup test
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Verify ensures: leftLength = |self.left|
			Assert::AreEqual(0., s1.leftLength(), true, L"s1.leftLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41>]", x1, true, L"s1's internal rep = [<>,<22,41>]");
		} // UT231LeftLength

		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT24RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT24RightLength: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22>,<41,-5,33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22>,<41,-5,33>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::AreEqual(3., s1.rightLength(), true, L"s1.rightLength() = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<22>,<41,-5,33>]", x1, true, L"s1's internal rep = [<22>,<41,-5,33>]");
		} // UT24RightLength

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT241RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT241RightLength: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22>,<>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::AreEqual(0., s1.rightLength(), true, L"s1.rightLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<22>,<>]", x1, true, L"s1's internal rep = [<22>,<>]");
		} // UT241RightLength
	};
}
