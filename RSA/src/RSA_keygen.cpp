#include "RSA.hpp"

using namespace std;
using namespace CryptoPP;

void secret_key::reset(){p=0;q=0;d=0;}
void public_key::reset(){n=0;e=0;}

bool RSA::set_security_par(int par){
    if((par<=0)||(par%8!=0)){
        return false;
    }
    else{
        initialized = false;

        enc_sk.reset();
        enc_pk.reset();
        enc_eu_func = 0;

        sign_sk.reset();
        sign_pk.reset();
        enc_eu_func = 0;

        security_par = par;
        return true;
    }
}

Integer RSA::find_prime(){
    BBS_generator gen(0,false);
    primality_test PT;
    Integer num;


    while(true){
        num = gen.gen_num(security_par);
        if(num.IsEven()){
            num++;
        }
        while(static_cast<int>(num.BitCount())<=security_par){
            if(PT.test(num)){
                return num;
            }
            num += Integer::Two();
        }
    }
}

bool RSA::keygen(){
    enc_sk.reset();
    enc_pk.reset();

    enc_pk.e = Integer("0xFFFF");
    while(enc_sk.d == Integer::Zero()){
        enc_sk.p = find_prime();
        enc_sk.q = find_prime();
        if(enc_sk.q == enc_sk.p){
            continue;
        }        
        enc_pk.n = enc_sk.p*enc_sk.q;
        enc_eu_func = (enc_sk.p-Integer::One())*(enc_sk.q-Integer::One());
        enc_sk.d = enc_pk.e.InverseMod(enc_eu_func);       
    }

    sign_sk.reset();
    sign_pk.reset();

    sign_pk.e = Integer("0xFFFF");
    while(sign_sk.d == Integer::Zero()){
        sign_sk.p = find_prime();
        sign_sk.q = find_prime();
        if(sign_sk.q == sign_sk.p){
            continue;
        }        
        sign_pk.n = sign_sk.p*sign_sk.q;
        sign_eu_func = (sign_sk.p-Integer::One())*(sign_sk.q-Integer::One());
        sign_sk.d = sign_pk.e.InverseMod(sign_eu_func);       
    }

    initialized = true;
    return true;
}

public_key RSA::get_encryption_public_key(){
    return enc_pk;
}

public_key RSA::get_signature_public_key(){
    return sign_pk;
}