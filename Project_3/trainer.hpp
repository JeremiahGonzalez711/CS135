/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3B
*/
#include <iostream>
#include <string>
#include <vector>
#include "department.hpp"
using namespace std;

MLDepartment::MLDepartment(std::vector<Profemon> profemons){
    for (int i = 0; i < profemons.size(); i++){
        if (profemons[i].getSpecialty() == 0){
            MLDepartment::addProfemon(profemons[i]);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 0){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}


SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    for (int i = 0; i < profemons.size(); i++){
        if (profemons[i].getSpecialty() == 1){
            SoftwareDepartment::addProfemon(profemons[i]);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 1){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    for (int i = 0; i < profemons.size(); i++){
        if (profemons[i].getSpecialty() == 2){
            HardwareDepartment::addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 2){
        Trainer::addProfemon(profemon);
        return true;
    }
    return false;
}