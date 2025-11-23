#include "RSA.hpp"

using namespace std;
using namespace CryptoPP;

Integer RSA::sign(Integer message){
if(!initialized){
    throw runtime_error("uninitialized key");
}

return a_exp_b_mod_c(message, sign_sk.d, sign_pk.n);
}

bool RSA::verify(Integer message, Integer signature, public_key s_pk){
    if(signature >= s_pk.n){
        throw runtime_error("invalid signature");
    }

    Integer rec = a_exp_b_mod_c(signature, s_pk.e, s_pk.n);
    return (message == rec);
}