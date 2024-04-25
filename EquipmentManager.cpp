#include "pch.h"
#include "EchipamentManager.h"

EchipamentManager::EchipamentManager()
{
    echipamente = gcnew List<Echipament^>();
}

EchipamentManager::~EchipamentManager()
{
}

void EchipamentManager::AddEchipament(String^ nume, double pret)
{
    Echipament^ nouEchipament = gcnew Echipament();
    nouEchipament->name = nume;
    nouEchipament->price = pret;
    echipamente->Add(nouEchipament);
    Console::WriteLine("Echipament adaugat cu succes.");
}

void EchipamentManager::DeleteEchipament(String^ nume)
{
    for (int i = 0; i < echipamente->Count; i++)
    {
        if (echipamente[i]->name == nume)
        {
            echipamente->RemoveAt(i);
            Console::WriteLine("Echipament sters cu succes.");
            return;
        }
    }
    Console::WriteLine("Echipamentul nu a fost gasit.");
}

void EchipamentManager::DisplayAllEchipamente()
{
    Console::WriteLine("\nLista de echipamente:");
    for each (Echipament ^ echipament in echipamente)
    {
        Console::WriteLine("Nume: " + echipament->name + ", Pret: " + echipament->price);
    }
}

void EchipamentManager::FindEchipamentByName(String^ nume)
{
    for each (Echipament ^ echipament in echipamente)
    {
        if (echipament->name == nume)
        {
            Console::WriteLine("Echipament gasit: Nume: " + echipament->name + ", Pret: " + echipament->price);
            return;
        }
    }
    Console::WriteLine("Echipamentul nu a fost gasit.");
}
