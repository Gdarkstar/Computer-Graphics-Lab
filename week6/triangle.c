#include <graphics.h>
 #include<stdio.h>
#include <math.h> 
#define bresen line

void bresengham(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
    dx=x1-x0;
    dy=y1-y0;
 
    x=x0;
    y=y0;
 
    p=2*dy-dx;
 
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,7);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,7);
            p=p+2*dy;
        }
        x=x+1;
    }
}
int main()
{ 
   int gd = DETECT, gm;
   int x = 1000, y = 1000, radius;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
bresen(10,10,40,10);
 // drawline(20,20,500,500);
bresen(40,10,40,40);
//bresengham(20,20,25,70);
bresen(10,10,40,40);



//rectangle 
bresen(50,50,50,80);
 // drawline(20,20,500,500);
bresen(50,80,80,80);
//bresengham(20,20,25,70);
bresen(80,80,80,50);
bresen(50,50,80,50);

int d;
 scanf("%d",&d);
   getch();
   closegraph();
   return 0;
}
