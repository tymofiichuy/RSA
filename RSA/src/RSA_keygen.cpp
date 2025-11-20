#include "RSA.hpp"

void secret_key::reset(){p=0;q=0;d=0;}
void public_key::reset(){n=0;e=0;}

bool RSA::set_security_par(int par){
    if((par<=0)||(par%8!=0)){
        return false;
    }
    else{
        enc_sk.reset();
        enc_pk.reset();
        enc_eu_func = 0;

        sign_sk.reset();
        sign_pk.reset();
        enc_eu_func = 0;

        security_par = par;
    }
}