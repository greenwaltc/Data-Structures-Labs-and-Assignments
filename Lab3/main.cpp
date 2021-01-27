#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <vector>

using namespace std;


string parseFileName(string fileName, const string type);

void storeWordsInVector(vector<string>& tokens, const string fileName);

void storeWordsInSet(set<string>& unique, const string fileName);

int main (int argc, char* argv[]){
    
    string fileName = argv[1];
    
    set<string> unique;
    storeWordsInSet(unique, fileName);
    
    vector<string> tokens;
    storeWordsInVector(tokens, fileName);
    
    //Make a better map with list and vector of strings
    int M = 2;
    map<list<string>, vector<string>> wordmap;
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
                        
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }
    
    srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
    
    //Creat final sermon
    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    int count = 1;
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap[state][ind]<<" ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }
    
    return 0;
}


string parseFileName(string fileName, const string type){
    int parse = fileName.find(".txt");
    fileName.erase(parse, 4);
    fileName += "_" + type + ".txt";
    return fileName;
}

void storeWordsInVector(vector<string>& tokens, const string fileName){
    string next_line;  // Each data line
    ifstream in(fileName);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            if (isalpha(token[0])){ // Check to see if token is a word, so unrecognized formats are skipped
                string nopunct = "";
                for(auto &c : token) { // Remove Punctuation      
                    if (isalpha(c)) {
                        nopunct +=c;       
                    }
                }
    	        tokens.push_back(nopunct);
            }
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    
    string fileStream = parseFileName(fileName, "vector");
    ofstream myfile;
    myfile.open (fileStream);
        for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
            myfile << *it << endl;
        }
    myfile.close();
}

void storeWordsInSet(set<string>& unique, const string fileName){
    string next_line;  // Each data line
    ifstream in(fileName);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
		    unique.insert(nopunct);
	    }
    }
    
    cout << "Number of unique words "<<unique.size()<<endl;
    
    string fileStream = parseFileName(fileName, "set");
    
    ofstream myfile;
    myfile.open (fileStream);
        for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
            myfile << *it << endl;
        }
    myfile.close();
}