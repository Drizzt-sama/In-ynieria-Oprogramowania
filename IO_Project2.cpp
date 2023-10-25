#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Produkt {
	string nazwa;
	int cena;
};

void swap(Produkt& a, Produkt& b) {
	Produkt temp = a;
	a = b;
	b = temp;
}

int partition(vector<Produkt>& produkty, int low, int high) {
    int pivot = produkty[high].cena; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        if (produkty[j].cena > pivot) {
            i++;
            swap(produkty[i], produkty[j]);
        }
    }

    swap(produkty[i + 1], produkty[high]);
    return (i + 1);
}


void quickSort(vector<Produkt>& produkty, int low, int high) {
    if (low < high) {
        int pivot = partition(produkty, low, high);

        quickSort(produkty, low, pivot - 1);
        quickSort(produkty, pivot + 1, high);
    }
}


int main() {
    vector<Produkt> produkty;
    cout << "Podaj informacje o 10 produktach." << endl;

    for (int i = 1; i <= 10; i++) {
        Produkt produkt;
        cout << i << ". Podaj nazwe produktu: ";
        cin >> produkt.nazwa;
        cout << "Podaj cene produktu: ";
        cin >> produkt.cena;
        produkty.push_back(produkt);
    }

    quickSort(produkty, 0, produkty.size() - 1);

    cout << "\nProdukty od najdro?szych do najta?szych:\n";
    for (const Produkt& produkt : produkty) {
        cout << "Nazwa: " << produkt.nazwa << ", Cena: " << produkt.cena << endl;
    }

    return 0;
}