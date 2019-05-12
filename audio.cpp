#include "audio.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

NGLLEL001::audio::audio(int sampleRate,int bitCount,int noChanels,std::string inPutFile,std::string secondFile,std::string outPutFile):sampleRate(sampleRate),bitCount(bitCount),noChanels(noChanels),inPutFile(inPutFile),secondFile(secondFile),outPutFile(outPutFile){

}

NGLLEL001::audio NGLLEL001::audio::operator+(NGLLEL001::audio rhs){
    NGLLEL001::audio newFile(sampleRate,bitCount,noChanels,inPutFile,secondFile,outPutFile);
    cout << "jhgftgh test 1" << endl;
    for (auto i = data_vector.begin(); i != data_vector.end(); i++){
        auto rhsElement = rhs.data_vector.begin();
        newFile.data_vector.push_back(*i + *rhsElement);
        rhsElement++;
    }
    cout << "jhgftgh test 2" << endl;
    return newFile;
}

void NGLLEL001::audio::readFile(string fileName){
    ifstream file(fileName.c_str(), ios::binary | ios::in);
    string bit = "";

    while (getline(file,bit)){
        int a;
        char x[bit.size() +1];
        strcpy(x,bit.c_str());
        stringstream s(x);
        s >> a;
        data_vector.push_back(a);
    }
    file.close();
    


}

vector<int> NGLLEL001::audio::data_vector(){
    return data_vector;
}

 void NGLLEL001::audio::writeToFile(string out,vector<int> vec){
    ofstream file(out.c_str(),ios::out);

    for (auto i = vec.begin(); i != vec.end(); i++){
        cout << *i << endl;
        file << *i;
    }
 //   file.close;

}

NGLLEL001::audio::~audio(){}


