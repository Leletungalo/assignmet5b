#ifndef _audio
#define _audio
#include <istream>
#include <vector>


namespace NGLLEL001{
   // template <typename T>
    class audio{
    private:
        int sampleRate;
        int bitCount;
        int noChanels;
        int lengthOfFile;
        float NumOfSamples;
        std::string inPutFile,secondFile, outPutFile;
        
        
    public:
        audio(int sampleRate,int bitCount,int noChanels,std::string inPutFile,std::string secondFile,std::string outPutFile);
        audio operator+(audio rhs);
        audio operator|(audio rhs);
        audio operator*(std::pair<int,int> rhs);
        audio operator^(std::pair<int,int> rhs);
        std::vector<uint8_t> data_vector;
        void readFile(std::string fileName);
        std::vector<int8_t> getVec();
        void writeToFile(std::string out,audio vec);
        ~audio();
    };
}

#endif