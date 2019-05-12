#ifndef _audio
#define _audio
#include <istream>

namespace NGLLEL001{
   // template <typename T>
    class audio{
    private:
        int sampleRate;
        int bitCount;
        int noChanels;
        std::string inPutFile, outPutFile;
        
    public:
        audio(int sampleRate,int bitCount,int noChanels,std::string inPutFile,std::string outPutFile);
        audio operator+(audio rhs);
        ~audio();
    };
}

#endif