#ifndef _audio
#define _audio

#include <fstream>
#include <ostream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <numeric>
#include <sstream>

namespace NGLLEL001{
    using namespace std;
    template <typename T>
    class audio{
    private:
        int sampleRate;
        int bitCount;
        int noChanels;
        int lengthOfFile;
        float NumOfSamples;
        std::string outPutFile;
        std::vector<T> data_vector;
        
    public:
        
        audio<T>(int sampleRate,int leagth,int noChanels, std::string outPutFile):sampleRate(sampleRate),lengthOfFile(leagth),noChanels(noChanels),outPutFile(outPutFile){}
        void setVec(std::vector<T> vec){
            this->data_vector = vec;
        }

        audio(const audio& rhs):sampleRate(rhs.sampleRate),bitCount(rhs.bitCount),noChanels(rhs.noChanels),lengthOfFile(rhs.lengthOfFile),NumOfSamples(rhs.NumOfSamples),outPutFile(rhs.outPutFile),data_vector(rhs.data_vector){}
        
        audio(audio&& rhs):sampleRate(rhs.sampleRate),bitCount(rhs.bitCount),noChanels(rhs.noChanels),lengthOfFile(rhs.lengthOfFile),NumOfSamples(rhs.NumOfSamples),outPutFile(rhs.outPutFile),data_vector(rhs.data_vector){
        sampleRate = bitCount = noChanels = lengthOfFile = NumOfSamples = -1;
        data_vector.clear();
        }

        audio<T> operator+(audio<T> rhs){
            NGLLEL001::audio<T> newFile(sampleRate,bitCount,noChanels,outPutFile);
            
            for (auto i = this->data_vector.begin(); i != this->data_vector.end(); i++){
            auto rhsElement = rhs.data_vector.begin();
            int sum =  *i + *rhsElement;
        
            if(sum > numeric_limits<T>::max()){
                sum = numeric_limits<T>::max();
            }
            newFile.data_vector.push_back(sum);
            rhsElement++;
            }
            return newFile; 
        }
        audio operator|(audio rhs){
            for (auto i = rhs.data_vector.begin(); i != rhs.data_vector.end(); i++){
                data_vector.push_back(*i);
            }
            return *this;
        }
        audio operator*(std::pair<float,float> rhs){
            if (noChanels == 1){
                vector<T> tempVec;
                for (auto i = data_vector.begin(); i != data_vector.end(); i++) {
                    int temp = *i * rhs.first;
                    tempVec.push_back(temp);
                }
                data_vector.clear();
                this->setVec(tempVec);
            }
            return *this;
            
        }
        audio operator^(std::pair<int,int> rhs){
            int range = rhs.second - rhs.first;
            int newSamele = NumOfSamples - range - 1;
            int newLen = (int) (newSamele / (float) sampleRate);

            vector<T> tempVec;
            for (auto i = data_vector.begin(); i < data_vector.end(); i++){
                if (*i <= rhs.first || *i >= rhs.second ){
                   tempVec.push_back(*i);
                }
            }

            audio<T> tempAudio(newSamele,newLen,noChanels,outPutFile);
            tempAudio.setVec(tempVec);
            return tempAudio;
        }

        void reverse(){
            std::reverse(data_vector.begin(),data_vector.end());
        }

        audio radd(const audio& rhs, pair<int,int> p){
            audio range1(*this);
            audio range2(*this);
            range1.data_vector.clear();
            range2.data_vector.clear();
            range1.data_vector.resize(p.second - p.first);
            range2.data_vector.resize(p.second - p.first);

            std::copy(this->data_vector.begin() + p.first, this->data_vector.begin() + p.second, range1.data_vector.begin());
            std::copy(rhs.data_vector.begin() + p.first, rhs.data_vector.begin() + p.second, range2.data_vector.begin());
            
            return range1 + range2;
        }

        float RMS(){
            float caculated = accumulate(data_vector.begin(),data_vector.end(),0.0, 
                                [](float total,const T& element){
                                    return (total + (pow(element,2)));
                                });

            caculated = (float) sqrt(caculated / ((float) NumOfSamples));
            return caculated;
        }
        
        void readFile(std::string fileName){
            std::ifstream file(fileName, std::ios::binary | std::ios::in);
            
            file.seekg(0, file.end);
            int fileSize = file.tellg();
            file.seekg(0, file.beg);

            NumOfSamples = fileSize / (sizeof(T) * noChanels);
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
        std::vector<T> getVec();
        void writeToFile(std::string out,audio vec){
            ofstream file(out.c_str(),ios::out);
            for (auto i = vec.data_vector.begin(); i != vec.data_vector.end(); i++){
                file << (char) *i;
            }
        }
        ~audio(){}
    };
}
#endif