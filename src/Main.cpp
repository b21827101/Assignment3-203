#include <iostream>
#include "ClassReading.h"
#include <string>
using namespace std;
ofstream myFile;

int main(int argc, char** argv) {
    strcpy (ClassReading::dests,argv[1]);  //dests.txt
    strcpy (ClassReading::packages,argv[2]);    //packages.txt
    strcpy (ClassReading::trucks,argv[3]);  //trucks.txt
    strcpy (ClassReading::missions,argv[4]);    //missions.txt
    strcpy (ClassReading::output,argv[5]);    //output
    myFile.open(argv[5]);//output
    ClassReading class1;
    class1.reading();
    return 0;
}
