// Задание «Лампа со шторой».
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int time, lamp, curtains;
    cout << "What time is it outside now? (example of input: 1 (6:00-22:00) / 2 (22:00-6:00)) " << endl;
    cin >> time;
    while ((time != 1) && (time != 2) && (time != 3)) {
        cout << "Invalid input. Try again.  " << endl;
        cin >> time;
    }
    cout << "Are the curtains drawn?  (example of input: 1 (yes) / 2 (no)) " << endl;
    cin >> curtains;
    while ((curtains != 1) && (curtains != 2)) {
        cout << "Invalid input. Try again.  " << endl;
        cin >> curtains;
    }    
    cout << "Is the lamp on?   (example of input: 1 (yes) / 2 (no)) " << endl;
    cin >> lamp;
    while ((lamp != 1) && (lamp != 2)) {
        cout << "Invalid input. Try again.  " ;
        cin >> lamp;
    }
    if ((time == 1) && (curtains == 2))
        cout << "It's light in the room " << endl;
    else if (lamp == 1)
        cout << "It's light in the room " << endl;
    else if ((time == 2 || curtains == 1) && (lamp == 2))
        cout << "It's dark in the room. " << endl;
    else if ((curtains == 1) && (lamp == 2))
        cout << "It's dark in the room. " << endl;
    //cout << time << curtains << lamp << endl;
    system("pause");
    return 0;
}
