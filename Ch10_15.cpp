#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binarySearch(vector<string> &list, string find);
void selectionSort(vector<string> &list);

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

    //Applying sort
    selectionSort(names);

    //Search
    string find = "Kyle";
    int searchResult = binarySearch(names, find);
    if (searchResult != -1)
    {
        cout << find << " found at index " << searchResult << endl;
    }
    else
    {
        cout << find << " is not in the vector." << endl;
    }
}

//Binary Search
int binarySearch(vector<string>& list, string find)
{
    int first = 0, last = list.size()-1, mid;

    while (first <= last)
    {
        mid = (first + last)/2;

        if (list[mid].compare(find) == 0)
        {
            return mid;
        }
        else if (list[mid].compare(find) > 0)
        {
            last = mid-1;
        }
        else
        {
            first = mid+1;
        }
    }

    return -1;
}

//Selection Sort
void selectionSort(vector<string> &list)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        int lowestIndex = i;
        for (int j = i + 1; j < list.size(); j++)
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