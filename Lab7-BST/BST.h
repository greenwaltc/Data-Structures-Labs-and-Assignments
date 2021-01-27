//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {
public:
	BST();
	~BST();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface* getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	
	/* My own functions: */
	
	bool insert(Node*& localRoot, int data);
	bool replaceParent(Node*& localRoot, Node*& localRoot_left);
	bool removeHelper(Node*& localRoot, int data);
	void clearHelper(Node*& localRoot);
	void replace_parent(Node*& localRoot, Node*& localRoot_leftChild);
	
private:
	Node* root;
	
};