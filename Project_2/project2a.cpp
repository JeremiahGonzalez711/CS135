/*
Author: Jeremiah Gonzalez
Course: CSCI-135
Instructor: Genady Maraysh
Assignment: Project 2B
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Pseudo code
int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names',
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){

    //creating new arrays
    string new1[g_curr_size];
    string new2[g_curr_size];
    string new3[g_curr_size];
    int new4[g_curr_size];

    //copying the contents of the old arrays to the new ones
    for (int i = 0; i < g_curr_size; i++)
    {
        new1[i] = g_song_names[i];
        new2[i] = g_artist_names[i];
        new3[i] = g_genres[i];
        new4[i] = g_song_durations[i];
    }

    //double array size
    g_curr_size *= 2;

    //point the old arrays to the new ones
    g_song_names = new string[g_curr_size];
    g_artist_names = new string[g_curr_size];
    g_genres = new string[g_curr_size];
    g_song_durations = new int[g_curr_size];

    for (int i = 0; i < g_curr_size / 2; i++)
    {
        g_song_names[i] = new1[i];
        g_artist_names[i] = new2[i];
        g_genres[i] = new3[i];
        g_song_durations[i] = new4[i];
    }
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into
                          the global-arrays and set the
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate
                          an array of larger size if the
                          dynamic arrays reach full
                          capacity.
*/
void readSongs(string filename){

    ifstream fin(filename); //streams file

    if (fin.fail())
    {
        cerr << "File cannot be opened.";      //file fail to open
        exit(1);
    }

    string line;    //creates string variable called line

    //extracting information from the line
    while (getline(fin, line))
    {
        int colon = line.find(':');
        string song_name = line.substr(0, colon);
        g_song_names[g_number_of_songs] = song_name;

        int dash = line.find('-');
        string artist_name = line.substr(colon + 1, dash - colon - 1);
        g_artist_names[g_number_of_songs] = artist_name;

        int rdash = line.rfind('-');
        string genre = line.substr(dash + 1, rdash - dash - 1);
        g_genres[g_number_of_songs] = genre;

        string duration = line.substr(rdash + 1);
        g_song_durations[g_number_of_songs] = stoi(duration);

        g_number_of_songs++;

        //adding song information to the global arrays
        if (g_number_of_songs == g_curr_size) {
            allocateNew(); }
    }
}
/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'

    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]

                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]

                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist
*/
string * getGenreSongs(string genre, int &genreCount){
    int genre_count = 0;
    string* songs = new string [100];

    for (int i = 0; i< g_number_of_songs; i++){     
        if (g_genres [i] == genre){
            songs[genre_count] = g_song_names[i];
            genre_count++;
        }
    }

    genreCount = genre_count;

    return songs;
}
/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration
*/

string * getSongsFromDuration(int duration, int &durationsCount, int filter){
    int dur_count = 0;
    string* songs = new string [100];

    for (int i = 0; i< g_number_of_songs; i++){
        if (filter == 0 && g_song_durations [i]> duration){
            songs[dur_count] = g_song_names[i];
            dur_count++;
        }

        else if (filter == 1 && g_song_durations [i] < duration){
            songs[dur_count] = g_song_names [i];
            dur_count++;
        }

        else if (filter == 2 && g_song_durations [i] == duration){
            songs[dur_count] = g_song_names [i];
            dur_count++;
        }
    }
    durationsCount = dur_count;
    return songs;
}

/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found

    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]

                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist
*/
string * getUniqueArtists(int &uniqueCount){
    string * uniqueArtists = new string[g_number_of_songs];
    uniqueCount = 0;
    for (int i = 0; i < g_number_of_songs; i++){
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++){
            if (g_artist_names[i] == uniqueArtists[j]){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            uniqueArtists[uniqueCount++] = g_artist_names[i];
        }
    }
    if (uniqueCount == 0){
        delete[] uniqueArtists;
        uniqueArtists = new string[0];
    }
    return uniqueArtists;
}
/*
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any
                  other artists in the playlist
*/
string getFavoriteArtist() {
    if (g_number_of_songs == 0) {
        return "NONE";
    }
    string favoriteArtist;
    int favoriteCount = 0;
    int currentCount;
    for (int i = 0; i < g_number_of_songs; i++) {
        currentCount = 0;
        for (int j = 0; j < g_number_of_songs; j++) {
            if (g_artist_names[i] == g_artist_names[j]) {
                currentCount++;
            }
        }
        if (currentCount > favoriteCount) {
            favoriteCount = currentCount;
            favoriteArtist = g_artist_names[i];
        }
    }

    return favoriteArtist;

}
int main(){

    readSongs("Songs.txt");

    cout << "Number of Songs: " << g_number_of_songs << endl;

    cout << "Song Names: " << endl;
    for(int i = 0; i < g_number_of_songs; i++ ){
        cout << g_song_names[i] << endl;
    }
    cout << "Artist Names: " << endl;
    for(int i = 0; i < g_number_of_songs; i++ ){
        cout << g_artist_names[i] << endl;
    }
    cout << "Song Durations: " << endl;
    for(int i = 0; i < g_number_of_songs; i++ ){
        cout << g_song_durations[i] << endl;
    }
    cout << "Genres: " << endl;
    for(int i = 0; i < g_number_of_songs; i++ ){
        cout << g_genres[i] << endl;
    }
    cout << endl;

    return 0;
}


