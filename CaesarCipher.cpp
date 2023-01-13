#include <string>
#include "CaesarCipher.h"

using namespace std;
 CaesarCipher::CaesarCipher(string initLine)
 {
     strLine = initLine;
 }

 string CaesarCipher::CaesarEncrypt(string str, int  shift)
 {
     string encrypt;
     for (int i = 0; i <= str.size() - 1; ++i)
     {
         char a, b;
         int x;
         a = str[i];
         x = (int)a;
         if (x == 32)
         {
             encrypt += x;
             continue; // ignore space
         }
         else if (x >= 65 && x <= 90) // A to Z
         {
             x += shift;
             if (x > 90)
             {
                 b = x - 26;
             }
             else if (x < 65)
             {
                 b = x + 26;
             }
             else
             {
                 b = x;
             }

             encrypt += b;
         }
         else if (x >= 97 && x <= 122) // a  to z
         {
             x += shift;
             if (x > 122)
             {
                 b = x - 26;
             }
             else if (x < 97)
             {
                 b = x + 26;
             }
             else
             {
                 b = x;
             }

             encrypt += b;
         }
         else
         {
             // in case character not being between A-Z and a-z
             encrypt += x ;
         }
     }
     return encrypt;
 }

 string CaesarCipher::generateKey(string str, string key)
 {
     int x = str.size();

     for (int i = 0; i < x; i++)
     {
         if (x == i)
             i = 0;
         if (key.size() == str.size())
             break;
         key.push_back(key[i]);
     }
     return key;
 }

 string CaesarCipher::VingenereEncrypt(string str, string key)
 {
     string encrypt;
     string newKey;
     newKey = generateKey(str, key);
     for (int i = 0; i < str.size(); i++)
     {
         char x = str[i];
         // converting in range 0-25
         if (isupper(str[i]))
         {
             x = (str[i] - 'A' + newKey[i] - 'A') % 26;
             x += 'A';
         }
         else if (islower(str[i]))
         {
             x = (str[i] - 'a' + newKey[i] - 'A') % 26;
             x += 'a';
         }

         // convert into alphabets(ASCII)
         

         encrypt.push_back(x);
     }
     return encrypt;
 }

 string CaesarCipher::VingenereDecrypt(string str, string key)
 {
     string decrypt;
     string newKey;
     newKey = generateKey(str, key);
     for (int i = 0; i < str.size(); i++)
     {
         // converting in range 0-25
         //char x = (str[i] - newKey[i] + 26) % 26;

         char x = str[i];
         // converting in range 0-25
         if (isupper(str[i]))
         {
             x = (str[i] - 'A' - newKey[i] + 'A' + 26) % 26;
             x += 'A';
         }
         else if (islower(str[i]))
         {
             x = (str[i] - 'a' - newKey[i] + 'A' + 26) % 26;
             x += 'a';
         }


         // convert into alphabets(ASCII)
         //x += 'A';
         decrypt.push_back(x);
     }
     return decrypt;
 }


 