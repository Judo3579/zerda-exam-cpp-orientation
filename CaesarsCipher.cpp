/*
 * CaesarChipher.cpp
 *
 *  Created on: 2017. jan. 11.
 *      Author: Judo
 */

#include "CaesarsCipher.h"

CaesarsCipher::CaesarsCipher(string content, int shift) {

	alphabetLower = "abcdefghijklmnopqrstuvwxyz";
	alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	this->content = content;
	this->decryptedContent = decrypt(content, shift);
}

CaesarsCipher::~CaesarsCipher() {
}

string CaesarsCipher::getDecryptedContent() {
	return this->decryptedContent;
}

string CaesarsCipher::decrypt(string str, int shift) {

	string result;
	shift = 3;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		char c = *it;
		char r = c;

		if (('A' <= c) && (c <= 'Z') ) {
			int idx = c - 65;
			r = alphabetUpper[(idx + shift) % 26];
		} else if ( ('a' <= c) && (c <= 'z')) {
			int idx = c - 97;
			r = alphabetLower[(idx + shift) % 26];
		}
		std::cout << r;
		result += r;
	}

	return result;
}




