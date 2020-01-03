#include <string>
#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<string>& list);

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

    selectionSort(names);

    cout << "\nAfter Selection Sort:" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }
    return 0;
}

void selectionSort(vector<string>& list)
{
    for (int i = 0; i < list.size()-1; i++)
    {
        int lowestIndex = i;
        for (int j = i+1; j < list.size(); j++)
        {
            if (list[lowestIndex].compare(list[j]) > 0)
            {
                lowestIndex = j;
            }
        }
        string temp = list[i];
        list[i] = list[lowestIndex];
        list[lowestIndex] = temp;
    }
}