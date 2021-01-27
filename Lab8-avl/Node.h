#pragma once
#include "NodeInterface.h"
#include "AVLNode.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface {

public:

	enum  balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};
	
	Node(int data, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	virtual ~Node() {}

	int getData() const;

	NodeInterface * getLeftChild() const;

	NodeInterface * getRightChild() const;
	
private:
    int data;
    Node* left;
    Node* right;
    friend class AVL;
};