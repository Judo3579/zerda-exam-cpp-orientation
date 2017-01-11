//============================================================================
// Name        : vizsga3.cpp
// Author      : haha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "CaesarsCipher.h"

using namespace std;


#define E_PARAM_NOT_ENOUGH_PARAM 1
#define E_PARAM_NO_INPUTFILENAME 4
#define E_PARAM_NO_SHIFT_VALUE_PROVIDED 2


void argHandling(int argc, char **argv, string &intputFileName, int &shift, string &outputFileName) throw(int) {

	if (argc < 4) {
		throw E_PARAM_NOT_ENOUGH_PARAM;
	}

	if (argv[1][0] != '-') {
		intputFileName = argv[1];
	} else {
		throw E_PARAM_NO_INPUTFILENAME;
	}

	for (int i = 2; i < argc; i++) {
		string param(argv[i]);

		cout << "arg(" << i << "): " << param << endl;

		if (param == "-s") {
			if(i+1 != argc && argv[i+1][0] != '-') {
				string paramOpts(argv[i+1]);
				istringstream ss(paramOpts);
				ss >> shift;
			} else {
				throw E_PARAM_NO_SHIFT_VALUE_PROVIDED;
			}
		}
		if (param == "-o") {
			if(i+1 != argc && argv[i+1][0] != '-') {
				outputFileName = argv[i+1];
			}
		}
	}
}

string readFileIntoString(string inputFileName){
	ifstream t(inputFileName.c_str());
	stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

void writeStringToFile(string outputFileName, string content){
	ofstream myfile;
	myfile.open(outputFileName.c_str());
	myfile << content;
	myfile.close();
}


int main(int argc, char **argv) {

	string inputFileName;
	string outputFileName;
	int shift;

	try {
		argHandling(argc, argv, inputFileName, shift, outputFileName);

		cout << "inputFileName: " << inputFileName << endl;
		cout << "outputFileName: " << outputFileName << endl;
		cout << "shift: " << shift << endl;

		string content = readFileIntoString(inputFileName);

		CaesarsCipher caesar(content, shift);
		string decryptedContent = caesar.getDecryptedContent();

		if (outputFileName.empty()) {
			cout << endl << decryptedContent << endl;
		}else{
			writeStringToFile(outputFileName, decryptedContent);
		}

		cout << "terminate" << endl;

	} catch (int errcode) {
		cout << "errorCode: " << errcode << endl;
		switch (errcode) {
		case E_PARAM_NOT_ENOUGH_PARAM:
			cout << "Not enough provided" << endl;
			break;
		case E_PARAM_NO_INPUTFILENAME:
			cout << "No filename is provided." << endl;
			break;
		case E_PARAM_NO_SHIFT_VALUE_PROVIDED:
			cout << "No shift is provided" << endl;
			break;
		}
	}

	return 0;
}

