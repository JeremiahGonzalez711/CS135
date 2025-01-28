/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3A
*/
#include <string>
#include "skill.hpp"
using namespace std;
// constructors

Skill::Skill() {
    this->name = "Undefined";
    this->description = "Undefined";
    this->uses = -1;
    this->specialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    this->specialty = specialty;
    this->uses = uses;
}

std::string Skill::getName() {			//gathering inforation 
    return name;
}

std::string Skill::getDescription() {
    return description;
}

int Skill::getTotalUses() {
    return uses;
}

int Skill:: getSpecialty() {
    return specialty;
}

void Skill::setName(std::string name) {		//stating information 
    this->name = name;
}

void Skill::setDescription(std::string description) {
    this->description = description;
}

void Skill::setTotalUses(int uses) {
    this->uses = uses;
}

bool Skill::setSpecialty(int specialty) {
    if (specialty >=0 && specialty <=2) {
        this->specialty = specialty;
        return true;
    } else {
        return false;
    }
    return false;
}
