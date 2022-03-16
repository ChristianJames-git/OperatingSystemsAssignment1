#include "dictionary.h"

int main(int argc, char **argv) {
    if (argc != 3) { //make sure correct args amount
        cout << "Please input correct number of inputs" << endl;
        exit(EXIT_FAILURE);
    }
    auto *dictTree = new dictionary;
    dictTree->readDict(argv[1]); //read in dictionary and populate tree
    dictTree->readWords(argv[2]); //read in words and output counts
    return 0;
}
