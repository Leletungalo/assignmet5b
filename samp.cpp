#include <iostream>
#include <string>
#include "audio.h"
#include <vector>
#include <cstdint>

using namespace std;

int main(int argc, char const *agrv[]){
    if(argc < 11){
        cout << "input command not correct" << endl;
    }else{
        int sampleRate = stoi(string(agrv[2]));
        int bitCount = stoi(string(agrv[4]));
        int noChanels = stoi(string(agrv[6]));
        NGLLEL001::audio leg(sampleRate,bitCount,noChanels,string(agrv[10]),string(agrv[11]),string(agrv[8]));
        NGLLEL001::audio leg2(sampleRate,bitCount,noChanels,string(agrv[10]),string(agrv[11]),string(agrv[8]));

        leg.readFile(string(agrv[10]));
        leg2.readFile(string(agrv[11]));

        auto b = leg + leg2;

        b.writeToFile(string(agrv[8]),b.data_vector);
        cout << "tad" << endl;
    }
    


    return 0;
}
