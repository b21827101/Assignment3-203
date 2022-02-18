/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/
/*To use this function template we use the following format for the function call:
function_name <type> (parameters);
*/
#ifndef UNTITLED3_STACK_H
#define UNTITLED3_STACK_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
extern ofstream myFile;

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    string toping();
    int size() const;
    //Push: Place item on top of the stack
    void push(const T& newItem);
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const;
    //Pop: Remove item from the top of the stack
    void pop();
    void  display();
    static string *dissarr[5];


private:
    struct ListNode {
        T item;
        ListNode* next;
    };
    ListNode* _head;
    int _size;


};
#endif //UNTITLED3_STACK_H

template<typename T>
void Stack<T>::display(){ //this method using for displaying at output.txt
    ListNode* curPtr = _head;
    myFile<<"Packages:\n";
    while (curPtr != NULL){
        istringstream iss(curPtr->item);
        string pack1,city;
        iss >> pack1>>city;
        myFile << pack1<<"\n";
        curPtr = curPtr->next;
    }
}


template<typename T>
bool Stack<T>::isEmpty() const {
    if(_head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::push(const T &newItem) {
    ListNode* newNode = new ListNode;

    if(isEmpty()) { //if head is null
        newNode->item = newItem;
        newNode->next = NULL;
        _head = newNode;
        _size++;  //increasing size after push method
        return;

    }
    newNode->item = newItem;
    newNode->next = _head;
    _size++;
    _head = newNode;
}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    if (isEmpty()){
        return;
    }
    else{
        stackTop =_head->item;
    }
}

template<typename T>
void Stack<T>::pop() {
    ListNode* temp = new ListNode;
    if (isEmpty()){    // Check for stack underflow
        return;
    }
    else{
        // Top assign into temp
        temp = _head;
        // Assign second node to top
        _head = _head->next;
        temp->next = NULL;
        _size--;   //decreasing size after pop method
        free(temp);
    }
}

template<typename T>
Stack<T>::Stack(){
    _head = NULL;
    _size = 0;
}

template<typename T>
Stack<T>::~Stack() {
    while (!isEmpty())
        pop();
}

template<typename T>
string Stack<T>::toping() {  //getting top element in there
    ListNode* curPtr = _head;
    if (curPtr != NULL){
        //cout << " " << curPtr->item;
        return curPtr->item;
    }
}

