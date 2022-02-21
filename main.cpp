#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>  
int sk;

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    double vidurkis = 0;
    double med, gal, galm;
    vector<int> n;
};

bool isNumber(const string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
vector<studentas> rezult;

void ivestis(int i, int max) {
    string pavard;
    string nd;
    int sk;
    bool g = true;
    cin >> pavard;
    rezult[i].pavarde = pavard;
    while (g) {
        cin >> nd;
        if (isNumber(nd)) {
            sk = stoi(nd);
            rezult[i].n.push_back(sk);
            rezult[i].vidurkis += sk;
        }
        else {
            g = false;
            
            if (i + 1 < max) {
                rezult[i + 1].vardas = nd;
            }
        }
    }
}
void medi(int i, int j) {
    if (j % 2 == 1) {
       rezult[i].med = rezult[i].n[j / 2 + 1];
    }
    else {
        rezult[i].med = (rezult[i].n[j / 2] + rezult[i].n[j / 2 + 1]) / 2;
    }
}

void galVid(int i) {
    rezult[i].gal = 0.6 * rezult[i].n.back() + 0.4 * rezult[i].vidurkis;
    rezult[i].galm = 0.6 * rezult[i].med + 0.4 * rezult[i].vidurkis;
}


int main() {
    int studentSk = rand() % 3 + 1;
    cout << studentSk;
    for (int i = 0; i < studentSk; i++) {
        rezult.push_back(studentas());
    }
    cin >> rezult[0].vardas;
    for (int i = 0; i < studentSk; i++) {
        ivestis(i, studentSk);
        rezult[i].vidurkis = (rezult[i].vidurkis - rezult[i].n.back()) / rezult[i].n.size();
        medi(i, rezult[i].n.size());
        galVid(i);
    }
    cout << "Pavarde     Vardas     Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < studentSk; i++) {
        cout << rezult[i].vardas << "     " << rezult[i].pavarde << "     " << rezult[i].gal << "     " << rezult[i].galm << endl;
    }
}
