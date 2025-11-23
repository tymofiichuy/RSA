#include "RSA.hpp"

using namespace std;
using namespace CryptoPP;

Integer RSA::encrypt(Integer message, public_key r_pk){
    if(!initialized){
        throw runtime_error("uninitialized key");
    }

    return a_exp_b_mod_c(message, r_pk.e, r_pk.n);
}

Integer RSA::decrypt(Integer ciphertext){
    if(!initialized){
        throw runtime_error("uninitialized key");
    }
    else if(ciphertext >= enc_pk.n){
        throw runtime_error("invalid ciphertext");
    }

    return a_exp_b_mod_c(ciphertext, enc_sk.d, enc_pk.n);
}