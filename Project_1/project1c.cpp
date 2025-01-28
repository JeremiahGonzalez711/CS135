/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 1C
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
//Task C
/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists
                          or if the array reached maximum
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos) {
    for(int i = 0; i < g_word_count; i++){      //returns false if word already exist
        if(g_words[i] == word){
            return false;
        }
    }
    if(g_word_count == g_MAX_WORDS){        //returns false if dictionary is full
        return false;
    }
    g_words[g_word_count] = word;               //updating arrays if the word is successfully added
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;

    g_word_count++;

    return true;
}
/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos){
    for(int i = 0; i < g_word_count; i++)
    {
        if(g_words[i] == word)      // if word is in dictionary, replace its definition and pos with new definition and pos
        {
            g_definitions[i] = definition;
            g_pos[i] = pos;
            return true;
        }
    }
    return false;           //if word is not found return false
}
/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word){
    int index = getIndex(word);     //if word is not in dictionary return false
    if (index == -1) {
        return false;
    }
    else {

        for (int i = index; i < g_word_count - 1; i++) {        
            g_words[i] = g_words[i+1];
            g_definitions[i] = g_definitions[i+1];
            g_pos[i] = g_pos[i+1];
        }

        g_words[g_word_count-1] = "";       //update g_word_count to remove the word if successful
        g_definitions[g_word_count-1] = "";
        g_pos[g_word_count-1] = "";

        g_word_count--;
        return true;
    }
}



/*
int main(){

    readWords("prod.txt");

    addWord("Book","A object to read","Noun");

    cout <<"g_word_count: " << g_word_count << '\n';
    for(int i = 0; i < g_word_count; i++){
        cout << g_words[i] << g_pos[i] << g_definitions[i] << endl;
    }

    return 0;
}
*/

