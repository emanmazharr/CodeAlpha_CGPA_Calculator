#include <iostream>
#include <iomanip>
#include <windows.h>
#include <sstream> // to replace to_string()
using namespace std;

void header(string title) {
    system("cls");
    cout << "=============================\n";
    cout << "     " << title << "\n";
    cout << "=============================\n\n";
    Sleep(300);
}

int main() {
    int n;
    header("CGPA CALCULATOR");
    cout << "Enter number of courses: ";
    cin >> n;

    string courseName[50];
    float grade[50];
    int credit[50];
    float totalGradePoints = 0, totalCredits = 0;

    for (int i = 0; i < n; i++) {
        stringstream ss;
        ss << "Course Entry " << (i + 1);
        header(ss.str());

        cout << "Course name: ";
        cin >> ws;
        getline(cin, courseName[i]);
        cout << "Grade (on 4.0 scale): ";
        cin >> grade[i];
        cout << "Credit hours: ";
        cin >> credit[i];

        totalGradePoints += grade[i] * credit[i];
        totalCredits += credit[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    header("RESULT SUMMARY");
    for (int i = 0; i < n; i++) {
        cout << setw(2) << i + 1 << ". " << courseName[i]
             << " | Grade: " << grade[i]
             << " | Credit: " << credit[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nFinal CGPA: " << cgpa << endl;

    system("pause");
    return 0;
}

