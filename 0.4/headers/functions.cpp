//Student functions---------------------------------------------------------------------------------------

#include "student.h"

    double Student::calculateScore(){
        double sum = 0;
        for(double mark : homework)
            sum += mark;
        return (0.4*(sum/homework.size())) + (0.6*examScore);
    };
    double Student::median() {
        double m;
        sort(homework.begin(),homework.end());
        if(homework.size()%2 == 0){
            m = (homework[homework.size()/2]+homework[(homework.size()/2)-1])/2.0;
        }
        else{
            m = homework[homework.size()/2];
        }
        return (m*0.4) + (0.6*examScore);
    }
    void Student::setName(string name){
        firstName = name;
    }
    void Student::setLastName(string lname){
        lastName = lname;
    }
    void Student::setMark(double mark){
        homework.push_back(mark);
    }
    void Student::setExam(double exam){
        examScore = exam;
    }

//Studs FUNCTIONS ---------------------------------------------------------------------------------

#include "studs.h"

bool Studs::checkFile(const char *fileName){
    std::ifstream infile(fileName);
    return infile.good();
}

void Studs::inputData(){
    string text;
    int number, choice,mark;
    while(true){
        Student temp;

        cout << "Įveskite studento vardą: " << endl;
        cin >> text;
        temp.setName(text);

        cout << "Įveskite studento pavardę: " << endl;
        cin >> text;
        temp.setLastName(text);

        cout << "Įveskite studento namų darbų užduočių skaičių: " << endl;
        cin >> number;
        if(!cin)
        {
            cout << "Bad input!" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> number;
        }

        cout << "Ar norite generuoti atsitiktinius pažymius? (1/0)" << endl;
        cin >> choice;

        if(choice == 1){
            srand(0);
            for(int i=0;i<number;i++){
                temp.setMark(1+(double)rand()/RAND_MAX*9);
            }
            cout << "Sugeneruota!" << endl;

        }
        else{

            for(int i=0;i<number;i++){
                cout << "Įveskite studento namų darbų rezultatą: " << endl;
                cin >> mark;
                temp.setMark(mark);
            }

        }

        cout << "Įveskite studento egzamino rezultatą: " << endl;
        cin >> number;
        temp.setExam(number);

        while(true) {

            cout << "Pridėti dar vieną studentą? (1/0) ";
            cin >> choice;
            if(choice == 0 || choice == 1)
                break;

        }
        students.push_back(temp);
        if(choice==0)
            return;

    }
}

void Studs::checkLongestNames(){
    int fname=longestName,lname=longestLastName;
    for (const auto &el : students){
        if(el.firstName.length() > fname)
            fname = el.firstName.length();
        if(el.lastName.length() > lname)
            lname = el.lastName.length();
    }
    longestName = fname;
    longestLastName = lname;
}

void Studs::readFileData(const char input[]){
    if(!checkFile(input))
    {
        throw "Nuskaitymo failas neegzistuoja!";
    }
    string text;
    int number, choice,mark;
    std::ifstream x(input);
    while(true){
        Student temp;

        if(x.eof())
            break;

        x >> text;
        temp.setName(text);

        x >> text;
        temp.setLastName(text);

        x >> number;

        for(int i=0;i<number;i++){
            x >> mark;
            temp.setMark(mark);
        }

        x >> number;
        temp.setExam(number);

        students.push_back(temp);

    }
}


void Studs::printResult(){
    checkLongestNames();
    sortStudents();
        cout << left << setw(longestName+1) << "Vardas" << setw(longestLastName+1) << "Pavardė" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for(auto student:students){
            cout << left << setw(longestName+1) << student.firstName << setw(longestLastName+1) << student.lastName << setw(20) << fixed << setprecision(2) << student.calculateScore() << setw(15) << fixed << setprecision(2) << student.median() << endl;
        }
}

void Studs::sortStudents() {
    std::sort(students.begin(), students.end(),
              [](Student& lhs, Student& rhs) {
                  return lhs.firstName > rhs.firstName;
              });
}

void Studs::generateLists(int n){
    std::ofstream out("generatedList.txt");
    Student temp;
    int number,mark;
    srand(0);
    for(int i=1;i<=n;i++){
        temp.firstName = "Vardas" + std::to_string(i);
        out << temp.firstName << " ";
        temp.lastName = "Pavarde" + std::to_string(i);
        out << temp.lastName << " ";
        number = 1+(double)rand()/RAND_MAX*9;
        out << number << " ";
        for(int j=0;j<number;j++){
            mark = 1+(double)rand()/RAND_MAX*9;
            temp.setMark(mark);
            out << mark << " ";
        }
        temp.examScore = 1+(double)rand()/RAND_MAX*9;
        out << temp.examScore << endl;
        students.push_back(temp);
    }
    out.close();
}

void Studs::sortByMarks(){
    std::ofstream out1("vargsiukai.txt");
    std::ofstream out2("kietekai.txt");
    for(auto student:students){
        if(student.calculateScore() < 5.0){
            out1 << student.firstName << " " << student.lastName << " " << fixed << setprecision(2) << student.calculateScore() << endl;
        }
        else{
            out2 << student.firstName << " " << student.lastName << " " << fixed << setprecision(2) << student.calculateScore() << endl;
        }
    }
    out1.close();
    out2.close();
}

//Timer functions
#include "timer.h"

void Timer::startClock() {
    start = std::chrono::high_resolution_clock::now();
}

void Timer::endClock(string opName) {
    end = std::chrono::high_resolution_clock::now();
    duration = end-start;
    cout << "\x1B[31m" << opName <<  " : " << duration.count() << " s" << "\033[0m\t\t" << std::endl;

}