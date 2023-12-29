#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerSeq.h"
#include "Wrapper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L5R
{
	TEST_CLASS(L5R)
	{
	public:
		
		// -----------------------------------------------------
		// Queue1()
		// -----------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------
		TEST_METHOD(UT01Constructor)
		{
			IntegerSeq s1;
			Text x1;

			Logger::WriteMessage(L"UT01Constructor: Sequence2();");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Verify ensures: self = <>
			toText(s1, x1);
			Assert::AreEqual(L"<>", x1, true, L"s1 = <>");
		} // UT01Constructor

		// -----------------------------------------------------
		// clear
		// -----------------------------------------------------
		//! clears self
		// -----------------------------------------------------
		TEST_METHOD(UT02Clear)
		{
			IntegerSeq s1;
			Text x1;

			Logger::WriteMessage(L"UT02Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");


			s1.clear();


			toText(s1, x1);
			Assert::AreEqual(L"<>", x1, true, L"s1 = <>");
		} // UT02Clear

		// -----------------------------------------------------
		// transferFrom
		// -----------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------
		TEST_METHOD(UT03TransferFrom)
		{
			IntegerSeq s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT03TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: transferFrom
			s1.transferFrom(s2);


			toText(s1, x1);
			Assert::AreEqual(L"<>", x1, true, L"s1 = <>");


			toText(s2, x2);
			Assert::AreEqual(L"<>", x2, true, L"s2 = <>");
		} // UT03TransferFrom

		// -----------------------------------------------------

		TEST_METHOD(UT031TransferFrom)
		{
			IntegerSeq s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT031TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <10,14> and s2 = <11,12>");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,12> and s2 = <>");

			// Test setup
			k = 14;
			s1.add(Integer(0), k);
			k = 10;
			s1.add(Integer(0), k);

			k = 12;
			s2.add(Integer(0), k);
			k = 11;
			s2.add(Integer(0), k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);


			toText(s1, x1);
			Assert::AreEqual(L"<11,12>", x1, true, L"s1 = <11,12>");


			toText(s2, x2);
			Assert::AreEqual(L"<>", x2, true, L"s2 = <>");
		} // UT031TransferFrom

		// -----------------------------------------------------
		// operator =
		// -----------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------
		TEST_METHOD(UT04Assignment)
		{
			IntegerSeq s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT04Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");


			// Execute operation: operator =
			s1 = s2;


			toText(s1, x1);
			toText(s2, x2);
			Assert::IsTrue(x1 == x2, L"s1 = s2");


			toText(s2, x2);
			Assert::AreEqual(L"<>", x2, true, L"s2 = <>");
		} // UT04Assignment

		// -----------------------------------------------------
		// add
		// -----------------------------------------------------
		//! updates self
		//! clears k
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
		// -----------------------------------------------------
		TEST_METHOD(UT05Add)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos, k;

			Logger::WriteMessage(L"UT05Add: s1.add(pos, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and pos = 0 and k = 15");
			Logger::WriteMessage(L"\toutgoing: s1 = <15> and pos = 0 and k = 0");

			// Test set up
			pos = 0;
			k = 15;

			// Execute operation: add
			s1.add(pos, k);


			toText(s1, x1);
			Assert::AreEqual(L"<15>", x1, true, L"s1 = <15>");


			Assert::IsTrue(k == 0, L"k = 0");


			Assert::IsTrue(pos == 0, L"pos = 0");
		} // UT05Add

		// -----------------------------------------------------

		TEST_METHOD(UT051Add)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos, k;

			Logger::WriteMessage(L"UT051Add: s1.add(pos, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and pos = 0 and k = 15");
			Logger::WriteMessage(L"\toutgoing: s1 = <14,15,16,17> and pos = 0 and k = 0");

			// Test set up
			pos = 0;
			k = 15;
			s1.add(pos, k);
			pos = 1;
			k = 16;
			s1.add(pos, k);
			pos = 0;
			k = 14;
			s1.add(pos, k);
			pos = 3;
			k = 17;

			// Execute operation: add
			s1.add(pos, k);


			toText(s1, x1);
			Assert::AreEqual(L"<14,15,16,17>", x1, true, L"s1 = <14,15,16,17>");


			Assert::IsTrue(k == 0, L"k = 0");


			Assert::IsTrue(pos == 3, L"pos = 3");
		} // UT051Add

		// -----------------------------------------------------
		// remove
		// -----------------------------------------------------
		//! updates self
		//! replaces x
		//! restores pos
		//! requires: 0 <= pos < |self|
		//! ensures: self = #self[0, pos) * #self[pos+1, |#self|)  and
		//!          <x> = #self[pos, pos+1)
		// -----------------------------------------------------
		TEST_METHOD(UT06Remove)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos, k;

			Logger::WriteMessage(L"UT06Remove: s1.remove(pos, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <10,20,30> and pos = 1 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <10,30> and pos = 1 and k = 20");

			// Test set up
			s1.add(0, Integer(30));
			s1.add(0, Integer(20));
			s1.add(0, Integer(10));
			pos = 1;
			k = 0;

			// Execute operation: remove
			s1.remove(pos, k);


			Assert::IsTrue(k == 20, L"k = 20");


			toText(s1, x1);
			Assert::AreEqual(L"<10,30>", x1, true, L"s1 = <10,30>");


			Assert::IsTrue(pos == 1, L"pos = 1");
		} // UT06Remove

		// -----------------------------------------------------

		TEST_METHOD(UT061Remove)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos, k;

			Logger::WriteMessage(L"UT061Remove: s1.remove(pos, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <10,20,30> and pos = 2 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <10,20> and pos = 2 and k = 30");

			// Test set up
			s1.add(0, Integer(30));
			s1.add(0, Integer(20));
			s1.add(0, Integer(10));
			pos = 2;
			k = 0;

			// Execute operation: remove
			s1.remove(pos, k);


			Assert::IsTrue(k == 30, L"k = 30");


			toText(s1, x1);
			Assert::AreEqual(L"<10,20>", x1, true, L"s1 = <10,20>");


			Assert::IsTrue(pos == 2, L"pos = 2");
		} // UT061Remove

		// -----------------------------------------------------
		// replaceEntry
		// -----------------------------------------------------
		//! updates self
		//! updates x
		//! restores pos
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1)  and
		//!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
		// -----------------------------------------------------
		TEST_METHOD(UT07ReplaceEntry)
		{
			IntegerSeq s1, s2;
			Text x1;
			Integer pos, k;

			Logger::WriteMessage(L"UT07ReplaceEntry: s1.replaceEntry(pos, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <10,20,30> and pos = 2 and k = -30");
			Logger::WriteMessage(L"\toutgoing: s1 = <10,20,-30> and pos = 2 and k = 30");

			// Test set up
			s1.add(0, Integer(30));
			s1.add(0, Integer(20));
			s1.add(0, Integer(10));
			pos = 2;
			k = -30;

			s2 = s1;
			toText(s2, x1);
			Assert::AreEqual(L"<10,20,30>", x1, true, L"s2 = <10,20,30>");

			// Execute operation: replaceEntry
			s1.replaceEntry(pos, k);


			//Assert::IsTrue(k == 30, L"k = 30");
			Assert::AreEqual(30.0, k + 0.0, true, L"k = 30");


			toText(s1, x1);
			Assert::AreEqual(L"<10,20,-30>", x1, true, L"s1 = <10,20,-30>");


			Assert::IsTrue(pos == 2, L"pos = 2");
		} // UT07ReplaceEntry

		// -----------------------------------------------------
		// entry
		// -----------------------------------------------------
		//! restores self
		//! restores pos
		//! requires:  0 <= pos < |self|
		//! ensures: <entry> = self[pos, pos+1)
		// -----------------------------------------------------
		TEST_METHOD(UT08Entry)
		{
			IntegerSeq s1, s2;
			Text x1;
			Integer pos, entry;

			Logger::WriteMessage(L"UT08Entry: s1.entry(pos);");
			Logger::WriteMessage(L"\tincoming: s1 = <10,20,30> and pos = 2");
			Logger::WriteMessage(L"\toutgoing: s1 = <10,20,30> and pos = 2");

			// Test set up
			s1.add(0, Integer(30));
			s1.add(0, Integer(20));
			s1.add(0, Integer(10));
			pos = 2;

			s2 = s1;
			toText(s2, x1);
			Assert::AreEqual(L"<10,20,30>", x1, true, L"s2 = <10,20,30>");

			// Execute operation: entry
			entry = s1.entry(pos);


			Assert::IsTrue(entry == 30, L"<entry> = <30>");


			toText(s1, x1);
			Assert::AreEqual(L"<10,20,30>", x1, true, L"s1 = <10,20,30>");


			Assert::IsTrue(pos == 2, L"pos = 2");
		} // UT08Entry

		// -----------------------------------------------------
		// append
		// -----------------------------------------------------
		//! updates self
		//! clears s1
		//! ensures: self = #self  *  sToAppend
		// -----------------------------------------------------
		TEST_METHOD(UT09Append)
		{
			IntegerSeq s1, s2, s3, s4;
			Text x1, x2;

			Logger::WriteMessage(L"UT09Append: s2.append(s1);");
			Logger::WriteMessage(L"\tincoming: s1 = <30,40,50,60> and s2 = <0,10,20>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <10,20,30,40,50,60>");

			// Test set up
			s1.add(0, Integer(60));
			s1.add(0, Integer(50));
			s1.add(0, Integer(40));
			s1.add(0, Integer(30));
			s2.add(0, Integer(20));
			s2.add(0, Integer(10));
			s2.add(0, Integer(0));

			s3 = s1;
			s4 = s2;
			toText(s3, x1);
			Assert::AreEqual(L"<30,40,50,60>", x1, true, L"s3 = <30,40,50,60>");
			toText(s4, x2);
			Assert::AreEqual(L"<0,10,20>", x2, true, L"s4 = <0,10,20>");

			// Execute operation: append
			s2.append(s1);


			toText(s2, x2);
			Assert::AreEqual(L"<0,10,20,30,40,50,60>", x2, true, L"s2 = <0,10,20,30,40,50,60>");


			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT09Append

		// -----------------------------------------------------
		// split
		// -----------------------------------------------------
		//! updates self
		//! replaces s1
		//! restores pos
		//! requires:  0 <= pos <= |self|
		//! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
		// -----------------------------------------------------
		TEST_METHOD(UT10Split)
		{
			IntegerSeq s1, s2;
			Text x1, x2;
			Integer pos;

			Logger::WriteMessage(L"UT10Split: s2.split(pos, s1);");
			Logger::WriteMessage(L"\tincoming: s1 = <-30> and pos = 1 and s2 = <10,20,30,40>");
			Logger::WriteMessage(L"\toutgoing: s1 = <20,30,40> and pos = 1 and s2 = <10>");

			// Test set up
			s1.add(0, Integer(-30));
			s2.add(0, Integer(40));
			s2.add(0, Integer(30));
			s2.add(0, Integer(20));
			s2.add(0, Integer(10));
			pos = 1;

			// Execute operation: split
			s2.split(pos, s1);


			toText(s2, x2);
			Assert::AreEqual(L"<10>", x2, true, L"s2 = <10>");


			toText(s1, x1);
			Assert::AreEqual(L"<20,30,40>", x1, true, L"s1 = <20,30,40>");
			Assert::IsTrue(pos == 1, L"pos = 1");
		} // UT10Split

		// -----------------------------------------------------

		TEST_METHOD(UT101Split)
		{
			IntegerSeq s1, s2;
			Text x1, x2;
			Integer pos;

			Logger::WriteMessage(L"UT101Split: s2.split(pos, s1);");
			Logger::WriteMessage(L"\tincoming: s1 = <-30,-20> and pos = 1 and s2 = <10,20,30,40>");
			Logger::WriteMessage(L"\toutgoing: s1 = <30,40> and pos = 1 and s2 = <10,20>");

			// Test set up
			s1.add(0, Integer(-20));
			s1.add(0, Integer(-30));
			s2.add(0, Integer(40));
			s2.add(0, Integer(30));
			s2.add(0, Integer(20));
			s2.add(0, Integer(10));
			pos = 2;

			// Execute operation: split
			s2.split(pos, s1);


			toText(s2, x2);
			Assert::AreEqual(L"<10,20>", x2, true, L"s2 = <10,20>");


			toText(s1, x1);
			Assert::AreEqual(L"<30,40>", x1, true, L"s1 = <30,40>");
			Assert::IsTrue(pos == 2, L"pos = 2");
		} // UT101Split

		// -----------------------------------------------------
		// length
		// -----------------------------------------------------
		//! restores self
		//! ensures: length = |self|
		// -----------------------------------------------------
		TEST_METHOD(UT11Length)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos;

			Logger::WriteMessage(L"UT11Length: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Execute operation: length
			s1.length();


			toText(s1, x1);
			Assert::IsTrue(s1.length() == 0, L"|s1| = 0");
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT11Length

		// -----------------------------------------------------
		
		TEST_METHOD(UT111Length)
		{
			IntegerSeq s1;
			Text x1;
			Integer pos;

			Logger::WriteMessage(L"UT111Length: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <10,20>");
			Logger::WriteMessage(L"\toutgoing: s1 = <10,20>");

			// Test setup
			s1.add(0, Integer(20));
			s1.add(0, Integer(10));

			// Execute operation: length
			s1.length();


			toText(s1, x1);
			Assert::IsTrue(s1.length() == 2, L"|s1| = 2");
			Assert::IsTrue(x1 == "<10,20>", L"s1 = <10,20>");
		} // UT111Length
	};
}
