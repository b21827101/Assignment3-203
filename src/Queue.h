
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
extern ofstream myFile;

template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    int size() const;
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem);
    //Dequeue: Items are removed from the front of the queue
    void dequeue();
    void display();
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const;
    string topqueue();
private:
    struct QueueNode {
        T item;
        QueueNode *next;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_lastNode;  //back
    QueueNode *_rear;  //front
};

template<typename T>
Queue<T>::Queue() {
    _lastNode = NULL;
    _rear = NULL;
    _size =0;
}

template<typename T>
Queue<T>::~Queue() {
    while(!isEmpty()){
        dequeue();
    }
}

template<typename T>
bool Queue<T>::isEmpty() const {
    if(_size == 0) { //size is zero return true
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    QueueNode *newnode = new QueueNode;

    // set data portion of new node
    newnode->item = newItem;
    newnode->next = NULL;

    // insert the new node
    if (isEmpty()) {// insertion into empty queue
        _rear = newnode;
    }
    else{
        _lastNode->next = newnode;
    }
    // insertion into nonempty queue
    _lastNode = newnode;
    _size++;
}

template<typename T>
void Queue<T>::dequeue() {
    if (isEmpty()){
        return;

    }
    else{
        // queue is not empty; remove front
        QueueNode *temp = _rear;

        if (_rear == _lastNode){
            _rear = NULL;
            _lastNode = NULL;
        }
        else{
            _rear = _rear->next;
        }
        temp->next = NULL;
        free(temp);
        _size--;  //decreasing size
    }
}

template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    if (isEmpty()){
        return ;
    }
    else {
        // queue is not empty; retrieve front
        queueTop = _rear->item;
        return;
    }
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::display() {
    QueueNode *curPtr = _rear;  //this method is using for output
    myFile<<"Trucks:\n";
    while (curPtr != NULL){
        istringstream iss(curPtr->item);
        string power,city,truck;
        iss >>truck>>city>>power;
        myFile<<truck<<"\n";
        curPtr = curPtr ->next;
    }
}

template<typename T>
string Queue<T>::topqueue() {  //display top element
    QueueNode* curPtr = _rear;
    if (curPtr != NULL){
        return curPtr->item;
    }
}

