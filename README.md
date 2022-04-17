Pirmoji Užduotis - v0.4
====

Aprašymas v0.4 
==
Ši programa paėma studento vardą, pavardę, namų darbų rezultatus ir egzamino rezultatą iš teksto failo ir apskaičiuoją vidurkį pagal šią formulę  
GalutinisVid = 0.4 * vidurkis + 0.6 egzaminas  
Taip pat galutinis vidurkis yra skaičiuojamas pagal medianą;  
GalutinisVid = 0.4 * mediana + 0.6 * egzaminas   
Teksto failą gailma naujai sugeneruoti ir tai sukurs 5 failus su dydžiais nuo 1000 iki 10000000  
Programa gavus visus duomenis išrūšiuoja studentus į dvi grupes: kietiakai ir nevykeliai ir tada juos išspausdina i 2 atskirus failus su studento vardu, pavardę ir abiejais galutinio vidurkio variantais  

Failai 
==
Užduotį sudaro **main.cpp** failas  
Kuriame viskas saugoma yra vektoriuose.   
**kursiokai.txt** failas iš kurio traukemi visi v0.2 uzduotyje duoti duomenys  
**ats.txt** failas kuriame spausdinami visi studentų duomenys  
**kietekai.txt** failas kuriame spausdinami visū studentų duomenys kurių vidurkis bent 5  
**nevykeliai.txt** failas kuriame spausdinami visū studentų duomenys kurių vidurkis mažiau nei 5  
**struktura.h** failas kuriame laikoma struktūros aprašymas  
**skaiciai.h** failas kuriame laikoma tikrinimo ar skaičius ir skaičių generavimo funkcijos  
**1000.txt** 1000 studentų dydžio sugeneruotas failas  
**10000.txt** 10000 studentų dydžio sugeneruotas failas  
**100000.txt** 100000 studentų dydžio sugeneruotas failas  
**1000000.txt** 1000000 studentų dydžio sugeneruotas failas  
**10000000.txt**10000000 studentų dydžio sugeneruotas failas  

Instrukcijos 
==
Programos naudojimo gidas: 
1. Programa paklausa vartotojo ar skaityti duomenis iš teksto failo, jei ne vykdoma v0.1 versija
2. Jei pasirinkta taip klausiama ar generuoti failus ar naudoti jau sugeneruotus failus
3. jei pasirinkta generuoti tai sugeneruos 5 naujus failus su dydžiais nuo 1000 iki 10000000
4. Tada klausiama kuri failą norite nuskaityti
5. Programa nuskaičius faila surušiuoja viską ir atspausdina duomenis i **"kietekai.txt"** ir **"nevykeliai.txt"** failus
