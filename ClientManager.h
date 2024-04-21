#pragma once
#include "pch.h"
#include <string>
#include <list>

using namespace System;
using namespace System::Collections::Generic;

ref class ClientManager
{
private:
    // Structura pentru a reprezenta informațiile despre un client
    ref struct ClientInfo
    {
        String^ name;
        int age;
        double weight;

        // Constructor
        ClientInfo(String^ name, int age, double weight)
        {
            this->name = name;
            this->age = age;
            this->weight = weight;
        }
    };

    // List pentru a stoca clienții
    List<ClientInfo^>^ clients;

public:
    // Constructor
    ClientManager();

    // Destructor
    ~ClientManager();

    // Metodă pentru adăugarea unui client nou
    void AddClient(String^ name, int age, double weight);

    // Metodă pentru afișarea informațiilor despre toți clienții
    void DisplayAllClients();

    // Metodă pentru a căuta un client după nume
    void FindClientByName(String^ name);
};
