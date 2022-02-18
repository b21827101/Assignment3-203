#ifndef UNTITLED3_TRUCK_H
#define UNTITLED3_TRUCK_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Packages.h"
#include "Queue.h"

using namespace std;

class Truck: public Packages {
public:
    Queue<string> *queue1;
    Truck();
    void pushInitialTruck(int countdests,string destsArr[],int counttruck,string truckarr[],string missionsArr[],int countmissions);
    void appendTruckinStation(int cityT1,int countdests);
    void pushLastTruck(string destsArr[],int countdests, int cityT3);
    void enqueueTruck(const string newItem);
    void display(string destsArr[],int countdests);
    string cargo;
};

Truck::Truck() {
    head1 = tail = NULL;
}


void Truck::pushInitialTruck(int countdests,string destsArr[],int counttruck,string truckarr[],string missionsArr[],int countmissions) {

    queue1 = new Queue<string>[countdests];

    for (int i = 0; i < countdests; i++) { //inserting initial trucks for each cities
        istringstream iss(destsArr[i]);
        string city;
        string truck, city1, power;
        iss >> city;
        for (int x = 0; x < counttruck; x++) {
            istringstream iss1(truckarr[x]);
            iss1 >> truck >> city1 >> power;
            if (city1 == city) {
                queue1[i].enqueue(truck);
            }
        }
    }
}

void Truck::appendTruckinStation(int cityT1,int countdests) {//taking truck from first city

    cargo = queue1[cityT1].topqueue();
    enqueueTruck(cargo);
    queue1[cityT1].dequeue();
}

void Truck::pushLastTruck(string destsArr[],int countdests,int cityT3) {//at last city i am appending the truck in this city
    queue1[cityT3].enqueue(cargo);
    Truck();

}

void Truck::enqueueTruck(const string newItem) { //pushing trucks
    Node1* temp = new Node1();

    if (head1 == NULL){
        head1 = tail = temp;
       _size1++;
    }

    else{
        head1->prev = temp;
        temp->next = head1;
        head1= temp;
        _size1++;
    }

}

void Truck::display(string destsArr[],int countdests) {
    for (int i = 0; i < countdests; i++) {
        myFile<<destsArr[i]<<"\n";
        v[i].display();
        queue1[i].display();    //this method is using for output.txt
        myFile<<"-------------\n";
    }
}


#endif //UNTITLED3_TRUCK_H
