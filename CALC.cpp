#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main() {
    SetConsoleTitle(L"GrossPayCalculator");
    double max = 0;
    double hours = 0;
    double pay = 0;
    double overtimemulti = 0;
    double overtimepay = 0;
    double regularpay = 0;
    double grosspay = 0;

    cout << "Enter max time without overtime (e.g 40): ";
    cin >> max;
    cout << "\n";
    cout << "Enter total hours worked: ";
    cin >> hours;
    cout << "\n";
    cout << "Enter pay (e.g 10.25): ";
    cin >> pay;
    cout << "\n";
    cout << "Enter overtime pay multipler (e.g 1.5): ";
    cin >> overtimemulti;

    if (max < hours) {
        regularpay = max * pay;
        hours = hours - max;
        overtimemulti = pay * overtimemulti;
        overtimepay = hours * overtimemulti;
        grosspay = regularpay + overtimepay;




    }
    else {

        grosspay = hours * pay;


    }
    wostringstream grosspays;
    grosspays.precision(2);
    grosspays << fixed << grosspay;
    wstring grosspaybox = L"Your grosspay is: $" + grosspays.str();
    cout << "\n";
    MessageBox(0, grosspaybox.c_str(), L"Gross pay result", MB_OK | MB_ICONINFORMATION);
    return 0;

}