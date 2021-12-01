#include "Computer.h"
#include "Extra.h"

void computer::ReadComputer(ifstream& infile)
{
    string temp;
    getline(infile, temp);
    istringstream str(temp);
    getline(str, cpu_brand, ';');
    getline(str, temp, ';');
    cpu_clock = atof(temp.c_str());
    getline(str, motherboard, ';');
    getline(str, harddrive, ';');
    getline(str, videocard, ';');
    getline(str, temp, ';');
    wifi = atoi(temp.c_str());
    getline(str, temp, ';');
    price = atoi(temp.c_str());
    getline(str, temp, ';');
    store = atoi(temp.c_str());
}
void upgradeComputer::ReadComputer(ifstream& infile)
{
    string temp;
    getline(infile, temp);
    istringstream str(temp);
    getline(str, cpu_brand, ';');
    getline(str, temp, ';');
    cpu_clock = atof(temp.c_str());
    getline(str, motherboard, ';');
    getline(str, harddrive, ';');
    getline(str, videocard, ';');
    getline(str, temp, ';');
    wifi = atoi(temp.c_str());
    getline(str, temp, ';');
    price = atoi(temp.c_str());
    getline(str, temp, ';');
    store = atoi(temp.c_str());
    getline(str, light, ';');
    getline(str, cooling, ';');
    getline(str, temp, ';');
    ssd = atoi(temp.c_str());
}
void laptop::ReadComputer(ifstream& infile)
{
    string temp;
    getline(infile, temp);
    istringstream str(temp);
    getline(str, cpu_brand, ';');
    getline(str, temp, ';');
    cpu_clock = atof(temp.c_str());
    getline(str, motherboard, ';');
    getline(str, harddrive, ';');
    getline(str, videocard, ';');
    getline(str, temp, ';');
    wifi = atoi(temp.c_str());
    getline(str, temp, ';');
    price = atoi(temp.c_str());
    getline(str, temp, ';');
    store = atoi(temp.c_str());
    getline(str, temp, ';');
    weight = atoi(temp.c_str());
    getline(str, temp, ';');
    usbPort = atoi(temp.c_str());
}

void computer::ReadComputerWithKeyboard()
{
    cout << "Print the cpu_brand = ";
    cin.get();
    getline(cin, cpu_brand);
    cout << "Print the cpu_clock = ";
    cpu_clock = isFloat();
    cout << "Print the motherboard = ";
    cin.get();
    getline(cin, motherboard);
    cout << "Print the harddrive = ";
    getline(cin, harddrive);
    cout << "Print the videocard = ";
    getline(cin, videocard);
    cout << "Modul wifi (true/false) = ";
    wifi = isBool();
    cout << "Print the price = ";
    price = isInt();
    cout << "Print count in store = ";
    store = isInt();
}
void upgradeComputer::ReadComputerWithKeyboard()
{
    cout << "Print the cpu_brand = ";
    cin.get();
    getline(cin, cpu_brand);
    cout << "Print the cpu_clock = ";
    cpu_clock = isFloat();
    cout << "Print the motherboard = ";
    cin.get();
    getline(cin, motherboard);
    cout << "Print the harddrive = ";
    getline(cin, harddrive);
    cout << "Print the videocard = ";
    getline(cin, videocard);
    cout << "Modul wifi (true/false) = ";
    wifi = isBool();
    cout << "Print the price = ";
    price = isInt();
    cout << "Print count in store = ";
    store = isInt();
    cout << "Print the light = ";
    cin.get();
    getline(cin, light);
    cout << "Print the cooling = ";
    getline(cin, cooling);
    cout << "Ssd (true/false)";
    ssd = isBool();
}
void laptop::ReadComputerWithKeyboard()
{
    cout << "Print the cpu_brand = ";
    cin.get();
    getline(cin, cpu_brand);
    cout << "Print the cpu_clock = ";
    cpu_clock = isFloat();
    cout << "Print the motherboard = ";
    cin.get();
    getline(cin, motherboard);
    cout << "Print the harddrive = ";
    getline(cin, harddrive);
    cout << "Print the videocard = ";
    getline(cin, videocard);
    cout << "Modul wifi (true/false) = ";
    wifi = isBool();
    cout << "Print the price = ";
    price = isInt();
    cout << "Print count in store = ";
    store = isInt();
    cout << "Print weight = ";
    weight = isInt();
    cout << "Print quantity of usbPort = ";
    usbPort = isInt();
}



void computer::addToFile()
{
    ofstream fout("computers.txt", ios_base::app);
    fout << cpu_brand << ";" << cpu_clock << ";"
        << motherboard << ";" << harddrive << ";"
        << videocard << ";" << wifi << ";"
        << price << ";" << store << ";" << endl;
    fout.close();
}
void upgradeComputer::addToFile()
{
    ofstream fout("upgradeComputers.txt", ios_base::app);
    fout << cpu_brand << ";" << cpu_clock << ";"
        << motherboard << ";" << harddrive << ";"
        << videocard << ";" << wifi << ";"
        << price << ";" << store << ";"
        << light << ";" << cooling << ";"
        << ssd << ";" << endl;
    fout.close();
}
void laptop::addToFile()
{
    ofstream fout("laptops.txt", ios_base::app);
    fout << cpu_brand << ";" << cpu_clock << ";"
        << motherboard << ";" << harddrive << ";"
        << videocard << ";" << wifi << ";"
        << price << ";" << store << ";" 
        << weight << ";" << usbPort << ";"
        << endl;
    fout.close();
}


void computer::ShowComputer(int i)
{
    cout
        << left << setw(3) << i + 1
        << left << setw(1) << " "
        << left << setw(25) << cpu_brand
        << left << setw(15) << cpu_clock
        << left << setw(22) << motherboard
        << left << setw(30) << harddrive
        << left << setw(25) << videocard
        << left << setw(10) << wifi
        << left << setw(10) << price
        << left << setw(5) << store
        << endl;
}
void upgradeComputer::ShowComputer(int i)
{
    cout
        << left << setw(3) << i + 1
        << left << setw(1) << " "
        << left << setw(25) << cpu_brand
        << left << setw(15) << cpu_clock
        << left << setw(22) << motherboard
        << left << setw(30) << harddrive
        << left << setw(25) << videocard
        << left << setw(10) << wifi
        << left << setw(10) << price
        << left << setw(8) << store
        << left << setw(10) << light
        << left << setw(10) << cooling
        << left << setw(5) << ssd
        << endl;
}
void laptop::ShowComputer(int i)
{
    cout
        << left << setw(3) << i + 1
        << left << setw(1) << " "
        << left << setw(25) << cpu_brand
        << left << setw(15) << cpu_clock
        << left << setw(22) << motherboard
        << left << setw(30) << harddrive
        << left << setw(25) << videocard
        << left << setw(10) << wifi
        << left << setw(10) << price
        << left << setw(8) << store
        << left << setw(8) << weight
        << left << setw(5) << usbPort
        << endl;
}

void computer::ShowTableHeader()
{
    cout
        << left << setw(4) << " "
        << left << setw(25) << "cpu_brand"
        << left << setw(15) << "cpu_clock"
        << left << setw(22) << "motherboard"
        << left << setw(30) << "harddrive"
        << left << setw(25) << "videocard"
        << left << setw(10) << "wifi"
        << left << setw(10) << "price"
        << left << setw(8) << "store"
        << endl;
}
void upgradeComputer::ShowTableHeader()
{
    cout
        << left << setw(4) << " "
        << left << setw(25) << "cpu_brand"
        << left << setw(15) << "cpu_clock"
        << left << setw(22) << "motherboard"
        << left << setw(30) << "harddrive"
        << left << setw(25) << "videocard"
        << left << setw(10) << "wifi"
        << left << setw(10) << "price"
        << left << setw(8) << "store"
        << left << setw(10) << "light"
        << left << setw(10) << "cooling"
        << left << setw(5) << "ssd"
        << endl;
}
void laptop::ShowTableHeader()
{
    cout
        << left << setw(4) << " "
        << left << setw(25) << "cpu_brand"
        << left << setw(15) << "cpu_clock"
        << left << setw(22) << "motherboard"
        << left << setw(30) << "harddrive"
        << left << setw(25) << "videocard"
        << left << setw(10) << "wifi"
        << left << setw(10) << "price"
        << left << setw(8) << "store"
        << left << setw(8) << "weight"
        << left << setw(5) << "usbPort"
        << endl;
}
int computer::cost()
{
    return price * store;
}
bool computer::red()
{
    int cpuRed = 0, videocardRed = 0;
    string amd = "AMD";
    if (cpu_brand.length() > 2 && videocard.length() > 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (cpu_brand[i] == amd[i])
                cpuRed++;
            if (videocard[i] == amd[i])
                videocardRed++;
        }
        if (cpuRed == 3 && videocardRed == 3)
            return true;
    }
    return false;
}
bool computer::blue()
{
    string nvidia = "nvidia";
    string intel = "intel";
    int cpuBlue = 0, videocardBlue = 0;
    if (cpu_brand.length() > 4 && videocard.length() > 5)
    {
        for (int i = 0; i < 5; i++)
            if (cpu_brand[i] == intel[i])
                cpuBlue++;
        for (int i = 0; i < 6; i++)
            if (videocard[i] == nvidia[i])
                videocardBlue++;
        if (cpuBlue == 5 && videocardBlue == 6)
            return true;
    }
    return false;
}
float computer::getCpu_clock()
{
    return cpu_clock;
}
int computer::getPrice()
{
    return price;
}
string computer::getType()
{
    return type;
}