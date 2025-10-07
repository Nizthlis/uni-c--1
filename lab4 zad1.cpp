#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Ile_jest(char* tablica, int rozmiar) {
    int ilosc = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i] == '\0') {
            ilosc++;
        }
    }
    return ilosc;
}

void Wprowadz(char* wyjscie, int rozmiar_wyjscie, int* zajete, char* znaki) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int ilosc_pozostalych = Ile_jest(zajete, rozmiar_wyjscie);
    if (ilosc_pozostalych <= 0) {
        cout << "Tablica wyjsciowa jest juz wypelniona" << endl;
        return;
    }
    int indeks;
    do {
        indeks = rand() % rozmiar_wyjscie;
    } while (zajete[indeks] != 0);
    int pozostale_znaki = Ile_jest(znaki, 45);
    if (pozostale_znaki <= 0) {
        cout << "Brak wolnych znakow ktore mozna wykorzystac" << endl;
        return;
    }
    int znak_indeks = rand() % pozostale_znaki;
    wyjscie[indeks] = znaki[znak_indeks];
    zajete[indeks] = 1;
    znaki[znak_indeks] = '\0';
}

void Wyswietl(char* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void Wyswietl(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void Wyczysc(char* wyjscie, int* zajete, char* znaki, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        wyjscie[i] = '\0';
        zajete[i] = 0;
    }
    for (int i = 0; i < 45; i++) {
        znaki[i] = static_cast<char>(i + 48);
    }
}

int main() {
    const int rozmiar_wyjscie = 11;
    char wyjscie[rozmiar_wyjscie];
    int zajete[rozmiar_wyjscie];
    char znaki[45];
    srand(static_cast<unsigned int>(time(nullptr)));
    Wyczysc(wyjscie, zajete, znaki, rozmiar_wyjscie);
    cout << "Tablica wyjsciowa (przed): ";
    Wyswietl(wyjscie, rozmiar_wyjscie);
    Wprowadz(wyjscie, rozmiar_wyjscie, zajete, znaki);
    cout << "Tablica wyjsciowa (po): ";
    Wyswietl(wyjscie, rozmiar_wyjscie);
    return 0;
}
