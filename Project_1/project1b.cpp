/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 1B
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
		string sign;
        string definitions;
        string junk;        //New String Variable
        int count = 0;

        while(fin >> words >> pos >> sign ){
            getline(fin,definitions);  //reads one line from the file
            g_words[g_word_count] = words;
            g_pos [g_word_count] = pos;
			definitions = definitions.substr(1);   //substr starts at first letter and ends at definition length aka last letter
            g_definitions [g_word_count] = definitions;
            g_word_count++;
        }
        fin.close();
}
//Task B
/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(string word){
    int index = -1;
    for (int i = 0; i < g_word_count; i++){
        if (word == g_words[i]){
            index = i;
        }
    }
    return index;
}
/*
@param            :   The string with a query word
@return           :   Return the string definition of
                  the word from  `g_definitions`
                  global-array. Return "NOT_FOUND" if
                  word doesn't exist in the dictionary
@post             :   Find the definition of the given `word`
                  Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    string n = "NOT_FOUND";
    for (int i = 0; i < g_word_count; i++){
        if (word == g_words[i]){
            return g_definitions[i];
        }
    }
    return n;
}
/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos)
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word){
    string n = "NOT_FOUND";
    for (int i = 0; i < g_word_count; i++){
        if (word == g_words[i]){
            return g_pos[i];
        }
    }
    return n;
}
/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/
int countPrefix(string prefix){
    int i = 0;
    for ( int j = 0; j < g_word_count; j++){
        if (prefix == g_words[j].substr(0,prefix.length())){
            i++;
        }
    }
    return i;
}

/*
int main(){

    readWords("filename");

    string iword;

    cout <<"Enter a word: " << endl;
    cin >> iword;

    cout << getPOS(iword) << endl;

    cout <<"g_word_count: " << g_word_count << '\n';
    for(int i = 0; i < g_word_count; i++){
        cout << g_words[i] << g_pos[i] << g_definitions[i] << endl;
    }

    return 0;
}
*/