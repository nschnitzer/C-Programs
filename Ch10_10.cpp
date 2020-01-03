#include <iostream>
#include <string>
#include <vector>

using namespace std;

int seqSearch(vector<string> list, string value);

int main()
{
    vector<string> stringVec;
    stringVec.push_back("First");
    stringVec.push_back("Second");
    stringVec.push_back("Third");
    stringVec.push_back("Fourth");

    string find = "Third";
    if (seqSearch(stringVec, find) != -1)
    {
        cout << "The value " << find << " found at " << seqSearch(stringVec, find);
        cout << "th index "  << endl;
    }
    else
    {
        cout << "The value " << find << " could not be found in the vector";
    }
    
    find = "Hello?";
    if (seqSearch(stringVec, find) != -1)
    {
        cout << "The value " << find << " found at " << seqSearch(stringVec, find);
        cout << "th index "  << endl;
    }
    else
    {
        cout << "The value " << find << " could not be found in the vector";
    }
}

int seqSearch(vector<string> list, string value)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (value.compare(list[i]) == 0)
        {
            return i+1;
        }
    }
    return -1;
}