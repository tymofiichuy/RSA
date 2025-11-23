#include<cryptopp/integer.h>

class BBS_generator{
private:
    CryptoPP::Integer seed;
    CryptoPP::Integer state;
    bool byte = true;

    uint8_t clock();    
    
    CryptoPP::Integer mod;
public:
    void set_seed(CryptoPP::Integer s);
    void change_mode();

    //len in bits!
    CryptoPP::Integer gen_num(int len);

    BBS_generator(CryptoPP::Integer s, bool b);
};

