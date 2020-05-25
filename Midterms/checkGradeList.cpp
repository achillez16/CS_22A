// Created by Preetesh Barretto on 5/22/20.

//Write a function named “checkGradeList” that accepts an array of grades (char)
//and its size. It will go through the list of grades, check its validity (only accept
//‘A’, ‘a’, ‘B’, ‘b’, ‘C’, ‘c’, ‘D’, ’d’, ‘F’, or ‘f’). It will replace invalid values with
//‘I’. The function will also return the number of invalid values that it has replaced
//using output parameter.

#include <iostream>
using namespace std;

int checkGradeList(char grades_arr[]);
int class_size = 0;

int main(){
    do {
        cout << "Enter the Class Size: ";
        cin >> class_size;
        if (cin.fail())  {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Class Size. Please try again." << endl;
            continue;
        } else
            break;
    } while(true);


    char grades_arr[class_size];
    for (int i = 0; i < class_size; i++) {
        cout << "Enter grade for student " << (i+1) << ": ";
        cin >> grades_arr[i];
        int c = grades_arr[i];
        if (islower(c))
            grades_arr[i] = toupper(c);
        cin.ignore();
    }
    int invalid_grades = checkGradeList(grades_arr);
    cout << "\nNumber of Invalid Grades: " << invalid_grades << endl;
    cout << "Final Grades: ";
    for(int i=0; i<= class_size-1 ; i++) {
         cout << grades_arr[i] << ", ";
    }
}

int checkGradeList(char grades_arr[]) {
    int invalid = 0;
    for (int i=0; i < class_size; i++) {
        char grade;
        grade = grades_arr[i];
        if ((grade >= 'A' && grade <= 'D') or (grade >= 'a'&& grade <= 'd') or (grade == 'F') or (grade == 'f'))
            continue;
        else {
            grades_arr[i] = 'I';
            invalid += 1;
        }
    }
    return invalid;
}

// OUTPUTS

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/checkGradeList
//Enter the Class Size: 5
//Enter grade for student 1: A
//Enter grade for student 2: F
//Enter grade for student 3: 9
//Enter grade for student 4: H
//Enter grade for student 5: B
//
//Number of Invalid Grades: 2
//Final Grades: A, F, I, I, B,
//Process finished with exit code 0


///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/checkGradeList
//Enter the Class Size: 4
//Enter grade for student 1: A
//Enter grade for student 2: B
//Enter grade for student 3: C
//Enter grade for student 4: F
//
//Number of Invalid Grades: 0
//Final Grades: A, B, C, F,
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/checkGradeList
//Enter the Class Size: 0
//
//Number of Invalid Grades: 0
//Final Grades:
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/checkGradeList
//Enter the Class Size: 1
//Enter grade for student 1: 5
//
//Number of Invalid Grades: 1
//Final Grades: I,
//Process finished with exit code 0