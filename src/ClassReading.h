#ifndef UNTITLED2_CLASSREADING_H
#define UNTITLED2_CLASSREADING_H
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

class ClassReading {
public:
    static char dests[50];
    static char missions[50];
    static char packages[50];   //for argv
    static char trucks[50];
    static char output[50];
    void reading();
    void writeline(int countdests,string destsArr[],string missionsArr[],int countmissions);
};

#endif //UNTITLED2_CLASSREADING_H
