#include "pch.h"
#include "ClientManager.h"

using namespace System;

int ReadIntFromConsole(String^ prompt)
{
    Console::Write(prompt);
    String^ input = Console::ReadLine();
    return Int32::Parse(input);
}

double ReadDoubleFromConsole(String^ prompt)
{
    Console::Write(prompt);
    String^ input = Console::ReadLine();
    return Double::Parse(input);
}

String^ ReadStringFromConsole(String^ prompt)
{
    Console::Write(prompt);
    return Console::ReadLine();
}

int main(array<System::String^>^ args)
{
    // Crează o instanță a clasei ClientManager
    ClientManager^ clientManager = gcnew ClientManager();

    // Meniu interactiv
    while (true)
    {
        Console::WriteLine("Meniu:");
        Console::WriteLine("1. Adauga client");
        Console::WriteLine("2. Afiseaza toti clientii");
        Console::WriteLine("3. Cauta client dupa nume");
        Console::WriteLine("4. Iesire");

        int choice = ReadIntFromConsole("Alege o optiune: ");

        switch (choice)
        {
        case 1:
        {
            // Adaugă un client
            String^ name = ReadStringFromConsole("Introdu numele clientului: ");
            int age = ReadIntFromConsole("Introdu varsta clientului: ");
            double weight = ReadDoubleFromConsole("Introdu greutatea clientului: ");
            clientManager->AddClient(name, age, weight);
            break;
        }
        case 2:
        {
            // Afișează toți clienții
            clientManager->DisplayAllClients();
            break;
        }
        case 3:
        {
            // Caută un client după nume
            String^ name = ReadStringFromConsole("Introdu numele clientului cautat: ");
            clientManager->FindClientByName(name);
            break;
        }
        case 4:
        {
            // Ieșire din program
            return 0;
        }
        default:
        {
            Console::WriteLine("Optiune invalida. Te rog sa alegi din nou.");
            break;
        }
        }
    }

    return 0;
}
