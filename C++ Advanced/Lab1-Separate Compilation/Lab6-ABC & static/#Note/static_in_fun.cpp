#include <iostream>
using namespace std;



void fun(int depth, int& count)
{

    static int num_calls = 0;
    count = ++num_calls;

    if(depth == 0)
        return;

    fun(depth-1, count);

}

int main()
{
    int num_calls, num_calls2;
    
    fun(32,num_calls); //33
    cout << "num_calls = : "<< num_calls << '\n';

    fun(3,num_calls2); //37
    cout << "num_calls2 = : "<< num_calls2 << '\n';
}