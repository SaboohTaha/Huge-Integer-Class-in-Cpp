#include "HugeInteger.h"

void Init(HugeInteger*& H,int& NOHs)
{
    ifstream Rdr("input.txt");
    Rdr >> NOHs;
    H = new HugeInteger[NOHs];
    for (int i = 0; i < NOHs; i++)
    {
        Rdr >> H[i];
    }
}

void Print(HugeInteger*& H,const int& NOHs)
{
    system("cls");
    for (int i = 0; i < NOHs; i++)
    {
        cout << "H" << i + 1 << " " << H[i] << endl;
    }
}

void Menu()
{
    cout << "----------------------------" << endl;
    cout << "1. For Binary Operators ( + , - , * , / , % )" << endl;
    cout << "2. For Boolean Operators ( < , > , <= , >= , == , != )" << endl;
    cout << "3. For Assignment Binary Operators ( += , -+ , *= , /= , %= )" << endl;
    cout << "0. To Exit." << endl;
    cout << "----------------------------" << endl;
}

void Menu1()
{
    cout << "----------------------------" << endl;
    cout << "Addition\t\t+" << endl;
    cout << "Substraction\t\t-" << endl;
    cout << "Multiplication\t\t*" << endl;
    cout << "Division\t\t/" << endl;
    cout << "Modulus\t\t\t%" << endl;
    cout << "----------------------------" << endl;
}

void Menu2()
{
    cout << "----------------------------" << endl;
    cout << "Less Than\t\t<" << endl;
    cout << "Greater Than\t\t>" << endl;
    cout << "Less Than Equal To\t<=" << endl;
    cout << "Greater Than Equal To\t>=" << endl;
    cout << "Equality\t\t==" << endl;
    cout << "Not Equal To\t\t!=" << endl;
    cout << "----------------------------" << endl;
}

void Menu3()
{
    cout << "----------------------------" << endl;
    cout << "Addition Equal To\t\t+=" << endl;
    cout << "Substraction Equal To\t\t-=" << endl;
    cout << "Multiplication Equal To\t\t*=" << endl;
    cout << "Division Equal To\t\t/=" << endl;
    cout << "Modulus Equal To\t\t%=" << endl;
    cout << "----------------------------" << endl;
}


int main()
{
    Menu1();
    HugeInteger* H;
    int NOHs;
    Init(H, NOHs);
    char option, d, opr;
    int aoi, loi, roi, select;
    do
    {
        Print(H, NOHs);
        Menu();
        cin >> select;
        switch (select)
        {
        case 1:
            do
            {
                Print(H, NOHs);
                Menu1();
                cout << "Syntax :: H1 = H2 + H3" << endl;
                cout << "Enter The Assigning Equation: ";
                cin >> d >> aoi >> d >> d >> loi >> opr >> d >> roi;
                aoi--, loi--, roi--;
                switch (opr)
                {
                case '+':
                    H[aoi] = H[loi] + H[roi];
                    break;
                case '-':
                    H[aoi] = H[loi] - H[roi];
                    break;
                case '*':
                    H[aoi] = H[loi] * H[roi];
                    break;
                case '/':
                    H[aoi] = H[loi] / H[roi];
                    break;
                case '%':
                    H[aoi] = H[loi] % H[roi];
                    break;
                default:
                    break;
                }
                Print(H, NOHs);
                cout << "Do You Want To Continue? (Y/N): ";
                cin >> option;
            } while (option == 'y' || option == 'Y');
            break;
        case 2:
            do
            {
                Print(H, NOHs);
                Menu2();
                cout << "Syntax :: H1 < H3 or H1 <= H3" << endl;
                cout << "Enter: ";
                cin >> d >> loi >> opr;
                loi--;
                switch (opr)
                {
                case '<':
                    cin >> d;
                    if (d == '=')
                    {
                        cin >> d >> roi;
                        roi--;
                        cout << "H" << loi + 1 << " <= H" << roi + 1 << ((H[loi] <= H[roi]) ? " :: True" : " :: False") << endl;
                    }
                    else
                    {
                        cin >> roi;
                        roi--;
                        cout << "H" << loi + 1 << " < H" << roi + 1 << ((H[loi] < H[roi]) ? " :: True" : " :: False") << endl;
                    }
                    break;
                case '>':
                    cin >> d;
                    if (d == '=')
                    {
                        cin >> d >> roi;
                        roi--;
                        cout << "H" << loi + 1 << " >= H" << roi + 1 << ((H[loi] >= H[roi]) ? " :: True" : " :: False") << endl;
                    }
                    else
                    {
                        cin >> roi;
                        roi--;
                        cout << "H" << loi + 1 << " > H" << roi + 1 << ((H[loi] > H[roi]) ? " :: True" : " :: False") << endl;
                    }
                    break;
                case '=':
                    cin >> d >> d >> roi;
                    roi--;
                    cout << "H" << loi + 1 << " == H" << roi + 1 << ((H[loi] == H[roi]) ? " :: True" : " :: False") << endl;
                    break;
                case '!':
                    cin >> d >> d >> roi;
                    roi--;
                    cout << "H" << loi + 1 << " != H" << roi + 1 << ((H[loi] != H[roi]) ? " :: True" : " :: False") << endl;
                    break;
                default:
                    break;
                }
                cout << "Do You Want To Continue? (Y/N): ";
                cin >> option;
            } while (option == 'y' || option == 'Y');
            break;
        case 3:
            do
            {
                Print(H, NOHs);
                Menu3();
                cout << "Syntax :: H1 += H3" << endl;
                cout << "Enter The Assigning Equation: ";
                cin >> d >> aoi >> opr >> d >> d>> loi;
                aoi--, loi--;
                switch (opr)
                {
                case '+':
                    H[aoi] += H[loi];
                    break;
                case '-':
                    H[aoi] -= H[loi];
                    break;
                case '*':
                    H[aoi] *= H[loi] ;
                    break;
                case '/':
                    H[aoi] /= H[loi] ;
                    break;
                case '%':
                    H[aoi] %= H[loi] ;
                    break;
                default:
                    break;
                }
                Print(H, NOHs);
                cout << "Do You Want To Continue? (Y/N): ";
                cin >> option;
            } while (option == 'y' || option == 'Y');
            break;
        case 0:
            cout << "Exiting The Calculator." << endl;
            break;
        default:
            cout << "Invalid Option Entered!" << endl;
            break;
        }
        if (select == 0)
        {
            break;
        }
    } while (true);
}