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
void txMoveBall(float x, float y, float vx, float vy, float dt)
{
            x += vx*dt;
            y += vy*dt;
            if (x > 700 || x < 100)
            vx = -vx;
            if (y > 500 || y < 100)
            vy = -vy;
}

int main()
{
    txCreateWindow(800, 600);
    for ( ; ; )
    {
        txClear();
        drawBall(400, 300, 100, 255, 0, 0);
        txMoveBall(400, 300, 1, 1, dt);
    }

return 0;
}
