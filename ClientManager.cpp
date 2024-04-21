#include "pch.h"
#include "ClientManager.h"

// Implementarea funcțiilor membre ale clasei ClientManager

ClientManager::ClientManager()
{
    // Inițializarea listei de clienți
    clients = gcnew List<ClientInfo^>();
}

ClientManager::~ClientManager()
{
    // Eliberarea resurselor alocate
}

void ClientManager::AddClient(String^ name, int age, double weight)
{
    // Crearea unei instanțe de ClientInfo cu informațiile primite
    ClientInfo^ newClient = gcnew ClientInfo(name, age, weight);

    // Adăugarea noului client în lista de clienți
    clients->Add(newClient);
}

void ClientManager::DisplayAllClients()
{
    // Verificăm dacă lista de clienți este goală
    if (clients->Count == 0)
    {
        Console::WriteLine("Nu exista clienti inregistrati.");
        return;
    }

    // Afisarea informațiilor despre toți clienții
    for each (ClientInfo ^ client in clients)
    {
        Console::WriteLine("Nume: {0}, Varsta: {1}, Greutate: {2}", client->name, client->age, client->weight);
    }
}

void ClientManager::FindClientByName(String^ name)
{
    bool found = false;

    // Căutăm clienții după nume
    for each (ClientInfo ^ client in clients)
    {
        if (client->name->Equals(name))
        {
            Console::WriteLine("Nume: {0}, Varsta: {1}, Greutate: {2}", client->name, client->age, client->weight);
            found = true;
        }
    }

    // Dacă nu s-a găsit niciun client cu numele specificat
    if (!found)
    {
        Console::WriteLine("Nu s-a gasit niciun client cu numele specificat.");
    }
}
