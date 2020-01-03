#include <iostream>
#include <vector>
#include <string>

using namespace std;

void insertionSort(vector<string>& list);

int main()
{
    vector<string> names;
    names.push_back("Mike");
    names.push_back("Chris");
    names.push_back("Drew");
    names.push_back("Ryan");
    names.push_back("Kyle");
    names.push_back("Chad");
    names.push_back("Parker");
    names.push_back("Eric");
    names.push_back("Victor");

    //Print names before sort
    cout << "Before sort: " << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    insertionSort(names);

    cout << "\nAfter Insertion Sort:" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }
    return 0;
}

void insertionSort(vector<string>& list)
{
    for (int i = 1; i < list.size(); i++)
    {
        string key = list[i];
        int j;
        for (j = i-1; i >= 0 && list[j].compare(key) > 0; j--)
        {
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}