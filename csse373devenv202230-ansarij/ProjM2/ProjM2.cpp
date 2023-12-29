#include "pch.h"
#include "CppUnitTest.h"
#include "UnlabeledUndirectedGraph/UnlabeledUndirectedGraph1.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjM2
{
	TEST_CLASS(ProjM2)
	{
	public:
		
		// -----------------------------------------------------------------------------------
		// UnlabeledUndirectedGraph1()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = ({},{})
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: UnlabeledUndirectedGraph1();");
			Logger::WriteMessage(L"\toutgoing: u1 = ({},{})");

			// Verify ensures: self = ({},{})
			toText(u1, x1);
			Assert::AreEqual(L"({},{})", x1, true, L"u1's internal rep = ({},{})");
		} // UT01ConstructorV1 

		// -----------------------------------------------------------------------------------
		// clear
		// -----------------------------------------------------------------------------------
		//! clears self
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT02ClearV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;


			Logger::WriteMessage(L"UT02ClearV1: u1.clear();");
			Logger::WriteMessage(L"\tincoming: u1 = ({},{})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({},{})");

			// Execute operation: clear
			u1.clear();

			// Verify clears parameter mode: clears self
			toText(u1, x1);
			Assert::AreEqual(L"({},{})", x1, true, L"u1's internal rep = ({},{})");
		} // UT02ClearV1

		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03TransferFromV1)
		{
			UnlabeledUndirectedGraph1 u1;
			UnlabeledUndirectedGraph1 u2;
			Text x1, x2;
			Integer k1, k2;

			Logger::WriteMessage(L"UT04TransferFromV1: u1.transferFrom(u2);");
			Logger::WriteMessage(L"\tincoming: u1 = ({},{}) and u2 = ({1,2,3},{{2,3}}) ");
			Logger::WriteMessage(L"\toutgoing:  u1 = ({1,2,3},{{2,3}}) and u2 = ({},{})");

			// Test set up
			u2.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u2.addEdge(k1, k2);

			// Execute operation: transferFrom
			u1.transferFrom(u2);

			// Verify ensures: self = #source
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");

			//Verify parameter mode clears: clears source
			toText(u2, x2);
			Assert::AreEqual(L"({},{})", x2, true, L"u2's internal rep = ({},{})");
		} // UT03TransferFromV1

		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT04AssignmentV1)
		{
			UnlabeledUndirectedGraph1 u1;
			UnlabeledUndirectedGraph1 u2;
			Text x1;
			Integer k1, k2;

			Logger::WriteMessage(L"UT05AssignmentV1: u1 = u2;");
			Logger::WriteMessage(L"\tincoming: u1 = ({},{}) and u2 = ({1,2,3},{{2,3}}) ");
			Logger::WriteMessage(L"\toutgoing: u1 = ({1,2,3},{{2,3}}) and u2 = ({1,2,3},{{2,3}})");

			// Test set up
			u2.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u2.addEdge(k1, k2);

			// Execute operation:  operator =
			u1 = u2;

			// Verify ensures self = rhs
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");
			// Verify restores parameter mode: restores rhs
			toText(u2, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u2's internal rep = ({1,2,3},{{2,3}})");
		} // UT04AssignmentV1

		TEST_METHOD(UT05SetNumberOfVerticesV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05SetNumberOfVerticesV1: u1.setNumberOfVertices(5);");
			Logger::WriteMessage(L"\tincoming: u1 = ({},{})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({},{})");

			// Test set up
			k = 5;

			// Execute operation: setNumberOfVertices
			u1.setNumberOfVertices(5);

			// Verify ensures 
			k = u1.numberOfVertices();
			toText(u1, x1);
			Assert::AreEqual(5.0, k + 0.0, true, L"u1.numberOfVertices() = 5");
			Assert::AreEqual(L"({1,2,3,4,5},{})", x1, true, L"u1's internal rep = ({1,2,3,4,5},{})");
			// Verify restores parameter mode: restores rhs
		} // UT05SetNumberOfVerticesV1

		TEST_METHOD(UT06AddEdgeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1, x2;
			Integer k1, k2, k3;

			Logger::WriteMessage(L"UT06AddEdgeV1: u1.addEdge(3, 5);");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3,4,5},{{2,3},{2,5}}) ");
			Logger::WriteMessage(L"\toutgoing:  u1 = ({1,2,3,4,5},{{2,3},{2,5},{3,5}})");

			// Test set up
			u1.setNumberOfVertices(5);
			k1 = 2;
			k2 = 3;
			k3 = 5;
			u1.addEdge(k1, k2);
			u1.addEdge(k1, k3);

			// Execute operation: addEdge
			u1.addEdge(k2, k3);

			// Verify ensures
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{2,3},{2,5},{3,5}})", x1, true, L"u1's internal rep = ({1,2,3,4,5},{{2,3},{2,5},{3,5}})");
			Assert::AreEqual(2.0, k1 + 0.0, true, L"k1 = 2");
			Assert::AreEqual(3.0, k2 + 0.0, true, L"k2 = 3");
		} // UT06AddEdgeV1

		TEST_METHOD(UT07RemoveEdgeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1, x2;
			Integer k1, k2;

			Logger::WriteMessage(L"UT07RemoveEdgeV1: u1.removeEdge(2,3);");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3},{{2,3}}) ");
			Logger::WriteMessage(L"\toutgoing:  u1 = ({1,2,3},{})");

			// Test set up
			u1.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u1.addEdge(k1, k2);

			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");

			// Execute operation: removeEdge
			u1.removeEdge(k1, k2);

			// Verify ensures
			toText(u1, x2);
			Assert::AreEqual(L"({1,2,3},{})", x2, true, L"u1's internal rep = ({1,2,3},{})");
			Assert::AreEqual(2.0, k1 + 0.0, true, L"k1 = 2");
			Assert::AreEqual(3.0, k2 + 0.0, true, L"k2 = 3");
		} // UT07RemoveEdgeV1

		TEST_METHOD(UT08RemoveAnyIncidentEdgeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1, x2;
			Integer k1, k2, k3, k4;

			Logger::WriteMessage(L"UT08RemoveAnyIncidentEdgeV1: u1.removeAnyIncidentEdge(2,3);");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3,4,5},{{2,3},{2,5},{3,4}}) ");
			Logger::WriteMessage(L"\toutgoing:  u1 = ({1,2,3,4,5},{{2,3},{2,5}})");

			// Test set up
			u1.setNumberOfVertices(5);
			k1 = 2;
			k2 = 3;
			k3 = 5;
			u1.addEdge(k1, k2);
			u1.addEdge(k1, k3);
			k3 = 4;
			u1.addEdge(k2, k3);

			// Execute operation: removeAnyIncidentEdge
			u1.removeAnyIncidentEdge(k3, k4);

			// Verify ensures
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{2,3},{2,5}})", x1, true, L"u1's internal rep = ({1,2,3,4,5},{{2,3},{2,5}})");
			Assert::AreEqual(3.0, k4 + 0.0, true, L"k4 = 3");
		} // UT08RemoveAnyIncidentEdgeV1

		TEST_METHOD(UT09RemoveAnyEdgeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1, x2;
			Integer k1, k2, k3, k4, k5;

			Logger::WriteMessage(L"UT08RemoveAnyEdgeV1: u1.removeAnyEdge(2,3);");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3,4,5},{{{2,3},{2,5},{3,5}}) ");
			Logger::WriteMessage(L"\toutgoing:  u1 = ({1,2,3,4,5},{{2,5},{3,5}})");

			// Test set up
			u1.setNumberOfVertices(5);
			k1 = 2;
			k2 = 3;
			k3 = 5;
			u1.addEdge(k1, k2);
			u1.addEdge(k1, k3);
			u1.addEdge(k2, k3);

			// Execute operation: removeAnyEdge
			u1.removeAnyEdge(k4, k5);

			// Verify ensures
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{2,5},{3,5}})", x1, true, L"u1's internal rep = ({1,2,3,4,5},{{2,5},{3,5}})");
			Assert::AreEqual(2.0, k4 + 0.0, true, L"k4 = 2");
			Assert::AreEqual(3.0, k5 + 0.0, true, L"k5 = 3");
		} // UT09RemoveAnyEdgeV1

		TEST_METHOD(UT10NumberOfVerticesV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;
			Integer k1, k2, k3;

			Logger::WriteMessage(L"UT10NumberOfVerticesV1: u1.numberOfVertices();");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3},{{2,3}})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({1,2,3},{{2,3}})");

			// Test set up
			u1.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u1.addEdge(k1, k2);

			// Execute operation: numberOfVertices
			k3 = u1.numberOfVertices();

			// Verify ensures 
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");
			Assert::AreEqual(3.0, k3 + 0.0, true, L"u1.numberOfVertices() = 2");
			// Verify restores parameter mode: restores rhs
		} // UT10NumberOfVerticesV1

		TEST_METHOD(UT11NumberOfEdgesV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;
			Integer k1, k2, k3;

			Logger::WriteMessage(L"UT11NumberOfEdgesV1: u1.numberOfEdges();");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3},{{2,3}})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({1,2,3},{{2,3}})");

			// Test set up
			u1.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u1.addEdge(k1, k2);

			// Execute operation: numberOfEdges
			k3 = u1.numberOfEdges();

			// Verify ensures 
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");
			Assert::AreEqual(1.0, k3 + 0.0, true, L"u1.numberOfVertices() = 1");
			// Verify restores parameter mode: restores rhs
		} // UT11NumberOfEdgesV1

		TEST_METHOD(UT12DegreeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;
			Integer k1, k2, k3, k4;

			Logger::WriteMessage(L"UT12DegreeV1: u1.degree();");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3,4,5},{{2,5},{3,5}})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({1,2,3,4,5},{{2,5},{3,5}})");

			// Test set up
			u1.setNumberOfVertices(5);
			k1 = 2;
			k2 = 3;
			k3 = 5;
			u1.addEdge(k1, k3);
			u1.addEdge(k2, k3);

			// Execute operation: degree
			k4 = u1.degree(k1);

			// Verify ensures 
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{2,5},{3,5}})", x1, true, L"u1's internal rep = ({1,2,3,4,5},{{2,5},{3,5}})");
			Assert::AreEqual(1.0, k4 + 0.0, true, L"u1.degree(3) = 1");
			// Verify restores parameter mode: restores rhs
		} // UT12DegreeV1

		TEST_METHOD(UT12IsEdgeV1)
		{
			UnlabeledUndirectedGraph1 u1;
			Text x1;
			Integer k1, k2;
			Boolean res;

			Logger::WriteMessage(L"UT12IsEdgeV1: u1.isEdge(2,3);");
			Logger::WriteMessage(L"\tincoming: u1 = ({1,2,3},{{2,3}})");
			Logger::WriteMessage(L"\toutgoing: u1 = ({1,2,3},{{2,3}})");

			// Test set up
			u1.setNumberOfVertices(3);
			k1 = 2;
			k2 = 3;
			u1.addEdge(k1, k2);

			// Execute operation: setNumberOfVertices
			res = u1.isEdge(k1, k2);

			// Verify ensures 
			toText(u1, x1);
			Assert::AreEqual(L"({1,2,3},{{2,3}})", x1, true, L"u1's internal rep = ({1,2,3},{{2,3}})");
			Assert::IsTrue(res, L"u1.isEdge(2,3) == true");
			// Verify restores parameter mode: restores rhs
		} // UT12IsEdgeV1
	};
}
