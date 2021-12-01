#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <iomanip> 
#include <string>
#include <sstream>

using namespace std;

class computer
{
protected:
    string type;
    string cpu_brand;
    float cpu_clock;
    string motherboard;
    string harddrive;
    string videocard;
    bool wifi;
    int price;
    int store;
public:
    /*computer(string cpu_brand, float cpu_clock, string motherboard, string harddrive, string videocard, bool wifi, int price, int store);*/
    computer() { type = "computer"; };
    virtual void ReadComputer(ifstream& infile);
    virtual void ReadComputerWithKeyboard();
    virtual void addToFile();
    virtual void ShowComputer(int i);
    virtual void ShowTableHeader();
    string getType();
    int cost();
    bool red();
    bool blue();
    float getCpu_clock();
    int getPrice();

};

class upgradeComputer : public computer
{
private:
    string light;
    string cooling;
    bool ssd;
public:
    upgradeComputer() { type = "upgradeComputer"; };
    void ReadComputer(ifstream& infile) override;
    void ReadComputerWithKeyboard() override;
    void addToFile() override;
    void ShowComputer(int i) override;
    void ShowTableHeader() override;
};

class laptop : public computer
{
private:
    int weight;
    int usbPort;
public:
    laptop() { type = "laptop"; };
    void ReadComputer(ifstream& infile) override;
    void ReadComputerWithKeyboard() override;
    void addToFile() override;
    void ShowComputer(int i) override;
    void ShowTableHeader() override;
};