
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include "CaesarCipher.h"

using namespace std;


void readFile(string fileName, vector<CaesarCipher>& listOfLine)
{
	ifstream ifs;
	string newFile = "D:/" + fileName + ".txt";
	ifs.open(newFile);

	if (!ifs.is_open()) {
		cout << "Could not open file numFile.txt." << endl;
		return; // indicates error
	}
	string line;
	getline(ifs, line);
	int i = 0;
	while (!ifs.eof() || !ifs.fail())
	{
		CaesarCipher* cipher = new CaesarCipher(line);
		listOfLine.push_back(*cipher);
		getline(ifs, line);
	}
	ifs.close();
}

void encryptFile(string fileName, vector<CaesarCipher> listOfLine, string prefix, int shift)
{
	ofstream ofs;

	//string newFile = "D:/" + prefix + '_' + fileName + ".txt";

	//string newFile = "";
	//newFile += "D:/" + prefix + '_' + fileName + ".txt";

	string newFile = "D:/";
	newFile += prefix;
	newFile += '_';
	newFile += fileName + ".txt";
	bool isEncrypt = true;
	ofs.open(newFile, ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "Could not open file " << fileName << endl;
		isEncrypt = false;
		return; // indicates error

	}
	for (int i = 0; i < listOfLine.size(); ++i)
	{
		string lineEncry;
		lineEncry = listOfLine.at(i).CaesarEncrypt(listOfLine.at(i).strLine, shift);
		ofs << lineEncry << endl;
	}
	ofs.close();
	if (isEncrypt)
		cout << "File: " << newFile << " has been written. Let's see the result. " << endl;
}

void vigenereEncryptFile(string fileName, vector<CaesarCipher> listOfLine, string key, string prefix, bool isEncrypt)
{
	ofstream ofs;

	string newFile = "D:/";
	newFile += prefix;
	newFile += '_';
	newFile += fileName + ".txt";
	bool isSuccessEncrypt = true;
	ofs.open(newFile, ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "Could not open file " << fileName << endl;
		isSuccessEncrypt = false;
		return; // indicates error

	}
	for (int i = 0; i < listOfLine.size(); ++i)
	{
		string lineEncry;
		if (isEncrypt)
		{
			lineEncry = listOfLine.at(i).VingenereEncrypt(listOfLine.at(i).strLine, key);
		}
		else
		{
			lineEncry = listOfLine.at(i).VingenereDecrypt(listOfLine.at(i).strLine, key);
		}
		
		ofs << lineEncry << endl;
	}
	ofs.close();
	if (isSuccessEncrypt)
		cout << "File: " << newFile << " has been written. Let's see the result. " << endl;
}


void doEncrypt()
{
	ifstream ifs;
	ofstream ofs;
	int shift;
	string prefix;
	string filename, var, encrypt;

	vector<CaesarCipher> listOfLine;
	cout << "You are encrypting/decrypting a file. Please follow the instructions. " << endl;
	cout << "Enter the Name of file input: " << endl;
	cin >> filename;
	cout << "Enter name prefix for output file: " << endl;
	cin >> prefix;
	while (prefix.length() > 1)
	{
		cout << "You input wrong prefix with more than 1 character. Please do it again! " << endl;
		cin >> prefix;
	}
	readFile(filename, listOfLine);

	int chooseTypeCipher;
	cout << "Choose type cipher: 1 - Caesar Cipher | 2 - Vigenère cipher " << endl;
	cin >> chooseTypeCipher;
	if (chooseTypeCipher == 1)
	{
		cout << "Enter the value of shift: " << endl;
		cin >> shift;			
		encryptFile(filename, listOfLine, prefix, shift);
	}
	else if (chooseTypeCipher == 2)
	{
		string keyWord;
		cout << "Enter the string keyword for cipher: " << endl;
		cin >> keyWord;
		int keyType;
		cout << "Would you like encrypt or decrypt the file ? ( 1:encrypt || 2: decrypt) " << endl;
		cin >> keyType;
		if (keyType == 1)
		{
			vigenereEncryptFile(filename,listOfLine,keyWord,prefix,true);
		}
		else if (keyType == 2)
		{
			vigenereEncryptFile(filename, listOfLine, keyWord, prefix, false);
		}
	}
}

int main()
{
	doEncrypt();
	char  play_again;
	cout << "Woul you like to do it again? (press N/n to exit)." << endl;
	cin >> play_again;
	while (toupper(play_again) != 'N')
	{
		doEncrypt();
		cout << "Woul you like to do it again? (press N/n to exit)." << endl;
		cin >> play_again;
	}
}