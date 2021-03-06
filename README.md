# VU OOP
## Duomenų apdorojimas
## Intro
Užduotis atlikta Objektinio programavimo kursui (VU Informacinių sistemų inžinerija).
[UŽDUOTIES PUSLAPIS](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis)

## Versijos
### v0.1

Programa nuskaito studento V/P (input), namų darbų bei egzamino rezultatus. Rezultatas išvedamas į konsolę. Vėliau panaudotos dvi skirtingos konteinerių rūšys: C masyvas ir vektorius. Juose saugomi namų darbų rezultatai. Pridėta atsitiktinių pažymių generacija.

### v0.2

Duomenų nuskaitymas iš ```kursiokai.txt``` failo. Sukurtas sulygiuotų rezultatų išvedimas į konsolę surikiavus studentus.

### v0.3

Iškeltos funkcijos bei struktūros į atskirus header failus ```/headers/``` aplanke. Panaudoti ```exception handling``` metodai, kad apsaugoti programą nuo neveikimo dėl nesamo duomenų nuskaitymo failo.

### v0.4

#### Programos greičio spartos analizė
- **10 studentų generacija:**
    - [Nuotrauka](https://imgur.com/GflAb6K.png)
- **100 studentų generacija:**
    - [Nuotrauka](https://imgur.com/mxKBVGF.png)
    - [Nuotrauka](https://imgur.com/xZqENN0.png)
- **1000 studentų generacija:**
    - [Nuotrauka](https://imgur.com/RquAXVO.png)
    - [Nuotrauka](https://imgur.com/3GHTgBF.png)
- **10000 studentų generacija:**
    - [Nuotrauka](https://imgur.com/0jEeez4.png)
    - [Nuotrauka](https://imgur.com/WYi0t6p.png)
- **Maksimali studentų generacija (29000 studentų):**
    - [Nuotrauka](https://imgur.com/xJ9jNFd.png)
    - Rezultatas nebuvo išvedamas į konsolę, nes per didelis studentų skaičius priverstų programą sunaudoti per didelę dalį atminties bei gali priversti nutraukti tolimesnį programos vykdymą dėl apkrovos procesoriui.
- **CPU apkrova, kai studentų generuojama daugiau, negu 29000:**
    - [Nuotrauka](https://imgur.com/AOXIeAf.png)

### v0.5

#### Programos testavimas naudojant skirtingus STL konteinerius
- [Vector](https://imgur.com/skcD1pY.png)
- [List](https://imgur.com/D1COYZj.png)
- [Deque](https://imgur.com/6vJbsoB.png)

### v1.0 Final version

#### The two strategy comparison (speed test):

**VECTORS:**
- 1st WAY
```
Data input : 12.2456 s
List generation : 2.30376 s
Output file creation : 31.3149 s
```
- 2nd WAY
```
Data input : 23.1446 s
List generation : 2.9846 s
Output file creation : 25.7201 s
```

**DEQUE:**
- 1st WAY
```
Data input : 7.1919 s
List generation : 9.05115 s
Output file creation : 59.7953 s
```
- 2nd WAY
```
Data input : 8.54892 s
List generation : 8.01951 s
Output file creation : 23.987 s
```

**LIST:**
- 1st WAY
```
Data input : 6.75256 s
List generation : 2.51547 s
Output file creation : 30.6666 s
```
- 2nd WAY
```
Data input : 23.9859 s
List generation : 4.11313 s
Output file creation : 19.7126 s
```

### Kaip paleisti programą?

Jeigu naudojate CLion, tai paleisti programą galima su CMake pagalba. O jeigu norite paleisti programą su terminalu (CMD prompt), tai šitas kodas tai padarys:
```g++ -o main main.cpp headers/studs.h headers/student.h headers/main.h headers/functions.cpp```