#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string findMonth(string m)
{
    if (m == "Jan")
        return "01";
    else if (m == "Feb")
        return "02";
    else if (m == "Mar")
        return "03";
    else if (m == "Apr")
        return "04";
    else if (m == "May")
        return "05";
    else if (m == "Jun")
        return "06";
    else if (m == "Jul")
        return "07";
    else if (m == "Aug")
        return "08";
    else if (m == "Sep")
        return "09";
    else if (m == "Oct")
        return "10";
    else if (m == "Nov")
        return "11";
    else if (m == "Dec")
        return "12";

    return 0;
}

string reformatDate(string date)
{
    string day, month, year;
    string formatDate;

    int size = date.length();

    char c[size + 1];
    strcpy(c, date.c_str());

    char *token = NULL;

    token = strtok(c, " ");
    day = token;
    day.erase(day.size() - 2);

    if (day.length() == 1)
       day.insert(0, "0");
    token = strtok(NULL, " ");
    month = token;
    token = strtok(NULL, " ");
    year = token;

    string num = findMonth(month);

    formatDate = year;
    formatDate.append("-");
    formatDate.append(num);
    formatDate.append("-");
    formatDate.append(day);

    return formatDate;
}

int main()
{
    string input, output;

    cout << "Enter the date in format 20th Oct 2052" << endl;
    cin.ignore();
    getline(cin, input);

    output = reformatDate(input);
    cout << output << endl;
    return 0;
}