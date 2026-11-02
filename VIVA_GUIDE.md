# Viva Guide - CGPA Calculator

Notes for presenting the project and answering questions.

## 30-second summary

Our program is a console CGPA calculator written in C++. The user enters the number of semesters, then the subjects of each semester with credits and grades. The program converts each grade to grade points, calculates the SGPA for every semester, and finally prints the overall CGPA. It also checks the input, so wrong entries are rejected and asked again.

## How the program flows

1. `main` creates the grade scale (a `map` from grade to points).
2. It reads the number of semesters.
3. For each semester it reads the number of subjects.
4. For each subject, `readSubject` reads the name, credits, and grade.
5. The subject is stored in a `vector<Subject>`, and its weighted points and credits are added to the overall totals.
6. After the semester, `calculateGpa` gives the SGPA.
7. After all semesters, the overall CGPA is printed.

## Functions

| Function | What it does |
| -------- | ------------ |
| `readPositiveInt` | Reads a whole number greater than zero. Asks again on text, zero, or negative input. Returns false if input ends. |
| `readSubject` | Reads the subject name, credits, and grade. Rejects an empty name and grades not in the scale. |
| `calculateGpa` | Returns total weighted points divided by total credits for the subjects given. |
| `main` | Controls the whole flow and prints SGPA and CGPA. |

## Formulas

```
Weighted points of a subject = credits x grade points
SGPA = total weighted points of the semester / total credits of the semester
CGPA = total weighted points of all semesters / total credits of all semesters
```

Worked example from the README sample:

- Semester 1: Maths 4 credits A (8), Physics 3 credits B+ (7), English 2 credits O (10)
  - Weighted points = 32 + 21 + 20 = 73, credits = 9, SGPA = 73 / 9 = 8.11
- Semester 2: Programming 4 credits O (10), Chemistry 3 credits B (6)
  - Weighted points = 40 + 18 = 58, credits = 7, SGPA = 58 / 7 = 8.29
- Overall CGPA = (73 + 58) / (9 + 7) = 131 / 16 = 8.19

## Likely questions and answers

**1. What is the difference between SGPA and CGPA?**
SGPA is the grade point average of one semester. CGPA is the average over all semesters completed so far.

**2. Why is the CGPA not the average of the SGPAs?**
Because semesters can have different total credits. Using total weighted points divided by total credits gives each credit the same weight. In the sample, the average of 8.11 and 8.29 is 8.20, but the correct CGPA is 8.19.

**3. Why did you use a struct?**
`Subject` groups the name, credits, and grade points of one subject in a single unit, so one subject can be passed around and stored as one object.

**4. Why did you use a map for the grades?**
A `map<string, double>` links each grade like `A+` directly to its points. Looking up a grade is one `find` call, and changing the grade scale only means editing one list in `main`.

**5. Why a vector for the subjects?**
The number of subjects is not known before the program runs. A `vector` grows as subjects are added with `push_back`.

**6. What does `cin.ignore(numeric_limits<streamsize>::max(), '\n')` do?**
It removes the leftover characters, including the newline, from the input buffer. Without it, the newline left after reading a number would be picked up by the next `getline` and give an empty subject name.

**7. What do `cin.clear()` and `cin.ignore()` do when the user types text instead of a number?**
`cin >> value` fails and `cin` goes into an error state. `cin.clear()` resets that state, and `cin.ignore()` throws away the wrong input so the loop can ask again.

**8. Why do you check `cin.eof()`?**
If the input ends (for example Ctrl+Z on Windows), asking again would loop forever. Returning false lets the program exit cleanly.

**9. Why are the functions returning `bool`?**
`true` means the value was read successfully. `false` means input ended, and `main` stops safely.

**10. Why `const` and `&` in `const map<string, double>& gradeScale`?**
`&` passes the map without copying it, which is faster. `const` promises the function will not change it.

**11. Why `long long` for credits?**
Total credits are summed over many subjects. `long long` keeps a large sum from overflowing.

**12. What happens if the user enters a wrong grade like `a` or `D`?**
The map search does not find it, so the program prints a message and asks again. Grades are case-sensitive, so `a` is rejected and `A` is accepted.

**13. Can subject names have spaces?**
Yes. The name is read with `getline`, which reads the whole line. The grade is read with `cin >>`, so it cannot have spaces.

**14. What do `fixed` and `setprecision(2)` do?**
They show the result with exactly two digits after the decimal point.

**15. What if the total credits are zero?**
`calculateGpa` returns 0.0 to avoid dividing by zero. In practice credits must be greater than zero, so this is a safety check.

**16. How did you test it?**
We tried normal inputs, many subjects, and wrong inputs such as text, zero, negative numbers, empty names, and invalid grades, and compared the output with hand calculations.

**17. What are the limitations?**
It does not save data to a file, it only supports the one grade scale in the code, and grades must be typed in capital letters.

**18. What could be improved?**
Saving results to a file, a graphical interface, supporting different grade scales, and accepting lowercase grades.

## Team roles

- M. Dharmasudheer: project structure and main C++ program
- M. Dhanush: SGPA/CGPA formulas and grade-point mapping
- M. Kuladeep: testing with different inputs and checking output accuracy
- Chiruhas: documentation, sample input/output, and PPT

## Tips for the viva

- Know the formula and be able to calculate one example by hand.
- Be ready to explain why `cin.ignore` is used after reading numbers.
- Everyone in the team should know the whole flow, not only their own part.
