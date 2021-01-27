#include "Hashmap.h"
#include <string>
#include <vector>

Hashmap::Hashmap(){
    for (int i = 0; i < BUCKETS; i++){
        buckets[i] = NULL;
    }
    mapSize = 0;
}

Hashmap::~Hashmap(){
    clear();
}

unsigned int Hashmap::hash(string key) const{
    unsigned int hash = 7;
    for ( int i = 0; i < key.length(); i++ ){
        hash = hash*31 + key.at(i);
    }
    hash %= BUCKETS;
    return hash;
}

void Hashmap::insert(string key, int value){
    int hashcode = hash(key);
    
    //Find out if the map with key is already in the list at buckets[hashcode]
    bool inBuckets = false;
    Node* temp = buckets[hashcode];
    while (temp != NULL){
        if (temp->key == key){
            inBuckets = true;
            break;
        }
        temp = temp->next;
    }
    
    if ( inBuckets == true ){ // Update the value at key
        temp->value = value;
    }
    else {
        //Create a new node with the given key, value and insert node into the list at buckets[hashcode]
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        
        //Inserting at the beginning of doubly linked list taken from Stack Overflow
        newNode->next = buckets[hashcode];
        newNode->prev = NULL;
        if (buckets[hashcode] != NULL){
            buckets[hashcode]->prev = newNode;
        }
        buckets[hashcode] = newNode;
        
        mapSize++; //The number of nodes in the hash table has increased
    }
}

bool Hashmap::contains(string key) const{
    bool result = false;
    int hashcode = hash(key);
    Node* temp = buckets[hashcode];
    while (temp != NULL){
        if (temp->key == key){
            result = true;
            break;
        }
        temp = temp->next;
    }
    return result;
}

int Hashmap::get(string key) const{
    bool inBuckets = false;
    int hashcode = hash(key);
    Node* temp = buckets[hashcode];
    while (temp != NULL){
        if (temp->key == key){
            inBuckets = true;
            return temp->value;
        }
        temp = temp->next;
    }
    if (inBuckets == false){
        throw invalid_argument( "invalid_argument" );
    }
}

int& Hashmap::operator [](string key){ 
    int hashcode = hash(key);
    bool inBuckets = false;
    Node* temp = buckets[hashcode];
    while (temp != NULL){
        if (temp->key == key){
            inBuckets = true;
            break;
        }
        temp = temp->next;
    }
    if (inBuckets == true){
        return temp->value;
    }
    else if (inBuckets == false){
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = 0;
        
        //Inserting at the beginning of doubly linked list taken from Stack Overflow
        newNode->next = buckets[hashcode];
        newNode->prev = NULL;
        if (buckets[hashcode] != NULL){
            buckets[hashcode]->prev = newNode;
        }
        buckets[hashcode] = newNode;
        
        mapSize++; //The number of nodes in the hash table has increased
        return newNode->value;
    }
}

bool Hashmap::remove(string key){
    bool ret = false;
    int hashcode = hash(key);
    Node* temp = buckets[hashcode];
    while (temp != NULL){
        if (temp->key == key){
            ret = true;
            break;
        }
        temp = temp->next;
    }
    if (ret == false){
        return false;
    }
    else { //the node with key was found. Method implemented from Stack Overflow
        Node* del = temp;
        if (del == buckets[hashcode]){ //the node to remove is the head
            buckets[hashcode] = del->next;
        }
        if (del->next != NULL){
            del->next->prev = del->prev;
        }
        if (del->prev != NULL){
            del->prev->next = del->next;
        }
        delete del;
        del = NULL;
        mapSize--;
        return true;
    }
}

void Hashmap::clear(){
    for (int i = 0; i < BUCKETS; i++){
        while (buckets[i] != NULL){
            remove(buckets[i]->key);
        }
        buckets[i] = NULL;
    }
    mapSize = 0;
}

string Hashmap::toString() const{
    stringstream ss;
    for (int i = 0; i < BUCKETS; i++){
        Node* temp = buckets[i];
        
        ss << "["<<i<<"]" << " ";
        while (temp != NULL){
            ss << temp->key << " => " << temp->value;
            if (temp->next != NULL){
                ss << ", ";
            }
            temp = temp->next;
        }
        ss << "\n";
    }
    return ss.str();
}

int Hashmap::size() const{
    return mapSize;
}

string Hashmap::toSortedString() const{
    stringstream ss;
    priority_queue<Node*, vector<Node*>, NodeCompare> nodeHeap;
    for (int i = 0; i < BUCKETS; i++){
        // Iterate through each bucket. Use nodeHeap.push to push all Node* onto heap.
        Node* temp = buckets[i];
        while (temp != NULL){
            nodeHeap.push(temp);
            temp = temp->next;
        }
    }
    while(!nodeHeap.empty()){
        Node* top = nodeHeap.top(); // Get top node (next node in sorted order)
        ss << top->key << " => " << top->value << endl; // Add node data to stringstream
        nodeHeap.pop(); // Pop it off
    }
  return ss.str();
}