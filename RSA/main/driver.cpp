#include "RSA.hpp"

using namespace std;
using namespace CryptoPP;

int main(){
    RSA cipher;
    cipher.keygen();
    cout << "Public encryption key: " << hex << cipher.get_encryption_public_key().n << "\n" << "Public signing key: " << cipher.get_signature_public_key().n << "\n\n";

    BBS_generator gen(0,false);
    Integer M, M_e, M_d, S_s, S_v;
    public_key r_pk;

    M = gen.gen_num(512);

    string temp1, temp2;

    cin >> temp1;
    r_pk.n = Integer(temp1.c_str());
    r_pk.e = Integer("0x10001");

    M_e = cipher.encrypt(M, r_pk);
    cout << "Message: " << M << "\nCiphertext: " << M_e << "\n\n";

    cin >> temp1;
    M_e = Integer(temp1.c_str());
    M_d = cipher.decrypt(M_e);
    cout << "Ciphertext: " << M_e << "\nMessage: " << M_d << "\n\n";



    S_s = cipher.sign(M);
    cout << "Message: " << M << "\nSignature: " << S_s << "\n\n";

    cin >> temp1;
    S_v = Integer(temp1.c_str());
    cin >> temp2;
    M_e = Integer(temp2.c_str());
    cout << "Message: " << M << "\nSignature: " << S_s << "\nVerified: " << cipher.verify(M_e, S_v, r_pk) << "\n\n";

    return 0;
}