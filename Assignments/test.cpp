//
// Created by Preetesh Barretto on 5/23/20.
//

#include <iostream>
using namespace std;
int main()
{
    int array1[] = {1, 2, 3};
    char array2[] = {'A', 'B', 'C'};
    int length = (sizeof(array1) / sizeof(array1[0]));
    for (int i=0; i< length; i++) {
        cout << array1[i] <<endl;
    }
    cout << array1 << endl;
    cout << array2 << endl;
    return 0;
}
