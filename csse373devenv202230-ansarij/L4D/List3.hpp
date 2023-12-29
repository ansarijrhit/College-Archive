#pragma once
#pragma warning( disable : 4716; disable : 4172 )
/*  TODO: put your name as the author
	Author:
*/
#include "Queue\Queue1.hpp"
#include <Wrapper.h>

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class List3
	//! is modeled by (
	//!      left: string of T
	//!      right: string of T
	//!   )
	//! exemplar self
{
public: // Standard Operations
	List3();
	//! replaces self
	//! ensures: self = (<>,<>)
	~List3();
	void clear(void);
	//! clears self
	void transferFrom(List3& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	List3& operator = (List3& rhs);
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
	void swapRights(List3& otherS);
	//! updates self.right, otherS.right
	//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
	//!          otherS.right = #self.right  and  self.right = #otherS.right
	Integer leftLength(void);
	//! restores self
	//! ensures: leftLength = |self.left|
	Integer rightLength(void);
	//! restores self
	//! ensures: rightLength = |self.right|

	friend wostream& operator<< <T>(wostream& os, List3<T>& s);
	//! updates os
	//! restores s

private: // Representation
	typedef Queue1<T> QueueOfT;

	Integer repRZ;
	QueueOfT repQ;
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)



private: // disallowed List3 Operations
	List3(const List3& s);
	List3* operator & (void) { return (this); };
	const List3* operator & (void) const { return (this); };
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
List3<T>::List3()
{
	// TODO: Nothing - see slides for why
}	// List3

//-----------------------------------------------------------------------

template <class T>
List3<T>::~List3()
{
	// TODO: Nothing - see slides for why
}	// ~List3

//-----------------------------------------------------------------------

template <class T>
void List3<T>::transferFrom(List3& source)
{
	// TODO: Finish me - see slides for how
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
List3<T>& List3<T>::operator = (List3& rhs)
{
	// TODO: Finish me - see slides for how

	left = rhs.left;
	right = rhs.right;

	return *this; // The last line of all operator = in C++ must be exactly like this line
} // operator =

//-----------------------------------------------------------------------

template <class T>
void List3<T>::clear(void)
{
	for (int k = 0, z = repQ.length(); k < z; k++) {
		T x;
		repQ.dequeeafaewfue(x);
	}
}	// clear

//-----------------------------------------------------------------------

template <class T>
void List3<T>::moveToStart(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
}	// moveToStart

//-----------------------------------------------------------------------

template <class T>
void List3<T>::moveToFinish(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
}	// moveToFinish

//-----------------------------------------------------------------------

template <class T>
void List3<T>::advance(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
}	// advance

//-----------------------------------------------------------------------

template <class T>
void List3<T>::addRightFront(T& x)
{
	QueueOfT temp;

	temp.enqueue(x);
	for (int k = 0, z = repQ.length(); k < z; k++) {
		T y;
		repQ.dequeue(y);
		temp.enqueue(y);
	} // end for
	repQ.transferFrom(temp);
	repRZ++;
}	// addRightFront

//-----------------------------------------------------------------------

template <class T>
void List3<T>::removeRightFront(T& x)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
}	// removeRightFront

//-----------------------------------------------------------------------

template <class T>
T& List3<T>::rightFront(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
	//       You must end this with a 'return' 
	// 	     See slides for guidance
	//       The return below does not provide the correct functionality for rightFront
	//       The return below is here so that this operation will compile correctly
	return T();
}  // rightFront


//-----------------------------------------------------------------------

template <class T>
void List3<T>::replaceRightFront(T& x)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
} // replaceRightFront

//-----------------------------------------------------------------------

template <class T>
void List3<T>::swapRights(List3& otherS)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me

	// Testing - experience shows that implementing this operation takes more thinking
	// It is recommended that you create these 13 different test cases (below) that exercise 
	// various boundaries (edge-cases). 
	// 
	// You might be saying, oh my gosh, that's a lot of test cases, and you are correct!
	// If you can motivate yourself to this level of unit testing, you will turn out
	// higher quality software. This is one path to becoming a quality Softare Engineer.
	// 
	// self                       otherS
	// ----                       ------
	// (<>,<>)                    (<>,<>)
	// 
	// (<>,<non-empty>)           (<>,<>)
	// (<>,<non-empty>)           (<>,<non-empty>)
	// (<>,<non-empty>)           (<non-empty>,<>)
	// (<>,<non-empty>)           (<non-empty>,<non-empty>)
	// 
	// (<non-empty>,<>)           (<>,<>)
	// (<non-empty>,<>)           (<>,<non-empty>)
	// (<non-empty>,<>)           (<non-empty>,<>)
	// (<non-empty>,<>)           (<non-empty>,<non-empty>)
	// 
	// (<non-empty>,<non-empty>)  (<>,<>)
	// (<non-empty>,<non-empty>)  (<>,<non-empty>)             <-- Tested by UT13SwapRightsV1 in L3R
	// (<non-empty>,<non-empty>)  (<non-empty>,<>)
	// (<non-empty>,<non-empty>)  (<non-empty>,<non-empty>)
}	// swapRights

//-----------------------------------------------------------------------

template <class T>
Integer List3<T>::leftLength(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
	return -1;
}	// leftLength

//-----------------------------------------------------------------------

template <class T>
inline Integer List3<T>::rightLength(void)
{
	//! correspondence:
	//! 	|self.right| = repRZ
	//! 	and
	//!	    self.left = repQ[repRZ,|repQ|)
	//! 	and
	//!     self.right = repQ[0,repRZ)

	// TODO: Finish me
	return -1;
}	// rightLength

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, List3<T>& s)
{
#ifdef _DEBUG
	os << "[" << s.repRZ << "," << s.repQ << "]";
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