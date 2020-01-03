#include <vector>
#include <string>
#include <iostream>

using namespace std;

void bubbleSort(vector<string>& list);

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

    bubbleSort(names);

    cout << "\nAfter sort:" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }
}

void bubbleSort(vector<string>& list)
{
    for (int i = 1; i < list.size(); i++)
    {
        for (int j = 0; j < list.size() - i; j++)
        {
            if (list[j].compare(list[j+1]) > 0)
            {
                string temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
    }
}