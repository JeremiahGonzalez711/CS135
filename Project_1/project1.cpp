
/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 1A

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename){      //String with file name

        ifstream fin(filename);

        if (fin.fail()) {
            cerr << "File cannot be opened for reading." << endl;
            exit(1); // exit if failed to open the file
        }
        string line;
        string words;
        string pos;
        string definitions; //New String Variable
		string sign;
        int count = 0;

        while(fin >> words >> pos >> sign){
            getline(fin,definitions);  //reads one line from the file
            g_words[g_word_count] = words;
            g_pos [g_word_count] = pos;
			definitions = definitions.substr(1);   //substr starts at first 
            g_definitions [g_word_count] = definitions;
            g_word_count++;
        }
        fin.close();
}
/*
int main(){

    readWords("filename");
    for(int i = 0; i < g_word_count; i++){
        cout << g_words[i] << g_pos[i] << g_definitions[i] << endl;
    }

    return 0;
}
*/