#include <graphics.h> ;
#include <stdlib.h>;
#include <stdio.h>;
#include <conio.h>;
#include <dos.h>;
#include <iostream.h>;

int crewmate(int x, int y, int size, int color)
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    // body
    rectangle((x - size), (y + size), (x + size), (y - size));
    floodfill((x + size - 2), y, color);
    // head
    arc(x, (y - size), 0, 180, size);
    floodfill((x + size - 2), (y - size - 2), color);
    // legs
    rectangle((x - size), (y + size), (x - size / 5), (y + size * 7 / 4));
    rectangle((x + size), (y + size), (x + size / 5), (y + size * 7 / 4));
    floodfill((x + size - 2), (y + size + 2), color);
    floodfill((x - size + 2), (y + size + 2), color);
    // bagpack
    rectangle((x - size * 3 / 2), (y - size + 5), (x - size), (y + size));
    floodfill((x - size * 3 / 2 + 2), (y - size + 7), color);
    // border
    setcolor(0);
    rectangle((x - size * 3 / 2 - 1), (y - size + 4), (x - size - 2), (y + size + 1));
    rectangle((x - size * 3 / 2 - 2), (y - size + 3), (x - size - 1), (y + size + 2));
    arc(x, (y - size), 0, 180, size + 1);
    arc(x, (y - size), 0, 180, size + 2);
    line((x - size - 1), (y - size), (x - size - 1), (y + size * 7 / 4));
    line((x - size - 2), (y - size), (x - size - 2), (y + size * 7 / 4));
    line((x + size + 1), (y - size), (x + size + 1), (y + size * 7 / 4));
    line((x + size + 2), (y - size), (x + size + 2), (y + size * 7 / 4));
    line((x - size - 1), (y + size * 7 / 4), (x - size / 5 + 1), (y + size * 7 / 4));
    line((x - size - 2), (y + size * 7 / 4 + 1), (x - size / 5 + 2), (y + size * 7 / 4 + 1));
    line((x + size + 1), (y + size * 7 / 4), (x + size / 5 - 1), (y + size * 7 / 4));
    line((x + size + 2), (y + size * 7 / 4 + 1), (x + size / 5 - 2), (y + size * 7 / 4 + 1));
    line((x - size / 5 + 1), (y + size), (x - size / 5 + 1), (y + size * 7 / 4));
    line((x - size / 5 + 2), (y + size), (x - size / 5 + 2), (y + size * 7 / 4));
    line((x + size / 5 - 1), (y + size), (x + size / 5 - 1), (y + size * 7 / 4));

    line((x + size / 5 - 2), (y + size), (x + size / 5 - 2), (y + size * 7 / 4));
    line((x - size / 5), (y + size + 1), (x + size / 5), (y + size + 1));
    line((x - size / 5), (y + size + 2), (x + size / 5), (y + size + 2));
    // mask
    setcolor(3);
    rectangle((x - size / 3), (y - size / 2), (x + size * 6 / 5), (y - size * 5 / 4));
    setfillstyle(SOLID_FILL, 3);
    floodfill((x + size * 6 / 5 - 5), (y - size / 2 - 2), 3);
    setcolor(0);
    rectangle((x - size / 3 - 1), (y - size / 2 + 1), (x + size * 6 / 5 + 1), (y - size * 5 / 4 - 1));
    rectangle((x - size / 3 - 2), (y - size / 2 + 2), (x + size * 6 / 5 + 2), (y - size * 5 / 4 - 2));
    return 0;
}
int main(void)
{
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy;
    initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    int c = 0;
    do
    {
        // background
        setcolor(0);
        line(0, midy, (getmaxx() - 175), midy);
        line(0, midy + 1, (getmaxx() - 175), midy + 1);
        line((getmaxx() - 175), midy, getmaxx(), (midy + 200));
        line((getmaxx() - 175), (midy + 1), getmaxx(), (midy + 201));
        setcolor(7);
        line(0, midy - 1, (getmaxx() - 175), midy - 1);

        line((getmaxx() - 175), (midy - 1), getmaxx(), (midy + 199));
        setfillstyle(SOLID_FILL, 7);
        floodfill(midx, midy - 5, 7);
        setcolor(0);
        line((getmaxx() - 175), 0, (getmaxx() - 175), midy);
        line((getmaxx() - 176), 0, (getmaxx() - 176), midy);
        setcolor(8);
        line(0, (midy + 2), (getmaxx() - 175), (midy + 2));
        line((getmaxx() - 175), (midy + 2), getmaxx(), (midy + 202));
        setfillstyle(SOLID_FILL, 8);
        floodfill(midx, midy + 5, 8);
        setcolor(0);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(9, HORIZ_DIR, 3);
        outtextxy(midx - 100, midy - 150, "AMONG US");
        // background ends
        int impx, impy, crwx, crwy;
        for (impx = 0, impy = (midy + 100); impx < (getmaxx() - 300); impx += 50)
        {
            crewmate((getmaxx() - 200), (midy + 60), 25, 14);
            crewmate(impx, impy, 25, 4);
            delay(300);
            setfillstyle(SOLID_FILL, 8);
            floodfill(impx, impy, 8);
        }
        crewmate(impx, impy, 25, 4);
        delay(300);
        int hammerx = impx, hammery = impy - 70;
        for (; hammerx <= getmaxx() - 200; hammerx += 35, hammery += 10)
        {
            circle(hammerx, hammery, 15);
            setfillstyle(SOLID_FILL, 0);
            floodfill(hammerx, hammery, 0);
            delay(300);
            setfillstyle(SOLID_FILL, 8);
            floodfill(hammerx, hammery, 8);
        }
        // setfillstyle(SOLID_FILL, 8);

        // floodfill(getmaxx()-200,midy+60, 8);
        setcolor(14);
        ellipse((getmaxx() - 200), (midy + 80), 0, 360, 40, 20);
        setfillstyle(SOLID_FILL, 14);
        floodfill((getmaxx() - 200), (midy + 80), 14);
        delay(300);
        setfillstyle(SOLID_FILL, 8);
        floodfill(impx, impy, 8);
        for (crwx = 0, crwy = midy + 80; impx < getmaxx(); impx += 35, impy += 40)
        {
            crewmate(crwx, crwy, 25, 2);
            setcolor(14);
            ellipse((getmaxx() - 200), (midy + 80), 0, 360, 40, 20);
            setfillstyle(SOLID_FILL, 14);
            floodfill((getmaxx() - 200), (midy + 80), 14);
            crewmate(impx, impy, 25, 4);
            delay(300);
            setfillstyle(SOLID_FILL, 8);
            floodfill(impx, impy, 8);
            setfillstyle(SOLID_FILL, 8);
            floodfill(crwx, crwy, 8);
            if (impy < (midy + 180))
            {
                crwx += 40;
            }
            else
            {
                crwx -= 40;
            }
        }
        clearviewport();
        delay(400);
        setfillstyle(SOLID_FILL, 0);
        floodfill(midx, (midy), 0);
        setcolor(15);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(2, HORIZ_DIR, 10);
        outtextxy(midx, midy, "RED");
        delay(400);

        clearviewport();
        setfillstyle(SOLID_FILL, 0);
        floodfill(midx, (midy), 0);
        setcolor(15);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(midx, midy, "RED WAS");
        delay(400);
        clearviewport();
        setfillstyle(SOLID_FILL, 0);
        floodfill(midx, (midy), 0);
        setcolor(15);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(midx, midy, "RED WAS THE");
        delay(400);
        clearviewport();
        setfillstyle(SOLID_FILL, 0);
        floodfill(midx, (midy), 0);
        setcolor(15);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(midx, midy, "RED WAS THE IMPOSTER !");
        delay(400);
        c++;
    } while (c < 3);
    getch();
    closegraph();
    return 0;
}