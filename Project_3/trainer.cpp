/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3B
*/
#include <iostream>
#include <vector>
#include <string>
#include "trainer.hpp"
using namespace std;

Trainer::Trainer(){
    selected_profemon = nullptr;
}

Trainer::Trainer(std::vector <Profemon> profemons){
    for (int i = 0; i < profemons.size(); i++){
        if (i < 3){
            current_team[i] = profemons[i];
        } else {
            profedex.push_back(profemons[i]);
        }
    }

    selected_profemon = &current_team[0];
}

bool Trainer::contains(std::string name){
    for(int i = 0; i < 3; i++) {
        if(current_team[i].getName() == name) {
            return true;
        }
    }

    for(int j = 0; j < profedex.size(); j++) {
        if(profedex[j].getName() == name) {
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon){

    int i = 0;
    if(contains(profemon.getName()) == true){
        return false;
    }

    while (i < 3){
        if(current_team[i].getName() == "Undefined"){
            current_team[i] = profemon;
            return true;
        }
        i++;
    }

    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name){
    std::vector <Profemon> x;
    Profemon z;
    int i = 0;
    bool y = false;

    for (int i = 0; i < profedex.size(); i++){
        if(name == profedex[i].getName()){
            y = true;
        } else {
            x.push_back(profedex[i]);
        }
    }
    if(y){
        profedex = x;
        return true;
    }

    while(i < 3){
        if (current_team[i].getName() == name){
            current_team[i] = z;
            return true;
        }
        i++;
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name){
    Profemon y;
    for (int i = 0; i <= profedex.size(); i++){
        if (profedex[i].getName() == name){
            if(current_team[slot].getName() != "Undefined") {
                y = profedex[i];
                profedex[i] = current_team[slot];
                current_team[slot] = y;
            }
            else{
                current_team[slot] = profedex[i];
                removeProfemon(name);
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot){
    if (current_team[slot].getName() != "Undefined"){
        selected_profemon = &current_team[slot];
        return true;
    } else {
        return false;
    }
}

Profemon Trainer::getCurrent(){
    return *selected_profemon;
}

void Trainer::printProfedex(){
    for (int i = 0; i < profedex.size(); i++){
        profedex[i].printProfemon(false);
        std::cout << endl;
    }
}

void Trainer::printTeam(){
    for (int i = 0; i < 3; i++){
        if(current_team[i].getName() != "Undefined"){
            current_team[i].printProfemon(true);
            std::cout << endl;
        }
    }
}