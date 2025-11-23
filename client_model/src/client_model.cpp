#include "client_model.hpp"

using namespace std;
using namespace CryptoPP;

client_model::client_model(){
    cipher.keygen();
}

public_key client_model::get_enc_pk(){
    return cipher.get_encryption_public_key();
}

public_key client_model::get_sign_pk(){
    return cipher.get_signature_public_key();
}

message client_model::send_message(Integer msg, public_key r_pk){
    message s_msg;
    s_msg.sender_enc = get_enc_pk();
    s_msg.sender_sign = get_sign_pk();

    s_msg.msg = cipher.encrypt(msg, r_pk);

    uint8_t byte;
    hash_f.Restart();
    for(int i = 0; i < static_cast<int>(msg.ByteCount()); i++){
        byte = msg.GetByte(i);
        hash_f.Update(&byte, 1);
    }
    uint8_t digest[SHA3_256::DIGESTSIZE];
    hash_f.Final(digest);
    s_msg.sgn = cipher.sign(Integer(digest,SHA3_256::DIGESTSIZE));

    return s_msg;
}

Integer client_model::recieve_message(message msg){
    Integer r_msg = cipher.decrypt(msg.msg), rec_sign;

    uint8_t byte;
    hash_f.Restart();
    for(int i = 0; i < static_cast<int>(r_msg.ByteCount()); i++){
        byte = r_msg.GetByte(i);
        hash_f.Update(&byte, 1);
    }
    uint8_t digest[SHA3_256::DIGESTSIZE];
    hash_f.Final(digest);
    rec_sign = Integer(digest,SHA3_256::DIGESTSIZE);

    if(cipher.verify(rec_sign, msg.sgn, msg.sender_sign)){
        cout << "Successfully verified\n";
    }
    else{
        cout << "Verification failed\n";
    }
    return r_msg;
}