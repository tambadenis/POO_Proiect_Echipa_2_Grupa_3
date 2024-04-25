#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include <vector>

using namespace System;
using namespace System::Collections::Generic; // Include the managed collection types

ref class EchipamentManager
{
public:
    EchipamentManager();
    ~EchipamentManager(); // Declararea destructorului
    void AddEchipament(String^ name, double price);
    void DeleteEchipament(String^ name);
    void DisplayAllEchipamente();
    void FindEchipamentByName(String^ name);

private:
    ref struct Echipament
    {
        String^ name;
        double price;
    };

    List<Echipament^>^ echipamente; // Use List<T> instead of std::vector
};
