#include "primality_test.hpp"

using namespace std;
using namespace CryptoPP;

int main(){
    primality_test PT;
    // BBS_generator gen(0, false);
    // Integer num = gen.gen_num(128);
    Integer num("767377738997279121624757319");

    cout << "number: " << num << "\nprime: " << PT.test(num);
    return 0;
}