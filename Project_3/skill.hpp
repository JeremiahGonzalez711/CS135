/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3A
*/
#ifndef SKILL_HPP
#define SKILL_HPP
#include <string>
#include <iostream>
using namespace std;


class Skill {
    private:				//class for description, name, uses and specialty 
        std::string name; 
        std::string description; 
        int uses; 
        int specialty; 
		
    public:
        Skill();
        Skill(std::string name, std::string description, int specialty, int uses);
        std::string getName();
        std::string getDescription();
        int getTotalUses();
        int getSpecialty();
        void setName(std::string name);
        void setDescription(std::string description);
        void setTotalUses(int uses);
        bool setSpecialty(int specialty);
};
#endif