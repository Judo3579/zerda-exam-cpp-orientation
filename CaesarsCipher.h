/*
 * CaesarChipher.h
 *
 *  Created on: 2017. jan. 11.
 *      Author: Judo
 */

#ifndef CAESARSCIPHER_H_
#define CAESARSCIPHER_H_

#include <string>
#include <iostream>

using namespace std;

class CaesarsCipher {

private:
	string content;
	string decryptedContent;

	string decrypt(string content, int shift);

public:
	CaesarsCipher(string content, int shift);
	virtual ~CaesarsCipher();

	string getDecryptedContent();

	string alphabetLower;
	string alphabetUpper;
};

#endif /* SRC_CAESARSCIPHER_H_ */

