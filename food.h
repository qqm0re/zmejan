#include <graphics.h>
#include <ctime>                        // требуется для генерации случайных чисел

class food
{
private:
        POS foodPos;                    // ПОзиция
public :
        void draw();                    // функция для рисования еды в окне
        void generate(int, int);        // функция для получения фруктов каждый раз, когда змея их съедает
        bool update(int, int);          // дает нам статус фрукта (вне зависимости сьеден он или нет)
};

void food::draw()                       // Отрисовка Фруктов
{
     setcolor(RED);
     rectangle(foodPos.x, foodPos.y, foodPos.x+30, foodPos.y+30);
     setfillstyle(INTERLEAVE_FILL, RED);
     floodfill(foodPos.x+15, foodPos.y+15, RED);
}

void food::generate(int snakeHeadx, int snakeHeady)     // Генерация новой позиции фрукта
{
     srand(time(0));
     foodPos.x = 30*(rand()%15 + 1);
     srand(time(0));
     foodPos.y = 30*(rand()%15 + 1);
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          generate(snakeHeadx, snakeHeady);
}

bool food::update(int snakeHeadx, int snakeHeady)       // Сообщает статус фрукта
{
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          return true;
     else
          return false;
}

