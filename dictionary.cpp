#include "dictionary.h"

void dictionary::readDict(char *dictFile) { //read in dictionary file to vector and call populateTree
    openFile(dictFile); //open file
    readIn(&dictionaryStore); //read in dictionary file
    populateTree(); //populate dictionary tree
    closeIn(); //close file
}

void dictionary::populateTree() { //populate tree with dictionary words
    prevNode = &root;
    for (auto & i : dictionaryStore) {
        if (!add(i.c_str(), i.c_str())) { //call add
            cout << "failed to insert word" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

bool dictionary::add(const char *remainingChars, const char *wordBeingInserted) { //adds word to dictionary tree
    int nextIndex = ASCIItoIndex(remainingChars++[0]); //convert current char to ASCII and increment to next char
    if (prevNode->next[nextIndex] == nullptr) { //create new node if missing
        prevNode->next[nextIndex] = new dictNode();
    }
    prevNode = prevNode->next[nextIndex]; //increment prevNode
    if (*remainingChars == '\0') { //check if end of word
        prevNode->isWord = true;
        prevNode = &root;
        return true;
    } else { //recurse with next char
        return add(remainingChars, wordBeingInserted);
    }
}

void dictionary::searchCount(const string& str) { //uses helper methods and outputs count
    dictNode *temp = findEndingNodeOfAStr(str.c_str(), str.c_str()); //find end of string
    int count = 0;
    if (temp != nullptr)
        countWordsStartingFromANode(temp, count); //count words that start with string
    cout << str << " " << count << endl; //output
}

dictNode *dictionary::findEndingNodeOfAStr(const char *remainingStr, const char *strBeingSearched) { //finds node at end of string or null if not in the dictionary
    int index = ASCIItoIndex(remainingStr++[0]); //convert current char to ASCII and increment to next char
    dictNode *toReturn;
    if (index == -1) //if character was null then end of string
        toReturn = prevNode;
    else if (prevNode->next[index] == nullptr) //if next[index] is null, return null as string isn't in dictionary
        toReturn = nullptr;
    else { //else recurse to next character
        prevNode = prevNode->next[index];
        toReturn = findEndingNodeOfAStr(remainingStr, strBeingSearched);
    }
    prevNode = &root;
    return toReturn;
}

void dictionary::countWordsStartingFromANode(dictNode *currNode, int &count) { //count from last letter of string
    if (currNode->isWord) //check if current char completes a word
        count++;
    for (auto & i : currNode->next) //search through all words that start with the given word, counting
        if (i != nullptr)
            countWordsStartingFromANode(i, count);
}

void dictionary::readWords(char *wordsFile) { //reads in each line of words, splits into words and calls searchCount on each word
    openFile(wordsFile); //open file
    string line;
    while (getline(inStream, line)) { //read in each line
        char *word = strtok((char *)line.c_str(), delimiters); //separate first word by using delimiters
        while (word != nullptr) { //loop through each word in line
            searchCount(word); //count and output for each word
            word = strtok(NULL, delimiters); //next word
        }
    }
    closeIn(); //close file
}

void dictionary::openFile(char *file) { //open file helper method
    inStream.open(file);
    if (!inStream.is_open()) { //check if file was opened successfully
        cout << "file not found" << endl;
        exit(EXIT_FAILURE);
    }
}

void dictionary::closeIn() { //close file helper method
    if (inStream.is_open())
        inStream.close();
    else {
        cout << "Input not open" << endl;
        exit(EXIT_FAILURE);
    }
}

void dictionary::readIn(vector<string> *storage) { //read into vector helper method
    string nextLine;
    while (inStream.good()) { //read in each line until eof
        getline(inStream, nextLine);
        if (nextLine.empty()) //skip over blank lines
            continue;
        nextLine = nextLine;
        storage->push_back(nextLine.c_str()); //add each line to given storage vector
    }
}

int dictionary::ASCIItoIndex(char character) { //ASCII to Index helper method
    int temp = character - '\0'; //get ASCII value of character
    if (temp == 0) //check if null
        return -1;
    else if (temp == 39) //check if '
        return 26;
    else if (temp >= 65 && temp <= 90) //check if upper case
        return temp - 65;
    else if (temp >= 97 && temp <= 122) //check if lower case
        return temp - 97;
    else {
        cout << "invalid character found" << endl;
        exit(EXIT_FAILURE);
    }
}
