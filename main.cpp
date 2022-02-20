#include <iostream>
#include <math.h>
#include <vector>  
int sk;

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    double n; // pazymiu skaicius
    double vidurkis = 0;
    int med;
    double egz;
    double gal;
};

studentas rezult;

void as() {
    double nd; //pazymys
    cout << "iveskite varda ";
    cin >> rezult.vardas;
    cout << "iveskite pavarde ";
    cin >> rezult.pavarde;
    cout << "iveskite kiek pazymiu ";
    cin >> rezult.n;
    for (int i = 0; i < rezult.n; i++) { // iveda visus skaicius
        cout << "iveskite pazymi ";
        cin >> nd;
        rezult.vidurkis += nd;
    } 
    rezult.vidurkis = rezult.vidurkis / rezult.n;
    cout << "iveskite egzamino rezultata ";
    cin >> rezult.egz;
    rezult.gal = 0.6 * rezult.egz + 0.4 * rezult.vidurkis;
    cout << "Pavarde     Vardas     Galutinis(vid.)" << endl;
    cout << "-----------------------------"<<endl;
    cout << rezult.vardas << "     " << rezult.pavarde << "     " << rezult.gal;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    cout << "kiek studentu ";
    cin >> sk;
    for (int i = 0; i < sk; i++) {
        as();
    }
}
