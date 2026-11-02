#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Subject {
    string name;
    int credits;
    double gradePoints;
};

bool readPositiveInt(const string& prompt, int& value) {
    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (value > 0) {
                return true;
            }

            cout << "Please enter a number greater than zero.\n";
        } else {
            if (cin.eof()) {
                return false;
            }

            cout << "Please enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool readSubject(
    Subject& subject,
    const map<string, double>& gradeScale
) {
    while (true) {
        cout << "Subject name: ";

        if (!getline(cin, subject.name)) {
            return false;
        }

        if (!subject.name.empty()) {
            break;
        }

        cout << "Subject name cannot be empty.\n";
    }

    if (!readPositiveInt("Credits: ", subject.credits)) {
        return false;
    }

    string grade;

    while (true) {
        cout << "Grade (O, A+, A, B+, B, C, F): ";

        if (!(cin >> grade)) {
            return false;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        map<string, double>::const_iterator found =
            gradeScale.find(grade);

        if (found != gradeScale.end()) {
            subject.gradePoints = found->second;
            return true;
        }

        cout << "That grade is not on the grade scale. Try again.\n";
    }
}

double calculateGpa(const vector<Subject>& subjects) {
    double weightedPoints = 0.0;
    long long totalCredits = 0;

    for (size_t i = 0; i < subjects.size(); ++i) {
        weightedPoints += subjects[i].credits * subjects[i].gradePoints;
        totalCredits += subjects[i].credits;
    }

    if (totalCredits == 0) {
        return 0.0;
    }

    return weightedPoints / totalCredits;
}

int main() {
    const map<string, double> gradeScale = {
        {"O", 10}, {"A+", 9}, {"A", 8}, {"B+", 7},
        {"B", 6}, {"C", 5}, {"F", 0}
    };

    int semesterCount;

    if (!readPositiveInt("Number of semesters: ", semesterCount)) {
        return 0;
    }

    double allWeightedPoints = 0.0;
    long long allCredits = 0;

    for (int semester = 1; semester <= semesterCount; ++semester) {
        cout << "\nSemester " << semester << '\n';

        int subjectCount;

        if (!readPositiveInt("Number of subjects: ", subjectCount)) {
            return 0;
        }

        vector<Subject> subjects;

        for (int i = 0; i < subjectCount; ++i) {
            cout << "\nSubject " << i + 1 << '\n';

            Subject subject;

            if (!readSubject(subject, gradeScale)) {
                return 0;
            }

            subjects.push_back(subject);
            allWeightedPoints += subject.credits * subject.gradePoints;
            allCredits += subject.credits;
        }

        cout << fixed << setprecision(2);
        cout << "SGPA for semester " << semester << ": "
             << calculateGpa(subjects) << '\n';
    }

    if (allCredits > 0) {
        cout << "\nOverall CGPA: "
             << allWeightedPoints / allCredits << '\n';
    }

    return 0;
}
