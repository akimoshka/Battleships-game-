#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


int kol_ships(int n[10][10])
{
    int kol = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (n[i][j] == 1) kol++;
        }
    }
    return kol;
}

void compVcomp(int kol)
{
    //1
    int comp_1[10][10], n = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            comp_1[i][j] = 0;
        }
    }
    int x_c, y_c;
    while (n != kol)
    {
        x_c = 1 + rand() % 9;
        y_c = 1 + rand() % 9;
        while (comp_1[x_c][y_c] != 0)
        {
            x_c = 1 + rand() % 9;
            y_c = 1 + rand() % 9;
        }
        comp_1[x_c][y_c] = 1;
        n++;
    }

    //2
    n = 0;
    int comp_2[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            comp_2[i][j] = 0;
        }
    }

    while (n != kol)
    {
        x_c = 1 + rand() % 9;
        y_c = 1 + rand() % 9;
        while (comp_2[x_c][y_c] != 0)
        {
            x_c = 1 + rand() % 9;
            y_c = 1 + rand() % 9;
        }
        comp_2[x_c][y_c] = 1;
        n++;
    }

    //вывод полей 
    while (kol_ships(comp_1) != 0 && kol_ships(comp_2) != 0)
    {
        system("cls");
        cout << "Computer 1:\n";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    if (j == 0) cout << "0" << setw(3);
                    else {
                        cout << setw(3) << j;
                    }
                }
                else if (j == 0) {
                    cout << i << setw(3);
                }
                else if (comp_1[i][j] == 1) cout << setw(3) << "X";
                else if (comp_1[i][j] == 2) cout << setw(3) << "#";
                else if (comp_1[i][j] == 3) cout << setw(3) << "0";
                else cout << setw(3) << ".";
            }
            cout << endl;
        }

        cout << "\nComputer 2:\n";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    if (j == 0) cout << "0" << setw(3);
                    else {
                        cout << setw(3) << j;
                    }
                }
                else if (j == 0) {
                    cout << i << setw(3);
                }
                else if (comp_2[i][j] == 1) cout << setw(3) << "X";
                else if (comp_2[i][j] == 2) cout << setw(3) << "#";
                else if (comp_2[i][j] == 3) cout << setw(3) << "0";
                else cout << setw(3) << ".";
            }
            cout << endl;
        }
        system("pause");
        int x, y;
        x = 1 + rand() % 9;
        y = 1 + rand() % 9;
        while (comp_2[x][y] == 2 || comp_2[x][y] == 3)
        {
            x = 1 + rand() % 9;
            y = 1 + rand() % 9;
        }
        cout << "Computer 1: " << x << ", " << y;
        cout << endl;
        if (comp_2[x][y] == 1)
        {
            cout << "Computer 1 hit a ship!!!\n\n";
            comp_2[x][y] = 2;
        }
        else if (comp_2[x][y] == 0)
        {
            cout << "MIS\n\n";
            comp_2[x][y] = 3;
        }

        x = 1 + rand() % 9;
        y = 1 + rand() % 9;
        while (comp_1[x][y] == 2 || comp_1[x][y] == 3)
        {
            x = 1 + rand() % 9;
            y = 1 + rand() % 9;
        }
        cout << "Computer 2: " << x << ", " << y;
        cout << endl;
        if (comp_1[x][y] == 1)
        {
            cout << "Computer 2 hit a ship!!!\n";
            comp_1[x][y] = 2;
        }
        else if (comp_1[x][y] == 0)
        {
            cout << "MIS\n";
            comp_1[x][y] = 3;
        }

        //0 - пустое поле (.)
        //1 - судно (X)
        //2 - подбитое судно (#)
        //3 - неправильное попадение в судно (0)

        system("pause");

    }
    if (kol_ships(comp_1) == 0 && kol_ships(comp_2) > 0)
    {
        system("cls");
        cout << "Computer 2 wins!!!\n";
    }
    else if (kol_ships(comp_1) > 0 && kol_ships(comp_2) == 0)
    {
        system("cls");
        cout << "Computer 1 wins!!!\n";
    }
    else
    {
        system("cls");
        cout << "TIE!!!\n";
    }

}



void persVcomp(int kol)
{
    system("cls");
    bool ans;
    int ships_p[10][10], ships_c[10][10], n = 0, x, y;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ships_p[i][j] = 0;
            ships_c[i][j] = 0;
        }
    }

    while (n != kol)
    {
        x = 1 + rand() % 9;
        y = 1 + rand() % 9;
        while (ships_c[x][y] != 0)
        {
            x = 1 + rand() % 9;
            y = 1 + rand() % 9;
        }
        ships_c[x][y] = 1;
        n++;
    }
    n = 0;
    cout << "1 - enter ships yourself\n0 - computer enters your ships for you\nEnter here - ";
    cin >> ans;
    if (ans == 0)
    {
       
        while (n != kol)
        {
            x = 1 + rand() % 9;
            y = 1 + rand() % 9;
            while (ships_p[x][y] != 0)
            {
                x = 1 + rand() % 9;
                y = 1 + rand() % 9;
            }
            ships_p[x][y] = 1;
            n++;
        }
    }
    else
    {
        system("cls");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    if (j == 0) cout << "0" << setw(3);
                    else {
                        cout << setw(3) << j;
                    }
                }
                else if (j == 0) {
                    cout << i << setw(3);
                }
                else cout << setw(3) << ".";
            }
            cout << endl;
        }
        cout << "\nEnter the coordinats of your ships(x y): \n";
        for (int kol_i = 0; kol_i < kol; kol_i++)
        {
            int x, y;
            cin >> x >> y;

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (x == i && y == j)
                    {
                        ships_p[i][j] = 1;
                        break;
                    }
                }
            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == 0) {
                        if (j == 0) cout << "0" << setw(3);
                        else
                        {
                            cout << setw(3) << j;
                        }
                    }
                    else if (j == 0)
                    {
                        cout << i << setw(3);
                    }
                    else if (ships_p[i][j] == 1) cout << setw(3) << "X";

                    else cout << setw(3) << ".";

                }
                cout << endl;
            }
        }
    }


    while (kol_ships(ships_p) != 0 && kol_ships(ships_c) != 0)
    {
        system("pause");
        system("cls");


        cout << "YOUR FIELD\n";

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    if (j == 0) cout << "0" << setw(3);
                    else {
                        cout << setw(3) << j;
                    }
                }
                else if (j == 0) {
                    cout << i << setw(3);
                }
                else if (ships_p[i][j] == 1) cout << setw(3) << "X";
                else if (ships_p[i][j] == 2) cout << setw(3) << "#";
                else if (ships_p[i][j] == 3) cout << setw(3) << "0";
                else cout << setw(3) << ".";
            }
            cout << endl;
        }


        cout << "\nCOMPUTER FIELD\n";

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    if (j == 0) cout << "0" << setw(3);
                    else {
                        cout << setw(3) << j;
                    }
                }
                else if (j == 0) {
                    cout << i << setw(3);
                }
                else if (ships_c[i][j] == 2) cout << setw(3) << "#";
                else if (ships_c[i][j] == 3) cout << setw(3) << "0";
                //else if (ships_c[i][j] == 1) cout << setw(3) << "X";
                else cout << setw(3) << ".";
            }
            cout << endl;
        }
        cout << "\nEnter the coordinate of your oponent ship(x y) - ";
        cin >> x >> y;
        if (ships_c[x][y] == 1)
        {
            cout << "You hit a ship!!!\n";
            ships_c[x][y] = 2;
        }
        else
        {
            cout << "MIS\n";
            ships_c[x][y] = 3;
        }

        cout << "\n\nYour oponents turn - ";
        x = 1 + rand() % 9;
        y = 1 + rand() % 9;
        while (ships_p[x][y] == 2 || ships_p[x][y] == 3)
        {
            x = 1 + rand() % 9;
            y = 1 + rand() % 9;
        }
        cout << x << ", " << y;
        cout << endl;

        if (ships_p[x][y] == 1)
        {
            cout << "Your oponent hit your ship!!!\n";
            ships_p[x][y] = 2;
        }
        else
        {
            cout << "MIS\n";
            ships_p[x][y] = 3;
        }
        cout << endl;
    }

    if (kol_ships(ships_p) == 0 && kol_ships(ships_c) > 0)
    {
        system("cls");
        cout << "Computer wins!!!\n";
    }
    else if (kol_ships(ships_p) > 0 && kol_ships(ships_c) == 0)
    {
        system("cls");
        cout << "YOU WIN!!!\n";
    }
    else
    {
        system("cls");
        cout << "TIE!!!\n";
    }
}



int main()
{
    srand(time(NULL));
    system("color 3E");

    int kol;
    cout << "\t\tBattle Ships!!!!\n";

    //поле
    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0) {
                if (j == 0) cout << "0" << setw(3);
                else {
                    cout << setw(3) << j;
                }
            }
            else if (j == 0) {
                cout << i << setw(3);
            }
            else cout << setw(3) << ".";
        }
        cout << endl;
    }
    */

    bool ans;
    cout << "Enter the amount of ships you wnat to have - ";
    cin >> kol;
    cout << "Enter a mode:\n\n1 - Computer vs Computer\n0 - Person vs Computer\n\nEnter here - ";
    cin >> ans;
    if (ans == 1)
    {
        compVcomp(kol);
    }
    if (ans == 0)
    {
        persVcomp(kol);
    }

    system("pause");
    system("cls");

    cout << "Do you want to play again?\n\n1 - yes\n0 - no\n\n\tEnter here - ";
    cin >> ans;
    while (ans == 1)
    {
        system("cls");

        cout << "\t\tBattle Ships!!!!\n";

        cout << "Enter the amount of ships you wnat to have - ";
        cin >> kol;

        cout << "Enter a mode:\n\n1 - Computer vs Computer\n0 - Person vs Computer\n\nEnter here - ";
        cin >> ans;

        if (ans == 1)
        {
            compVcomp(kol);
        }
        if (ans == 0)
        {
            persVcomp(kol);
        }

        system("pause");
        system("cls");

        cout << "Do you want to play again?\n\n1 - yes\n0 - no\n\n\tEnter here - ";

        cin >> ans;
    }


    return 0;
}
