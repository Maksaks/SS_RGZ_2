#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
    
using namespace std;
//________________MADE_BY_Maksim________________
class Game {
private:
    int sizeX, sizeY;
    bool** map;
public:
    void CoutMap(); // показ матрицы
    void SetMap(); // установка значений матрицы
    void DisplayMap(); // вывод игрового поля
    void PlayGame(); // начало игры(логика)
    void AllSetOne(); // все клетки живые
    void SetRandom(); // рандомные значения
    Game(int sizeX, int sizeY);
    ~Game();
};
//________________MADE_BY_Maksim________________

//________________MADE_BY_Maksim________________
void Game::PlayGame()
{
    int checker, checkexit, lastchangedcheck = -1, lastchangedcheck2 = -1, iteration_number = 0;
    while (true) {
        // проверка на пустое поле и на зацикленность
        checkexit = 0;
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                if (!map[i][j]) { checkexit++; }
            }
        }
        //выход если пустое игровое поле
        if (checkexit == (sizeX * sizeY)) { system("cls"); DisplayMap(); cout << "\nThe game was successfully completed on " << iteration_number << " step. Congratulations!!!\n " << endl; return; }
        // выход если образовался бесконечный цикл клеток(в результате проверок двух итераций цикла)
        if (lastchangedcheck == checkexit && checkexit == lastchangedcheck2 && iteration_number >= 3) { cout << "Your cells are immortal, congratulations, you are a genius!" << endl; return; }
        lastchangedcheck2 = lastchangedcheck;
        lastchangedcheck = checkexit;


        system("pause");
        system("cls");
        cout << " Step ->" << ++iteration_number << endl;
        checker = 0;
        DisplayMap();
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                //проверка согласно условиям
                // checker переменная для подсчёта соседей клетки
                checker = 0;
                if (i == 0 && j == 0) { // левый верхний угол

                    if (map[i + 1][j]) checker++;
                    if (map[i][j + 1]) checker++;
                    if (map[i + 1][j + 1]) checker++;

                    if (map[i + 1][sizeX - 1]) checker++;
                    if (map[i][sizeX - 1]) checker++;
                    if (map[sizeY - 1][sizeX - 1]) checker++;
                    if (map[sizeY - 1][j]) checker++;
                    if (map[sizeY - 1][j + 1]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }
                    continue;
                }
                if (i == sizeY - 1 && j == 0) { // левый нижний угол
                    if (map[i - 1][j]) checker++;
                    if (map[i][j + 1]) checker++;
                    if (map[i - 1][j + 1]) checker++;

                    if (map[0][j + 1]) checker++;
                    if (map[0][0]) checker++;
                    if (map[0][sizeX - 1]) checker++;
                    if (map[sizeY - 1][sizeX - 1]) checker++;
                    if (map[sizeY - 2][sizeX - 1]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }
                    continue;
                }
                if (i == 0 && j == sizeX - 1) { // правый верхний угол
                    if (map[i + 1][j]) checker++;
                    if (map[i][j - 1]) checker++;
                    if (map[i + 1][j - 1]) checker++;

                    if (map[sizeY - 1][sizeX - 2]) checker++;
                    if (map[sizeY - 1][sizeX - 1]) checker++;
                    if (map[sizeY - 1][0]) checker++;
                    if (map[0][0]) checker++;
                    if (map[1][0]) checker++;


                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }
                    continue;
                }
                if (i == sizeY - 1 && j == sizeX - 1) { // правый нижний угол
                    if (map[i - 1][j]) checker++;
                    if (map[i][j - 1]) checker++;
                    if (map[i - 1][j - 1]) checker++;

                    if (map[sizeY - 2][0]) checker++;
                    if (map[sizeY - 1][0]) checker++;
                    if (map[0][0]) checker++;
                    if (map[0][sizeX - 1]) checker++;
                    if (map[0][sizeX - 2]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }
                    continue;
                }
                if (i == 0) { //верхняя граница

                    if (map[i][j + 1]) checker++;
                    if (map[i][j - 1]) checker++;
                    if (map[i + 1][j]) checker++;
                    if (map[i + 1][j + 1]) checker++;
                    if (map[i + 1][j - 1]) checker++;

                    if (map[sizeY - 1][j]) checker++;
                    if (map[sizeY - 1][j + 1]) checker++;
                    if (map[sizeY - 1][j - 1]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }

                    continue;
                }
                if (j == 0) { //левая граница

                    if (map[i - 1][j]) checker++;
                    if (map[i][j + 1]) checker++;
                    if (map[i + 1][j]) checker++;
                    if (map[i + 1][j + 1]) checker++;
                    if (map[i - 1][j + 1]) checker++;

                    if (map[i][sizeX - 1]) checker++;
                    if (map[i + 1][sizeX - 1]) checker++;
                    if (map[i - 1][sizeX - 1]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }

                    continue;
                }
                if (i == sizeY - 1) { //нижняя граница

                    if (map[i][j - 1]) checker++;
                    if (map[i][j + 1]) checker++;
                    if (map[i - 1][j]) checker++;
                    if (map[i - 1][j + 1]) checker++;
                    if (map[i - 1][j - 1]) checker++;

                    if (map[0][j]) checker++;
                    if (map[0][j - 1]) checker++;
                    if (map[0][j + 1]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }

                    continue;
                }
                if (j == sizeX - 1) { //правая граница

                    if (map[i + 1][j]) checker++;
                    if (map[i - 1][j]) checker++;
                    if (map[i][j - 1]) checker++;
                    if (map[i + 1][j - 1]) checker++;
                    if (map[i - 1][j - 1]) checker++;

                    if (map[i][0]) checker++;
                    if (map[i + 1][0]) checker++;
                    if (map[i - 1][0]) checker++;

                    if (checker < 2 || checker > 3) { map[i][j] = 0; }
                    if (checker == 3 && !map[i][j]) { map[i][j] = 1; }

                    continue;
                }
                if (map[i - 1][j]) checker++;
                if (map[i + 1][j]) checker++;
                if (map[i][j + 1]) checker++;
                if (map[i][j - 1]) checker++;

                if (map[i + 1][j - 1]) checker++;
                if (map[i + 1][j + 1]) checker++;
                if (map[i - 1][j - 1]) checker++;
                if (map[i - 1][j + 1]) checker++;

                if (checker < 2 || checker > 3) { map[i][j] = 0; }
                if (checker == 3 && !map[i][j]) { map[i][j] = 1; }
            }
        }
    }
}
//________________MADE_BY_Maksim________________

//________________MADE_BY_Maksim________________
void Game::AllSetOne()
{
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            map[i][j] = 1;
        }
    }
}
//________________MADE_BY_Maksim________________
//________________MADE_BY_Maksim________________
Game::Game(int sizeX, int sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    map = new bool* [sizeY];
    for (int i = 0; i < sizeY; i++) {
        map[i] = new bool[sizeX];
    }
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            map[i][j] = 0;
        }
    }
}

Game::~Game()
{
    for (int i = 0; i < sizeY; i++)
        delete[] map[i];
    delete[] map;
}
//________________MADE_BY_Maksim________________
int main()
{
    system("color 70");
    int x, y;
    srand(time(NULL));
    while (true) {
        system("cls");
        cout << "Input size x y" << endl;
        cin >> x >> y;
        if (x <= 0 || y <= 0) continue;
        else break;
    }

    Game Console(x, y);
    Console.CoutMap();
    Console.SetMap();
    Console.PlayGame();
    

    system("pause");
    return 0;
}

//________________MADE_BY_Dima________________
void Game::CoutMap()
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
}
//________________MADE_BY_Dima________________
void Game::DisplayMap()
{
    for (int i = 0; i < sizeX * 2 + 2; i++)
        cout << "\x0dc";
    cout << endl;
    for (int i = 0; i < sizeY; i++) {
        cout << "\xdd";
        for (int j = 0; j < sizeX; j++) {
            if (map[i][j])
                cout << "><";
            if (!map[i][j])
                cout << "  ";
        }
        cout << "\xde" << endl;
    }
    for (int i = 0; i < sizeX * 2 + 2; i++)
        cout << "\x0df";
    cout << endl;
}
//________________MADE_BY_Dima________________
void Game::SetMap()
{
    while (true) {
        int x, y;
        system("cls");
        cout << "\t";
        for (int i = 0; i < sizeX; i++)
            cout << i + 1 << " ";

        cout << endl;
        for (int i = 0; i < sizeY; i++)
        {
            cout << i + 1 << ":\t";
            for (int j = 0; j < sizeX; j++)
            {
                if (j < 9) {
                    cout << map[i][j] << " ";
                }
                else cout << map[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "Input live kletki x y (x - horiz, y - vertic) or 0 0 to finish or 11111 11111 to fill the whole array 1 \n or 22222 22222 to fill rand" << endl;
        cin >> x >> y;

        if (x == 11111 || y == 11111)
        {
            AllSetOne(); return;
        }
        if (x == 22222 || y == 22222)
        {
            SetRandom(); return;
        }
        if (x > sizeX || y > sizeY || x < 0 || y < 0)
            continue;
        if (x == 0 || y == 0)
            return;
        x--;
        y--;
        map[y][x] = 1;
    }
}
//________________MADE_BY_Dima________________
//________________MADE_TOGETHER________________
void Game::SetRandom()
{
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {

