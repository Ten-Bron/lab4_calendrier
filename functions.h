//
// Created by lordelbardooo on 10/30/26.
//
#pragma once
#include <iostream>
#include <ostream>
#include <array>
#include <vector>
#include <chrono>
#include <string>

int receive_date(); // ask the user to type a year, and ask again if this date is not valid.
void loop_program(); // restart the program if asked.
bool bissextile(int annee); // return true if the year contains 366 day, false if 365.
int set_initial_offset_day(const int annee); // return the number of the first days of January that dont belong to this year
void print_month(const int num_days_in_month, int& offset_day); // fill the month with days,
void print_year(int annee); // fill and print every months for the year.



