#include "BST.h"

#include <iostream>

using namespace std;

	BST::BST(){
	    root = NULL;
	}
	BST::~BST(){
	    clear();
	}

	NodeInterface* BST::getRootNode() const{
		return this->root;
	}

	bool BST::add(int data){
		if (root == NULL){
			Node* newRoot = new Node(data);
			root = newRoot;
			return true;
		}
	    else if (insert(root, data)){
	    	return true;
	    }
	    else {
	    	return false;
	    }
	}

	bool BST::remove(int data){
    	return removeHelper(root, data);
	}

	void BST::clear(){
		while(root != NULL){
	    	remove(root->data);
		}
	}
	
	void BST::clearHelper(Node*& localRoot){
		if (localRoot == NULL){
			return;
		}
		clearHelper(localRoot->leftChild);
		clearHelper(localRoot->rightChild);
		delete localRoot;
		localRoot = NULL;
	}
	
	
	bool BST::insert(Node* &localRoot, int data){
	    if (localRoot == NULL){
	        localRoot = new Node(data);
	        return true;
	    }
	    else if (localRoot->data == data){
	        return false;
	    }
	    else if (data < localRoot->data){
	        return insert(localRoot->leftChild, data);
	    }
	    else {
	        return insert(localRoot->rightChild, data);
	    }
	}
	
	bool BST::removeHelper(Node*& localRoot, int data){
		if (localRoot == NULL){
			return false;
		}
		if (data < localRoot->data){
			//Return the result of deleting from the left subtree
			return removeHelper(localRoot->leftChild, data);
		}
		else if (data > localRoot->data){
			//Return the result of deleting from the right subtree
			return removeHelper(localRoot->rightChild, data);
		}
		else { //We are at the node (localRoot) with the value data
			if (localRoot->leftChild == NULL && localRoot->rightChild == NULL){
				delete localRoot;
				localRoot = NULL;
				return true;
			}
			else if (localRoot->leftChild != NULL && localRoot->rightChild == NULL){
				Node* del = localRoot;
				localRoot = localRoot->leftChild;
				delete del;
				del = NULL;
				return true;
			}
			else if (localRoot->rightChild != NULL && localRoot->leftChild == NULL){
				Node* del = localRoot;
				localRoot = localRoot->rightChild;
				delete del;
				del = NULL;
				return true;
			}
			else{
				Node* temp = localRoot->leftChild;
				Node* parent = temp;
				while(temp->rightChild != NULL){
					parent = temp;
					temp = temp->rightChild;
				}
				localRoot->data = temp->data;
				removeHelper(localRoot->leftChild, localRoot->data);
				return true;
			}
		}
		return false;
	}

