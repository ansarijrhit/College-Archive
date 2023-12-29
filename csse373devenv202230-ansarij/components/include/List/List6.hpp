#pragma once
#pragma warning( disable : 4716; disable : 4172 )
/*
	Author: Jordan Ansari
*/
#include "PreemptableQueue\PreemptableQueue1.hpp"

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class List6
	//! is modeled by (
	//!      left: string of T
	//!      right: string of T
	//!   )
	//! exemplar self
{
public: // Standard Operations
	List6();
	//! replaces self
	//! ensures: self = (<>,<>)
	~List6();
	void clear(void);
	//! clears self
	void transferFrom(List6& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	List6& operator = (List6& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// List3 Specific Operations
	void moveToStart(void);
	//! updates self
	//! ensures: self.left = <>  and  self.right = #self.left * #self.right
	void moveToFinish(void);
	//! updates self
	//! ensures: self.right = <>  and  self.left = #self.left * #self.right
	void advance(void);
	//! updates self
	//! requires: self.right /= <>
	//! ensures: self.left * self.right = #self.left * #self.right  and
	//!          |self.left| = |#self.left| + 1
	void addRightFront(T& x);
	//! updates self.right
	//! clears x
	//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
	void removeRightFront(T& x);
	//! updates self.right
	//! replaces x
	//! requires: self.right /= <>
	//! ensures: self.left = #self.left  and
	//!          <x> is prefix of #self.right  and 
	//!          self.right = #self.right[1,|#self.right|)
	T& rightFront(void);
	//! restores self
	//! requires: self.right /= <>
	//! ensures: <rightFront> is prefix of self.right
	void replaceRightFront(T& x);
	//! updates self.right, x
	//! requires: self.right /= <>
	//! ensures: self.left = #self.left  and
	//!          <x> is prefix of #self.right  and
	//!          self.right = <#x> * #self.right[1, |#self.right|)
	void swapRights(List6& otherS);
	//! updates self.right, otherS.right
	//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
	//!          otherS.right = #self.right  and  self.right = #otherS.right
	Integer leftLength(void);
	//! restores self
	//! ensures: leftLength = |self.left|
	Integer rightLength(void);
	//! restores self
	//! ensures: rightLength = |self.right|

	friend wostream& operator<< <T>(wostream& os, List6<T>& s);
	//! updates os
	//! restores s

private: // Representation
	typedef PreemptableQueue1<T> PQueueOfT;

	PQueueOfT qL;
	PQueueOfT qR;
	//! correspondence:
	//! self = (rev(qL),qR)


private: // disallowed List3 Operations
	List6 (const List6& s);
	List6* operator & (void) {return (this);};
	const List6* operator & (void) const {return (this);};
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// private Operations
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
List6<T>::List6 ()
{
}	// List6

//-----------------------------------------------------------------------

template <class T>
List6<T>::~List6 ()
{
}	// ~List6

//-----------------------------------------------------------------------

template <class T>
void List6<T>::transferFrom(List6& source)
{
	for (int k = 0, z = qL.length(); k < z; k++) {
		T x;
		qL.dequeue(x);
	}
	for (int k = 0, z = qR.length(); k < z; k++) {
		T x;
		qR.dequeue(x);
	}
	for (int k = 0, z = source.qL.length(); k < z; k++) {
		T x;
		source.qL.dequeue(x);
		qL.enqueue(x);
	}
	for (int k = 0, z = source.qR.length(); k < z; k++) {
		T x;
		source.qR.dequeue(x);
		qR.enqueue(x);
	}
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
List6<T>& List6<T>::operator = (List6& rhs)
{
	qL = rhs.qL;
	qR = rhs.qR;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void List6<T>::clear (void)
{
	for (int k = 0, z = qL.length(); k < z; k++) {
		T x;
		qL.dequeue(x);
	}
	for (int k = 0, z = qR.length(); k < z; k++) {
		T x;
		qR.dequeue(x);
	}
}	// clear

//-----------------------------------------------------------------------

template <class T>
void List6<T>::moveToStart (void)
{
	for (int k = 0, z = qL.length(); k < z; k++) {
		T x;
		qL.dequeue(x);
		qR.inject(x);
	}
}	// moveToStart

//-----------------------------------------------------------------------

template <class T>
void List6<T>::moveToFinish (void)
{
	for (int k = 0, z = qR.length(); k < z; k++) {
		T x;
		qR.dequeue(x);
		qL.inject(x);
	}
}	// moveToFinish

//-----------------------------------------------------------------------

template <class T>
void List6<T>::advance (void)
{
	T x;
	qR.dequeue(x);
	qL.inject(x);
}	// advance

//-----------------------------------------------------------------------

template <class T>
void List6<T>::addRightFront (T& x)
{
	qR.inject(x);
}	// addRightFront

//-----------------------------------------------------------------------

template <class T>
void List6<T>::removeRightFront (T& x)
{
	qR.dequeue(x);
}	// removeRightFront

//-----------------------------------------------------------------------

template <class T>
T& List6<T>::rightFront(void)
{
	return qR.front();  // A return is required, this one is incorrect, here only to avoid compiler error
}  // rightFront


//-----------------------------------------------------------------------

template <class T>
void List6<T>::replaceRightFront (T& x)
{
	qR.replaceFront(x);
} // replaceRightFront

//-----------------------------------------------------------------------

template <class T>
void List6<T>::swapRights (List6& s)
{
	PQueueOfT temp;
	for (int k = 0, z = qR.length(); k < z; k++) {
		T x;
		qR.dequeue(x);
		temp.enqueue(x);
	}
	qR.transferFrom(s.qR);
	s.qR.transferFrom(temp);
}	// swapRights

//-----------------------------------------------------------------------

template <class T>
Integer List6<T>::leftLength (void)
{
	return qL.length();
}	// leftLength

//-----------------------------------------------------------------------

template <class T>
inline Integer List6<T>::rightLength (void)
{
	return qR.length();
}	// rightLength

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, List6<T>& s)
{
#ifdef NDEBUG
	os << L"(<";
	int lengthOfLeft = s.leftLength();

	s.moveToStart();
	for (int k = 0, lastItem = lengthOfLeft - 1; k < lengthOfLeft; k++) {
		os << s.rightFront();
		s.advance();
		if (k < lastItem) {
			os << L",";
		} // end if
	}
	os << L">,<";

	int lengthOfRight = s.rightLength();
	for (int k = 0, lastItem = lengthOfRight - 1; k < lengthOfRight; k++) {
		os << s.rightFront();
		s.advance();
		if (k < lastItem) {
			os << L",";
		} // end if
	}
	os << L">)";

	// reset fence to original location
	s.moveToStart();
	for (int k = 0; k < lengthOfLeft; k++) {
		s.advance();
	}

#else
	os << "[" << s.qL << "," << s.qR << "]";
#endif

	return os;
}