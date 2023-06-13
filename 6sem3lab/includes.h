#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <set>
#include <conio.h>
#include <ctype.h>
#include "windows.h"

using namespace std;

string get_text_from_file()
{
    const string path = "enwik8tm";
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(EXIT_FAILURE);
    }

    return string((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
}

void put_text_to_file(string str)
{
    string file;
    cout << "¬ведите название сохран€емого файла: ";
    cin >> file;
    ofstream out;
    out.open(file);
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}