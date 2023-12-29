#pragma once
#pragma warning( disable : 4716; disable : 4172)
/*
	Author: put your name here
*/
#include "Queue\Queue1.hpp"

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class List2
	//! is modeled by (
	//!      left: string of T
	//!      right: string of T
	//!   )
	//! exemplar self
{
public: // Standard Operations
	List2();
	//! replaces self
	//! ensures: self = (<>,<>)
	~List2();

	void clear(void);
	//! clears self
	void transferFrom(List2& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	List2& operator = (List2& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// List2 Specific Operations
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
	void swapRights(List2& otherS);
	//! updates self.right, otherS.right
	//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
	//!          otherS.right = #self.right  and  self.right = #otherS.right
	Integer leftLength(void);
	//! restores self
	//! ensures: leftLength = |self.left|
	Integer rightLength(void);
	//! restores self
	//! ensures: rightLength = |self.right|

	friend wostream& operator<< <T>(wostream& os, List2<T>& s);
	//! updates os
	//! restores s


private: // Representation
	typedef Queue1<T> QueueOfT;

	QueueOfT leftQ;
	QueueOfT rightQ;
	//! correspondence:
	//!	self = leftQ * rightQ


private: // disallowed List2 Operations
	List2(const List2& s);
	List2* operator & (void) { return (this); };
	const List2* operator & (void) const { return (this); };

private:
	void leftToRight(void);
private:
	void rightToLeft(void);
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

template <class T>
void List2<T>::leftToRight(void) {
	for (int k = 0, z = leftQ.length(); k < z; k++) {
		T x;
		leftQ.dequeue(x);
		rightQ.enqueue(x);
	}
}

template <class T>
void List2<T>::rightToLeft(void) {
	for (int k = 0, z = rightQ.length(); k < z; k++) {
		T x;
		rightQ.dequeue(x);
		leftQ.enqueue(x);
	}
}

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
List2<T>::List2()
{
	// TODO: Nothing - see slides for why
}	// List2

//-----------------------------------------------------------------------

template <class T>
List2<T>::~List2()
{
	// TODO: Nothing - see slides for why
}	// ~List2

//-----------------------------------------------------------------------

template <class T>
void List2<T>::transferFrom(List2& source)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	

	for (int k = 0, z = leftQ.length(); k < z; k++) {
		T x;
		leftQ.dequeue(x);
	} // end for
	for (int k = 0, z = rightQ.length(); k < z; k++) {
		T x;
		rightQ.dequeue(x);
	} // end for
	leftQ.transferFrom(source.leftQ);
	rightQ.transferFrom(source.rightQ);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
List2<T>& List2<T>::operator = (List2& rhs)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	self.leftQ = rhs.leftQ;
	self.rightQ = rhs.rightQ;
	return *this; // The last line of all operator = in C++ must be exactly like this line
} // operator =

//-----------------------------------------------------------------------

template <class T>
void List2<T>::clear(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	for (int k = 0, z = leftQ.length(); k < z; k++) {
		T x;
		leftQ.dequeue(x);
	}
	for (int k = 0, z = rightQ.length(); k < z; k++) {
		T x;
		rightQ.dequeue(x);
	}
}	// clear

//-----------------------------------------------------------------------

template <class T>
void List2<T>::moveToStart(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	QueueOfT tempQ;
	tempQ.transferFrom(rightQ);
	rightQ.transferFrom(leftQ);
	for (int k = 0, z = tempQ.length(); k < z; k++) {
		T x;
		tempQ.dequeue(x);
		rightQ.enqueue(x);
	}
}	// moveToStart

//-----------------------------------------------------------------------

template <class T>
void List2<T>::moveToFinish(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	rightToLeft();
}	// moveToFinish

//-----------------------------------------------------------------------

template <class T>
void List2<T>::advance(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	T x;
	self.rightQ.dequeue(x);
	self.leftQ.enqueue(x);

}	// advance

//-----------------------------------------------------------------------

template <class T>
void List2<T>::addRightFront(T& x)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold


	// TODO: Nothing - use this to help understand the correspondence 
	//                 and how to do some of the other operations

	QueueOfT tempQ;

	tempQ.enqueue(x);
	for (int k = 0, z = rightQ.length(); k < z; k++) {
		T x;
		rightQ.dequeue(x);
		tempQ.enqueue(x);
	} // end for
	rightQ.transferFrom(tempQ);
}	// addRightFront

//-----------------------------------------------------------------------

template <class T>
void List2<T>::removeRightFront(T& x)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	rightQ.dequeue(x);
}	// removeRightFront

//-----------------------------------------------------------------------

template <class T>
T& List2<T>::rightFront(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	//       You must end this with a 'return' 
	//       The return below does not provide the correct functionality for rightFront
	//       The return below is here so that this operation will compile correctly
	return rightQ.front();
}  // rightFront


//-----------------------------------------------------------------------

template <class T>
void List2<T>::replaceRightFront(T& x)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	QueueOfT tempQ;
	tempQ.enqueue(x);
	rightQ.dequeue(x);
	for (int k = 0, z = rightQ.length(); k < z; k++) {
		T temp;
		rightQ.dequeue(temp);
		tempQ.enqueue(temp);
	} // end for
	rightQ.transferFrom(tempQ);
} // replaceRightFront
//-----------------------------------------------------------------------

template <class T>
void List2<T>::swapRights(List2& otherS)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	 
	QueueOfT tempQ;

	for (int k = 0, z = otherS.rightQ.length(); k < z; k++) {
		T x;
		otherS.rightQ.dequeue(x);
		tempQ.enqueue(x);
	} // end for
	otherS.rightQ.transferFrom(rightQ);
	rightQ.transferFrom(tempQ);
}	// swapRights

//-----------------------------------------------------------------------

template <class T>
inline Integer List2<T>::leftLength(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	//       You must end this with a 'return' 
	//       The return below does not provide the correct functionality for leftLength
	//       The return below is here so that this operation will compile correctly
	return leftQ.length();
}	// leftLength

//-----------------------------------------------------------------------

template <class T>
inline Integer List2<T>::rightLength(void)
{
	//! correspondence:
	//!	self = leftQ * rightQ
	//  You get to assume it holds at the beginning of the call to this operation
	//  You must gurantee it holds at the end of the call to this operation
	//  During the execution of this operation it does not have to hold

	
	//       You must end this with a 'return' 
	//       The return below does not provide the correct functionality for leftLength
	//       The return below is here so that this operation will compile correctly
	return rightQ.length();
}	// rightLength

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, List2<T>& s)
{
#ifdef _DEBUG
	os << "[" << s.leftQ << "," << s.rightQ << "]";
#else
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
#endif

	return os;
}