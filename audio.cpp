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

    for (auto i = data_vector.begin(); i != data_vector.end(); i++){
        cout << *i << endl;
        auto rhsElement = rhs.data_vector.begin();
        newFile.data_vector.push_back(*i + *rhsElement);
        rhsElement++;
    }
    return newFile;
}

NGLLEL001::audio NGLLEL001::audio::operator|(NGLLEL001::audio rhs){
    for (auto i = rhs.data_vector.begin(); i != rhs.data_vector.end(); i++){
        data_vector.push_back(*i);
    }
    return *this;
}

void NGLLEL001::audio::readFile(string fileName){
    ifstream file(fileName.c_str(), ios::binary | ios::in);
    
    file.seekg(0, file.end);
    int fileSize = file.tellg();
    file.seekg(0, file.beg);

    NumOfSamples = fileSize / (sizeof(int8_t) * noChanels);
    lengthOfFile = NumOfSamples / (float) sampleRate;
    int8_t hoho;
    char ogo[sizeof(int8_t)];
    while(file){
        file.read(ogo,sizeof(int8_t));
        stringstream s(ogo);
        s >> hoho;
        data_vector.push_back(hoho);
    }
    file.close();
}

 void NGLLEL001::audio::writeToFile(string out,NGLLEL001::audio vec){
    ofstream file(out.c_str(),ios::out);

    for (auto i = vec.data_vector.begin(); i != vec.data_vector.end(); i++){
        file << (char) *i ;
    }
 }



NGLLEL001::audio::~audio(){}


