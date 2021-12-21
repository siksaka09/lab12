#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;


int main(){
    int grade;

    cout << "Press Enter 3 times to reveal your future.";

    cin.get();
    cin.get();
    cin.get();

    srand(time(0));

    grade = rand()%9;
    string x;

    if(grade == 0) x = "A";
    else if(grade == 1)x = "B+";
    else if(grade == 2)x = "B";
    else if(grade == 3)x = "C+";
    else if(grade == 4)x = "C";
    else if(grade == 5)x = "D+";
    else if(grade == 6)x = "D";
    else if(grade == 7)x = "F";
    else if(grade == 8)x = "W";

    cout << "You will get "<< x <<" in this 261102.";

}

// cout << "Press Enter 3 times to reveal your future.";
// cout << "You will get A in this 261102.";
