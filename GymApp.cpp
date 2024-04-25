//GymApp.cpp

#include "pch.h"
#include "ClientManager.h"
#include "TrainerManager.h"
#include "EchipamentManager.h"
using namespace System;

int ReadIntFromConsole(String^ prompt)
{
    Console::Write(prompt);
    String^ input = Console::ReadLine();
    int result;
    if (Int32::TryParse(input, result))
    {
        return result;
    }
    else
    {
        return -1;
    }
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
    // Crează o instanță a clasei ClientManager, TrainerManager și EchipamentManager
    ClientManager^ clientManager = gcnew ClientManager();
    TrainerManager^ trainerManager = gcnew TrainerManager();
    EchipamentManager^ echipamentManager = gcnew EchipamentManager();

    bool continueRunning = true;

    // Meniu interactiv
    do {
        Console::WriteLine("Meniu principal:");
        Console::WriteLine("1. Administrare clienti");
        Console::WriteLine("2. Administrare antrenori");
        Console::WriteLine("3. Administrare echipamente");
        Console::WriteLine("4. Iesire");

        int choice = ReadIntFromConsole("Alege o optiune: ");

        switch (choice)
        {
        case 1:
        {
            // Meniu de gestionare a clientilor
            while (true)
            {
                Console::WriteLine("\nMeniu Administrare Clienti:");
                Console::WriteLine("1. Adauga client");
                Console::WriteLine("2. Sterge client");
                Console::WriteLine("3. Afiseaza toti clientii");
                Console::WriteLine("4. Cauta client dupa nume");
                Console::WriteLine("5. Inapoi la meniul principal");

                int clientChoice = ReadIntFromConsole("Alege o optiune: ");

                switch (clientChoice)
                {
                case 1:
                {
                    // Adaugarea unui client
                    String^ name = ReadStringFromConsole("Introdu numele clientului: ");
                    int age = ReadIntFromConsole("Introdu varsta clientului: ");
                    double weight = ReadDoubleFromConsole("Introdu greutatea clientului: ");
                    clientManager->AddClient(name, age, weight);
                    break;
                }
                case 2:
                {
                    // Stergerea unui client
                    String^ nameToDelete = ReadStringFromConsole("Introdu numele clientului de sters: ");
                    clientManager->DeleteClient(nameToDelete);
                    break;
                }
                case 3:
                {
                    // Afisarea tuturor clientilor
                    clientManager->DisplayAllClients();
                    break;
                }
                case 4:
                {
                    // Gaseste un client dupa nume
                    String^ name = ReadStringFromConsole("Introdu numele clientului cautat: ");
                    clientManager->FindClientByName(name);
                    break;
                }
                case 5:
                {
                    // Iesire
                    Console::WriteLine("\nRevenire la meniul principal...");
                    break;
                }
                default:
                {
                    Console::WriteLine("Optiune invalida. Te rog sa alegi din nou.");
                    break;
                }
                }
                if (clientChoice == 5)
                    break;
            }
            break;
        }
        case 2:
        {
            // Meniu de gestionare a antrenorilor
            while (true)
            {
                Console::WriteLine("\nMeniu Administrare Antrenori:");
                Console::WriteLine("1. Adauga antrenor");
                Console::WriteLine("2. Sterge antrenor");
                Console::WriteLine("3. Afiseaza toti antrenorii");
                Console::WriteLine("4. Cauta antrenor dupa nume");
                Console::WriteLine("5. Inapoi la meniul principal");

                int trainerChoice = ReadIntFromConsole("Alege o optiune: ");

                switch (trainerChoice)
                {
                case 1:
                {
                    // Adauga un antrenor
                    String^ name = ReadStringFromConsole("Introdu numele antrenorului: ");
                    int age = ReadIntFromConsole("Introdu varsta antrenorului: ");
                    String^ specialization = ReadStringFromConsole("Introdu specializarea antrenorului: ");
                    trainerManager->AddTrainer(name, age, specialization);
                    break;
                }
                case 2:
                {
                    // Sterge un antrenor
                    String^ nameToDelete = ReadStringFromConsole("Introdu numele antrenorului de sters: ");
                    trainerManager->DeleteTrainer(nameToDelete);
                    break;
                }
                case 3:
                {
                    // Afiseaza toti antrenori
                    trainerManager->DisplayAllTrainers();
                    break;
                }
                case 4:
                {
                    // Cauta un antrenor dupa nume
                    String^ name = ReadStringFromConsole("Introdu numele antrenorului cautat: ");
                    trainerManager->FindTrainerByName(name);
                    break;
                }
                case 5:
                {
                    // Revenire la meniul principal
                    Console::WriteLine("\nRevenire la meniul principal...");
                    break;
                }
                default:
                {
                    Console::WriteLine("Optiune invalida. Te rog sa alegi din nou.");
                    break;
                }
                }
                if (trainerChoice == 5)
                    break;
            }
            break;
        }
        case 3:
        {
            // Meniu de gestionare a echipamentelor
            while (true)
            {
                Console::WriteLine("\nMeniu Administrare Echipamente:");
                Console::WriteLine("1. Adauga echipament");
                Console::WriteLine("2. Sterge echipament");
                Console::WriteLine("3. Afiseaza toate echipamentele");
                Console::WriteLine("4. Cauta echipament dupa nume");
                Console::WriteLine("5. Inapoi la meniul principal");

                int echipamentChoice = ReadIntFromConsole("Alege o optiune: ");

                switch (echipamentChoice)
                {
                case 1:
                {
                    // Adauga un echipament
                    String^ name = ReadStringFromConsole("Introdu numele echipamentului: ");
                    double price = ReadDoubleFromConsole("Introdu pretul echipamentului: ");
                    echipamentManager->AddEchipament(name, price);
                    break;
                }
                case 2:
                {
                    // Sterge un echipament
                    String^ nameToDelete = ReadStringFromConsole("Introdu numele echipamentului de sters: ");
                    echipamentManager->DeleteEchipament(nameToDelete);
                    break;
                }
                case 3:
                {
                    // Afiseaza toate echipamentele
                    echipamentManager->DisplayAllEchipamente();
                    break;
                }
                case 4:
                {
                    // Cauta un echipament dupa nume
                    String^ name = ReadStringFromConsole("Introdu numele echipamentului cautat: ");
                    echipamentManager->FindEchipamentByName(name);
                    break;
                }
                case 5:
                {
                    // Revenire la meniul principal
                    Console::WriteLine("\nRevenire la meniul principal...");
                    break;
                }
                default:
                {
                    Console::WriteLine("Optiune invalida. Te rog sa alegi din nou.");
                    break;
                }
                }
                if (echipamentChoice == 5)
                    break;
            }
            break;
        }
        case 4:
        {
            // Iesire
            continueRunning = false;
            break;
        }
        default:
        {
            Console::WriteLine("Optiune invalida. Te rog sa alegi din nou.");
            break;
        }
        }
    } while (continueRunning);

    return 0;
}
