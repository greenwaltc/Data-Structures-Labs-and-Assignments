#pragma once

#include "NodeInterface.h"
#include "Node.h"
#include "AVLInterface.h"
#include "AVL_Tree.h"
#include <iostream>

using namespace std;

class AVL : public AVLInterface {
public:
	AVL();
	virtual ~AVL();

	NodeInterface * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();
	
	/* My own functions */
	bool insert(Node*& local_root, int data);
	bool removeHelper(Node*& local_root, int data);
	void rebalance(Node*& local_root);
	void rotate_left(Node*& n);
	void rotate_right(Node*& n);
	int get_balance(Node*& n);
	
	int get_height(Node*& local_root);
private:
    Node* root;
};