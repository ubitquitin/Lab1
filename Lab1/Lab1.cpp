// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//function to store all outputs from a filename into a vector<string>
int parse_inputs(vector<string> &output, char *filename) {
	ifstream filereader(filename);
	string word; //holds inputs
	if(filereader) {
		while (filereader >> word) {
			if (empty(word)) {
				continue;
			}
			if (filereader.eof()) {
				output.push_back(word);
				return Outputs::Success;
			}
			else {
				output.push_back(word);
			}
		}
	
		return Outputs::Success;
	}
	else{
		cout << "no file found" << endl;
		return Outputs::FileParsingFailure;
	}
}

int usage_message(char *name) {
	cout << "usage: lab1 <" << name << ">" << endl;
	return Outputs::BadInputArgs;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return usage_message(argv[0]);
	}


	vector<string> strs;

	//checks that there was no error reading file 
	if (parse_inputs(strs, argv[1]) != Outputs::Success) {
		cout << parse_inputs(strs,argv[1]) << "parse_inputs returned failure" << endl;
		return parse_inputs(strs, argv[1]);
	}
	else {
		vector<int> ints;
		bool allints = true;
		for (size_t i = 0;i < strs.size();++i) {
			for (char c : strs[i]) {
				if (isdigit(c)) {
					continue;
				}
				else {
					allints = false; //this will only set based on the last one.
				}
			}
			if (allints) {
				//wrap string in input stream
				istringstream iss(strs[i]);
				int value;
				//convert to int
				iss >> value;
				//push to vector of integers
				ints.push_back(value);
			}
			else {
				//print string to standard output stream
				cout << strs[i] << endl;
				allints = true;
			}
		}

		//lists integers after listing all of the strings.
		cout << "integers:" << endl;
		for (size_t i = 0; i < ints.size(); ++i) { 
			cout << ints[i] << endl;
		}
		return Outputs::Success;
	}
}

