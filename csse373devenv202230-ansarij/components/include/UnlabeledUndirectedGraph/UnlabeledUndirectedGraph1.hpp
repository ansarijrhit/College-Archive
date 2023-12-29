#pragma once
#include "Wrapper.h"
#include "CeramicArray/CeramicArray1.hpp"
#include "CeramicArray/CeramicArrayChecking.hpp"

/*
	Realization of UnlabeledUndirectedGraph
	Author: Jordan Ansari
*/


//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------


class UnlabeledUndirectedGraph1
	//! is modeled by UNLABELED_UNDIRECTED_GRAPH_MODEL
	//! exemplar g
	//! initialization ensures
	//! g = ({}, {})
{
public: // Standard Operations
	UnlabeledUndirectedGraph1();
	//! replaces self
	//! ensures: self = ({},{})
	~UnlabeledUndirectedGraph1();
	void clear();
	//! clears self
	void transferFrom(UnlabeledUndirectedGraph1& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	UnlabeledUndirectedGraph1& operator = (UnlabeledUndirectedGraph1& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

// UnlabeledUndirectedGraph Specific Operations

	void setNumberOfVertices(Integer nv);
		//! updates self
		//! restores nv
		//! ensures: self.vertices = {n: integer where (1 <= n <= nv) (n)} and
		//! self.edges = {}
	void addEdge(Integer v1, Integer v2);
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.vertices and
		//! v2 is in g.vertices and
		//! {v1, v2} is not in g.edges
		//! ensures: g.vertices = #g.vertices and
		//! g.edges = #g.edges union {{v1, v2}}
	void removeEdge(Integer v1, Integer v2);
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.vertices and
		//! v2 is in g.vertices and
		//! {v1, v2} is in g.edges
		//! ensures: g.vertices = #g.vertices and
		//! g.edges = #g.edges - {{v1, v2}}
	void removeAnyIncidentEdge(Integer v1, Integer& v2);
		//! updates self
		//! restores v1
		//! replaces v2
		//! requires: v1 is in g.vertices and
		//! there exists v : integer ({v1, v}) is in g.edges)
		//! ensures: g.vertices = #g.vertices and
		//! {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}
	void removeAnyEdge(Integer& v1, Integer& v2);
		//! updates self
		//! replaces v1, v2
		//! requires: g.edges /= {}
		//! ensures: g.vertices = #g.vertices and
		//! {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}
	void getVertexBounds(Integer& v1, Integer& v2);
	Integer getValueAtEdge(Integer v1, Integer v2);
	Integer numberOfVertices();
		//! restores self
		//! ensures: numberOfVertices = |g.vertices|
	Integer numberOfEdges();
		//! restores self
		//! ensures: numberOfEdges = |g.edges|
	Integer degree(Integer v);
		//! restores self, v
		//! ensures: degree = |{v2: integer where ({v, v2} is in g.edges) (v2)}|
	Boolean isEdge(Integer v1, Integer v2);
		//! restores self, v1, v2
		//! ensures: isEdge = ({v1, v2} is in g.edges)
	friend wostream& operator<< (wostream& os, UnlabeledUndirectedGraph1& q);
		//! updates os
		//! restores q
	
private:// Representation

	typedef CeramicArray1 <Integer> array;

	Integer vertexCount, edgeCount;
	CeramicArray1<Integer> vertices;
	CeramicArray1 <CeramicArray1<Integer>> edges;

private: // Disallowed UnlabeledUndirectedGraph1 Operations
	UnlabeledUndirectedGraph1(const UnlabeledUndirectedGraph1& s);
	UnlabeledUndirectedGraph1* operator & (void) {return this;};
	const UnlabeledUndirectedGraph1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

UnlabeledUndirectedGraph1::UnlabeledUndirectedGraph1()
{

}

UnlabeledUndirectedGraph1::~UnlabeledUndirectedGraph1()
{

}

void UnlabeledUndirectedGraph1::clear() {
	edges.clear();
	vertices.clear();
}

void UnlabeledUndirectedGraph1::transferFrom(UnlabeledUndirectedGraph1& source) {
	vertices.transferFrom(source.vertices);
	edges.transferFrom(source.edges);
	edgeCount = source.edgeCount;
	vertexCount = source.vertexCount;
	source.edgeCount = 0;
	source.vertexCount = 0;
}

UnlabeledUndirectedGraph1& UnlabeledUndirectedGraph1::operator=(UnlabeledUndirectedGraph1& rhs) {
	edges = rhs.edges;
	vertices = rhs.vertices;
	vertexCount = rhs.vertexCount;
	edgeCount = rhs.edgeCount;

	return *this;
}

void UnlabeledUndirectedGraph1::setNumberOfVertices(Integer nv) {
	vertexCount = nv;
	vertices.setBounds(1, nv);
	edges.clear();
}

void UnlabeledUndirectedGraph1::getVertexBounds(Integer& v1, Integer& v2) {
	vertices.getBounds(v1, v2);
}

Integer UnlabeledUndirectedGraph1::getValueAtEdge(Integer v1, Integer v2) {
	return edges[v1][v2];
}

void UnlabeledUndirectedGraph1::addEdge(Integer v1, Integer v2) {
	CeramicArray1<Integer> newEdge;
	CeramicArray1<CeramicArray1<Integer>> tempEdges;
	tempEdges = edges;
	newEdge.setBounds(0, 1);
	if (v1 <= v2) {
		newEdge[0] = v1;
		newEdge[1] = v2;
	}
	else {
		newEdge[0] = v2;
		newEdge[1] = v1;
	}
	for (int k = 0; k < edgeCount; k++) {
		if (edges[k][0] == newEdge[0] && edges[k][1] == newEdge[1]) {
			return;
		}
	}
	edgeCount++;

	edges.setBounds(0, edgeCount);
	if (edgeCount == 1) {
		edges[0] = newEdge;
		return;
	}

	boolean placed = false;

	for (int k = 0; k < edgeCount - 1; k++) {
		if (tempEdges[k][0] > newEdge[0] && !placed) {
			edges[k] = newEdge;
			placed = true;
		}
		else if (tempEdges[k][0] == newEdge[0] && !placed) {
			if (tempEdges[k][1] > newEdge[1]) {
				edges[k] = newEdge;
				placed = true;
			}
			else {
				edges[k] = tempEdges[k];
			}
		}
		else {
			if (!placed) {
				edges[k] = tempEdges[k];
			}
			else {
				edges[k] = tempEdges[k - 1];
			}
		}
		if (!placed) {
			edges[edgeCount - 1] = newEdge;
		}
	}
}

void UnlabeledUndirectedGraph1::removeEdge(Integer v1, Integer v2) {
	CeramicArray1<CeramicArray1<Integer>> tempEdges;
	tempEdges = edges;

	edges.setBounds(0, edgeCount-1);

	boolean found = false;

	for (int k = 0; k < edgeCount; k++) {
		if (tempEdges[k][0] == v1 && tempEdges[k][1] == v2) {
			found = true;
		}
		else {
			if (!found) {
				edges[k] = tempEdges[k];
			}
			else {
				edges[k-1] = tempEdges[k];
			}
		}
	}
	edgeCount--;
}

void UnlabeledUndirectedGraph1::removeAnyIncidentEdge(Integer v1, Integer& v2) {
	CeramicArray1<CeramicArray1<Integer>> tempEdges;
	tempEdges = edges;

	edges.setBounds(0, edgeCount - 1);

	boolean found = false;

	for (int k = 0; k < edgeCount; k++) {
		if (tempEdges[k][0] == v1) {
			found = true;
			v2 = tempEdges[k][1];
		}
		else if (tempEdges[k][1] == v1) {
			found = true;
			v2 = tempEdges[k][0];
		}
		else {
			if (!found) {
				edges[k] = tempEdges[k];
			}
			else {
				edges[k - 1] = tempEdges[k];
			}
		}
	}
	edgeCount--;
}

void UnlabeledUndirectedGraph1::removeAnyEdge(Integer& v1, Integer& v2) {
	CeramicArray1<CeramicArray1<Integer>> tempEdges;
	tempEdges = edges;

	edges.setBounds(0, edgeCount - 1);

	boolean found = false;
	
	v1 = tempEdges[0][0];
	v2 = tempEdges[0][1];

	for (int k = 1; k < edgeCount; k++) {
		edges[k - 1] = tempEdges[k];
	}
	edgeCount--;
}

Integer UnlabeledUndirectedGraph1::numberOfVertices() {
	return vertexCount;
}

Integer UnlabeledUndirectedGraph1::numberOfEdges() {
	return edgeCount;
}

Integer UnlabeledUndirectedGraph1::degree(Integer v) {
	int degree = 0;
	for (int k = 0; k < edgeCount; k++) {
		if (edges[k][0] == v || edges[k][1] == v) {
			degree++;
		}
	}
	return degree;
}

Boolean UnlabeledUndirectedGraph1::isEdge(Integer v1, Integer v2) {
	CeramicArray1<Integer> tempEdge;
	tempEdge.setBounds(0, 1);
	if (v1 <= v2) {
		tempEdge[0] = v1;
		tempEdge[1] = v2;
	}
	else {
		tempEdge[0] = v2;
		tempEdge[1] = v1;
	}
	for (int k = 0; k < edgeCount; k++) {
		if (edges[k][0] == tempEdge[0] && edges[k][1] == tempEdge[1]) {
			return true;
		}
	}
	return false;
}


wostream& operator<<(wostream &os, UnlabeledUndirectedGraph1& g)
{

	os << L"({";

	for (int k = 1, z = g.numberOfVertices(), lastItem = z; k <= z; k++) {
		os << k;

		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L"},{";

	for (int k = 0, z = g.numberOfEdges(), lastItem = z-1; k < z; k++) {
		os << L"{";
		os << g.edges[k][0];
		os << ",";
		os << g.edges[k][1];
		os << L"}";

		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for

	os << L"})";
	return os;
}

