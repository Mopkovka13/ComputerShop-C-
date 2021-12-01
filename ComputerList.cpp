#include "ComputerList.h"
#include "Extra.h"

computerList::computerList(int n)
{
    capacity = n;
    computers = new computer*[n];
    count = 0;
}
computerList::~computerList()
{
    capacity = 0;
    delete[] computers;
    count = 0;
}

void computerList::readComputers()
{
    ifstream infile1;
    infile1.open("computers.txt");
    computer* new_computers;
    if (infile1.is_open())
    {
        string temp;
        getline(infile1, temp);
        int tempCount = atoi(temp.c_str());
        for (int i = 0;i < tempCount;i++)
        {
            new_computers = new computer;
            new_computers->ReadComputer(infile1);
            computers[count] = new_computers;
            count++;
        }
        capacity -= count;
        infile1.close();
        cout << "Computers received\n";
    }
    else
    {
        cout << "Computers not received\n";
    }
    ifstream infile2;
    infile2.open("upgradeComputers.txt");
    if (infile2.is_open())
    {
        string temp;
        getline(infile2, temp);
        int tempCount = 0;
        tempCount = count + atoi(temp.c_str());
        for (int i = count; i < tempCount; i++)
        {
            new_computers = new upgradeComputer;
            new_computers->ReadComputer(infile2);
            computers[count] = new_computers;
            count++;
        }
        capacity -= count;
        infile2.close();
        cout << "upgradeComputers received\n";
    }
    else
    {
        cout << "upgradeComputers not received\n";
    }
    ifstream infile3;
    infile3.open("laptops.txt");
    if (infile3.is_open())
    {
        string temp;
        getline(infile3, temp);
        int tempCount = 0;
        tempCount = count + atoi(temp.c_str());
        for (int i = count; i < tempCount; i++)
        {
            new_computers = new laptop;
            new_computers->ReadComputer(infile3);
            computers[count] = new_computers;
            count++;
        }
        capacity -= count;
        infile3.close();
        cout << "laptops received";
    }
    else
    {
        cout << "laptops not received";
    }
    cout << "\n\n";
}
void computerList::showComputers()
{
    if (count == 0)
    {
        cout << "No data received" << endl;
    }
    else
    {
        int k = 0;
        bool success1 = false;
        bool success2 = false;
        bool success3 = false;
        for (int i = 0; i < count;i++)
        {
            if (computers[i]->getType() == "computer")
            {
                if (success1 == false)
                {
                    computers[i]->ShowTableHeader();
                    success1 = true;
                }
                computers[i]->ShowComputer(k);
                k++;
            }    
        }
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            if (computers[i]->getType() == "upgradeComputer")
            {
                if (success2 == false)
                {
                    computers[i]->ShowTableHeader();
                    success2 = true;
                }
                computers[i]->ShowComputer(k);
                k++;
            }
               
        }
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            if (computers[i]->getType() == "laptop")
            {
                if (success3 == false)
                {
                    computers[i]->ShowTableHeader();
                    success3 = true;
                }
                computers[i]->ShowComputer(k);
                k++;
            }

        }
        cout << endl;
    }
}

void computerList::addComputer()
{
    cout << "Add computer:\n1. Computer\n2. UpgradeComputer \n3. Laptop\n";
    int x;
    computer* new_computers;
    cin >> x;
    if (x == 1)
    {
        new_computers = new computer;
        new_computers->ReadComputerWithKeyboard();
        computers[count] = new_computers;
        count++;
    }
    else if (x == 2)
    {
        new_computers = new upgradeComputer;
        new_computers->ReadComputerWithKeyboard();
        computers[count] = new_computers;
        count++;
    }
    else if (x == 3) 
    {
        new_computers = new laptop;
        new_computers->ReadComputerWithKeyboard();
        computers[count] = new_computers;
        count++;
    }
    else
    {
        cout << "not found";
    } 
}

void computerList::deleteComputer()
{
    if (count == 0)
    {
        cout << "FIRSTLY, READ COMPUTERS\n";
    }
    else
    {
        cout << "if (you want to delete the computer)\n{\n    enter its number;\n}\nelse\n{\n    enter '0';\n}" << endl;
        int x;
        do
        {
            x = isInt();
        } while (x<0 || x>count);
        if (x == 0)
            return;
        else
        {
            for (int i = x - 1; i < count;i++)
            {
                computers[i] = computers[i + 1];
            }
            count--;
        }
    }
}

void computerList::saveIntoFile()
{
    if (count > 0)
    {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for (int i = 0; i < count; i++)
        {
            if (computers[i]->getType() == "computer")
                count1++;
            else if (computers[i]->getType() == "upgradeComputer")
                count2++;
            else if (computers[i]->getType() == "laptop")
                count3++;
        }
        ofstream file1;
        ofstream file2;
        ofstream file3;
        file1.open("computers.txt");
        file2.open("upgradeComputers.txt");
        file3.open("laptops.txt");
        file1 << count1 << endl;
        file2 << count2 << endl;
        file3 << count3 << endl;
        for (int i = 0; i < count;i++)
        {
            computers[i]->addToFile();
        }
        file1.close();
        file2.close();
        file3.close();
        cout << "Computers recorded\n";
    }
    else
    {
        cout << "FIRSTLY, READ COMPUTERS" << endl;
    }

}

void computerList::Price20To30()
{
    float ClockFr = 0;
    int Index = -1;
    bool success = false;
    for (int i = 0;i < count;i++)
    {
        if (computers[i]->getCpu_clock() > ClockFr && computers[i]->getPrice() >= 20000 && computers[i]->getPrice() <= 30000)
        {
            Index = i;
            ClockFr = computers[i]->getCpu_clock();
            success = true;
        }

    }
    
    if (ClockFr > 0)
    {
        computers[Index]->ShowTableHeader();
        if (success)
            computers[Index]->ShowComputer(0);
    }
    else
        cout << "Not found" << endl;
}
void computerList::TotalCost()
{
    int sum = 0;
    for (int i = 0;i < count;i++)
    {
        sum += computers[i]->cost();
    }
    cout << "Total cost = " << sum << " $" << endl;
}
void computerList::RedOrBlue()
{
    int k = 0;
    cout << "AMD computers: " << endl;
    for (int i = 0; i < count; i++)
    {
        if (computers[i]->red())
        {
            computers[i]->ShowComputer(k);
            k++;
        }
    }
    cout << "Intel & nvidia computers: " << endl;
    for (int i = 0; i < count; i++)
    {
        if (computers[i]->blue())
        {
            computers[i]->ShowComputer(k);
            k++;
        }

    }
    if (k == 0)
        cout << "Not found\n";
}

void computerList::SearchByType()
{
    string tempType;
    bool success = false;
    cin >> tempType;
    int k = 0;
    for (int i = 0; i < count; i++)
    {
        if (computers[i]->getType() == tempType)
        {
            if (success == false)
            {
                computers[i]->ShowTableHeader();
                success = true;
            }
            computers[i]->ShowComputer(k);
            k++;
        }
           
    }
    if(k==0)
        cout << "Not found\n";
}
