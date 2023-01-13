#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
using namespace std;
class CaesarCipher
{
    public:
        string strLine;
        CaesarCipher(string initLineint );
        string CaesarEncrypt(string str, int  shift);
        string generateKey(string str, string key);
        string VingenereEncrypt(string str, string key);
        string VingenereDecrypt(string str, string key);
};

#endif