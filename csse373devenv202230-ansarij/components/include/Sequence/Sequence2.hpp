#pragma once
#pragma warning( disable : 4716; disable : 4172 )
/*  
	Author: Jordan Ansari
*/

#include "TwoWayList\TwoWayList1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Sequence2
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Sequence2 ();
		//! replaces self
		//! ensures: self = <>
	~Sequence2 ();
	void clear (void);
		//! clears self
	void transferFrom (Sequence2& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Sequence2& operator = (Sequence2& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Sequence2 Specific Operations
	void add (Integer pos, T& x);
		//! updates self
		//! restores pos
		//! clears x
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
	void remove (Integer pos, T& x);
		//! updates self
		//! restores pos
		//! replaces x
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1) and
		//!          self = #self[0, pos) * #self[pos+1, |#self|)
	void replaceEntry (Integer pos, T& x);
		//! updates self, x
		//! restores pos
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1)  and
		//!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
	T& entry (Integer pos);
		//! restores self, pos
		//! requires: 0 <= pos < |self|
		//! ensures: <entry> = self[pos, pos+1)
	void append (Sequence2& sToAppend);
		//! updates self
		//! clears sToAppend
		//! ensures: self = #self * sToAppend
	void split (Integer pos, Sequence2& receivingS);
		//! updates self
		//! restores pos
		//! replaces receivingS
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
	Integer length (void);
		//! restores self
		//! ensures: length = |self|

	friend wostream& operator<< <T>(wostream& os, Sequence2& s);
		//! updates os
		//! restores q

private: // Representation
	typedef TwoWayList1<T> QueueOfT;

	QueueOfT repQ;


private: // Local Operations
	void placementModification(int pos);

private: // Disallowed Sequence2 Operations
	Sequence2 (const Sequence2& s);
	Sequence2* operator & (void) {return this;};
	const Sequence2* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::placementModification(int pos)
{
	repQ.moveToStart();
	for (int i = 0; i < pos; i++) {
		repQ.advance();
	}
}	// placementModification
//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Sequence2<T>::Sequence2 ()
{
}	// Sequence2

//-----------------------------------------------------------------------

template <class T>
Sequence2<T>::~Sequence2 ()
{
}	// ~Sequence2

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::clear(void)
{
	repQ.moveToStart();
	for (int k = 0, z = repQ.rightLength(); k < z; k++) {
		T x;
		repQ.removeRightFront(x);
	}
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::transferFrom(Sequence2& source)
{
	repQ.moveToStart();
	source.repQ.moveToStart();

	for (int k = 0, z = length(); k < z; k++) {
		T x;
		repQ.removeRightFront(x);
	}

	repQ.swapRights(source.repQ);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Sequence2<T>& Sequence2<T>::operator = (Sequence2& rhs)
{
	repQ = rhs.repQ;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::add (Integer pos, T& x)
{
	placementModification(pos);
	repQ.addRightFront(x);
}	// add

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::remove (Integer pos, T& x)
{
	placementModification(pos);
	repQ.removeRightFront(x);
}	// remove

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::replaceEntry (Integer pos, T& x)
{
	placementModification(pos);
	repQ.replaceRightFront(x);
}	// replaceEntry

//-----------------------------------------------------------------------

template <class T>
T& Sequence2<T>::entry (Integer pos)
{
	placementModification(pos);
	return repQ.rightFront();
}	// entry

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::append (Sequence2& sToAppend)
{
	repQ.moveToFinish();
	sToAppend.repQ.moveToStart();
	repQ.swapRights(sToAppend.repQ);
}	// append

//-----------------------------------------------------------------------

template <class T>
void Sequence2<T>::split (Integer pos, Sequence2& receivingS)
{
	placementModification(pos);
	receivingS.repQ.moveToStart();
	for (int k = 0, z = receivingS.repQ.rightLength(); k < z; k++) {
		T x;
		receivingS.repQ.removeRightFront(x);
	}
	repQ.swapRights(receivingS.repQ);
}	// split

//-----------------------------------------------------------------------

template <class T>
Integer Sequence2<T>::length (void)
{
	return repQ.leftLength() + repQ.rightLength();
}	// length

//-----------------------------------------------------------------------


// *********************************
// Reminder:
//
// operator << for Sequence2 calls Sequence's length and entry operations
// It will not function correctly until both of those operations are 
// implemented and defect free
//
// *********************************

template <class T>
wostream& operator<<(wostream& os, Sequence2<T>& s)
{

#ifdef NDEBUG
	os << L"<";
	for (int p = 0, z = s.length(), lastItem = z - 1; p < z; p++) {
		T x;

		os << s.entry(p);
		if (p < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";
	return os;
#else
	os << "[" << "If you test in Debug configuration, you must display Sequence2's internal rep, i.e., its private data members" "]";
#endif
} // operator<<