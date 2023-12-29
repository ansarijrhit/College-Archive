#include "Wrapper.h"
#include "UnlabeledUndirectedGraph.h"
#include "Queue/Queue0.hpp"
#include "Set/Set1.hpp"
#include "CeramicArray/CeramicArray1.hpp"


// -------------------------------------
// Recommendation: 
// Always work out as many defects as you can on small data sets
// A data set where you can by hand determine most if not all the solutions
// Do this instead of trying to work out defects on large data sets
// If a client gives you a large data set, then go about creating a smaller version
// -------------------------------------


// -------------------------------------
// Here is a small data set 
// -------------------------------------
//static Integer searchWordLength = 4;
//static Integer numVertices = 4;
//static Integer numEdges = 6;
//static Text vertexLabels[] = { L"X", L"t", L"o", L"u", L"r" };
//static Integer edgeV1[] = { 1, 1, 1, 2, 2, 3 };
//static Integer edgeV2[] = { 2, 3, 4, 3, 4, 4 };

/*
Here are the 10 words that my solution found

g1 = ({1,2,3,4},{{3,4},{2,4},{2,3},{1,4},{1,3},{1,2}})
Letter mapping: {(1,"t"),(2,"o"),(3,"u"),(4,"r")}
10 words found: {"ruru","rort","roto","rout","outr","tutu","toro","tort","tout","toto"}
*/


// -------------------------------------
// Here is the real data set based on Will Shortz's Six for a Spell puzzle
// 
// Once you have worked out most of the defects in your implementation using the small data set above
// comment out the declarations above and uncomment the declarations below
// -------------------------------------
static Integer searchWordLength = 6;
static Integer numVertices = 13;
static Integer numEdges = 36;
static Text vertexLabels[] = { L"X", L"a",L"c",L"d",L"e",L"e",L"i",L"l",L"n",L"o",L"o",L"p",L"r",L"t"};
static Integer edgeV1[] = { 1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,5,5,5,5,6,6,7,7,7,8,8,9,10,10,11 };
static Integer edgeV2[] = { 2,3,4,6,8,3,4,6,9,4,5,6,7,8,9,10,11,12,13,9,12,7,10,11,12,8,13,9,11,12,10,13,12,11,13,13 };

//-------------------------------------------------------------------

void loadGraph(UnlabeledUndirectedGraph& g) {
	g.setNumberOfVertices(numVertices);
	for (int k = 0; k < numEdges; k++) {
		g.addEdge(edgeV1[k], edgeV2[k]);
	} // end for
} // loadGraph

//-------------------------------------------------------------------

void outputLetterMapping() {
	wcout << "Letter mapping: {";
	for (int k = 1; k <= numVertices; k++) {
		wcout << "(" << k << "," << vertexLabels[k] << ")";
		if (k < numVertices) {
			wcout << ",";
		} // end if
	} // end for
	wcout << "}" << endl;
} // outputLetterMapping

//-------------------------------------------------------------------

//
// TODO: 
// Place here your free standing C++ operations that solve Six for a Spell puzzle
// 
// In Java, all operations have to be a member of a class, not so in C++
// In C++, you can just have free standing operations, i.e., ones not in a class
// In this file, loadGraph, outputLetterMapping, and main are all free standing operations
// 
//

CeramicArray1<Queue0<Text>> words;
Queue0<Text> foundWords;
int wordCount, foundWordCount;

boolean containsCharacter(Character c) {
	for (int i = 1; i <= numVertices; i++) {
		if (c == vertexLabels[i][0]) {
			return true;
		}
	}
	return false;
}

void loadDictionaryWords(Text& filename)
{
	Text word;
	File inputF;
	Boolean successful;

	inputF.openFile(filename, File::openForRead, successful);
	if (successful) {
		Integer filesize;
		inputF.read(filesize, successful);	// note: filesize is of type Integer
		for (int k = 0; k < filesize; k++) {
			inputF.read(word, successful);	// note: word is of type Text
			if (word.size() != searchWordLength) {
				continue;
			}
			Text newWord, newWord2;
			Character c;
			boolean cont = false;
			for (int i = 0; i < searchWordLength; i++) {
				newWord2 = word;
				newWord2.remove(i, c);
				if (!containsCharacter(c)) {
					cont = true;
				}
			}
			if (cont) {
				continue;
			}
			for (int i = searchWordLength; i > 1; i--) {
				newWord = word;
				words[i].enqueue(word);
				wordCount++;
				word = newWord;
				word.remove(i-1, c);
			}
		} // end for
		inputF.closeFile(successful);
	}
	else {
		wcout << "Error reading data file" << endl;
		wcout << "Colocate that file and this executable in the same folder" << endl << endl;
	} // end if
}

boolean alreadyFoundWord(Text& word) {
	for (int i = 0; i < foundWordCount; i++) {
		Text queuedWord;
		foundWords.dequeue(queuedWord);
		if (word == queuedWord) {
			foundWords.enqueue(queuedWord);
			return true;
		}
		foundWords.enqueue(queuedWord);
	}
	return false;
}

boolean checkForWord(Text& word, int wordLength) {
	if (wordLength == 1) {
		return true;
	}
	for (int i = 0; i < wordCount; i++) {
		Text queuedWord;
		words[wordLength].dequeue(queuedWord);
		if (word == queuedWord) {
			words[wordLength].enqueue(queuedWord);
			return true;
		}
		words[wordLength].enqueue(queuedWord);
	}
	return false;
}

void traverseGraph(UnlabeledUndirectedGraph& g, int currentVertex, Text& word) {
	if (checkForWord(word, word.size())) {
		//foundWords.enqueue(word);
		if (word.size() == searchWordLength && !alreadyFoundWord(word)) {
			wcout << L"Found word " << word << endl;
			foundWords.enqueue(word);
			foundWordCount++;
		}
		else {
			for (int i = 1; i <= numVertices; i++) {
				// Edge is in g
				if (i == currentVertex) {
					continue;
				}
				if (g.isEdge(currentVertex, i)) {
					Text newWord;
					newWord = word;
					newWord.append(vertexLabels[i]);
					if (newWord.size() > searchWordLength) {
						continue;
					}
					traverseGraph(g, i, newWord);
				}
			}
		}
	}
}

void findWords(UnlabeledUndirectedGraph& g) {
	for (int i = 1; i <= numVertices; i++) {
		Text word;
		word.append(vertexLabels[i]);
		traverseGraph(g, i, word);
	}
}

  //-------------------------------------------------------------------
  // main executable body
  //-------------------------------------------------------------------

int main(int argc, char* argv[])
{
	UnlabeledUndirectedGraph g1;

	wcout << "Program start" << endl;
	loadGraph(g1);
	outputLetterMapping();
	wcout << "g1 = " << g1 << endl;

	words.setBounds(2, searchWordLength);
	Text dictionaryFile = L"dictionary.dat";
	loadDictionaryWords(dictionaryFile);

	findWords(g1);

	wcout << "end program" << endl;
	return 0;
}	// end main
