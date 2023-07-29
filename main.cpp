#include <iostream>
// #include <bits/stdc++.h>
#include "DataGenerator.cpp"
// #include "Sorting Library/sortingLibrary.h"
#include "CommandProcess.cpp"

int main(int argc, char *argv[])
{
    if (argc == 5)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            if (string(argv[3]).find(".txt") != string::npos)
                commandOne(argv[2], argv[3], argv[4]);
            else
                commandThree(argv[2], atoi(argv[3]), argv[4]);
        }
        else if (strcmp(argv[1], "-c") == 0)
            commandFour(argv[2], argv[3], argv[4]);
        else
            cout << "Unknown Command!";
    }
    else if (argc == 6)
    {
        if (strcmp(argv[1], "-a") == 0)
            commandTwo(argv[2], atoi(argv[3]), argv[4], argv[5]);
        else if (strcmp(argv[1], "-c") == 0)
            commandFive(argv[2], argv[3], atoi(argv[4]), argv[5]);
        else
            cout << "Unknown Command!";
    }
    else
        cout << "Unkown command!";

    return 0;
}
