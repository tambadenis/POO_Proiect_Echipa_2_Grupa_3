#include "pch.h"
#include "TrainerManager.h"

TrainerManager::TrainerManager()
{
    // Initialize the list of trainers
    trainers = gcnew List<TrainerInfo^>();
}

TrainerManager::~TrainerManager()
{
    // Free allocated resources
}

void TrainerManager::AddTrainer(String^ name, int age, String^ specialization)
{
    // Create a new TrainerInfo instance with the received information
    TrainerInfo^ newTrainer = gcnew TrainerInfo(name, age, specialization);

    // Add the new trainer to the list of trainers
    trainers->Add(newTrainer);
}

void TrainerManager::DisplayAllTrainers()
{
    // Check if the list of trainers is empty
    if (trainers->Count == 0)
    {
        Console::WriteLine("Nu exista antrenori inregistrati.");
        return;
    }

    // Display information about all trainers
    for each (TrainerInfo ^ trainer in trainers)
    {
        Console::WriteLine("Nume: {0}, Varsta: {1}, Specializare: {2}", trainer->name, trainer->age, trainer->specialization);
    }
}

void TrainerManager::FindTrainerByName(String^ name)
{
    bool found = false;

    // Search for trainers by name
    for each (TrainerInfo ^ trainer in trainers)
    {
        if (trainer->name->Equals(name))
        {
            Console::WriteLine("Nume: {0}, Varsta: {1}, Specializare: {2}", trainer->name, trainer->age, trainer->specialization);
            found = true;
        }
    }

    // If no trainer with the specified name was found
    if (!found)
    {
        Console::WriteLine("Nu s-a gasit niciun antrenor cu numele specificat.");
    }
}

void TrainerManager::DeleteTrainer(String^ name)
{
    for (int i = 0; i < trainers->Count; i++)
    {
        if (trainers[i]->name->Equals(name))
        {
            trainers->RemoveAt(i);
            Console::WriteLine("Antrenorul cu numele {0} a fost sters.", name);
            return;
        }
    }
    Console::WriteLine("Nu s-a gasit niciun antrenor cu numele specificat.");
}
