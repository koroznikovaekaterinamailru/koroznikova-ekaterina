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
void moveBall(float* x, float* y, float* vx, float* vy)
{
        *x += *vx * dt;
        *y += *vy * dt;
        if (*y > 500 || *y < 100)
            *vy = -*vy;
        if (*x > 700 || *x < 100)
            *vx = -*vx;
}
void collideBall(float* x1, float* y1, float* r1, float* x2, float* y2, float* r2, float* vx1, float* vy1, float* vx2, float* vy2)
{
        if (((*x2-*x1)*(*x2-*x1) + (*y2-*y1)*(*y2-*y1)) <= (*r2+*r1)*(*r1+*r2))
            *vx1 = -*vx1;
            *vy1 = -*vy1;
            *vx2 = -*vx2;
            *vy2 = -*vy2;

 }
int main()
{
    txCreateWindow(800, 600);
    float x1 = 400;
    float y1 = 300;
    float vx1 = 100;
    float vy1 = 100;
    float x2 = 200;
    float y2 = 200;
    float vx2 = 20;
    float vy2 = 20;
    float r1 = 100;
    float r2 = 50;
    for ( ; ; )
    {
        txClear();
        drawBall(x1, y1, 100, 255, 0, 0);
        drawBall(x2, y2, 50, 0, 255, 0);
        moveBall(&x1, &y1, &vx1, &vy1);
        moveBall(&x2, &y2, &vx2, &vy2);
        collideBall(&x1, &y1, &r1, &x2, &y2, &r2, &vx1, &vy1, &vx2, &vy2);
        txSleep(dt);
    }

return 0;
}
