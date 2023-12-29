#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "IntegerQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Queue1UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// -----------------------------------------------------------------------------------
		// Queue1()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01Constructor)
		{
			IntegerQueue q1;
			Text x1;

			Logger::WriteMessage(L"UT01Constructor: Queue1();");
			Logger::WriteMessage(L"\toutgoing: q1 = <>");

			// Verify ensures: self = <>
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT01Constructor

		  // -----------------------------------------------------------------------------------
		  // clear
		  // -----------------------------------------------------------------------------------
		  //! clears self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT02Clear)
		{
			IntegerQueue q1;
			Text x1;

			Logger::WriteMessage(L"UT02Clear: q1.clear();");
			Logger::WriteMessage(L"\tincoming: q1 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <>");

			// Execute operation: clear
			q1.clear();

			// Verify parameter mode clears: clears self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT02Clear

		TEST_METHOD(UT03Clear)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03Clear: q1.clear();");
			Logger::WriteMessage(L"\tincoming: q1 = <10>");
			Logger::WriteMessage(L"\toutgoing: q1 = <>");

			// Test set up
			k = 10;
			q1.enqueue(k);

			// Execute operation: clear
			q1.clear();

			// Verify clears parameter mode: clears self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT03Clear

		  // -----------------------------------------------------------------------------------
		  // transferFrom
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! clears source
		  //! ensures: self = #source
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFrom)
		{
			IntegerQueue q1, q2;
			Text x1, x2;

			Logger::WriteMessage(L"UT04TransferFrom: q1.transferFrom(q2);");
			Logger::WriteMessage(L"\tincoming: q1 = <> and q2 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and q2 = <>");

			// Execute operation: transferFrom
			q1.transferFrom(q2);

			// Verify ensures: self = #source
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");

			// Verify clears parameter mode: clears source
			toText(q2, x2);
			Assert::IsTrue(x2 == "<>", L"q2 = <>");
		} // UT04TransferFrom

		TEST_METHOD(UT05TransferFrom)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT05TransferFrom: q1.transferFrom(q2);");
			Logger::WriteMessage(L"\tincoming: q1 = <> and q2 = <17>");
			Logger::WriteMessage(L"\toutgoing: q1 = <17> and q2 = <>");

			// Test set up
			k = 17;
			q2.enqueue(k);

			// Execute operation: transferFrom
			q1.transferFrom(q2);

			// Verify ensures: self = #source
			toText(q1, x1);
			Assert::IsTrue(x1 == "<17>", L"q1 = <17>");

			// Verify clears parameter mode: clears source
			toText(q2, x2);
			Assert::IsTrue(x2 == "<>", L"q2 = <>");
		} // UT05TransferFrom

		TEST_METHOD(UT06TransferFrom)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT06TransferFrom: q1.transferFrom(q2);");
			Logger::WriteMessage(L"\tincoming: q1 = <10> and q2 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and q2 = <>");

			// Test set up
			k = 10;
			q1.enqueue(k);

			// Execute operation: transferFrom
			q1.transferFrom(q2);

			// Verify ensures: self = #source
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");

			// Verify clears parameter mode: clears source
			toText(q2, x2);
			Assert::IsTrue(x2 == "<>", L"q2 = <>");
		} // UT06TransferFrom

		TEST_METHOD(UT07TransferFrom)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT07TransferFrom: q1.transferFrom(q2);");
			Logger::WriteMessage(L"\tincoming: q1 = <10> and q2 = <25>");
			Logger::WriteMessage(L"\toutgoing: q1 = <25> and q2 = <>");

			// Test set up
			k = 10;
			q1.enqueue(k);
			k = 25;
			q2.enqueue(k);

			// Execute operation: transferFrom
			q1.transferFrom(q2);

			// Verify ensures: self = #source
			toText(q1, x1);
			Assert::IsTrue(x1 == "<25>", L"q1 = <25>");

			// Verify clears parameter mode: clears source
			toText(q2, x2);
			Assert::IsTrue(x2 == "<>", L"q2 = <>");
		} // UT07TransferFrom

		  // -----------------------------------------------------------------------------------
		  // operator =
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! restores rhs
		  //! ensures: self = rhs
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT08Assignment)
		{
			IntegerQueue q1, q2;
			Text x1, x2;

			Logger::WriteMessage(L"UT08Assignment: q1 = q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <> and q2 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and q2 = <>");

			// Execute operation: operator =
			q1 = q2;

			// Verify ensures: self = rhs
			toText(q1, x1);
			toText(q2, x2);
			Assert::IsTrue(x1 == x2, L"q1 = q2");

			// Verify restores parameter mode: restores rhs
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT08Assignment

		TEST_METHOD(UT09Assignment)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT09Assignment: q1 = q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <> and q2 = <27>");
			Logger::WriteMessage(L"\toutgoing: q1 = <27> and q2 = <27>");

			// Test set up
			k = 27;
			q2.enqueue(k);

			// Execute operation: operator =
			q1 = q2;

			// Verify ensures: self = rhs
			toText(q1, x1);
			toText(q2, x2);
			Assert::IsTrue(x1 == x2, L"q1 = q2");

			// Verify restores parameter mode: restores rhs
			toText(q1, x1);
			Assert::IsTrue(x1 == "<27>", L"q1 = <27>");
		} // UT09Assignment

		TEST_METHOD(UT10Assignment)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT10Assignment: q1 = q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <10> and q2 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and q2 = <>");

			// Test set up
			k = 10;
			q1.enqueue(k);

			// Execute operation: operator =
			q1 = q2;

			// Verify ensures: self = rhs
			toText(q1, x1);
			toText(q2, x2);
			Assert::IsTrue(x1 == x2, L"q1 = q2");

			// Verify restores parameter mode: restores rhs
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT10Assignment

		TEST_METHOD(UT11Assignment)
		{
			IntegerQueue q1, q2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT11Assignment: q1 = q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <10> and q2 = <27>");
			Logger::WriteMessage(L"\toutgoing: q1 = <27> and q2 = <27>");

			// Test set up
			k = 10;
			q1.enqueue(k);
			k = 27;
			q2.enqueue(k);

			// Execute operation: operator =
			q1 = q2;

			// Verify ensures: self = rhs
			toText(q1, x1);
			toText(q2, x2);
			Assert::IsTrue(x1 == x2, L"q1 = q2");

			// Verify restores parameter mode: restores rhs
			toText(q1, x1);
			Assert::IsTrue(x1 == "<27>", L"q1 = <27>");
		} // UT11Assignment

		  // -----------------------------------------------------------------------------------
		  // enqueue
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! clears x
		  //! ensures: self = #self * <#x>
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT12Enqueue)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12Enqueue: q1.enqueue(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <> and k = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15> and k = 0");

			// Test set up
			k = 15;

			// Execute operation: enqueue
			q1.enqueue(k);

			// Verify ensures: self = #self * <#x>
			toText(q1, x1);
			Assert::IsTrue(x1 == "<15>", L"q1 = <15>");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT12Enqueue

		TEST_METHOD(UT13Enqueue)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13Enqueue: q1.enqueue(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <15> and k = 25");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,25> and k = 0");

			// Test set up
			k = 15;
			q1.enqueue(k);

			// Execute operation: enqueue
			k = 25;
			q1.enqueue(k);

			// Verify ensures: self = #self * <#x>
			toText(q1, x1);
			Assert::IsTrue(x1 == "<15,25>", L"q1 = <15,25>");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT13Enqueue

		  // -----------------------------------------------------------------------------------
		  // dequeue
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! replaces x
		  //! requires: self /= <>
		  //! ensures: <x> is prefix of #self  and  self = #self[1, |#self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT14Dequeue)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14Dequeue: q1.dequeue(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <30> and k = 0");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and k = 30");

			// Test set up
			k = 30;
			q1.enqueue(k);

			// Execute operation: dequeue
			q1.dequeue(k);

			// Verify ensures: <x> is prefix of #self
			Assert::IsTrue(k == 30, L"k = 30");

			// Verify ensures: self = #self[1, |#self|)
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT14Dequeue

		TEST_METHOD(UT15Dequeue)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15Dequeue: q1.dequeue(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <25,30> and k = 0");
			Logger::WriteMessage(L"\toutgoing: q1 = <30> and k = 25");

			// Test set up
			k = 25;
			q1.enqueue(k);
			k = 30;
			q1.enqueue(k);

			// Execute operation: dequeue
			q1.dequeue(k);

			// Verify ensures: <x> is prefix of #self
			Assert::IsTrue(k == 25, L"k = 25");

			// Verify ensures: self = #self[1, |#self|)
			toText(q1, x1);
			Assert::IsTrue(x1 == "<30>", L"q1 = <30>");
		} // UT15Dequeue

		  // -----------------------------------------------------------------------------------
		  // replaceFront
		  // -----------------------------------------------------------------------------------
		  //! updates self, x
		  //! requires: self /= <>
		  //! ensures: <x> is prefix of #self  and  self = <#x> * #self[1, |#self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT16ReplaceFront)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16ReplaceFront: q1.replaceFront(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <50> and k = 100");
			Logger::WriteMessage(L"\toutgoing: q1 = <100> and k = 50");

			// Test set up
			k = 50;
			q1.enqueue(k);

			// Execute operation: replaceFront
			k = 100;
			q1.replaceFront(k);

			// Verify ensures: <x> is prefix of #self
			Assert::IsTrue(k == 50, L"k = 50");

			// Verify ensures: self = <#x> * #self[1, |#self|)
			toText(q1, x1);
			Assert::IsTrue(x1 == "<100>", L"q1 = <100>");
		} // UT16ReplaceFront

		TEST_METHOD(UT17ReplaceFront)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17ReplaceFront: q1.replaceFront(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <50,55> and k = 100");
			Logger::WriteMessage(L"\toutgoing: q1 = <100,55> and k = 50");

			// Test set up
			k = 50;
			q1.enqueue(k);
			k = 55;
			q1.enqueue(k);

			// Execute operation: replaceFront
			k = 100;
			q1.replaceFront(k);

			// Verify ensures: <x> is prefix of #self
			Assert::IsTrue(k == 50, L"k = 50");

			// Verify ensures: self = <#x> * #self[1, |#self|)
			toText(q1, x1);
			Assert::IsTrue(x1 == "<100,55>", L"q1 = <100,55>");
		} // UT17ReplaceFront

		  // -----------------------------------------------------------------------------------
		  // front
		  // -----------------------------------------------------------------------------------
		  //! restores self
		  //! requires: self /= <>
		  //! ensures: <front> is prefix of self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT18Front)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18Front: q1.front();");
			Logger::WriteMessage(L"\tincoming: q1 = <75>");
			Logger::WriteMessage(L"\toutgoing: q1 = <75>");

			// Test set up
			k = 75;
			q1.enqueue(k);

			// Verify ensures: <front> is prefix of self
			Assert::IsTrue(q1.front() == 75, L"<front> is prefix of q1");

			// Verify restores parameter mode: restores self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<75>", L"q1 = <75>");
		} // UT18Front

		TEST_METHOD(UT19Front)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT19Front: q1.front();");
			Logger::WriteMessage(L"\tincoming: q1 = <75,80>");
			Logger::WriteMessage(L"\toutgoing: q1 = <75,80>");

			// Test set up
			k = 75;
			q1.enqueue(k);
			k = 80;
			q1.enqueue(k);

			// Verify ensures: <front> is prefix of self
			Assert::IsTrue(q1.front() == 75, L"<front> is prefix of q1");

			// Verify restores parameter mode: restores self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<75,80>", L"q1 = <75,80>");
		} // UT19Front

		  // -----------------------------------------------------------------------------------
		  // length
		  // -----------------------------------------------------------------------------------
		  //! restores self
		  //! ensures: length = |self|
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT20Length)
		{
			IntegerQueue q1;
			Text x1;

			Logger::WriteMessage(L"UT20Length: q1.length();");
			Logger::WriteMessage(L"\tincoming: q1 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <>");

			// Verify ensures: length = |self|
			Assert::IsTrue(q1.length() == 0, L"|q1| = 0");

			// Verify restores parameter mode: restores self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<>", L"q1 = <>");
		} // UT20Length

		TEST_METHOD(UT21Length)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT21Length: q1.length();");
			Logger::WriteMessage(L"\tincoming: q1 = <95>");
			Logger::WriteMessage(L"\toutgoing: q1 = <95>");

			// Test set up
			k = 95;
			q1.enqueue(k);

			// Verify ensures: length = |self|
			Assert::IsTrue(q1.length() == 1, L"|q1| = 1");

			// Verify restores parameter mode: restores self
			toText(q1, x1);
			Assert::IsTrue(x1 == "<95>", L"q1 = <95>");
		} // UT21Length

	};
}