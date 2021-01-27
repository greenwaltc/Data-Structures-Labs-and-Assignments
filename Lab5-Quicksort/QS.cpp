#include "QS.h"

void QS::quick_sort(int first, int last){
    if (last - first >= 1){
        int pivot = medianOfThree(first, last);
        pivot = partition(first, last, pivot);
        quick_sort(first, pivot - 1);
        quick_sort(pivot + 1, last);
    }
}

void QS::sortAll(){
    if (currInPos == 0) { return; }
    quick_sort(0, currInPos - 1);
}

int QS::medianOfThree(int left, int right){

	if (this->getSize() <= 0
	 || left >= right
	 || right > this->getSize() - 1
	 || left < 0){
	     return -1;
	 }
	
	
	int middle = (right + left)/2;
	
	if (array[middle] < array[left]){
	    swapVal(middle, left);
	}
	if (array[right] < array[middle]){
	    swapVal(right, middle);
	}
	if (array[middle] < array[left]){
	    swapVal(middle, left);
	}

    return middle;
}

int QS::partition(int left, int right, int pivotIndex){
	
	if (array == NULL
	||  pivotIndex > right
	||  pivotIndex < left
	||  left < 0
	||  right > this->getSize() - 1
	||  left >= right){
	    return -1;
	}
	
	swapVal(left, pivotIndex);


	int up = left + 1;
	int down = right;
	
	do{
	    while ((array[up] <= array[left]) && (up < right)){
	        ++up;
	    }
	    while ((array[down] > array[left]) && (down > left)){
	        --down;
	    }
	    if (up < down){
	        swapVal(up, down);
	    }
	}while (up < down);
	swapVal(left, down);
	return down;
}

string QS::getArray() const{

    if (array == NULL || this->getSize() == 0){
        return "";
    }
    
    string representation = "";
    for (int i = 0; i < this->getSize(); i++){
        if (i < this->getSize() - 1){
            representation += to_string(array[i]) + ",";
        }
        else if (i == this->getSize() - 1){
            representation += to_string(array[i]);
        }
    }
    return representation;
}

int QS::getSize() const{
    return currInPos;
}

bool QS::addToArray(int value){

    if (currInPos < arraySize){
        array[currInPos] = value;
        currInPos++;
        return true;
    }
    else if (currInPos >= arraySize){
        return false;
    }
    else{
        return false;
    }
}

bool QS::createArray(int capacity){

    if(array != 0){
        clear();
    }
    if(capacity < 0){
        return false;
    }
    
    array = new int[capacity];
    arraySize = capacity;

    return true;
}

void QS::clear(){
    delete [] array;
    array = NULL;
    currInPos = 0;
    arraySize = 0;
}

void QS::swapVal(int first, int second){
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}