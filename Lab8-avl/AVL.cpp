#include "AVL.h"
#include <algorithm>

AVL::AVL() {
    root = NULL;
}
AVL::~AVL() {
    clear();
}

NodeInterface * AVL::getRootNode() const{
    return root;
}

bool AVL::add(int data){
    return insert(root, data);
}

bool AVL::remove(int data){
    return removeHelper(root, data);
}

void AVL::clear(){
    while(root != NULL){
    	remove(root->data);
	}
}


/* -------------------------------------------------- */

bool AVL::insert(Node*& local_root, int data){
    //cout << "Implement insert" << endl;
    
    if (local_root == NULL){ // Tree is empty, make a new node
    	local_root = new Node(data);
    	return true;
	}
	else if (data == local_root->data){ //Node is already in the tree
	    return false;
	}
	else if (data < local_root->data){
	    bool isAdded = insert(local_root->left, data);
	    if (isAdded){
	    	rebalance(local_root);
	    }
	    return isAdded;
	}
	else if (data > local_root->data){
		bool isAdded = insert(local_root->right, data);
	    if (isAdded){
	    	rebalance(local_root);
	    }
	    return isAdded;
	}
	else {
		return false;
	}
}


void AVL::rebalance(Node*& local_root){
	
	if (local_root == NULL){
		return;
	}
	//Case left-left unbalance
	if ( (get_balance(local_root) == -2) && (get_balance(local_root->left) <= 0 ) ){
		rotate_right(local_root);
	}
	//ase left-right unbalance
	else if ( (get_balance(local_root) == -2) && (get_balance(local_root->left) == 1) ){
		rotate_left(local_root->left);
		rotate_right(local_root);
	}
	//Case right-right
	else if ( (get_balance(local_root) == 2) && (get_balance(local_root->right) >= 0) ){
		rotate_left(local_root);
	}
	//Case right-left
	else if ( (get_balance(local_root) == 2) && (get_balance(local_root->right) == -1) ) {
		rotate_right(local_root->right);
		rotate_left(local_root);
	}
}


bool AVL::removeHelper(Node*& local_root, int data){
	if (local_root == NULL){ //Didn't find the node with value
		return false;
	}
	else if (data < local_root->data){
		bool ret_val = removeHelper(local_root->left, data);
		rebalance(local_root);
		return ret_val;
	}
	else if (data > local_root->data){
		bool ret_val = removeHelper(local_root->right, data);
		rebalance(local_root);
		return ret_val;
	}
	else if (local_root->data == data){ //Found the value
		if (local_root->left == NULL && local_root->right == NULL){ // Node has no children
			delete local_root;
			local_root = NULL;
			return true;
		}
		else if (local_root->left != NULL && local_root->right == NULL){ // Node has only left child
			Node* temp = local_root->left;
			delete local_root;
			local_root = temp;
			rebalance(local_root);
			return true;
		}
		else if (local_root->left == NULL && local_root->right != NULL){ // Node has only right child
			Node* temp = local_root->right;
			delete local_root;
			local_root = temp;
			rebalance(local_root);
			return true;
		}
		// Node has both children
		Node* temp = local_root->left;
		Node* parent = temp;
		while(temp->right != NULL){
			parent = temp;
			temp = temp->right;
		}
		local_root->data = temp->data;
		removeHelper(local_root->left, local_root->data);
		rebalance(local_root);
		return true;
	}
}


void AVL::rotate_left(Node*& local_root){
	Node* temp = local_root->right;
	local_root->right = temp->left;
	temp->left = local_root;
	local_root = temp;
}


void AVL::rotate_right(Node*& local_root){
	Node* temp = local_root->left;
	local_root->left = temp->right;
	temp->right = local_root;
	local_root = temp;
}

int AVL::get_height(Node*& local_root){
	if (local_root == NULL){
		return 0;
	}
	int left = get_height(local_root->left);
	int right = get_height(local_root->right);
	
	return max(left, right) + 1;
}


int AVL::get_balance(Node*& n){
	//if (n->right != NULL && n->left != NULL){
		return get_height(n->right) - get_height(n->left);
}