#ifndef INTROPROJECT_DICTNODE_H
#define INTROPROJECT_DICTNODE_H

class dictNode {
public:
    dictNode();
    dictNode *next[27]{}; //stores nodes of tree a-z and '
    bool isWord; //stores if node ends a word
};


#endif
