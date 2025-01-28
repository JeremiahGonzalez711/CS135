/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3A
*/
#include<string>
#include<iostream> 
#include "skill.hpp"
#ifndef Profemon_HPP
#define Profemon_HPP

enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
    private:
        std::string name;
        int level;
		int max_experience;
		int curr_experience = 0;
        double max_health;
        Specialty specialty;
        Skill skills[3];
    public:
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
};
#endif