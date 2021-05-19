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
    void DisplayMap(); // вывод игрового поля//
    void PlayGame(); // начало игры(логика)
    void AllSetOne(); // все клетки живые
    void SetRandom(); // рандомные значения
    Game(int sizeX, int sizeY);
    ~Game();
};

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

