#include "TXLib.h"

const float dt = 0.1;
void drawBall(float x, float y, float r, float RED, float GREEN, float BLUE)
{
    for (int i = r; r > 0; r--)
    {
        txSetColor(RGB(RED - (RED*r/i), GREEN - (GREEN*r/i), BLUE - (BLUE*r/i)));
        txSetFillColor(RGB(RED - (RED*r/i), GREEN - (GREEN*r/i), BLUE - (BLUE*r/i)));
        txCircle(x, y, r);
        txSetFillColor(RGB(0,0,0));
    }

}

int main()
{
    txCreateWindow(800, 600);
    float x1 = 400;
    float y1 = 300;
    float vx1 = 5;
    float vy1 = 5;

    for ( ; ; )
    {
        txClear();
        drawBall(x1, y1, 100, 255, 0, 0);

        x1 += vx1 * dt;
        y1 += vy1 * dt;
        if (y1 > 500 || y1 < 100)
            vy1 = -vy1;
        if (x1 > 700 || x1 < 100)
            vx1 = -vx1;

        txSleep(dt);
    }

return 0;
}
