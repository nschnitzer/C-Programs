#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void addInOrder(vector<int>& vec, vector<int>& occ, int x);
int contains(vector<int> vec, int x);

int main()
{
     vector<int> vec;
     vector<int> occ;

     vector<int> inputs;
     inputs.push_back(55);
     inputs.push_back(80);
     inputs.push_back(78);
     inputs.push_back(92);
     inputs.push_back(95);
     inputs.push_back(55);
     inputs.push_back(78);
     inputs.push_back(53);
     inputs.push_back(92);
     inputs.push_back(65);
     inputs.push_back(78);
     inputs.push_back(95);
     inputs.push_back(85);
     inputs.push_back(92);
     inputs.push_back(85);
     inputs.push_back(95);
     inputs.push_back(95);
     
     for (int i = 0; i < inputs.size(); i++)
     {
         addInOrder(vec, occ, inputs[i]);
     }

     for (int i = 0; i < vec.size(); i++)
     {
         cout << vec[i] << ": " << occ[i] << endl;
     }

     return 0;
}

void addInOrder(vector<int>& vec, vector<int>& occ, int x)
{
    if (vec.size() == 0)
    {
        vec.push_back(x);
        occ.push_back(1);
        return;
    }
    
    if (contains(vec, x) != -1)
    {
        occ[contains(vec,x)] += 1;
    }
    else
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (x < vec[i])
            {
                vector<int> newvec;
                vector<int> newocc;
                for (int j = 0; j < i; j++)
                {
                    newvec.push_back(vec[j]);
                    newocc.push_back(occ[j]);
                }
                newvec.push_back(x);
                newocc.push_back(1);

                for (int j = i; j < vec.size(); j++)
                {
                    newvec.push_back(vec[j]);
                    newocc.push_back(occ[j]);
                }

                vec = newvec;
                occ = newocc;
                return;
            }
        }

        vec.push_back(x);
        occ.push_back(1);
    }
    
}


 //Determine if the vector contains the element
int contains(vector<int> vec, int x)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == x)
        {
            return i;
        }
    }
    return -1;
}
