//-------------------------------------------------------------------
// file: driver.cpp
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// obtain classes and operations from Include files
//-------------------------------------------------------------------

#include "wrapper.h"
#include "Sequence/Sequence4.hpp"
#include "StaticArray/StaticArray1.hpp"

// First create a named instance of Sequence that holds Text objects
typedef Sequence4 <Text> TextSequence;

// No Magic Numbers allowed
// So use enum to give names to the array lower and upper bounds, and size
enum { lowerBound = 0, upperBound = 4, arraySize = 5 };
// Create named instance called ArrayOfSequences, which is indexed from 0..4
typedef StaticArray1 <TextSequence, lowerBound, upperBound> ArrayOfSequences;


//-------------------------------------------------------------------
// program operations
//-------------------------------------------------------------------

void displayMenu (void)
{
	wcout << endl;
	wcout << "---------------------------------------------" << endl;
	wcout << endl;
	wcout << "     Command -  Result" << endl;
	wcout << "        g - toggle display menu" << endl;
	wcout << "        e - add" << endl;
	wcout << "        d - remove" << endl;
	wcout << "        r - replace entry" << endl;
	wcout << "        f - access entry" << endl;
	wcout << "        x - transfer from" << endl;
	wcout << "        a - append" << endl;
	wcout << "        s - split" << endl;
	wcout << "        z - length" << endl;
	wcout << "        = - copy" << endl;
	wcout << "        p - display" << endl;
	wcout << "        c - clear" << endl;
	wcout << "        q - quit program" << endl;
	wcout << endl;
	wcout << "---------------------------------------------" << endl;
	wcout << endl << "        command:";
}	// showMenu

//-------------------------------------------------------------------

void getCommand (Character& command)
{
	wcin >> command;
	wcout << endl;
}	// getCommand

//-------------------------------------------------------------------

Integer getIndex (ArrayOfSequences& aS)
{
	Integer index;

	Integer lowerB, upperB;
	aS.getBounds(lowerB, upperB);

	do {
		wcout << "which Sequence? " << lowerB << " .. " << upperB << ":";
		wcin >> index;
	} while ((index < lowerB) || (index > upperB));
	wcout << endl;
	return (index);
}	// getIndex

//-------------------------------------------------------------------

Integer getPosition (Integer maxAllowable)
{
	Integer position;

	do {
		wcout << "which position? 0 .. " << maxAllowable << ":";

		wcin >> position;
		wcout << endl;
	} while ((position < 0) || (position > maxAllowable));
	return (position);
}	// getPosition

//-------------------------------------------------------------------

void getText (Text& s)
{
	wcout << "Enter text string:";
	wcin >> s;
}	// getText

//-------------------------------------------------------------------

void doAdd(ArrayOfSequences& aS)
{
	Integer i, p;
	Text x;

	wcout << "Add to ";
	i = getIndex(aS);
	p = getPosition(aS[i].length());
	getText(x);
	aS[i].add(p, x);

	wcout << endl << "s[" << i << "].add(" << p << ", x); executed." << endl;
	wcout << "x = " << x << endl;
}	// doAdd

//-------------------------------------------------------------------

void doRemove(ArrayOfSequences& aS)
{
	Integer i, p, size;
	Text x;

	wcout << "Remove from ";

	i = getIndex(aS);
	size = aS[i].length();
	if (size > 0) {
		p = getPosition(size - 1);
		aS[i].remove(p, x);
	} // end if

	if (size > 0) {
		wcout << endl << "s[" << i << "].remove(" << p << ", x); executed." << endl;
		wcout << "x = " << x << endl;
	} else {
		wcout << "Error: |s[" << i << "]| = 0 - cannot remove from an empty sequence." << endl;
	} // end if
}	// doRemove

//-------------------------------------------------------------------

void doReplaceEntry (ArrayOfSequences& aS)
{
	Integer i, p, size;
	Text x;

	wcout << "Replace entry from ";

	i = getIndex(aS);
	size = aS[i].length();
	if (size > 0) {
		p = getPosition(size - 1);
		getText(x);
		aS[i].replaceEntry(p, x);
	} // end if

	if (size > 0) {
		wcout << endl << "s[" << i << "].replaceEntry(" << p << ", x); executed." << endl;
		wcout << "x = " << x << endl;
	} else {
		wcout << "Error: |s[" << i << "]| = 0 - cannot replace an entry in an empty sequence." << endl;
	} // end if
}	// doReplaceEntry

//-------------------------------------------------------------------

void doAppend (ArrayOfSequences& aS)
{
	Integer i, i2;

	wcout << "Append ";
	i = getIndex(aS);
	wcout << " to ";
	i2 = getIndex(aS);
	aS[i2].append(aS[i]);

	wcout << "s[" << i2 << "].append(s[" << i << "]); executed." << endl;
}	// doAppend

//-------------------------------------------------------------------

void doSplit (ArrayOfSequences& aS)
{
	Integer i, i2, p;
	Text x;

	wcout << "Split ";
	i = getIndex(aS);
	wcout << " to ";
	i2 = getIndex(aS);
	p = getPosition(aS[i].length());
	aS[i].split(p, aS[i2]);

	wcout << "s[" << i << "].split(" << p << ", s[" << i2 << "); executed." << endl;
}	// doSplit

//-------------------------------------------------------------------

void doEntry (ArrayOfSequences& aS)
{
	Integer i, p, size;

	wcout << "Access entry in ";
	i = getIndex(aS);
	
	size = aS[i].length();
	if (size > 0) {
		p = getPosition(size - 1);
		wcout << "s[" << i << "].entry(" << p << ") = " << aS[i].entry(p) << endl;
	}
	else if (size <= 0) {
		wcout << "Error: |s[" << i << "]| = 0 - cannot access an empty sequence." << endl;
	} // end if
}	// doEntry

//-------------------------------------------------------------------

void doLength (ArrayOfSequences& aS)
{
	Integer i, z;

	wcout << "Length of ";
	i = getIndex(aS);
	z = aS[i].length();

	wcout << "|s[" << i << "]| = " << z << endl;
}	// doLength

//-------------------------------------------------------------------

void doClear (ArrayOfSequences& aS)
{
	Integer i;

	wcout << "Clear ";
	i = getIndex(aS);
	aS[i].clear();

	wcout << "s[" << i << "].clear(); executed." << endl;
}	// doClear

//-------------------------------------------------------------------

void doTransferFrom (ArrayOfSequences& aS)
{
	Integer i, i2;

	do {
		wcout << "Transfer from ";
		i = getIndex(aS);
		wcout << endl << ".. to ";
		i2 = getIndex(aS);
		if (i == i2) {
			wcout << "Error: Cannot transfer a sequence to itself." << endl;
		} // end if
	} while (i == i2);

	aS[i2].transferFrom(aS[i]);
	wcout << endl << "aS[" << i2 << "].transferFrom(aS[" << i << "]); executed." << endl;
}	// doTransferFrom

//-------------------------------------------------------------------

void doCopy (ArrayOfSequences& aS)
{
	Integer i, i2;

	do {
		wcout << "Copy from ";
		i = getIndex(aS);
		wcout << endl << ".. to ";
		i2 = getIndex(aS);
		if (i == i2) {
			wcout << "Error: Cannot copy a sequence to itself." << endl;
		} // end if
	} while (i == i2);

	aS[i2] = aS[i];
	wcout << endl << "aS[" << i2 << "] = aS[" << i << "]; executed." << endl;
}	// doCopy

//-------------------------------------------------------------------

void doDisplay (ArrayOfSequences& aS)
{
	Integer i;

	wcout << "Display ";
	i = getIndex(aS);
	wcout << aS[i] << endl;
}	// doDisplay

//-------------------------------------------------------------------

void dispatchCommand (
		Character command,
		Boolean& showMenu,
		ArrayOfSequences& aS
	)
{
	switch (command) {
		case 'g':	// toggle display Menu
			showMenu = !showMenu;
			break;
		case 'e':
			doAdd(aS);
			break;
		case 'd':
			doRemove(aS);
			break;
		case 'r':
			doReplaceEntry(aS);
			break;
		case 'a':
			doAppend(aS);
			break;
		case 's':
			doSplit(aS);
			break;
		case 'f':
			doEntry(aS);
			break;
		case 'z':
			doLength(aS);
			break;
		case 'x':
			doTransferFrom(aS);
			break;
		case '=':
			doCopy(aS);
			break;
		case 'c':
			doClear(aS);
			break;
		case 'p':
			doDisplay(aS);
			break;
		case 'q':
			wcout << "Quit Command Interpreter" << endl;
			break;
		default:
			wcout << "Unknown command: " << command << endl;
			wcout << "Please reenter your command" << endl;
			break;
	}	// end switch
}	// dispatchCommand

//-------------------------------------------------------------------

void commandController (
		ArrayOfSequences& aS,
		Boolean& showMenu
	)
{
	Character command;

	do {
		if (showMenu) {
			displayMenu();
		}	// end if
		getCommand(command);
		dispatchCommand(command, showMenu, aS);
	} while (command != 'q' && command != 'Q');
} // commandController

//-------------------------------------------------------------------
// main executable body
//-------------------------------------------------------------------


int main(int argc, char* argv[])
{
	Boolean showMenu = (argc == 1);
	ArrayOfSequences aS1;

	commandController(aS1, showMenu);

	wcout << "end program" << endl;
	return 0;
} // end main