#pragma once

//
// realization of Sequence Template by layering on Queue
//

#include "Queue\Queue1.hpp"

template <class T>
class Sequence4
	//! is modeled by string(T)
	//!   exemplar self
{
public: // standard Operations
	Sequence4 ();
		//! alters self
		//! ensures: self = < >
	~Sequence4 ();
	void clear (void);
		//! alters self
		//! ensures: self = < >
	void transferFrom(Sequence4& source);
		//! alters self, source
		//! ensures self = #source  and  source = < >
	Sequence4& operator = (Sequence4& rhs);
		//! alters self
		//! preserves rhs
		//! ensures: self = rhs

	// Sequence4 Specific Operations
	void add (Integer pos, T& x);
		//! alters self
		//! preserves pos
		//! consumes x
		//! requires: 0 <= pos <= |self|
		//!  ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
	void remove (Integer pos, T& x);
		//! alters self
		//! preserves pos
		//! produces x
		//! requires: 0 <= pos < |self|
		//!  ensures: self = #self[0, pos) * #self[pos+1, |#self|)  and
		//!           <x> = #self[pos, pos+1)
	void replaceEntry (Integer pos, T& x);
		//! alters self, x
		//! preserves pos
		//! requires:  0 <= pos < |self|
		//!  ensures: <x> = #self[pos, pos+1)  and
		//!           self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
	T& entry (Integer pos);
		//! preserves self
		//! preserves pos
		//! requires:  0 <= pos < |self|
		//!  ensures: <entry> = self[pos, pos+1)
	void append (Sequence4& sToAppend);
		//! alters self
		//! consumes sToAppend
		//! ensures:    self = #self  *  sToAppend
	void split (Integer pos, Sequence4& receivingS);
		//! alters self
		//! preserves pos
		//! produces receivingS
		//! requires:  0 <= pos <= |self|
		//!  ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
	Integer length (void);
		//! preserves self
		//! ensures: length = |self|

	friend wostream & operator<< <T>(wostream &os, Sequence4& s);
	//! alters os
	//! preserves q


private: // representation

	typedef Queue1 <T> QueueOfT;

	QueueOfT qBefore;
	QueueOfT qAfter;

		//! corresponence
		//!    self = qBefore * qAfter

private: // local operations
	void moveElements(QueueOfT& toQ, QueueOfT& fromQ, Integer count);

private: // disallowed Sequence4 Operations
	Sequence4(const Sequence4& s);
	Sequence4* operator &(void) {return (this);};
	const Sequence4* operator & (void) const {return(this);};
};


//-----------------------------------------------------------------------
// local Operations
//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::moveElements(QueueOfT& toQ, QueueOfT& fromQ, Integer count)
	//! alters toQ, fromQ
	//! preserves count
	//! requires:  0 <= count <= |fromQ|
	//!  ensures: toQ = #toQ[0, |toQ|) * #fromQ[0, count) and fromQ = #fromQ[count, |fromQ|)
{
	for (int i = 0; i < count; i++) {
		T x;
		fromQ.dequeue(x);
		toQ.enqueue(x);
	} // end for
}	// rotateElements

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
Sequence4<T>::Sequence4()
{
}	// Sequence4

//-----------------------------------------------------------------------

template <class T>
Sequence4<T>::~Sequence4()
{
}	// ~Sequence4

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::transferFrom(Sequence4& source)
{
	qBefore.transferFrom(source.qBefore);
	qAfter.transferFrom(source.qAfter);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Sequence4<T>& Sequence4<T>::operator = (Sequence4& rhs)
{
	qBefore = rhs.qBefore;
	qAfter = rhs.qAfter;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::clear(void)
{
	qBefore.clear();
	qAfter.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::add(Integer position, T& x)
{
	moveElements(qBefore, qAfter, qAfter.length());
	moveElements(qAfter, qBefore, position);
	qAfter.enqueue(x);
	moveElements(qAfter, qBefore, qBefore.length());
}	// add

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::remove(Integer position, T& x)
{
	moveElements(qBefore, qAfter, qAfter.length());
	moveElements(qAfter, qBefore, position);
	qBefore.dequeue(x);
	moveElements(qAfter, qBefore, qBefore.length());
}	// remove

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::replaceEntry(Integer position, T& x)
{
	moveElements(qBefore, qAfter, qAfter.length());
	moveElements(qAfter, qBefore, position);
	qAfter.enqueue(x);
	qBefore.dequeue(x);
	moveElements(qAfter, qBefore, qBefore.length());
}	// replaceEntry

//-----------------------------------------------------------------------

template <class T>
T& Sequence4<T>::entry(Integer position)
{
	moveElements(qBefore, qAfter, qAfter.length());
	qAfter.transferFrom(qBefore);
	moveElements(qBefore, qAfter, position);
	return qAfter.front();
}	// entry

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::append(Sequence4& otherS)
{
	moveElements(qBefore, qAfter, qAfter.length());
	moveElements(otherS.qBefore, otherS.qAfter, otherS.qAfter.length());
	moveElements(qBefore, otherS.qBefore, otherS.qBefore.length());
}	// append

//-----------------------------------------------------------------------

template <class T>
void Sequence4<T>::split(Integer position,	Sequence4& receivingS)
{
	receivingS.qBefore.clear();
	receivingS.qAfter.clear();
	moveElements(qBefore, qAfter, qAfter.length());
	qAfter.transferFrom(qBefore);
	moveElements(qBefore, qAfter, position);
	moveElements(receivingS.qAfter, qAfter, qAfter.length());
}	// split

//-----------------------------------------------------------------------

template <class T>
Integer Sequence4<T>::length(void)
{
	return qBefore.length() + qAfter.length();
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream & operator<<(wostream &os, Sequence4<T>& s)
{
	os << L"<";
	for (int p = 0, z = s.length(), lastItem = z - 1; p < z; p++) {
		T x;

		os << s.entry(p);
		if (p < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";

	return (os);
} // operator<<

