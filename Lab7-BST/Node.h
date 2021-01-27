#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface {

public:
	Node(int data, Node* leftChild = NULL, Node* rightChild = NULL) {
		this->data = data;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}
	virtual ~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const{
	    return data;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const{
	    return leftChild;
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const{
	    return rightChild;
	}
	
	
private:
	Node* leftChild;
	Node* rightChild;
	int data;
	friend class BST;
};