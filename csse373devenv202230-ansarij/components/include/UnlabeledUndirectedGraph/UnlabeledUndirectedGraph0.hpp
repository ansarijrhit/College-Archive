#pragma once
#include "Wrapper.h"

/*
	Realization of UnlabeledUndirectedGraph using ChainPosition
	Author: Dr. Holly
*/

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------


class UnlabeledUndirectedGraph0
/*!
	math subtype BARE_EDGE is finite set of integer
	exemplar e
	constraint
	| e | = 2

	math subtype EDGE is (
		endpoints: BARE_EDGE,
		label : T
	)

	math subtype UNDIRECTED_GRAPH_MODEL is (
		vertices: finite set of integer,
		edges : finite set of EDGE
	)
	exemplar g
	constraint
	there exists nv : integer such that
	(g.vertices = { v: integer where(1 <= v <= nv) (v) }) and
	for all e : EDGE where(e is in g.edges)
		(for all v : integer
			where(v is in e.endpoints)
			(v is in g.vertices)) and
		for all v1, v2, v3, v4 : integer, y1, y2 : T
			where(({ v1, v2 }, y1) is in g.edges and
				({ v3, v4), y2) is in g.edges)
	 ({v1, v2} = {v3, v4} implies y1 = y2)

	 type UndirectedGraph is modeled by UNDIRECTED_GRAPH_MODEL
	 exemplar g
	 initialization ensures
		 g = ({},{})
!*/

{
public: // Standard Operations
	UnlabeledUndirectedGraph0 ();
		//! replaces self
		//! ensures: self = ({},{})
	~UnlabeledUndirectedGraph0 ();
	void clear (void);
		//! clears self
	void transferFrom (UnlabeledUndirectedGraph0& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	UnlabeledUndirectedGraph0& operator = (UnlabeledUndirectedGraph0& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// UnlabeledUndirectedGraph0 Specific Operations
	void setNumberOfVertices (Integer nv);
		//! updates self
		//! restores nv
		//! ensures: self.nodes = {n: integer where (1 <= n <= nv) (n)}  and
		//!          self.edges = {}

	void addEdge (Integer v1, Integer v2);
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.verticies and 
		//!           v2 is in g.verticies and
		//!           {v1, v2} is not in g.edges
		//! ensures: g.vertices = #g.vertices and
		//!          g.edges = #g.edges union {{v1, v2}}

	void removeEdge (Integer v1, Integer v2);
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.verticies and 
		//!           v2 is in g.verticies and
		//!           {v1, v2} is in g.edges
		//! ensures: g.vertices = #g.vertices and
		//!          {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}

	void removeAnyIncidentEdge (Integer v1, Integer& v2);
		//! updates self
		//! restores v1
		//! replaces v2
		//! requires: v1 is in g.verticies and 
		//!           there exists v : integer such that ({v1, v} is in g.edges)
		//! ensures: g.vertices = #g.vertices and
		//!          {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}

	void removeAnyEdge (Integer& v1, Integer& v2);
		//! updates self
		//! replaces v1, v2
		//! requires: g.edges /= {}
		//! ensures: g.vertices = #g.vertices and
		//!          {v1, v2} is in #g.edges and g.edges = #g.edges - {{v1, v2}}

	Integer numberOfVertices ();
		//! restores self
		//! ensures: numberOfVertices = |g.vertices|

	Integer numberOfEdges ();
		//! restores self
		//! ensures: numberOfEdges = |g.edges|

	Integer degree (Integer v);
		//! updates self
		//! restores v
		//! ensures: degree = |{v2: integer where ({v, v2} is in g.edges) (v2)}|

	Boolean isEdge (Integer v1, Integer v2);
		//! updates self
		//! restores v1
		//! replaces v2
		//! ensures: isEdge = {v1, v2} is in g.edges

	friend wostream& operator << (wostream& os, UnlabeledUndirectedGraph0& g);
		//! updates os
		//! restores g

private: // Representation
	class GraphTupleRecord {
	public:
		Integer v1;
		Integer v2;

		GraphTupleRecord() {}
		GraphTupleRecord(Integer v1, Integer v2)
		{
			self.v1 = v1;
			self.v2 = v2;
		} // GraphTupleRecord
		~GraphTupleRecord() {}

		void clear(void)
		{
			v1.clear();
			v2.clear();
		} // clear

		GraphTupleRecord& operator = (GraphTupleRecord& rhs)
		{
			self.v1 = rhs.v1;
			self.v2 = rhs.v2;
			return *this;
		} // operator =

		void transferFrom(GraphTupleRecord& source)
		{
			v1.transferFrom(source.v1);
			v2.transferFrom(source.v2);
		}

		Boolean areEqual(Integer v1, Integer v2)
		{
			return ((self.v1 == v1) && (self.v2 == v2)) || ((self.v1 == v2) && (self.v2 == v1));
		}

		Boolean isIncidentWithVertex(Integer v)
		{
			return (self.v1 == v) || (self.v2 == v);
		}

		Integer getOtherVertex(Integer incidentV)
			// requires: self.v1 = incidentV || self.v2 = incidentV
			// ensures: (incidentV = self.v1 && getOtherVertex = self.v2) ||
			//          (incidentV = self.v2 && getOtherVertex = self.v1)
		{
			if (self.v1 == incidentV) {
				return self.v2;
			}
			else {
				return self.v1;
			} // end if
		}

		friend wostream& operator <<(wostream& os, GraphTupleRecord& r)
		{
			os << L"(" << r.v1 << L"," << r.v1 << L")";
			return os;
		}
	};

	typedef ChainPosition1 <GraphTupleRecord> ChainPositionOfGraphTuple;

	ChainPositionOfGraphTuple chain;
	Integer vertexCount;
	Integer edgeCount;

private: // Local Operations

private: // Disallowed UnlabeledUndirectedGraph0 Operations
	UnlabeledUndirectedGraph0(const UnlabeledUndirectedGraph0& s);
	UnlabeledUndirectedGraph0* operator &(void) {return this;};
	const UnlabeledUndirectedGraph0* operator &(void) const {return this;};
};


//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------



//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

UnlabeledUndirectedGraph0::UnlabeledUndirectedGraph0()
{
	ChainPositionOfGraphTuple smartPosition;
	GraphTupleRecord label;

	smartPosition.labelNew(label);
	chain.transferFrom(smartPosition);
}	// UnlabeledUndirectedGraph0

//-----------------------------------------------------------------------


UnlabeledUndirectedGraph0::~UnlabeledUndirectedGraph0()
{
}	// ~UnlabeledUndirectedGraph0

//-----------------------------------------------------------------------


void UnlabeledUndirectedGraph0::clear(void)
{
	ChainPositionOfGraphTuple smartPosition;
	GraphTupleRecord label;

	chain.clear();
	smartPosition.labelNew(label);
	chain.transferFrom(smartPosition);
	vertexCount = 0;
	edgeCount = 0;
}	// clear

//-----------------------------------------------------------------------


void UnlabeledUndirectedGraph0::transferFrom(UnlabeledUndirectedGraph0& source)
{
	chain.transferFrom(source.chain);
	vertexCount.transferFrom(source.vertexCount);
	edgeCount.transferFrom(source.edgeCount);
} // transferFrom

//-----------------------------------------------------------------------


UnlabeledUndirectedGraph0& 
UnlabeledUndirectedGraph0::operator = (UnlabeledUndirectedGraph0& rhs)
{
	ChainPositionOfGraphTuple newPos, oldPos, current;
	GraphTupleRecord x;

	current.labelNew(x);
	chain = current;

	oldPos = rhs.chain;
	oldPos.applyTarget();
	while (!oldPos.isZero()) {
		x = oldPos.label();
		newPos.labelNew(x);
		current.swapWithTarget(newPos);
		current.applyTarget();
		oldPos.applyTarget();
	} // end while
	vertexCount = rhs.vertexCount;
	edgeCount = rhs.edgeCount;

	return *this;
} // operator =

//-----------------------------------------------------------------------


void UnlabeledUndirectedGraph0::setNumberOfVertices(Integer nv)
{
	vertexCount = nv;
} // setNumberOfVertices


void UnlabeledUndirectedGraph0::addEdge(Integer v1, Integer v2)
{
	GraphTupleRecord newTuple(v1, v2);
	ChainPositionOfGraphTuple newPosition;
	ChainPositionOfGraphTuple firstPosition;

	chain.swapWithTarget(firstPosition);

	newPosition.labelNew(newTuple);
	newPosition.swapWithTarget(firstPosition);
	chain.swapWithTarget(newPosition);

	edgeCount++;
}	// add

//-----------------------------------------------------------------------


void UnlabeledUndirectedGraph0::removeEdge(Integer v1, Integer v2)
{
	ChainPositionOfGraphTuple trailingPosition;
	ChainPositionOfGraphTuple currentPosition;
	GraphTupleRecord existingPair;

	trailingPosition = chain;
	currentPosition = trailingPosition;
	currentPosition.applyTarget();

	while (!currentPosition.label().areEqual(v1, v2)) {
		trailingPosition = currentPosition;
		currentPosition.applyTarget();
	}  // end while
	currentPosition.replaceLabel(existingPair);

	currentPosition.applyTarget();
	trailingPosition.swapWithTarget(currentPosition);

	edgeCount--;
}	// remove

//-----------------------------------------------------------------------

void UnlabeledUndirectedGraph0::removeAnyIncidentEdge(Integer v1, Integer& v2)
{
	ChainPositionOfGraphTuple trailingPosition;
	ChainPositionOfGraphTuple currentPosition;
	GraphTupleRecord existingPair;

	trailingPosition = chain;
	currentPosition = trailingPosition;
	currentPosition.applyTarget();

	while (!currentPosition.label().isIncidentWithVertex(v1)) {
		trailingPosition = currentPosition;
		currentPosition.applyTarget();
	}  // end while
	currentPosition.replaceLabel(existingPair);

	currentPosition.applyTarget();
	trailingPosition.swapWithTarget(currentPosition);
	v2 = existingPair.getOtherVertex(v1);

	edgeCount--;
}	// removeAnyIncidentEdge

//-----------------------------------------------------------------------


void UnlabeledUndirectedGraph0::removeAnyEdge(Integer& v1, Integer& v2)
{
	ChainPositionOfGraphTuple position;
	GraphTupleRecord existingPair;

	position = chain;
	position.applyTarget();

	position.replaceLabel(existingPair);
	position.applyTarget();
	chain.swapWithTarget(position);

	v1.transferFrom(existingPair.v1);
	v2.transferFrom(existingPair.v2);

	edgeCount--;
}	// removeAnyEdge

//-----------------------------------------------------------------------


Integer UnlabeledUndirectedGraph0::numberOfVertices(void)
{
	return vertexCount;
}	// numberOfVertices

//-----------------------------------------------------------------------

Integer UnlabeledUndirectedGraph0::numberOfEdges(void)
{
	return edgeCount;
}	// numberOfEdges

//-----------------------------------------------------------------------

Integer UnlabeledUndirectedGraph0::degree(Integer v)
{
	ChainPositionOfGraphTuple position;
	Integer degreeCount;

	position = chain;
	position.applyTarget();

	while (!position.isZero()) {
		if (position.label().isIncidentWithVertex(v)) {
			degreeCount++;
		}
		position.applyTarget();
	}	// end while

	return degreeCount;
} // degree

//-----------------------------------------------------------------------

Boolean UnlabeledUndirectedGraph0::isEdge(Integer v1, Integer v2) {
	ChainPositionOfGraphTuple position;
	Integer degreeCount;

	position = chain;
	position.applyTarget();

	while (!position.isZero() && !position.label().areEqual(v1, v2)) {
		position.applyTarget();
	}	// end while
	return !position.isZero();
} // isEdge

//-----------------------------------------------------------------------

wostream& operator<<(wostream& os, UnlabeledUndirectedGraph0& g)
{
	UnlabeledUndirectedGraph0 temp;

	os << L"({";
	for (int k = 1, z = g.numberOfVertices(), lastItem = z - 1; k <= z; k++) {
		os << k;		
		if (k <= lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L"},{";

	temp.setNumberOfVertices(g.numberOfVertices());
	while (g.numberOfEdges() > 0) {
		Integer v1, v2;

		g.removeAnyEdge(v1, v2);
		os << L"{" << ((v1 < v2) ? v1 : v2) << L"," << ((v1 < v2) ? v2 : v1) << L"}";
		if(g.numberOfEdges() > 0) {
			os << L",";
		} // end if
		temp.addEdge(v1, v2);
	}	// end for
	os << L"})";
	g.transferFrom(temp);

	return os;
} // operator<<


