#pragma once
// Filename: UnlabeledUndirectedGraphChecking1.hpp
template <class UnlabeledUndirectedGraph>
class UnlabeledUndirectedGraphChecking : public UnlabeledUndirectedGraph
{
public:
	// Overriding operations appear here

	void addEdge(Integer v1, Integer v2) {
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.vertices and
		//! v2 is in g.vertices and
		//! {v1, v2} is not in g.edges
		//! ensures: g.vertices = #g.vertices and
		//! g.edges = #g.edges union {{v1, v2}}
		 
		Integer lower, upper;
		UnlabeledUndirectedGraph::getVertexBounds(lower, upper);

		if (v1 < lower) {
			OutputDebugString(L"Operation: dequeue\n");
			OutputDebugString(L"Assertion failed: v1 < lower bound of vertices\n");
			DebugBreak();
		} else if (v1 > upper) {
			OutputDebugString(L"Operation: dequeue\n");
			OutputDebugString(L"Assertion failed: v1 > upper bound of vertices\n");
			DebugBreak();
		} else if (v2 < lower) {
			OutputDebugString(L"Operation: dequeue\n");
			OutputDebugString(L"Assertion failed: v2 < lower bound of vertices\n");
			DebugBreak();
		}
		else if (v2 > upper) {
			OutputDebugString(L"Operation: dequeue\n");
			OutputDebugString(L"Assertion failed: v2 > upper bound of vertices\n");
			DebugBreak();
		}
		else if (UnlabeledUndirectedGraph::isEdge(v1, v2)) {
			OutputDebugString(L"Operation: dequeue\n");
			OutputDebugString(L"Assertion failed: {v1, v2} already in edges.\n");
			DebugBreak();
		}
		UnlabeledUndirectedGraph::addEdge(v1, v2);
	}

	void removeEdge(Integer v1, Integer v2) {
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.vertices and
		//! v2 is in g.vertices and
		//! {v1, v2} is in g.edges
		//! ensures: g.vertices = #g.vertices and
		//! g.edges = #g.edges - {{v1, v2}}
		
		Integer lower, upper;
		UnlabeledUndirectedGraph::getVertexBounds(lower, upper);

		if (v1 < lower) {
			OutputDebugString(L"Operation: addEdge\n");
			OutputDebugString(L"Assertion failed: v1 < lower bound of vertices\n");
			DebugBreak();
		}
		else if (v1 > upper) {
			OutputDebugString(L"Operation: addEdge\n");
			OutputDebugString(L"Assertion failed: v1 > upper bound of vertices\n");
			DebugBreak();
		}
		else if (v2 < lower) {
			OutputDebugString(L"Operation: addEdge\n");
			OutputDebugString(L"Assertion failed: v2 < lower bound of vertices\n");
			DebugBreak();
		}
		else if (v2 > upper) {
			OutputDebugString(L"Operation: addEdge\n");
			OutputDebugString(L"Assertion failed: v2 > (upper bound of vertices\n");
			DebugBreak();
		}
		else if (!UnlabeledUndirectedGraph::isEdge(v1, v2)) {
			OutputDebugString(L"Operation: addEdge\n");
			OutputDebugString(L"Assertion failed: {v1,v2} not in edges\n");
			DebugBreak();
		}
		UnlabeledUndirectedGraph::removeEdge(v1, v2);
	}
	void removeAnyIncidentEdge(Integer v1, Integer& v2) {
		//! updates self
		//! restores v1
		//! replaces v2
		//! requires: v1 is in g.vertices and
		//! there exists v : integer ({v1, v}) is in g.edges)
		//! ensures: g.vertices = #g.vertices and
		//! {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}
		 
		Integer lower, upper;
		UnlabeledUndirectedGraph::getVertexBounds(lower, upper);

		if (v1 < lower) {
			OutputDebugString(L"Operation: removeAnyIncidentEdge\n");
			OutputDebugString(L"Assertion failed: v1 < lower bound of vertices\n");
			DebugBreak();
		}
		else if (v1 > upper) {
			OutputDebugString(L"Operation: removeAnyIncidentEdge\n");
			OutputDebugString(L"Assertion failed: v1 > upper bound of vertices\n");
			DebugBreak();
		}

		boolean found;
		for (int i = 0; i < (upper - lower); i++) {
			if (UnlabeledUndirectedGraph::getValueAtEdge(i, 0) == v1 || 
				UnlabeledUndirectedGraph::getValueAtEdge(i, 1) == v1) {
				found = true;
				break;
			}
		}

		if (!found) {
			OutputDebugString(L"Operation: removeAnyIncidentEdge\n");
			OutputDebugString(L"Assertion failed: vertex v1 not found in edges\n");
			DebugBreak();
		}

		UnlabeledUndirectedGraph::removeAnyIncidentEdge(v1, v2);
	}
	void removeAnyEdge(Integer& v1, Integer& v2) {
		//! updates self
		//! replaces v1, v2
		//! requires: g.edges /= {}
		//! ensures: g.vertices = #g.vertices and
		//! {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}
		
		if (UnlabeledUndirectedGraph::numberOfEdges() == 0) {
			OutputDebugString(L"Operation: removeAnyEdge\n");
			OutputDebugString(L"Assertion failed: graph has no edges\n");
			DebugBreak();
		}
		UnlabeledUndirectedGraph::removeAnyEdge(v1, v2);
	}
}; // end UnlabeledUndirectedGraphChecking
