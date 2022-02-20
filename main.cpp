#include <iostream>
#include <math.h>
#include <vector>  
int sk;

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    double n;// pazymiu skaicius
    double vidurkis = 0;
    double med=0;
    double egz;
    double gal;
};

studentas rezult;

void as() {
    double nd;//pazymys
    cout << "iveskite varda ";
    cin >> rezult.vardas;
    cout << "iveskite pavarde ";
    cin >> rezult.pavarde;
    cout << "iveskite kiek pazymiu ";
    cin >> rezult.n;
    int t = rezult.n;//laiko n verte kaip int
    for (int i = 0; i < rezult.n; i++) {// iveda visus skaicius + randa mediana
        cout << "iveskite pazymi ";
        cin >> nd;
        rezult.vidurkis += nd;
        
        if (t % 2 == 1) {
            if (i == t / 2) {
                rezult.med = nd;
            }
        }
        else {
            if (i+1 == t / 2 || i==t/2) {
                rezult.med += nd/2;
            }
        }
        
    }
    rezult.vidurkis = rezult.vidurkis / rezult.n;
    cout << "iveskite egzamino rezultata ";
    cin >> rezult.egz;
    cout << "Pavarde     Vardas     Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "-----------------------------" << endl;
    rezult.gal = 0.6 * rezult.egz + 0.4 * rezult.vidurkis;
    cout << rezult.vardas << "     " << rezult.pavarde << "     " << rezult.gal << "     " << rezult.med << endl;
}


int main() {
    cout << "kiek studentu ";
    cin >> sk;
    for (int i = 0; i < sk; i++) {
        as();
    }
    
    
}
