/*
Author: Jeremiah Gonzalez
Course: CSCI-135
Instructor: Genady Maraysh
Assignment: Project 2C
 */
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Song{         //class called song
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2; //pseudo code
int g_size = 0;

Song *g_songs = new Song[g_capacity];

void allocateNew() {        //replaces array g_songs with 2x the capacity
    g_capacity*=2;
    Song *n_Songs = new Song[g_capacity];
    for (int i = 0; i < g_capacity/2; i+=1) {
        n_Songs[i] = g_songs[i];
    }
    delete[] g_songs;
    g_songs = n_Songs;
    return;
}

void readSongs(string filename) {       //reads song, artist, and song durations and genres into the g_songs
    string line = "";

    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "Not found!"<< endl;
        exit(1);
    }

    while(getline(fin, line)){

        if (g_size + 1 >= g_capacity) {
            allocateNew();
        }

        g_songs[g_size].name = line.substr(0, line.find(':'));
        line = line.substr(line.find(':') + 1);

        g_songs[g_size].artist = line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1);

        g_songs[g_size].genre = line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1);

        g_songs[g_size].duration = stoi(line.substr(0, line.find("mins")));

        g_size+=1;
    }

    return;
}

Song *getGenreSongs(string genre, int &genreCount){     //returns a dynamic array of song
    int count = 0;
    Song *songs = new Song[100];


    for (int i = 0; i < g_size; i+=1) {
        if (g_songs[i].genre == genre) {
            songs[count] = g_songs[i];
            count+=1;
        }
    }
    genreCount=count;
    return songs;
}

Song *getSongsFromDuration(int duration, int &durationsCount, int filter){
    int d_count = 0;
    Song *songs = new Song[100];


    for (int i =0; i<g_size;i+=1){
        if(filter==0 &&g_songs[i].duration>duration){
            songs[d_count]= g_songs[i];
            d_count+=1;
        }
        else if(filter==1 &&g_songs[i].duration<duration){
            songs[d_count]=g_songs[i];
            d_count+=1;

        }
        else if(filter==2 &&g_songs[i].duration==duration){
            songs[d_count]=g_songs[i];
            d_count+=1;
        }
    }
    durationsCount=d_count;
    return songs;
}

string *getUniqueArtists(int &uniqueCount) {
    string *artists = new string[g_size];
    uniqueCount = 0;
    for (int i = 0; i < g_size; i++) {
        if (find(artists, artists + uniqueCount, g_songs[i].artist) == artists + uniqueCount) {
            uniqueCount+=1;
            artists[uniqueCount] = g_songs[i].artist;

        }
    }
    return artists;
}

string getFavoriteArtist(){
    if (g_size == 0) {
        return "";
    }
    int maxCount = 0;
    string maxArtist = "";
    for (int i = 0; i < g_size; i++) {
        int count = 0;
        for (int j = 0; j < g_size; j++) {
            if (g_songs[j].artist == g_songs[i].artist) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxArtist = g_songs[i].artist;
        }
    }
    return maxArtist;

}