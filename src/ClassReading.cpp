#include "ClassReading.h"
#include <string>
#include "Truck.h"
extern ofstream myFile;
using namespace std;
Truck t2;

char ClassReading::dests[50];
char  ClassReading::missions[50];
char  ClassReading::packages[50];
char  ClassReading::trucks[50];
char  ClassReading::output[50];

void ClassReading::reading() {
    int countpackage = 0;
    ifstream inFile;
    inFile.open(ClassReading::packages);//"packages2.txt"
    int jp = 0;
    if (!inFile) {
    }
    string strp;
    while (getline(inFile, strp)) {  //in there saving number of lines
        countpackage++;
    }
    inFile.close();

    inFile.open(ClassReading::packages);
    string packarr[countpackage+1];

    while (getline(inFile, strp)) { //after saving an array
        packarr[jp] = strp;
        jp++;
    }
    inFile.close();

    int counttruck = 0;
    ifstream inFile2;
    inFile2.open(ClassReading::trucks);//"trucks2.txt"
    int jt = 0;
    if (!inFile2) {
    }
    string strtruck;
    while (getline(inFile2, strtruck)) {//in there saving number of lines
        counttruck++;
    }
    inFile2.close();

    inFile2.open(ClassReading::trucks);
    string truckarr[counttruck+1];

    while (getline(inFile2, strtruck)) { //after saving an array
        truckarr[jt] = strtruck;
        jt++;
    }
    inFile2.close();


    int countmissions = 0;
    ifstream inFile3;
    inFile3.open(ClassReading::missions);//"missions2.txt"
    int jm = 0;
    if (!inFile3) {
    }
    string strmission;
    while (getline(inFile3, strmission)) {
        countmissions++;
    }
    inFile3.close();

    inFile3.open(ClassReading::missions);
    string missionsArr[countmissions+1];

    while (getline(inFile3, strmission)) {
        missionsArr[jm] = strmission;
        jm++;
    }
    inFile3.close();


    int countdests = 0;
    ifstream inFile4;
    inFile4.open(ClassReading::dests);//"commands3.txt""dests2.txt"
    int jd = 0;
    if (!inFile4) {
    }
    string strdests;
    while (getline(inFile4, strdests)) {//in there saving number of lines
        countdests++;
    }
    inFile4.close();

    inFile4.open(ClassReading::dests);
    string destsArr[countdests + 1];

    while (getline(inFile4, strdests)) {//after saving an array
        destsArr[jd] = strdests;
        jd++;
    }
    inFile4.close();

    t2.pushInitialTruck(countdests, destsArr, counttruck, truckarr, missionsArr,countmissions);  //first insert inital truck situations
    t2.pushinitialPackage( countpackage, packarr, countdests, destsArr); //first insert inital package situations
    writeline(countdests, destsArr, missionsArr, countmissions);

    myFile.close();
}

void ClassReading::writeline(int countdests,string destsArr[],string missionsArr[],int countmissions) {
    for (int x = 0; x < countmissions; x++) {   //returning as many lines of missions.txt
        vector<string> result;
        string linestr = missionsArr[x];
        stringstream ss(linestr);  //converting string
        while (ss.good()) {   //using vector for spliting
            string substr;
            getline(ss, substr, '-');
            result.push_back(substr);
        }
        stringstream ss1(result.at(3));
        ss1 << result.at(3);
        int pack1,pack;
        ss1 >> pack1;
        stringstream ss2(result.at(4)); //take number of package (pack and pack1)
        ss2 << result.at(4);
        ss2 >> pack;
        string midway =result.at(5);  //for midway station

        int cityT1;
        int cityT3;
        for (int y = 0; y < countdests; y++) {
            if (destsArr[y].find(result.at(2)) < destsArr[y].length()) {
                cityT3 = y;
            }
            if (destsArr[y].find(result.at(0)) < destsArr[y].length()) {//taking city index for trucks
                cityT1 = y;
            }
        }
        int city1;  int city2;  int city3;
        for (int y = 0; y < countdests; y++) {
            if (destsArr[y].find(result.at(0)) < destsArr[y].length()) {
                city1 = y;
            }
            if (destsArr[y].find(result.at(1)) < destsArr[y].length()) {  //taking city index for packages
                city2 = y;
            }
            if (destsArr[y].find(result.at(2)) < destsArr[y].length()) {
                city3 = y;
            }
        }
        t2.appendTruckinStation(cityT1,countdests);
        t2.pushandAfterMission(pack1,city1,pack,city2);
        t2.leavePackagesAtMidway(midway,city2,result,city3); //leave packages from trucks to midway
        t2.pushLastTruck(destsArr,countdests,cityT3); //after missions last situations

    }
    t2.display( destsArr, countdests);
}
