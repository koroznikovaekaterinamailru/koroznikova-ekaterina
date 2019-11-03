#include "TXLib.h"

const float dt = 0.1;
struct ball
   {
        float x = 0;
        float y = 0;
        float r = 0;
        float RED = 0;
        float GREEN = 0;
        float BLUE = 0;
        float vx = 100;
        float vy = 100;


   };

void drawBall(ball Example)
{
    for (int i = Example.r; Example.r > 0; Example.r--)
    {
        txSetColor(RGB(Example.RED - (Example.RED*Example.r/i), Example.GREEN - (Example.GREEN*Example.r/i), Example.BLUE - (Example.BLUE*Example.r/i)));
        txSetFillColor(RGB(Example.RED - (Example.RED*Example.r/i), Example.GREEN - (Example.GREEN*Example.r/i), Example.BLUE - (Example.BLUE*Example.r/i)));
        txCircle(Example.x, Example.y, Example.r);
        txSetFillColor(RGB(0,0,0));
    }

}
void moveBall(ball* Example)
{
        (*Example).x += (*Example).vx * dt;
        (*Example).y += (*Example).vy * dt;
        if ((*Example).y > 500 || (*Example).y < 100)
            (*Example).vy = -(*Example).vy;
        if ((*Example).x > 700 || (*Example).x < 100)
            (*Example).vx = -(*Example).vx;
}
void controllBall(ball* Example)
{
    if (GetAsyncKeyState(VK_LEFT))
    (*Example).vx = (*Example).vx - 1;
    if (GetAsyncKeyState(VK_RIGHT))
    (*Example).vx = (*Example).vx + 1;
    if (GetAsyncKeyState(VK_UP))
    (*Example).vy = (*Example).vy - 1;
    if (GetAsyncKeyState(VK_DOWN))
    (*Example).vy = (*Example).vy + 1;
}
void collideBall(ball* one, ball* two)
{
        if  ((((*two).x-(*one).x)*((*two).x-(*one).x) + ((*two).y-(*one).y)*((*two).y-(*one).y)) <= ((*two).r+(*one).r)*((*one).r+(*two).r))
            {
            (*one).vx = -(*one).vx;
            (*one).vy = - (*one).vy;
            (*two).vx = -(*two).vx;
            (*two).vy = -(*two).vy;
            }

 }
int main()
{
    txCreateWindow(800, 600);

    ball *Example = new ball [50];

        for (int i = 0; i < 15; i++)
    {
        for(int j = 1; j < 20; j++)
        {
            Example[i*2+j].x = (j + 1) * 40;
            Example[i*2+j].y = (i + 1) * 30;
            Example[i*2+j].RED = 255;
            Example[i*2+j].GREEN = 0;
            Example[i*2+j].BLUE = 0;
            Example[i*2+j].r = 10;
            Example[i*2+j].vx = 100;
            Example[i*2+j].vy = 100;
        }
    }

    for ( ; ; )
    {
    txBegin();

       for(int i = 0; i < 50; i++)
        {

            drawBall(Example[i]);
            moveBall(&Example[i]);
            controllBall(&Example[i]);
            txSetFillColor(RGB(0,0,0));
    txEnd();
            for(int j = 0; j < 50; j++)
            {
                collideBall(&Example[i], &Example[j]);
            }
        }
        txSleep(dt);

        }
    delete [] Example;

return 0;
}
