//
// Created by lordelbardooo on 10/30/26.
//
#include "functions.h"

using namespace  std;

int take_input() {
    int input;
    bool bIs_valid;
    do {
        cout << "entrer une valeur [1800 - 2100] :\n";
        cin >> input;
        bIs_valid = (input >= 1800 && input <= 2100);
        if (!bIs_valid) {
            cout << "/!\ erreur de saisie\n";
        }
    }while (!bIs_valid);
    return input;
}
void loop_program() {
    char input;
    do {
        int date = take_input();
        set_year(date);
        do {
            cout << "voulez-vous continuer [O|N] :\n";
            cin >> input;
        }while (input != 'O' && input != 'N');
    }while (input == 'O');
    cout << "Fin de programme\n";
}

bool bissextile(int annee) {
    return (annee % 400 == 0) or (annee % 4 == 0 and annee % 100 != 0);
}

// 1st January 2024 was a monday !!
int set_initial_offset_day(const int annee) {
    const int base_year = 2024;
    int sum = 0;

    if (annee >= base_year) {
        for (int i = base_year; i < annee; ++i) {
            sum += 365 + static_cast<int>(bissextile(i));
        }
    } else {
        for (int i = annee; i < base_year; ++i) {
            sum -= 365 + static_cast<int>(bissextile(i));
        }
    }
    return ((sum % 7) + 7) % 7;
}

int set_nDay_in_month(const int month,const int annee) {
    // control if the month has 28,29,30 or 31 days.
    if (month == 1) {
        // February, it has either 28 ir 29 days.
        if (bissextile(annee)) {
            //contains 29 days.
            return 29;
        }
        else {
            //containe 28 days.
            return 28;
        }
    }
    else if (month%2==0) {
        // month with 31 days
        return 31;
    }
    else {
        // month with 30 days
        return 30;
    }
}

void set_month(const int num_days_in_month, int& offset_day) {
    int count_day = 1; // used to fill the month, its equivalent to i, but count from 1 and doesnt count the empty spaces.
    int total_nDay = 0;
    for (size_t i = 0; i< num_days_in_month+offset_day; ++i) {
        // filling the month with the number of days.
        if (i%7==0 && i != 0) {
            // \n to conclude the week.
            cout <<endl;
        }
        if (i>= offset_day) {
            if (count_day <10) {
                // add a small space if the day contains only 1 digits, graphical fix that avoids ugly displacements.
                cout << " ";
            }
            cout << " " << count_day << " ";
            count_day++;
        }
        else {
            // if this day belongs to another month, add a space and skip to the next day.
            cout << "    ";
        }
        total_nDay = static_cast<int>(i);
    }
    cout << endl; // we a spacing the months there
    // uodate the offset day, so the next month will pursue from this last day of the month.
    // for example, if this month ends with saturday, the next month will start with sunday.
    offset_day = 1+(total_nDay%7);
}

void set_year(int annee) {
    array<string,12> months_name {
        "Janvier", "Fevrier", "Mars", "Avril",
        "Mai", "Juin","Juillet", "Aout", "Septembre",
        "Octobre", "Novembre", "Decembre"
    };
    int offset_day = set_initial_offset_day(annee);
    for (size_t i = 0; i< months_name.size(); ++i) {
        array<char,7> days_week{
            'L','M','M','J','V','S','D'
        };
        // title, exemple: February 2024.
        cout << months_name.at(i) << " " << annee <<endl;
        for (size_t i = 0; i< days_week.size(); ++i) {
            cout <<"  "<< days_week[i] << " ";
        }
        cout << endl;
        set_month(set_nDay_in_month(static_cast<int>(i),annee), offset_day);
        cout << endl;
        //set_month(i,months_name.at(i), annee);
    }

}
