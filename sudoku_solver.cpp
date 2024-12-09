#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

using namespace std;
#define grey "\x1b[38;5;247m"
#define greybg "\x1b[48;5;247m"
#define yellow "\x1b[33m"
#define red "\x1b[31m"
#define redbg "\x1b[41m"
#define reset "\x1b[0m"

void filla(int box[9][9], int a[9], int i, int j)
{
    int count = 0;
    for (int m = 1; m <= 9; m++)
    {
        int x = 1, y = 1, v = 1;
        for (int n = 0; n < 9; n++)
        {
            if (box[i][n] == m)
            {
                x = 0;
                break;
            }
            if (box[n][j] == m)
            {
                y = 0;
                break;
            }
        }
        int sr = (i / 3) * 3;
        int sc = (j / 3) * 3;
        for (int r = sr; r < sr + 3; r++)
        {
            for (int c = sc; c < sc + 3; c++)
            {
                if (box[r][c] == m)
                {
                    v = 0;
                    break;
                }
            }
        }
        if (x & y & v)
        {

            a[count++] = m;
        }
    }
}

int solve(int box[9][9], int i, int j)
{
    if (i > 8)
    {
        return 1;
    }
    if (box[i][j] != 0)
    {
        if (j == 8)
        {
            return solve(box, i + 1, 0);
        }
        return solve(box, i, j + 1);
    }
    int a[9] = {0};
    filla(box, a, i, j);
    for (int m = 0; m < 9 && a[m] != 0; m++)
    {
        box[i][j] = a[m];
        if (j == 8)
        {
            if (solve(box, i + 1, 0))
            {
                return 1;
            }
        }
        else
        {
            if (solve(box, i, j + 1))
            {
                return 1;
            }
        }
        box[i][j] = 0;
    }
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void sudoku_box(int c[9][9], int o, int p, int q)
{
    string whitebg;
    cout << "\n\n\n\n\n\n\n";
    if (q == 1)
    {
        cout << "\t\t";
    }
    cout << "\t\t\t\t";
    for (int i = 1; i <= 91; i++)
    {
        char ch = 220;
        cout << red << ch << reset;
    }
    cout << endl;
    for (int z = 1; z <= 9; z++)
    {
        if (q == 1)
        {
            cout << "\t\t";
        }
        cout << "\t\t\t\t" << redbg << " " << reset;
        for (int i = 1; i <= 9; i++)
        {
            if (o == z - 1 && p == i - 1)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            for (int j = 1; j <= 9; j++)
            {
                cout << whitebg << " " << reset;
            }
            if (i % 3 == 0)
            {
                cout << redbg << " " << reset;
            }
            else
            {
                cout << greybg << " " << reset;
            }
        }
        if (z == 5 && q == 0)
        {
            if (p == 9)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            cout << "\t\t\t" << whitebg << "              ";
        }
        cout << endl;
        if (q == 1)
        {
            cout << "\t\t";
        }
        cout << "\t\t\t\t" << redbg << " " << reset;
        for (int i = 1; i <= 9; i++)
        {
            if (o == z - 1 && p == i - 1)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            for (int j = 1; j <= 4; j++)
            {
                cout << whitebg << " " << reset;
            }
            if (c[z - 1][i - 1] > 0)
            {
                cout << red << whitebg << c[z - 1][i - 1] << reset;
            }
            else
            {
                cout << whitebg << " " << reset;
            }
            for (int j = 1; j <= 4; j++)
            {
                cout << whitebg << " " << reset;
            }
            if (i % 3 == 0)
            {
                cout << redbg << " " << reset;
            }
            else
            {
                cout << greybg << " " << reset;
            }
        }
        if (z == 5 && q == 0)
        {
            if (p == 9)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            cout << "\t\t\t" << whitebg << "   Continue   ";
        }
        cout << endl;
        if (q == 1)
        {
            cout << "\t\t";
        }
        cout << "\t\t\t\t" << redbg << " " << reset;
        for (int i = 1; i <= 9; i++)
        {
            if (o == z - 1 && p == i - 1)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            for (int j = 1; j <= 9; j++)
            {
                cout << whitebg << " " << reset;
            }
            if (i % 3 == 0)
            {
                cout << redbg << " " << reset;
            }
            else
            {
                cout << greybg << " " << reset;
            }
        }
        if (z == 5 && q == 0)
        {
            if (p == 9)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            cout << "\t\t\t" << whitebg << "              ";
        }
        cout << endl;
        if (q == 1)
        {
            cout << "\t\t";
        }
        cout << "\t\t\t\t" << redbg << " " << reset;
        for (int i = 1; i <= 9; i++)
        {
            if (o == z - 1 && p == i - 1)
            {
                whitebg = "\x1b[42m";
            }
            else
            {
                whitebg = "\x1b[47m";
            }
            for (int j = 1; j <= 9; j++)
            {
                if (z % 3 == 0)
                {
                    char ch = 220;
                    cout << whitebg << red << ch << reset;
                }
                else
                {
                    char ch = 220;
                    cout << whitebg << grey << ch << reset;
                }
            }
            if (i % 3 == 0 && z % 3 == 0)
            {
                cout << redbg << red << " " << reset;
            }
            else if (i % 3 == 0)
            {
                cout << redbg << " " << reset;
            }
            else if (z % 3 == 0)
            {
                char ch = 220;
                cout << greybg << red << ch << reset;
            }
            else
            {
                cout << greybg << " " << reset;
            }
        }
        cout << endl;
    }
    gotoxy(0, 0);
}

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
    hidecursor();
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "Welcome to sudoku solver!!!" << endl;
    cout << "\n\n\n\n\nRULES:\n->Green colour on the board indicates the cursor" << endl;
    cout << "->Values can be entered through beyboard" << endl;
    cout << "->Cursor can be moved by arrow keys" << endl;
    cout << "->If the value entered is wrong,then the value can be changed by pressing new value in the keyboard" << endl;
    cout << "->If the original value is empty but mistakenly entered some value,then the value can become empty by pressing zero" << endl;
    cout << "->After entering all the values,go to continue button by pressing right arrow key and press enter for solving the sudoku!!!" << endl;
    cout << "->After reading rules,Press any key to enter the values";
    char k;
    k = getch();
    if (k)
    {
        system("cls");
        gotoxy(0, 0);
    }
    int i = 0, j = 0;
    int box[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            box[i][j] = 0;
        }
    }
    i = 0, j = 0;
    for (;;)
    {
        sudoku_box(box, i, j, 0);
        int key;
        if (j != 9)
        {
            key = getch();
            if (key == 224)
            {
                key = getch();
                if (key == 72)
                {
                    if (i != 0)
                    {
                        i--;
                    }
                }
                else if (key == 75)
                {
                    if (j != 0)
                    {
                        j--;
                    }
                }
                else if (key == 77)
                {
                    if (j != 9)
                    {
                        j++;
                    }
                }
                else if (key == 80)
                {
                    if (i != 8)
                    {
                        i++;
                    }
                }
            }
            else if (key >= 48 && key <= 57)
            {
                box[i][j] = key - 48;
                continue;
            }
            else
            {
                continue;
            }
        }
        else
        {
            key = getch();
            if (key == 224)
            {
                key = getch();
                if (key == 75)
                {
                    if (j == 9)
                    {
                        j--;
                    }
                }
            }
            else if (key == 13)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    system("cls");
    i = solve(box, 0, 0);
    if (i == 0)
    {
        cout << "\n\n\n\n\n\t\t\t\tThe sudoku cannot be solved";
        return 0;
    }
    cout << "\n\n\n\t\tSolved Puzzle:";
    sudoku_box(box, -1, -1, i);
    return 0;
}