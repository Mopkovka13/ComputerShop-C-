#include "ComputerList.h"
#include "Extra.h"

void ClearScreen();
#define n 100

void menu();
int main()
{
    system("mode con cols=177 lines=38");
    char x;
    bool success = false;
    computerList list(n);

    ClearScreen();
    menu();
    cin >> x;
    while (x)
    {
        switch (x)
        {
        case '1':
            ClearScreen();
            list.readComputers();
            success = true;
            menu();
            break;
        case '2':
            ClearScreen();
            list.showComputers();
            system("pause");
            ClearScreen();
            menu();
            break;
        case '3':
            ClearScreen();
            if (success == false)
            {
                cout << "First, read the file\n\n";
                menu();
            }
            else
            {
                list.addComputer();
                ClearScreen();
                menu();
            }
            break;
        case '4':
            ClearScreen();
            list.deleteComputer();
            system("pause");
            ClearScreen();
            menu();
            break;
        case '5':
            ClearScreen();
            list.saveIntoFile();
            system("pause");
            ClearScreen();
            menu();
            break;
        case '6':
            ClearScreen();
            list.Price20To30();
            system("pause");
            ClearScreen();
            menu();
            break;
        case '7':
            ClearScreen();
            list.RedOrBlue();
            system("pause");
            ClearScreen();
            menu();
            break;
        case '8':
        {
            ClearScreen();
            list.TotalCost();
            system("pause");
            ClearScreen();
            menu();
            break;
        }
        case 'x':
        {
            ClearScreen();
            list.SearchByType();
            system("pause");
            ClearScreen();
            menu();
            break;
        }
        default:
            ClearScreen();
            cout << "Case is missing\n" << endl;
            menu();
            break;
        case '9':
            ClearScreen();
            cout << "Program is closed\n";
            //delete list;
            //delete[] computers;
            return 0;
        }
        cin >> x;
    }

    return 0;
}

void menu()
{
    cout << "1. Read from a file\n2. Show computers\n3. Add computer\n4. Delete computer\n5. Save into file\n6. Price(20-30k), Max cpu \n7. Full AMD or Intel&nvidia\n8. Total cost\nx. Search By Type\n9. Exit\n";
}
void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}