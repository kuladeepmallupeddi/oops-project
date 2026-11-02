# CGPA Calculator

A basic CGPA calculator made using C++.

## Overview

This is a console program that calculates the SGPA of each semester and the overall CGPA. The user enters the number of semesters, then the subjects of each semester with their credits and grades. The program checks every input and asks again when something is wrong, so a wrong entry does not crash it.

It was created for a C++ course project submission.

## Run the project

A C++11-compatible compiler is needed. Any online C++ compiler also works.

1. Download `cgpa_calculator.cpp`.
2. Open Command Prompt in the folder that contains the file.
3. Compile it:

   ```
   g++ -std=c++11 cgpa_calculator.cpp -o cgpa
   ```

4. Run it:

   ```
   cgpa
   ```

   On Linux or macOS use `./cgpa` instead.

## How to use

1. Enter the number of semesters.
2. For each semester, enter the number of subjects.
3. For each subject, enter the subject name, the credits, and the grade.
4. The program prints the SGPA after each semester and the overall CGPA at the end.

## Grade scale

| Grade | Grade points |
| ----- | ------------ |
| O     | 10           |
| A+    | 9            |
| A     | 8            |
| B+    | 7            |
| B     | 6            |
| C     | 5            |
| F     | 0            |

Grades must be typed in capital letters exactly as shown, for example `A+`.

## Formulas

```
SGPA = sum(credits x grade points) / sum(credits)   (for one semester)
CGPA = sum(credits x grade points) / sum(credits)   (for all semesters together)
```

The CGPA is worked out from the total weighted points and total credits of all semesters. It is not the plain average of the SGPAs, because semesters can have different total credits.

## Sample run

```
Number of semesters: 2

Semester 1
Number of subjects: 3

Subject 1
Subject name: Maths
Credits: 4
Grade (O, A+, A, B+, B, C, F): A

Subject 2
Subject name: Physics
Credits: 3
Grade (O, A+, A, B+, B, C, F): B+

Subject 3
Subject name: English
Credits: 2
Grade (O, A+, A, B+, B, C, F): O
SGPA for semester 1: 8.11

Semester 2
Number of subjects: 2

Subject 1
Subject name: Programming
Credits: 4
Grade (O, A+, A, B+, B, C, F): O

Subject 2
Subject name: Chemistry
Credits: 3
Grade (O, A+, A, B+, B, C, F): B
SGPA for semester 2: 8.29

Overall CGPA: 8.19
```

## Main features

- Calculates SGPA for every semester and the overall CGPA
- Works for any number of semesters and subjects
- Credit-weighted calculation using the grade scale above
- Asks again if the user types text, zero, or a negative number where a positive whole number is needed
- Asks again if the subject name is empty or the grade is not on the grade scale
- Results are shown with two decimal places

## Technology

- C++11
- Standard library only: `iostream`, `iomanip`, `limits`, `map`, `string`, `vector`
- Online C++ compiler or g++ to compile and run
- GDB for debugging
- VS Code with the C/C++ extension for editing

## Submission files

- `cgpa_calculator.cpp` - complete program
- `README.md` - setup and usage guide
- `PROJECT_REPORT.md` - project documentation
- `VIVA_GUIDE.md` - viva preparation notes

## Team

| Name | Role |
| ---- | ---- |
| M. Dharmasudheer | Designed the project structure and developed the main C++ program |
| M. Dhanush | Worked on the SGPA/CGPA formulas and grade-point mapping |
| M. Kuladeep | Tested with different inputs and checked output accuracy |
| Chiruhas | Prepared documentation, sample input/output, and the PPT |

CSE Core, Section Q
