#include <iostream>
#include <string>
#include "audio.h"
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char const *agrv[]){
    if(argc < 11){
        cout << "input command not correct" << endl;
    }else{
        int sampleRate = stoi(string(agrv[2]));
        int bitCount = stoi(string(agrv[4]));
        int noChanels = stoi(string(agrv[6]));
        
        if (string(agrv[9]) == "-add"){
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            NGLLEL001::audio<int8_t> file2(sampleRate,bitCount,noChanels,string(agrv[8]));

            file1.readFile(string(agrv[10]));
            file2.readFile(string(agrv[11]));

            auto outPut = file1 + file1;
            outPut.writeToFile(string(agrv[8]),outPut);
        }else if (string(agrv[9]) == "-cut"){
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            file1.readFile(string(agrv[12]));
            pair<int,int> range;
            int a,b;
            stringstream ss(agrv[10]);
            ss >> a;
            stringstream is(agrv[11]);
            is >> b;
            range.first = a;
            range.second = b;

            auto outPut = file1 ^ range;
            outPut.writeToFile(string(agrv[8]),outPut);
            
        }else if (string(agrv[9]) == "-radd"){
             int r1,r2;
            stringstream ss(agrv[10]);
            ss >> r1;
            ss.str(" ");
            ss.clear();
            ss << agrv[11];
            ss >> r2;
            
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            NGLLEL001::audio<int8_t> file2(sampleRate,bitCount,noChanels,string(agrv[8]));
            file1.readFile(string(agrv[12]));
            file2.readFile(string(agrv[13]));
            pair<int,int> p;
            p.first = r1;
            p.second = r2;
            auto outPut = file1.radd(file2, p);
            outPut.writeToFile(string(agrv[8]),outPut);
        }else if (string(agrv[9]) == "-cat"){
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            NGLLEL001::audio<int8_t> file2(sampleRate,bitCount,noChanels,string(agrv[8]));

            file1.readFile(string(agrv[10]));
            file2.readFile(string(agrv[11]));

            auto outPut = file1 | file2;
            outPut.writeToFile(string(agrv[8]),outPut);
        }else if (string(agrv[9]) == "-v"){
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            file1.readFile(string(agrv[12]));
            pair<float,float> range;
            int a,b;
            stringstream ss(agrv[10]);
            ss >> a;
            stringstream is(agrv[11]);
            is >> b;
            range.first = a;
            range.second = b;
            if (noChanels == 1){
                auto outPut = file1 * range;
                outPut.writeToFile(string(agrv[8]),outPut);
            }
        }else if (string(agrv[9]) == "-rev"){
            NGLLEL001::audio<int8_t> file1(sampleRate,bitCount,noChanels,string(agrv[8]));
            file1.readFile(string(agrv[10]));
            file1.reverse();
            file1.writeToFile(string(agrv[8]),file1);
        }else if (string(agrv[9]) == "-rms"){
           
        }else if (string(agrv[9]) == "-norm"){
            
        }
    }
    return 0;
}