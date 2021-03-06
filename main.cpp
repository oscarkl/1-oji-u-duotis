#include "struktura.h"
#include "skaiciai.h"

int sk;
int counter=0;
double durs;
double duro;
#define MAXBUFLEN 1000000

using namespace std;

vector<studentas> rezult;

double dur[5];

void ivestis(int i, int max, char type) {
    string pavard;
    string nd;
    int sk;
    bool g = true;
    std::cout << "pavarde: ";
    cin >> pavard;
    if (isNumber(pavard)) {
        std::cout << "netinkama pavarde" << endl;
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
            nd = sansas(nd, rand());
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
void input(int& o) {
    char skait;
    if (o == 0) {
        cout << "ar norite naudoti jau sugeneruotus studenus? T/N:" << endl;
        cin >> skait;
        if (skait == 'T' || skait == 't')
        {
            cout << "pasirinkite faila kuri skaityti" << endl;
            cout << "(1) 1000" << endl;
            cout << "(2) 10000" << endl;
            cout << "(3) 100000" << endl;
            cout << "(4) 1000000" << endl;
            cout << "(5) 10000000" << endl;
            cin >> o;
        }
    }
    string name = "Kurstiokai.txt";
    if (o > 0) {
        name = to_string(int(1000 * pow(10, o - 1))) + "_studentu.txt";
    }
    cout << name;
    ifstream fd(name);
    if (fd) {
        if (fd.eof()) {
            cout << "failas yra tuscias" << endl;
        }
        else {
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
                        //cout << temp.vardas << " " << temp.pavarde <<" "<<temp.gal<<endl;
                        temp.n.clear();
                        temp.vidurkis = 0;
                    }
                    temp.vardas = data;
                    fd >> data;
                    temp.pavarde = data;
                    //cout << temp.pavarde;

                }
                else {
                    //cout << temp.vardas << endl;
                    sk = stoi(data);
                    temp.vidurkis += sk;
                    temp.n.push_back(sk);
                    j = 1;
                }

            }
            //cout << rezult.size() << " ";
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
            fd.close();
        }
    }
}
bool compare_5(const studentas& v) { return v.gal == 5; }

void output(int o) {
    //cout << rezult[0].gal;
    auto is = chrono::high_resolution_clock::now();
    sort(rezult.begin(), rezult.end(), [](const studentas& a, const studentas& b)
        {
            return a.gal < b.gal;
        });
    auto it = std::find_if(rezult.begin(), rezult.end(), compare_5);
    
    vector<studentas> kietiakai(it, rezult.end());
    
    vector<studentas> nevyk(rezult.begin(), it);
    
    //rezult.resize(rezult.size()-kietiakai.size());    
    rezult.clear();
    
    auto out = chrono::high_resolution_clock::now();
    auto dura = chrono::duration_cast<chrono::microseconds>(out-is);
    durs = dura.count();
    ofstream fr("ats.txt");
    fr << left << setw(16) << "Vardas" << left << setw(16)<<"Pavarde"<< left << setw(16)<<"Galutinis(vid.)" << left << setw(16)<< "Galutinis(med.)" << endl;
    fr << "-----------------------------" << endl;
    for (int i = 0; i < rezult.size(); i++) {
        fr << left << setw(16) << rezult[i].vardas << left << setw(16) << rezult[i].pavarde << left << setw(16) << fixed << setprecision(2)<< rezult[i].gal << left << setw(16) << fixed << setprecision(2)<< rezult[i].galm << endl;
    }
    fr.close();
    if (o > 0) {
        ofstream fr("nevykeliai.txt");
        fr << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(16) << "Galutinis(vid.)" << left << setw(16) << "Galutinis(med.)" << endl;
        fr << "-----------------------------" << endl;
        for (int i = 0; i < nevyk.size(); i++) {
            fr << left << setw(16) << nevyk[i].vardas << left << setw(16) << nevyk[i].pavarde << left << setw(16) << fixed << setprecision(2) << nevyk[i].gal << left << setw(16) << fixed << setprecision(2) << nevyk[i].galm << endl;
        }
        nevyk.clear();
        fr.close();
        ofstream fp("kietiakai.txt");
        fp << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(16) << "Galutinis(vid.)" << left << setw(16) << "Galutinis(med.)" << endl;
        fp << "-----------------------------" << endl;
        for (int i = 0; i < kietiakai.size(); i++) {
            fp << left << setw(16) << kietiakai[i].vardas << left << setw(16) << kietiakai[i].pavarde << left << setw(16) << fixed << setprecision(2) << kietiakai[i].gal << left << setw(16) << fixed << setprecision(2) << kietiakai[i].galm << endl;
        }
        kietiakai.clear();
        fp.close();
    }
    auto end = chrono::high_resolution_clock::now();
    auto durb = chrono::duration_cast<chrono::microseconds>(out - is);
    duro = durb.count();
}

void filegen() {
    studentas temp;
    string name;
    int skai;
    for (int i = 0; i < 5; i++) {
        auto start = chrono::high_resolution_clock::now();
        name = to_string(int(1000*pow(10,i)))+"_studentu.txt";
        cout << name<<endl;
        ofstream fr(name);
        fr << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(8) << "ND1" << left << setw(8) << "ND2" << left << setw(8) << "ND3" << left << setw(8) << "ND4" << left << setw(8) << "Egz." << endl;
        skai = 1000 * pow(10, i);
        for (int j = 1; j <= skai; j++) {
            temp.vardas = "Vardas" + to_string(j);
            temp.pavarde = "Pavarde" + to_string(j);
            for (int k = 0; k < 5; k++) {                
                temp.n.push_back(rand() % 10 + 1);
            }
            fr << left << setw(16) << temp.vardas << left << setw(16) << temp.pavarde << left << setw(8) << temp.n[0] << left << setw(8) << temp.n[1] << left << setw(8) << temp.n[2] << left << setw(8) << temp.n[3] << left << setw(8) << temp.n[4] << "\n";
            temp.n.clear();
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        dur[i] = duration.count()/double(1000);
        
        fr.close();
    }
}



int main() {
    auto pradz = chrono::high_resolution_clock::now();
    srand(time(NULL));
    int studentSk;
    char type;
    char skait;
    std::cout << "ar skaityti is failo T/N";
    cin >> skait;
    try {     
        if (skait != 'T' || skait != 't' || skait != 'N' || skait != 'n')
        {
            throw "netinkama ivestis";
        }       
    }
    catch(...){
        std::cout << "netinkama ivestis" << endl;
    }
    if (skait == 'N' || skait == 'n') {
        std::cout << "ivesti ar generuoti? i/g: ";
        cin >> type;
        try {
            if (type != 'I' || type != 'i' || type != 'G' || type != 'g')
            {
                throw "netinkama ivestis";
            }
        }
        catch (...) {
            std::cout << "netinkama ivestis" << endl;
        }
        if (type == 'i' || type == 'I') {
            std::cout << "Studentu sk: ";
            cin >> studentSk;
            for (int i = 0; i < studentSk; i++) {
                rezult.push_back(studentas());
            }
        }
        if (type == 'g' || type == 'G') {
            studentSk = rand() % 3 + 1;
            std::cout << "Studentu sk: " << studentSk << endl;
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
            std::cout << "ar yra daugiau studentu? T/N" << endl;
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
                std::cout << "netinkama ivestis" << endl;
            }
        }

        std::cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavarde" << left << setw(16) << "Galutinis(vid.)" << left << setw(16) << "Galutinis(med.)" << endl;
        std::cout << "-----------------------------" << endl;
        for (int i = 0; i < j + 1; i++) {
            std::cout << left << setw(16) << rezult[i].vardas << left << setw(16) << rezult[i].pavarde << left << setw(16) << fixed << setprecision(2) << rezult[i].gal << left << setw(16) << fixed << setprecision(2) << rezult[i].galm << endl;
        }
    }
    if (skait == 'T' || skait == 't') {
        int o;
        cout << "ar generuoti failus? T/N" << endl;
        cin >> skait;
        if (skait == 'N' || skait == 'n') {
            o = 0;
            //input(o);
            //sort(rezult.begin(), rezult.end(), [](const studentas& a, const studentas& b)
                //{
                    //return a.vardas < b.vardas;
                //});
            //output(o);
        }
        if (skait == 'T' || skait == 't') {
            filegen();
            cout << "pasirinkite faila kuri skirstyti" << endl;
            cout << "(1) 1000" << endl;
            cout << "(2) 10000" << endl;
            cout << "(3) 100000" << endl;
            cout << "(4) 1000000" << endl;
            cout << "(5) 10000000" << endl;
            cin >> o;
        }
            auto in = chrono::high_resolution_clock::now();
            input(o);
            auto out = chrono::high_resolution_clock::now();
            auto dura = chrono::duration_cast<chrono::microseconds>(out - in);


            auto pr = chrono::high_resolution_clock::now();
            output(o);
            auto pa = chrono::high_resolution_clock::now();
            auto ilg = chrono::duration_cast<chrono::microseconds>(pa-pr);

            for (int i = 0; i < 5; i++) {
                cout << "failo is " << fixed << int(1000 * pow(10, i)) << " skaiciu generavimas: " << dur[i] << endl;
                if (o == i + 1) {
                    cout << "skaitymas is " <<fixed<< int(1000 * pow(10, i)) << " skaiciu failo: " << dura.count() / double(1000000) << endl;
                    cout << "rusiavimas " << fixed << int(1000 * pow(10, i)) << " skaiciu failo: " << durs / double(1000000) << endl;
                    cout << "surusiuotu studentu is " << fixed << int(1000 * pow(10, i)) << " skaiciu failo spausdinimas: " << duro / double(1000000) << endl;
                }
                cout << endl;
            }
            auto pab = chrono::high_resolution_clock::now();
            auto truk = chrono::duration_cast<chrono::milliseconds>(pab - pradz);
            cout <<"visos programos laikas "<<truk.count() / double(1000)<< endl;
    }
}
