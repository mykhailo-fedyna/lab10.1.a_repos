#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// Перелік спеціальностей
enum Specialnist { KN, PM, FI };
string specialnistStr[] = { "КН", "ПМ", "ФІ" };

// Структура студента з об'єднанням для оцінок
struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    union {
        struct {
            int ocinka_fizyka;
            int ocinka_matematyka;
            int ocinka_informatyka;
        };
        int ocinki[3]; // Альтернативне представлення оцінок у вигляді масиву
    };
};

// Функція для створення масиву студентів
void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << " Прізвище: ";
        cin >> students[i].prizv;
        cout << " Курс: ";
        cin >> students[i].kurs;
        cout << " Спеціальність (0 - КН, 1 - ПМ, 2 - ФІ): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // Введення оцінок з усіх предметів
        cout << " Оцінка з фізики: ";
        cin >> students[i].ocinka_fizyka;
        cout << " Оцінка з математики: ";
        cin >> students[i].ocinka_matematyka;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].ocinka_informatyka;
        cout << endl;
    }
}

// Функція для виведення таблиці студентів
void PrintStudents(const Student* students, const int N) {
    cout << "=============================================================================================================" << endl;
    cout << "| № | Прізвище        | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з інформатики |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(2) << i + 1
            << " |  " << setw(15) << left << students[i].prizv
            << "|   " << setw(3) << students[i].kurs
            << "|" << setw(15) << specialnistStr[students[i].specialnist]
            << "|   " << setw(14) << students[i].ocinka_fizyka
            << "|   " << setw(18) << students[i].ocinka_matematyka
            << "| " << setw(20) << students[i].ocinka_informatyka << " |" << endl;
    }
    cout << "=============================================================================================================" << endl;
}

// Функція для обчислення кількості студентів із середнім балом меншим за 4
int CountLowAverageStudents(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double average = (students[i].ocinka_fizyka + students[i].ocinka_matematyka + students[i].ocinka_informatyka) / 3.0;
        if (average < 4.0) {
            count++;
        }
    }
    return count;
}

// Функція для визначення предмету з найменшим середнім балом
string FindSubjectWithLowestAverage(const Student* students, const int N) {
    double sum_fizyka = 0, sum_matematyka = 0, sum_informatyka = 0;

    for (int i = 0; i < N; i++) {
        sum_fizyka += students[i].ocinka_fizyka;
        sum_matematyka += students[i].ocinka_matematyka;
        sum_informatyka += students[i].ocinka_informatyka;
    }

    double avg_fizyka = sum_fizyka / N;
    double avg_matematyka = sum_matematyka / N;
    double avg_informatyka = sum_informatyka / N;

    if (avg_fizyka <= avg_matematyka && avg_fizyka <= avg_informatyka) {
        return "Фізика";
    }
    else if (avg_matematyka <= avg_fizyka && avg_matematyka <= avg_informatyka) {
        return "Математика";
    }
    else {
        return "Інформатика";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    int lowAvgCount = CountLowAverageStudents(students, N);
    cout << "Кількість студентів із середнім балом менше 4: " << lowAvgCount << endl;

    string lowestAvgSubject = FindSubjectWithLowestAverage(students, N);
    cout << "Предмет з найменшим середнім балом: " << lowestAvgSubject << endl;

    delete[] students;
    return 0;
}
