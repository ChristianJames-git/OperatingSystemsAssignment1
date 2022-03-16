#ifndef INTROPROJECT_DICTIONARY_H
#define INTROPROJECT_DICTIONARY_H

#include "dictNode.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

class dictionary {
public:
    void readDict(char *dictionaryFile);
    void readWords(char *wordsFile);
private:
    void openFile(char *file);
    void closeIn();
    void readIn(vector<string> *storage);
    void populateTree();
    static int ASCIItoIndex(char);
    bool add(const char *, const char *);
    void searchCount(const string&);
    dictNode* findEndingNodeOfAStr(const char *remainingStr, const char *strBeingSearched);
    void countWordsStartingFromANode(dictNode *currNode, int &count);
    ifstream inStream;
    vector<string> dictionaryStore;
    dictNode root; //stores root node
    dictNode *prevNode; //temp node
    const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~"; //delimiters string
};


#endif
