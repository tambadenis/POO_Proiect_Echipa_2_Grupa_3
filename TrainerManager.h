#pragma once
#include "pch.h"
#include <string>
#include <list>

using namespace System;
using namespace System::Collections::Generic;

ref class TrainerManager
{
private:
    // Struct to represent information about a trainer
    ref struct TrainerInfo
    {
        String^ name;
        int age;
        String^ specialization;

        // Constructor
        TrainerInfo(String^ name, int age, String^ specialization)
        {
            this->name = name;
            this->age = age;
            this->specialization = specialization;
        }
    };

    // List to store trainers
    List<TrainerInfo^>^ trainers;

public:
    // Constructor
    TrainerManager();

    // Destructor
    ~TrainerManager();

    // Method to add a new trainer
    void AddTrainer(String^ name, int age, String^ specialization);

    // Method to delete a trainer
    void DeleteTrainer(String^ name);

    // Method to display information about all trainers
    void DisplayAllTrainers();

    // Method to find a trainer by name
    void FindTrainerByName(String^ name);
};
