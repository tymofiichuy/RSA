#pragma once

#include "RSA.hpp"
#include<cryptopp/sha3.h>
#include<iostream>

class client_model{
private:
    RSA cipher;
    CryptoPP::SHA3_256 hash_f;

public:
    public_key get_enc_pk();
    public_key get_sign_pk();

    message send_message(CryptoPP::Integer msg, public_key r_pk);
    CryptoPP::Integer recieve_message(message msg);

    client_model();
};