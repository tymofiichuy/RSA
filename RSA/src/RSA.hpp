#include "bbs_generator.hpp"
#include "primality_test.hpp"
#include "string"

struct secret_key{
    CryptoPP::Integer p, q, d;
    void reset();
};

struct public_key{
    CryptoPP::Integer n, e;
    void reset();
};

class RSA{
private:
    secret_key enc_sk;
    public_key enc_pk;
    CryptoPP::Integer enc_eu_func;

    secret_key sign_sk;
    public_key sign_pk;
    CryptoPP::Integer sign_eu_func;

    //p size
    int security_par = 1024;

public:
    bool initialized = false;

    bool set_security_par(int par);
    bool keygen();
    //bool load_key(std::string file);

    public_key get_encryption_public_key();
    public_key get_signature_public_key();

    CryptoPP::Integer encrypt(CryptoPP::Integer message, public_key r_pk);
    CryptoPP::Integer decrypt(CryptoPP::Integer ciphertext);

    CryptoPP::Integer sign(CryptoPP::Integer message);
    bool verify(CryptoPP::Integer message, CryptoPP::Integer signature, public_key s_pk);

    RSA();
    ~RSA();
};