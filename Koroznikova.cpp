#include "TXLib.h"

const float dt = 0.1;
struct ball
   {
        float x;
        float y;
        float r;
        float RED;
        float GREEN;
        float BLUE;
        float vx;
        float vy;

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

    ball one;
    one.x = 400;
    one.y = 300;
    one.r = 100;
    one.RED = 255;
    one.GREEN = 0;
    one.BLUE = 0;
    one.vx = 100;
    one.vy = 100;

    ball two = { 200, 200, 50, 0, 255, 0, 100, 200};

    for ( ; ; )
    {
        txClear();
        drawBall(one);
        drawBall(two);
        moveBall(&one);
        moveBall(&two);
        controllBall(&one);
        controllBall(&two);
        collideBall(&one, &two);
        txSleep(dt);
           }

return 0;
}
