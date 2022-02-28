#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include <string>
#include <vector>  
#include <fstream>
#include <sstream>
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

string sansas(string& nd) {
    if (rand() % 8 != 0) {
        nd = to_string(rand() % 10 + 1);
    }
    else {
        nd = "oskaras";
    }
    return nd;
}

void ivestis(int i, int max, char type) {
    string pavard;
    string nd;
    int sk;
    bool g = true;
    cout << "pavarde: ";
    cin >> pavard;
    if (isNumber(pavard)) {
        cout << "netinkama pavarde" << endl;
        g = false;
        if (i + 1 < max) {
            rezult[i + 1].vardas = nd;
        }
    }
    rezult[i].pavarde = pavard;
    while (g) {
        if (type == 'i' || type == 'I') {
            cin >> nd;
        }
        if (type == 'g' || type == 'G') {
            nd = sansas(nd);
        }


        if (isNumber(nd)) {
            //cout << nd << endl;
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
        rezult[i].med = rezult[i].n[j / 2];
    }
    else {
        rezult[i].med = (rezult[i].n[j / 2 - 1] + rezult[i].n[j / 2]) / 2;
    }
}

void galVid(int i) {
    rezult[i].gal = 0.6 * rezult[i].n.back() + 0.4 * rezult[i].vidurkis;
    rezult[i].galm = 0.6 * rezult[i].n.back() + 0.4 * rezult[i].med;
}
void input() {
    ifstream fd("studentai10000.txt");
    string data;
    int sk;
    int j = 0;
    int g = true;  
    getline(fd, data);
    studentas temp;
    studentas zero;
    while (!fd.eof()) {  
        fd >> data;
            if (!isNumber(data))
            {
                if (j == 1) {
                    temp.vidurkis = (temp.vidurkis - temp.n.back()) / (temp.n.size() - 1);
                    if ((temp.n.size() - 1) % 2 == 1) {
                        temp.med = temp.n[(temp.n.size() - 1) / 2];
                    }
                    else {
                        temp.med = (temp.n[(temp.n.size() - 1) / 2 - 1] + temp.n[(temp.n.size() - 1) / 2]) / 2;
                    }
                    temp.gal = 0.6 * temp.n.back() + 0.4 * temp.vidurkis;
                    temp.galm = 0.6 * temp.n.back() + 0.4 * temp.med;
                    rezult.push_back(temp);
                    temp = zero;
                }
                    temp.vardas = data;
                    cout << data << endl;
                    fd >> data;
                    temp.pavarde = data;
                    cout << data << endl;
            }
            else {
                //cout << A << endl;
                sk = stoi(data);
                temp.vidurkis += sk;
                temp.n.push_back(sk);
            }
            j = 1;
    }
    temp.vidurkis = (temp.vidurkis - temp.n.back()) / (temp.n.size() - 1);
    if ((temp.n.size() - 1) % 2 == 1) {
        temp.med = temp.n[(temp.n.size() - 1) / 2];
    }
    else {
        temp.med = (temp.n[(temp.n.size() - 1) / 2 - 1] + temp.n[(temp.n.size() - 1) / 2]) / 2;
    }
    temp.gal = 0.6 * temp.n.back() + 0.4 * temp.vidurkis;
    temp.galm = 0.6 * temp.n.back() + 0.4 * temp.med;
    rezult.push_back(temp);
    cout << rezult[0].gal;
    fd.close();
}


int main() {
    srand(time(NULL));
    int studentSk;
    char type;
    char skait;
    cout << "ar skaityti is failo T/N";
    cin >> skait;
    if (skait == 'N' || skait == 'n') {
        cout << "ivesti ar generuoti? i/g: ";
        cin >> type;
        if (type == 'i' || type == 'I') {
            cout << "Studentu sk: ";
            cin >> studentSk;
            for (int i = 0; i < studentSk; i++) {
                rezult.push_back(studentas());
            }
        }
        if (type == 'g' || type == 'G') {
            studentSk = rand() % 3 + 1;
            cout << "Studentu sk: " << studentSk << endl;
            for (int i = 0; i < studentSk; i++) {
                rezult.push_back(studentas());
            }
        }
        //cin >> rezult[0].vardas;
        rezult[0].vardas = "oskaras";
        for (int i = 0; i < studentSk; i++) {
            ivestis(i, studentSk, type);
            if (rezult[i].n.size() > 1) {
                rezult[i].vidurkis = (rezult[i].vidurkis - rezult[i].n.back()) / (rezult[i].n.size() - 1);
                medi(i, rezult[i].n.size() - 1);
                galVid(i);
            }
            else {
                rezult[i].gal = 0;
                rezult[i].galm = 0;
            }
        }
        int j = studentSk - 1;
        char ats;
        bool y = true;
        while (y) {
            cout << "ar yra daugiau studentu? T/N" << endl;
            cin >> ats;
            if (ats == 'N' || ats == 'n') {
                y = false;
            }
            else if (ats == 'T' || ats == 't') {
                j++;
                rezult.push_back(studentas());
                rezult[j].vardas = "oskaras";
                ivestis(j, j + 1, type);
                if (rezult[j].n.size() > 1) {
                    rezult[j].vidurkis = (rezult[j].vidurkis - rezult[j].n.back()) / (rezult[j].n.size() - 1);
                    medi(j, rezult[j].n.size() - 1);
                    galVid(j);
                }
                else {
                    rezult[j].gal = 0;
                    rezult[j].galm = 0;
                }
            }
            else {
                cout << "netinkama ivestis" << endl;
            }
        }

        cout << "Pavarde     Vardas     Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < j + 1; i++) {
            cout << rezult[i].vardas << "     " << rezult[i].pavarde << "     " << rezult[i].gal << "     " << rezult[i].galm << endl;
        }
    }
    if (skait == 'T' || skait == 't') {
        input();
    }
}
