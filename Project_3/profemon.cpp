/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3A
*/
#include "profemon.hpp"
#include "skill.hpp" 
#include <iostream>
#include <string>
//constructors 

Profemon::Profemon() {
    this->name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    this->max_experience = 50;
    this->level = 0;
}

std::string Profemon::getName() {		//gets information 
    return name;
}

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() {
    return level;
}

double Profemon::getMaxHealth() {
    return max_health;
}

void Profemon::setName(std::string name) {
    this->name = name;
}

void Profemon::levelUp(int exp) {
    curr_experience += exp;
    while (curr_experience >= max_experience) {
        switch (this->getSpecialty()) {
            case (ML):
                level+=1; 	//increases to the next level

                curr_experience =curr_experience- max_experience; 

                max_experience = max_experience + 10; 		//increases the max_exp after leveling up
                break;
            case (SOFTWARE):
                level++; 

                curr_experience = curr_experience- max_experience;

               
                max_experience = max_experience+ 15;  
                break;
            case (HARDWARE):
                level++; 

                curr_experience = curr_experience- max_experience; 

                max_experience = max_experience+ 20; 
                break;
        }
    }
    return;
}

bool Profemon::learnSkill(int slot, Skill skill) {		// returns true if skill if skill has been successfully learned has to be within parameters of 0-2

    if (2 >= slot && slot >= 0 && skill.getSpecialty() == this->getSpecialty()) {
        skills[slot] = skill;
        return true;
    } else {

        return false;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills) {		//printing format (ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp 
    using namespace std;

    string thisSpecialty = "";
    switch (this->getSpecialty()) {
        case (ML):
            thisSpecialty = "ML";
            break;
        case (SOFTWARE):
            thisSpecialty = "SOFTWARE";
            break;
        case(HARDWARE):
            thisSpecialty = "HARDWARE";
            break;
    } 

    cout << this->getName() << " [" << thisSpecialty << "] | lvl " << this->getLevel() << " | exp " << curr_experience << '/' << max_experience << " | hp " << this->getMaxHealth() << endl;

    if(print_skills) {
        for(Skill i : skills) {
            if (i.getName() != "Undefined"){
                cout << "    " << i.getName() << " [" << i.getTotalUses() << "] : " << i.getDescription() << endl;
            }
        }
    }
    return;
}