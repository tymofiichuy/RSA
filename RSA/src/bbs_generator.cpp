#include "bbs_generator.hpp"

using namespace std;
using namespace CryptoPP;


BBS_generator::BBS_generator(Integer s, bool b):byte(b),
                                                mod("0x37682f6947aaab110517c20b76df64781da78b3e87eb58379085d3395793bdb9d9"){
    if((s>mod)||(s==Integer::Zero())){
        random_device rd;
        seed = rd();
    }
    else{
        seed = s;
    }
    state = seed;
}

void BBS_generator::set_seed(Integer s){
    if(s>mod){
        seed = 2;
        cerr << "Unable to set the seed, default one will be used";
    }
    else{
        seed = s;
    }
    state = seed;
}

void BBS_generator::change_mode(){
    byte = !byte;
}

uint8_t BBS_generator::clock(){
    if(byte){
        state = a_exp_b_mod_c(state, Integer::Two(), mod);
        return state.GetByte(0);
    }
    else{
        uint8_t res = 0;
        for(int i = 7; i >= 0; i--){
            state = a_exp_b_mod_c(state, Integer::Two(), mod);
            res ^= (state.GetBit(0))<<i;
        }
        return res;
    }
}

Integer BBS_generator::gen_num(int len){
    if((len<=0)||(len%8!=0)){
        throw runtime_error("invalid length");
    }
    int b_len = len/8; 
    Integer num;
    for(int i = 0; i < b_len; i++){
        num.SetByte(i, clock());
    }
    return num;
}