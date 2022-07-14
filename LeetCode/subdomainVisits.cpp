#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int numOfSubdomains(string ss)
{
    int num{0};
    int len = ss.length();
    char cstr[len + 1];
    strcpy(cstr, ss.c_str());
    char *token = NULL;

    token = strtok(cstr, ".");

    while (token != NULL)
    {
        num++;
        token = strtok(NULL, ".");
    }
    return num;
}

vector<string> prepareTokens(string str, int number)
{
    vector<string> tokens;
    int len = str.length();
    char cstr[len + 1];
    strcpy(cstr, str.c_str());
    char *token = NULL;
    int idx = 1;
    string rep, d1;

    token = strtok(cstr, ".");
    int s = strlen(token);

    for (int i = 0; i < s; i++)
    {
        if (isdigit(token[i]))
        {
            rep.push_back(token[i]);
        }
        else
            i = s;
    }
    tokens.push_back(rep);
    number--;

    d1 = str.substr(s + 1);
    tokens.push_back(d1);
    number--;

    if (number != 0)
    {
        int lend1 = d1.length();
        char c[lend1 + 1];
        strcpy(c, d1.c_str());
        token = strtok(c, ".");
        string d2 = token;
        token = strtok(NULL, ".");
        if (token != NULL)
            tokens.push_back(token);
        else
            tokens.push_back(d2);
    }
    return tokens;
}

vector<string> subdomainVisits(vector<string> &cpdomains)
{
    vector<string>::iterator it;
    string domain;
    vector<string> tokens;
    unordered_map<string, int> umap;
    vector<string> domains;
    int numberSubDomains{0};

    for (it = cpdomains.begin(); it != cpdomains.end(); it++)
    {
        domain = *it;
        numberSubDomains = numOfSubdomains(domain);
        tokens = prepareTokens(domain, numberSubDomains);
        int num{0};
        for (auto it = tokens.begin(); it != tokens.end(); it++)
        {

            if (it == tokens.begin())
            {
                num = 0;
                num = atoi((*it).c_str());
            }
            else
            {
                auto itr = umap.find((*it));
                if (itr != umap.end())
                    itr->second += num;
                else
                    umap.insert({*it, num});
            }
        }
    }
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        int rep = it->second;
        string num = to_string(rep);
        num.append(" ");
        num.append(it->first);
        domains.push_back(num);
    }
    for (auto it = cpdomains.begin(); it != cpdomains.end(); it++)
        domains.push_back(*it);

    return domains;
}

int main()
{
    vector<string> input, output;
    int numOfStrings{0};
    string str;

    cout << "Enter the number of websites" << endl;
    cin >> numOfStrings;

    cout << "Enter the websites" << endl;
    cin.ignore();
    for (int i = 0; i < numOfStrings; i++)
    {
        getline(cin, str);
        input.push_back(str);
    }

    output = subdomainVisits(input);
    cout << "--------------------" << endl;
    for (auto itr = output.begin(); itr != output.end(); itr++)
        cout << *itr << endl;
    return 0;
}