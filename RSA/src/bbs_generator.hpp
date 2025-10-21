#include<cryptopp/integer.h>

class BBS_generator{
private:
    CryptoPP::Integer seed;
    CryptoPP::Integer state;
    bool byte = true;
    
    CryptoPP::Integer mod;
public:
    void set_seed(CryptoPP::Integer s);
    void change_mode();
    uint8_t clock();

    BBS_generator(CryptoPP::Integer s, bool b);
};