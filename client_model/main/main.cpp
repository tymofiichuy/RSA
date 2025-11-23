#include "client_model.hpp"

using namespace std;
using namespace CryptoPP;

int main(){
    BBS_generator gen(0,false);
    Integer M = gen.gen_num(512), r_M;

    client_model Alice, Bob;
    cout << "Clients initialized\n";
    message msg = Alice.send_message(M, Bob.get_enc_pk());
    cout << "Message sent\n";
    r_M = Bob.recieve_message(msg);
    cout << std::hex << "Original message: " << M << "\nRecieved message: " << r_M << "\nSuccessfully recieved: " << (M==r_M) << "\n";

    return 0;
}