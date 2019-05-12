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

        newFile.data_vector.push_back(*i - *rhsElement);
        rhsElement++;
    }
    cout << "jhgftgh test 2" << endl;
    return newFile;
}

void NGLLEL001::audio::readFile(string fileName){
    ifstream file(fileName.c_str(), ios::binary | ios::in);
    
    file.seekg(0, file.end);
    int fileSize = file.tellg();
    file.seekg(0, file.beg);

    int NumOfSamples = fileSize / (sizeof(int8_t) * noChanels);
    int8_t hoho;
    char ogo[sizeof(int8_t)];
    while(file){
        file.read(ogo,sizeof(int8_t));
        stringstream s(ogo);
        s >> hoho;
        data_vector.push_back(hoho);
    }
    
    /*
    string bit = "";
    
    while (getline(file,bit)){
        int a;
        char x[bit.size() +1];
        strcpy(x,bit.c_str());
       // cout << x << endl;
        stringstream s(x);
        s >> a;
        cout << a << endl;
        data_vector.push_back(a);
    }*/
    file.close();
}
/*
vector<int8_t> NGLLEL001::audio::getVec(){
    return data_vector;
}*/

 void NGLLEL001::audio::writeToFile(string out,NGLLEL001::audio vec){
    ofstream file(out.c_str(),ios::out);

    for (auto i = vec.data_vector.begin(); i != vec.data_vector.end(); i++){
       // cout << *i << endl;
        file << (char) *i ;
    }
 //   file.close;
 }



NGLLEL001::audio::~audio(){}


