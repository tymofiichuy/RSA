#pragma once

#include<cryptopp/integer.h>
#include<random>

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
    //len in bits!
    CryptoPP::Integer gen_num(int len);

    BBS_generator(CryptoPP::Integer s, bool b);
};

