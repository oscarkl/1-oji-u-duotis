Pirmoji Užduotis - v0.1 

Aprašymas v0.12
Ši programa paėma studento vardą, pavardę, namų darbų rezultatus ir egzamino rezultatą ir apskaičiuoją vidurkį pagal šią formulę
GalutinisVid = 0.4 * vidurkis + 0.6 egzaminas
Taip pat galutinis vidurkis yra skaičiuojamas pagal medianą; 
GalutinisVid = 0.4 * mediana + 0.6 * egzaminas 
programa gavus visus duomenis išspausdina studento vardą, pavardę ir abu galutinio vidurkio variantus

Failai 
Užduotį sudaro **main.cpp** failas
Kuriame viskas saugoma yra vektoriuose. 

Instrukcijos 
Programos naudojimo gidas: 
1. Programa pradžioj paklausia vartotojo ar atsitiktinai generuoti ar ivesti duomenis
2. pasirinkus ivestį vartotojas iveda kiek studentų, kiekvienam priskiria vardą, pavardę, ir įveda jo pažymius, programa pereina prie kito studento/susistabdo kai vietoj skaitinės vertės ivedama kazkoks simbolis ar string kuris tada priskiriamas kaip kito studento varas.
3. pasirinkus generavimą programa atomatiškai sugeneruoja kažkoki studentų skaičiū, kiekvienam studentui priskiriamas vardas "oskaras", tačiau pavardę vistiek įveda vartotojas, tada yra generuojama skaičiai tarp 1 ir 10, ir yra 1/8 šansas, kad vietoj skaičiaus įves vardą kuris bus priskiriamas sekančiuj studentui.
4. pasibaigus pradiniam studentu skaiciui programa klausia ar dar nori pridėti studentu, atsakius ne programa baigiasi ir atspausdina sarašą visų studentų su jų vidurkiais, atsakius taip ivedami dar vieno studento duomenys, klausimas kartojasi kol vartotojas atsako ne
