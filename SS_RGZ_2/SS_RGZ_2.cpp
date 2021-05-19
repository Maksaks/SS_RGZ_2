#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
    
using namespace std;

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

   
    

    system("pause");
    return 0;
}

void Game::CoutMap()
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
}

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
