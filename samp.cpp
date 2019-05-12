#include <iostream>
#include <string>
#include "audio.h"

using namespace std;

int main(int argc, char const *agrv[]){
    if(argc < 11){
        cout << "input command not correct" << endl;
    }else{
        int sampleRate = stoi(string(agrv[2]));
        int bitCount = stoi(string(agrv[4]));
        int noChanels = stoi(string(agrv[6]));
        
    }
    


    return 0;
}
