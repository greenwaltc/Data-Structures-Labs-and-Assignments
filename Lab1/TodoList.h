#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
public:
    vector <string> tasks;
    TodoList() {
        ifstream infile ("TODOList.txt");
        string line;
        if (infile.is_open())
        {
            while ( getline (infile,line) )
            {
                tasks.push_back(line);
            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        ofstream outfile;
        outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
        for (int i = 0; i < tasks.size(); i++){
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task){
        tasks.push_back(_duedate + " " + _task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task){
        for (int i = tasks.size() - 1; i >= 0; i--){
            if((tasks.at(i)).find(_task) != string::npos){
                tasks.erase(tasks.begin() + i);
            }
        }
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList(){
        for (int i = 0; i < tasks.size(); i++){
            cout << tasks.at(i) << '\n';
        }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date){
        for (int i = 0; i < tasks.size(); i++){
            if((tasks.at(i)).find(_date) != string::npos){
                cout << tasks.at(i) << endl;
            }
        }
    }
};

#endif