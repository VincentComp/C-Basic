#include <iostream>
using namespace std;
  
int main()
{
    /*
        There are 6 errors in total. Can you catch them all? :)
  
        See the expected output section on the lab page to see what is expected from the corrected program.
    */
  
    int number; //Q1 miss ;
    cout << "Welcome to the exciting, fun, and awesome programming world! "
         << "Enter an odd number, and I can tell something about you! " << endl; //Q2 << miss
    cin >> number; //Q3 >>
  
    if (number % 2 == 0) //Q4 ==  
        cout << "Hmm... this is not an odd number..." << endl;
    else
    {
        if (number < 0) //Q5 number
            cout << "You seem to be a bit negative... :( Cheer up! " << endl;
        else
            cout << "You must be very excited! Me too! :)" << endl;
  
    } //Q6 miss }
    return 0;
}