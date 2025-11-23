#include "primality_test.hpp"

using namespace std;
using namespace CryptoPP;

bool Pascal_criterion::test(Integer in){
    if(in.IsEven()){
        return false;
    }
    else{
        int len = in.ByteCount();
        uint64_t sum;
        for(int i = 0; i < 8; i++){
            sum = 0;
            for(int j = 0; j < len; j++){
                sum += in.GetByte(j)*b_matrix[i][j%b_matrix[i].size()];
            }
            if(sum%primes[i]==0){
                return false;
            }
        }
    }
    return true;
}

void Miller_Rabin_test::set_precision(int pr){
    if(pr<0){
        throw runtime_error("invalid precision");
    }
    precision = pr;
}

bool Miller_Rabin_test::test(Integer in){
    BBS_generator gen(0, false);

    int pow = 0, counter = 0;
    Integer base, cp = in, temp;

    cp--;
    while(cp.IsEven()){
        pow++;
        cp /= 2;
    }

    //k = 64?
    while(counter < precision){
        do {base = gen.gen_num(in.ByteCount()*8);}while(base < 2 || base >= in - 1);

        if(Integer::Gcd(in, base) != Integer::One()){
            return false;
        }

        temp = a_exp_b_mod_c(base, cp, in);
        if((temp == Integer::One())||(temp == (in-Integer::One()))){
            counter++;
            continue;
        }
        
        for(int r = 1; r < pow; r++){
            temp = a_exp_b_mod_c(temp, Integer::Two(), in);
            if(temp == (in-Integer::One())){
                counter++;
                break;
            }
            else if(temp == Integer::One()){
                return false;
            }
        }
        return false;
    }
    return true;
}

bool primality_test::test(CryptoPP::Integer in){
    if(!PC.test(in)){
        return false;
    }
    return MRT.test(in);
}