#ifndef UNTITLED3_PACKAGES_H
#define UNTITLED3_PACKAGES_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stack.h"
using namespace std;


class Packages {

public:
    Stack<string> *v;
    struct Node1 {
        string data1;
        Node1* next;
        Node1* prev;
    };
    Node1* head1= NULL;
    Node1* tail = NULL;
    int _size1;

    Packages();
    string deleteNode(struct Node1* head1,Node1* del);
    string deleteForIndex(int n);
    void pushinitialPackage(int count,string *packarr,int countdests,string *destsArr);
    void pushandAfterMission(int pack1,int city1,int pack,int city2);
    void pushPackagesInTruck(const string &new_data);
    void leavePackagesAtMidway(string midway,int city2,vector<string>,int city3);
    string AddPackagesForLastStation();
    bool isEmpty() const;
};

Packages::Packages() {
    head1 = tail = NULL;
    _size1 = 0;
}

bool Packages::isEmpty() const {
    return _size1==0;
}

string Packages::AddPackagesForLastStation() { //if the city is last city we appending all packages in there
    if (!isEmpty()){
        Node1* temp = head1;
        if (head1 == tail){
            tail = NULL;
        }
        string delValue = temp->data1;
        head1 = head1->next;
        _size1--;
        delete temp;
        if(delValue.empty()){
            return "null";
        }
        else{
            return delValue;
        }
    }
    else{
        return 0;
    }
}



void Packages::pushinitialPackage(int countpackage, string packarr[],int countdests, string destsArr[]) {
    v = new Stack<string>[countdests];

    for (int i = 0; i < countdests; i++) {  //this methods for inital packages
        for (int y = 0; y < countpackage; y++) {
            istringstream iss(packarr[y]);
            string pack1, city, dest;
            iss >> pack1 >> city;
            istringstream iss1(destsArr[i]);
            iss1 >> dest;
            if (city == dest) {   //if packages line contains city name,i appended
                v[i].push(pack1);
            }
        }
    }
}



string Packages::deleteNode(struct Node1* head1,struct Node1* del){
    if (head1 == NULL || del == NULL){
        return "null";
    }
    if (head1 == del){// If node to be deleted is head node
        head1 = del->next;
    }

    //Change next only if node to be deleted is NOT the last node
    if (del->next != NULL){
        del->next->prev = del->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL){
        del->prev->next = del->next;
    }
    string str1 = del->data1;
    _size1--;
    free(del);
    return str1;
}


string Packages::deleteForIndex(int n){ //for deleting according to package index

    if (head1 == NULL || n <= 0)    // if list in NULL or invalid position is given
        return 0;

    struct Node1* current = head1;
    /* traverse up to the node at position 'n' from the beginning */
    for (int i = 1; current != NULL && i < n; i++){
        current = current->next;
    }

    // if 'n' is greater than the number of nodes in the doubly linked list
    if (current == NULL){
        return 0;
    }
    /* delete the node pointed to by 'current' */
    return deleteNode( head1,current);
}


void Packages::pushPackagesInTruck(const string &new_data){
    struct Node1* newItem;
    newItem=new Node1;
    newItem->data1=new_data;
    if(head1==NULL){
        head1=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
        _size1++;
    }//pushing new item inside truck
    else{
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
        _size1++;
    }
}

void Packages::pushandAfterMission(int pack1,int city1,int pack,int city2) {
    for (int i = 0; i < pack1; i++) {
        pushPackagesInTruck(v[city1].toping()); //i am taking packages from city1 and city2
        v[city1].pop();
    }

    for (int i = 0; i < pack; i++) {
        pushPackagesInTruck(v[city2].toping());
        v[city2].pop();
    }
}

void Packages::leavePackagesAtMidway(string midway,int city2,vector<string> result,int city3) {
    int prev = -1;
    stringstream ss4(midway);
    int looping = 0;
    while (ss4.good()) {   //using vector for split line
        string substr;
        getline(ss4, substr, ','); //get first string delimited by comma
        result.push_back(substr);
        stringstream ss5(substr);
        ss5 << substr;
        int del;   //convert from int to string
        ss5 >> del;
        string str2;
        if (del > prev) {
            str2 = deleteForIndex(del + 2 - looping);
            v[city2].push(str2);
        }
        else {   //if else using for unordered integers
            str2 = deleteForIndex(del + 2);
            v[city2].push(str2);
        }
        prev = del;
        looping++;
    }

    while(_size1 !=0 ){
        string str2 = AddPackagesForLastStation();     //last stations when inserting all package until isempty
        if(str2 != "null"){
            v[city3].push(str2);
        }
    }
}
#endif //UNTITLED3_PACKAGES_H
