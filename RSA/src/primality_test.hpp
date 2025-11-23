#include<cryptopp/integer.h>
#include<vector>
#include "bbs_generator.hpp"

class Pascal_criterion{
private:
    int base = 256;
    int primes[8] = {3, 5, 7, 11, 13, 17, 19, 23};
    std::vector<uint8_t> b_matrix[8] = {{1}, {1}, {1, 4, 2}, {1, 3, 9, 5, 4}, {1, 9, 3}, {1}, {1, 9, 5, 7, 6, 16, 11, 4, 17}, {1, 3, 9, 4, 12, 13, 16, 2, 6, 18, 8}};

public:
    bool test(CryptoPP::Integer in);
};

class Miller_Rabin_test{
private:
    int precision = 16;

public:
    //Pr(err) = 1/2^(2pr)
    void set_precision(int pr);

    bool test(CryptoPP::Integer in);    
};

class primality_test{
private:
    Pascal_criterion PC;
    Miller_Rabin_test MRT;

public:
    bool test(CryptoPP::Integer in);
};