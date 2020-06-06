#include <iostream>
using namespace std;

// passing a pointer has the same effect as pass-by-reference
void  addTax(double * pPrice) 
{
   // (*pPrice) = (*pPrice) * 1.10 ;  // 10% tax
   (*pPrice) *= 1.10 ;
}

void addTax(double & price)
{
   price *= 1.10 ;
}

int main()
{
    // array name is a constant pointer to the first element in the array
    bool   answers[]    = {true, false, true} ;
    int    quantities[] = {10, 20, 30, 40, 10} ;
    double prices[]     = {1.99, 2.88, 3.77, 4.66} ;
    double price1, price2, price3, price4 ;

    cout << boolalpha << (*answers) << endl ;
    cout << *quantities << endl ;
    cout << *prices     << endl ;

    // pointer arithmetic:
    //   add 1 means point to the next element in the array
    //     (it does not add literally 1. It adds 1 element (because the size of the element may not be 1)
    cout << boolalpha << *(answers + 1) << endl ;
    cout << * (quantities + 1) << endl;
    cout << * (prices + 1) << endl ;
    
    cout << "Price list: " << endl ;
    for(int counter=0; counter < 4; counter++)
    {
      cout << prices[counter]     << endl ;   // using array notation
      cout << *(prices + counter) << endl ;   // using pointer notation
    }

    int    * pCount  = NULL ;
    bool   * pAnswer = NULL ;
    double * pPrice  = nullptr ;

    int     count  = 0 ;
    bool    answer = false ;
    double  price  = 0.0 ;

    pCount  = & count ;
    *pCount = 123 ;
    cout << "Count: " << count << endl ;

    price = 100.00 ;
    addTax( & price ) ;
    cout << "Price with tax is " << price << endl ;
    addTax( price ) ;
    cout << "Price with more tax is " << price << endl ;

    pPrice = & price ;
    addTax( pPrice ) ;
    cout << "Price with more tax is " << price << endl ;

    // dynamic memory allocation: storage are gotten only at runtime (when you run the program)
    //    and the storage is available only after the instruction to allocate them

    int  howMany = 0 ;
    cout << "How many expenses do you have? " ;
    cin >> howMany ;
    
    if (howMany > 0)
    {
      double *pExpenses = new double[howMany] ;    // "new" operator will allocate storage dynamically
      // "new" returns a pointer

      for(int counter=0; counter < howMany; counter++)
          pExpenses[counter] = 0.0 ;   // if you have a pointer, you can use "dereference operator"
                                       //   or you can simply use array notation
    }

    return 0 ;
}