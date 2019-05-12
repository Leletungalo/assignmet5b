#include "audio.h"
#include "iostream"
using namespace std;

NGLLEL001::audio::audio(int sampleRate,int bitCount,int noChanels,std::string inPutFile,std::string outPutFile):sampleRate(sampleRate),bitCount(bitCount),noChanels(noChanels),inPutFile(inPutFile),outPutFile(outPutFile){
    
}

NGLLEL001::audio::~audio(){}

NGLLEL001::audio NGLLEL001::audio::operator+(NGLLEL001::audio rhs){
    
    return rhs;
}