#include <iostream>
#include <string>
using namespace std;

int main()
{
    //introduce fare
    double fare;
    
    //prompts, set variables equal to responses
    cout << "Age of rider: ";
    int age;
    cin >> age;
    cin.ignore(10000, '\n');
    
    cout << "Student? (y/n): ";
    string studentyn;
    getline(cin, studentyn);
        
    cout << "Destination: ";
    string destination;
    getline(cin, destination);

    cout << "Number of zone boundaries crossed: ";
    int boundaries;
    cin >> boundaries;
    
    //determine the fares
    if (age<18 && boundaries<=1)
        fare = .65;
        
    else if (age>=65)
    {
        if (boundaries == 0)
            fare = .45;
        else if (boundaries == 1 && studentyn == "y")
            fare = .65;
        else
            fare = .55 + (.25*boundaries);
    }
    
    else if (age>=18 && studentyn == "y" && boundaries<=1)
        fare = .65;
    
    else
        fare = 1.35 + (.55*boundaries);
    
    //formatting of output
    cout << "---" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    
    //responses to errors in items
    if (age < 0)
    {
        cout << "The age must not be negative" << endl;
        return 1;
    }
    
    else if ((studentyn != "y") && (studentyn != "n"))
    {
        cout << "You must enter y or n" << endl;
        return 1;
    }
    
    else if (destination == "")
    {
        cout << "You must enter a destination" << endl;
        return 1;
    }
    
    else if (boundaries < 0)
    {
        cout << "The number of zone boundaries crossed must not be negative" << endl;
        return 1;
    }
    
    //output if no errors in items
    else
        cout << "The fare to " << destination << " is $" << fare << endl;
    
}
