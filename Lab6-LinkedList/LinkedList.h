#pragma once
#include "LinkedListInterface.h"
#include <sstream>

template<typename T>
class LinkedList: public LinkedListInterface<T>
{

private:
    struct Node{
        T data;
        Node* next;
        Node(const T& the_data, Node* next_val = NULL) :
	        data(the_data) {next = next_val;}
    };
    
    Node *head = NULL;
	int num_items = 0;
	
public:

	LinkedList(void) {
		head = NULL;
		num_items = 0;
	};
	virtual ~LinkedList(void) {
		clear();
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertHead(T value){
		if (!find(value)){
			if (num_items == 0){
		    	Node *newNode = new Node(value);
		    	head = newNode;
		    	num_items++;
			}
			else{
				Node* newNode = new Node(value, head);
				head = newNode;
				num_items++;
			}
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value){
		if (!find(value)){
		    if (num_items == 0){
		    	insertHead(value);
		    }
		    else if (num_items > 0){
		    	Node* newNode = new Node(value);
		    	Node* temp = head;
		    	while(temp->next != NULL){
		    		temp = temp->next;
		    	}
		    	temp->next = newNode;
		    	num_items++;
		    }
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	virtual void insertAfter(T value, T insertionNode){
		if (head == NULL){
			insertHead(value);
		}
		if (find(value) == true){
			
		}
		else {
			Node* temp = head;
			while(temp != NULL){
				if (temp->data == insertionNode){
					Node* newNode = new Node(value);
					newNode->next = temp->next;
					temp->next = newNode;
					num_items++;
					break;
				}
				temp = temp->next;
			}
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value){
	    if ( (head != NULL) && (find(value)) ){
	    	if (head->data == value){
	    		Node* temp = head;
	    		head = head->next;
	    		delete temp;
	    		temp = NULL;
	    		num_items--;
	    	}
	    	else{
		    	Node* traverse = head;
		    	while(traverse != NULL){
		    		if (traverse->next->data == value){
		    			Node* ptr = traverse->next;
		    			traverse->next = traverse->next->next;
		    			delete ptr;
		    			ptr = NULL;
		    			num_items--;
		    			break;
		    		}
		    		traverse = traverse->next;
		    	}
	    	}
	    }
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	virtual void clear(){
	    if (head != NULL){
	    	while (head != NULL){
	    		Node* traverse = head;
	    		head = head->next;
	    		delete traverse;
	    		traverse = NULL;
	    		num_items--;
	    	}
	    }
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index){
	    
	    if (index < 0){
	    	throw out_of_range("under");
	    }
	    else if (index >= num_items){
	    	throw out_of_range("over");
	    }
	    else{
	    	Node* temp = head;
	    	for (int i = 0; i <= index; i++){
	    		if (i == index){
	    			return temp->data;
	    		}
	    		temp = temp->next;
	    	}
	    }
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size(){
	    return num_items;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	virtual string toString(){
	    stringstream ss;
	    string empty = "";
	    Node* temp = head;
	    if (temp == NULL){
	    	return empty;
	    }
	    else{
		    while (temp->next != NULL){
		    	ss << temp->data << " ";
		    	temp = temp->next;
		    }
		    ss << temp->data;
		    return ss.str();
	    }
	}


    /*Returns true if a @param value is in the linked list, false otherwise*/
    bool find(T value){
		Node* temp = head;
		while(temp != NULL){
			if (temp->data == value){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

};
