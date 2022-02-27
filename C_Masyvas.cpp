#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include <string>
#include <vector>  
#include <fstream>
#include <sstream>
int sk;
const int numb = 2;

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    double vidurkis = 0;
    double med, gal, galm;
    int n [numb];
};
studentas* rezult= new studentas[3];

bool isNumber(const string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

string sansas(string& nd) {
    if (rand() % 8 != 0) {
        nd = to_string(rand() % 10 + 1);
    }
    else {
        nd = "oskaras";
    }
    return nd;
}

void ivestis(int i) {
    cout << "vardas: ";
    cin >> rezult[i].vardas;
    cout << "pavarde: ";
    cin >> rezult[i].pavarde;
    
    for (int j = 0; j < numb; j++) {
        cout << "pazymys:";
        cin >> rezult[i].n[j];
    }
    rezult[i].vidurkis = rezult[i].vidurkis - rezult[i].n[numb];
    if ((numb-1) % 2 == 1) {
        rezult[i].med = rezult[i].n[(numb-1) / 2];
    }
    else {
        rezult[i].med = (rezult[i].n[(numb-1) / 2 - 1] + rezult[i].n[(numb-1) / 2]) / 2;
    }
    rezult[i].gal = 0.6 * rezult[i].n[numb-1] + 0.4 * rezult[i].vidurkis;
    rezult[i].galm = 0.6 * rezult[i].n[numb-1] + 0.4 * rezult[i].med;
}

int main() {
    srand(time(NULL));
    char tn = 'T';
    for (int i = 0; i < 3; i++) {
        ivestis(i);
    }
    int j = 2;
    while (tn == 'T' || tn == 't') {
        j++;
        studentas* temp = new studentas[j];
        for (int k = 0; k < j - 1; k++)
        {
            temp[k] = rezult[k];
        }
        delete[] rezult;
        studentas* rezult = new studentas[j];
        for (int k = 0; k < j - 1; k++)
        {
            rezult[k] = temp[k];
        }
        ivestis(j);
        delete[] temp;
        cout << "ar yra dar studentu? T/N";
        cin >> tn;

    }
    

        cout << "Pavarde     Vardas     Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < numb; i++) {
            cout << rezult[i].vardas << "     " << rezult[i].pavarde << "     " << rezult[i].gal << "     " << rezult[i].galm << endl;
        }
}
