#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

void createInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int &totalNum, double &totalInv);
void printInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int totalNum, double totalInv);
void sortInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice);
void checkInventory(int search, vector<int> itemID, vector<string> itemName, vector<int> pInStore);
void sellItem(int item, vector<int> itemID, vector<int> &pInStore, vector<int> &pSold, vector<double> sellingPrice, double &totalInv, int &totalNum);
void orderStock(int item, int quantity, vector<int> itemID, vector<int> &pOrdered, vector<int> &pInStore, vector<double> sellingPrice, double &totalInv, int &totalNum);
void newInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int &totalNum, double &totalInv);


int main()
{
    vector<string> itemName;
    vector<int> itemID, pOrdered, pInStore, pSold;
    int totalNum = 0;
    vector<double> manufPrice, sellingPrice;
    double totalInv = 0;

    createInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice, totalNum, totalInv);
    printInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice, totalNum, totalInv);

    bool sent = true;
    while (sent)
    {
        cout << "Please enter the option that you want to select: " << endl
             << "1)Check Stock  2)Sell Item 3)Print Report 4)Add Stock 5)Order Stock 6)Exit" << endl;
        int num;
        cin >> num;
        if (num == 1)
        {
            cout << "Please enter the item id: ";
            int idCheck;
            cin >> idCheck;
            checkInventory(idCheck, itemID, itemName, pInStore);
        }
        else if (num == 2)
        {
            cout << "Please enter the item id: ";
            int id;
            cin >> id;
            cout << endl;
            sellItem(id, itemID, pInStore, pSold, sellingPrice, totalInv, totalNum);
        }
        else if (num == 3)
        {
            cout << "Printing report..." << endl;
            printInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice, totalNum, totalInv);
        }
        else if (num == 4)
        {
            cout << "Please enter the item id: ";
            int id, quantity;
            cin >> id;
            cout << endl << "Please enter the quantity: ";
            cin >> quantity;
            cout << endl;
            orderStock(id, quantity, itemID, pOrdered, pInStore, sellingPrice, totalInv, totalNum);
        }
        else if (num == 5)
        {
            newInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice, totalNum, totalInv);
        }
        else if (num == 6)
        {
            sent = false;
        }
        else
        {
            cout << "Unknown input... Please try again." << endl;
        }
    }

    cout << "Program Terminating...";
    return 0;
}

void createInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int &totalNum, double &totalInv)
{
    ifstream inFile;
    inFile.open("input2.txt");
    while (!inFile.eof())
    {
        int in;
        string s;
        getline(inFile, s, '\n');
        stringstream stream(s);
        stream >> in;
        //cout << "in " << in << endl;
        itemID.push_back(in);

        string inString;
        getline(inFile, inString, '\n');
        inFile.clear();
        //cout << "InString 11 " << inString << endl;
        itemName.push_back(inString);

        inFile >> in;
        //cout << "in 22 " << in << endl;
        pOrdered.push_back(in);
        pInStore.push_back(in);
        totalNum += in;
        pSold.push_back(0);

        double inDub;
        getline(inFile, s, '\n');
        stringstream str(s);
        str >> inDub;
        //cout << "inDub " << inDub << endl;
        manufPrice.push_back(inDub);
        str >> inDub;
        //cout << "inDub 2 " << inDub << endl;
        sellingPrice.push_back(inDub);

        totalInv += (inDub * in);
    }
    inFile.close();
    sortInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice);
}

void printInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int totalNum, double totalInv)
{
    cout << "Item ID\tItem Name\tpOrdered\tpInStore\tpSold\tmanufPrice\tsellingPrice" << endl;
    for (int i = 0; i < itemID.size(); i++)
    {
        cout << itemID[i] << "\t" << itemName[i] << "\t" << pOrdered[i] << "\t\t" << pInStore[i] << "\t\t" << pSold[i] << "\t$";
        cout << showpoint << fixed << setprecision(2) << manufPrice[i] << "\t\t$" << sellingPrice[i] << endl;
    }

    cout << endl;

    cout << "Total Inventory: $" << totalInv << endl;
    cout << "Total Number of Items in the Store: " << totalNum << endl
         << endl;
}

void sortInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice)
{
    for (int i = 0; i < itemName.size() - 1; i++)
    {
        int lowestIndex = i;
        for (int j = i + 1; j < itemName.size(); j++)
        {
            if (itemName[lowestIndex].compare(itemName[j]) > 0)
            {
                lowestIndex = j;
            }
        }

        //Switch Item Name
        string temp = itemName[i];
        itemName[i] = itemName[lowestIndex];
        itemName[lowestIndex] = temp;

        //Switch Item ID
        int tmp = itemID[i];
        itemID[i] = itemID[lowestIndex];
        itemID[lowestIndex] = tmp;

        //switch pOrdered
        tmp = pOrdered[i];
        pOrdered[i] = pOrdered[lowestIndex];
        pOrdered[lowestIndex] = tmp;

        //switch pInStore
        tmp = pInStore[i];
        pInStore[i] = pInStore[lowestIndex];
        pInStore[lowestIndex] = tmp;

        //switch pSold
        tmp = pSold[i];
        pSold[i] = pSold[lowestIndex];
        pSold[lowestIndex] = tmp;

        //switch manufPrice
        double dtmp = manufPrice[i];
        manufPrice[i] = manufPrice[lowestIndex];
        manufPrice[lowestIndex] = dtmp;

        //switch sellingPrice
        dtmp = sellingPrice[i];
        sellingPrice[i] = sellingPrice[lowestIndex];
        sellingPrice[lowestIndex] = dtmp;
    }
}

void checkInventory(int search, vector<int> itemID, vector<string> itemName, vector<int> pInStore)
{
    for (int i = 0; i < itemID.size(); i++)
    {
        if (search == itemID[i])
        {
            cout << endl
                 << "# of stock for " << itemName[i] << ": " << pInStore[i] << endl;
            return;
        }
    }
    cout << "Item Not Found" << endl;
}

void sellItem(int item, vector<int> itemID, vector<int> &pInStore, vector<int> &pSold, vector<double> sellingPrice, double &totalInv, int &totalNum)
{
    //Find the product
    for (int i = 0; i < itemID.size(); i++)
    {
        if (item == itemID[i])
        {
            //Check if there are any in stock
            if (pInStore[i] > 0)
            {
                cout << "Transaction confirmed" << endl;
                pInStore[i]--;
                pSold[i]++;
                totalNum--;
                totalInv -= sellingPrice[i];
                return;
            }
            cout << "Transaction Failed: Out of stock" << endl;
            return;
        }
    }

    cout << "Item not found" << endl;
    return;
}

void orderStock(int item, int quantity, vector<int> itemID, vector<int> &pOrdered, vector<int> &pInStore, vector<double> sellingPrice, double &totalInv, int &totalNum)
{
    //Search for the product
    for (int i = 0; i < itemID.size(); i++)
    {
        if (item == itemID[i])
        {
            pOrdered[i] += quantity;
            pInStore[i] += quantity;
            totalInv += (sellingPrice[i]*quantity);
            totalNum += quantity;
            cout << "Stock Added Successfully!" << endl;
            return;
        }
    }

    cout << "The product could not be found..." << endl;
    return;
}

void newInventory(vector<int> &itemID, vector<string> &itemName, vector<int> &pOrdered, vector<int> &pInStore, vector<int> &pSold, vector<double> &manufPrice, vector<double> &sellingPrice, int &totalNum, double &totalInv)
{
    int item, ordered;
    double manuf, sellPrice;
    string name;

    cout << "Please enter the item id: ";
    cin >> item;
    cout << endl << "Please enter the item Name: ";
    getline(cin, name);
    cout << name << endl;
    getline(cin, name);
    cout << "NAME: " << name << endl;
    cout << endl << "Please enter the quantity ordered: ";
    cin >> ordered;
    cout << endl << "Please enter the manufacturer's price: ";
    cin >> manuf;
    cout << endl << "Please enter the selling price: ";
    cin >> sellPrice;
    cout << endl << "..." << endl;

    itemID.push_back(item);
    itemName.push_back(name);
    pOrdered.push_back(ordered);
    pInStore.push_back(ordered);
    pSold.push_back(0);
    manufPrice.push_back(manuf);
    sellingPrice.push_back(sellPrice);
    totalInv += (ordered*sellPrice);
    totalNum += ordered;
    cout << "New Stock Added To Inventory Sucessfully!" << endl;
    sortInventory(itemID, itemName, pOrdered, pInStore, pSold, manufPrice, sellingPrice);
    return;
}
