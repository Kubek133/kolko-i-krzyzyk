#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    string questions[10] = //pytania
    {
        "Kto jest obecnym prezydentem USA?",
        "Gdzie znajduje sie glowna siedziba CDPR?",
        "Ktora firma produkuje i sprzedaje konsole XBOX?",
        "W ktorej sali mamy obecnie zajecia?",
        "Kto jest zalozycielem firmy Apple?",
        "Kiedy wybrano Jana Pawla II jako glowe kosciola?",
        "Co jest ciezsze, 1 kg pierza czy 1 kg kamieni?",
        "Ile to pol tora dodac pol tora?",
        "Na torcie jest 13 swieczek. Jedna zgasla. Ile zostalo?",
        "Ktory miesiac ma 28 dni?",
    };

    string options[10][4] = // mozliwe opcje do wybrania
    {
        {"Donald Trump","Barack Obama","Joe Biden","Joe Mama"},
        {"Gdansk","Warszawa","Sosnowiec","Krosno"},
        {"Sony","Microsoft","Nintendo","LG"},
        {"K 211 A","K 001","K 111","K 210 A"},
        {"Jeremy Sochan","Bill Gates","Steve Jobs","Michael Jordan"},
        {"16.10.1978","15.10.1978","14.10.1978","17.10.1978"},
        {"zadna odp nie jest prawidlowa","kamienie","pierze","Ich waga jest taka sama"},
        {"3","1","Jeden tor","zadna odp nie jest prawidlowa"},
        {"13","13 i tort","12","12 i tort"},
        {"Grudzien","Kazdy","luty","Maj"},
    };
    string correctOptions[10] = // prawidlowe odp
    {
        "Joe Biden","Warszawa","Microsoft","K 210 A","Steve Jobs","16.10.1978","Ich waga jest taka sama","Jeden tor","13","Kazdy"
    };

    int userOptions[10] =
    {
        0,0,0,0,0,0,0,0,0,0
    };
    int totalQs = 10;
    int op;

    //Wyswietlenie pytania i wszystkich mozliwych odp do wybrania
    for (int i = 0; i < totalQs; i++)
    {
        cout << "Pytanie # " << (i + 1) << endl;
        cout << questions[i] << endl;
        cout << "1." << options[i][0] << endl;
        cout << "2." << options[i][1] << endl;
        cout << "3." << options[i][2] << endl;
        cout << "4." << options[i][3] << endl<<endl;

        cout << "Wybierz opcje od 1 do 4 lub 0 aby pominac: ";
        cin >> userOptions[i];
        cout << endl << "----------------------------" << endl << endl;
    }
    //Okienko ktore wyswietla sie po 
    cout << "====== ====== ====== ======= ======" << endl;
    cout << "====== Prawidlowa Odpowiedz  ======" << endl;
    cout << "====== ====== ======  ====== ======" << endl;

    for (int i = 0; i < totalQs; i++)
    {
        cout << "Pytanie # " << (i + 1) << endl;
        cout << questions[i] << endl;
        cout << "1." << options[i][0] << endl;
        cout << "2." << options[i][1] << endl;
        cout << "3." << options[i][2] << endl;
        cout << "4." << options[i][3] << endl << endl;

        if (userOptions[i] == 0)
        {
            cout << "Pominales pytanie." << endl;
        }
        else
        {
            cout << "Wybrales : " << options[i][userOptions[i] - 1] << endl;
        }
        cout << "Poprawna odpowiedz : " << correctOptions[i] << endl << endl;

        cout << "Nacisnij dowolny klawisz aby kontynuowac..." << endl;
        _getch();
        cout << endl << "------------------" << endl;
    }
    
    //wyswietlenie wyniku
    cout << endl << endl;
    cout << "====== ====== ======" << endl;
    cout << "====== Wynik  ======" << endl;
    cout << "====== ====== ======" << endl;

    int correct = 0;
    int incorrect = 0;
    int skipped = 0;
    for (int i = 0; i < totalQs; i++)
    {
        if (userOptions[i] != 0)
        {
            if (correctOptions[i] == options[i][userOptions[i] - 1])
            {
                correct++;
            }
            else {
                incorrect++;
            }
        }
        else {
            skipped++;
        }
    }
    cout << "Wszystkich pytan jest : " << totalQs << endl;
    cout << "Poprawne : " << correct << endl;
    cout << "Niepoprawne : " << correct << endl;
    cout << "Pominiete : " << skipped << endl;

    _getch();
    return 0;
}