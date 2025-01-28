/**
Author: Jeremiah Gonzalez
course: CSCI-135
Instructor:Genady Maryash
Assignment: Project 3B
*/
#ifndef DEPARTMENT
#define DEPARTMENT

#include "trainer.hpp"

class MLDepartment: public Trainer{
    public:
        MLDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class SoftwareDepartment: public Trainer{
    public:
        SoftwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class HardwareDepartment: public Trainer{
    public:
        HardwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

#endif