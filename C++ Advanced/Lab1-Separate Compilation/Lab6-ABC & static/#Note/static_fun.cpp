#include <iostream>
using namespace std;

class People
{
    
    public:
        People(){num_person++;}
        ~People(){num_person--;}
        static void get_num(){cout << "number of persons : " <<  num_person << endl; }

    private:
    static int num_person;
};

int People :: num_person;

int main()
{
    People :: get_num();
    
    People p1;
    p1.get_num();
}