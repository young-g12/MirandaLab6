#include "arrow.h"

arrowClass::arrowClass()
{
    speed = 0;
    x = 100;
    y = 100;
    dir = 1;
    score = 0;

    for (int i = 0; i < 4; i++)
    {
        arrow_bmp[i] = NULL;
    }
}

arrowClass::~arrowClass()
{
    for (int i = 0; i < 4; i++)
    {
        al_destroy_bitmap(arrow_bmp[i]);
    }
}

void arrowClass::drawArrow()
{
    al_draw_bitmap(arrow_bmp[getDirection()], getX(), getY(), 0);
}

// draw UFO bitmap
void arrowClass::create_arrow_bitmap(ALLEGRO_DISPLAY* display)
{
    for (int i = 0; i < 4; i++)
    {
        arrow_bmp[i] = al_create_bitmap(64, 64);

        if (!arrow_bmp[i])
        {
            exit(1);
            al_destroy_display(display);
        }

        al_set_target_bitmap(arrow_bmp[i]);

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_filled_ellipse(
            32, 40,
            20, 10,
            al_map_rgb(255, 0, 255));

        al_draw_filled_circle(
            32, 28,
            10,
            al_map_rgb(0, 255, 255));

        // erase UFO bitmap area
        al_draw_filled_rectangle(
            28, 5,
            36, 20,
            al_map_rgb(150, 150, 150));

        al_draw_line(
            32, 5,
            32, 0,
            al_map_rgb(255, 255, 255),
            2);

        al_draw_filled_triangle(
            28, 5,
            36, 5,
            32, 0,
            al_map_rgb(255, 0, 0));
    }

    al_set_target_backbuffer(display);
}

void arrowClass::erase_arrow()
{
    int left = x;
    int top = y;
    int right = x + 64;
    int bottom = y + 64;

    al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0, 0, 0));
}

void arrowClass::up()
{
    dir = 0;
    speed++;

    if (speed > MAXSPEED)
        speed = MAXSPEED;
}

void arrowClass::down()
{
    dir = 2;
    speed++;

    if (speed > MAXSPEED)
        speed = MAXSPEED;
}

void arrowClass::left()
{
    dir = 3;
    speed++;

    if (speed > MAXSPEED)
        speed = MAXSPEED;
}

void arrowClass::right()
{
    dir = 1;
    speed++;

    if (speed > MAXSPEED)
        speed = MAXSPEED;
}

int arrowClass::getDirection()
{
    return dir;
}

int arrowClass::getSpeed()
{
    return speed;
}

int arrowClass::getX()
{
    return x;
}

// Gilberto Miranda
int arrowClass::getY()
{
    return y;
}

// keep UFO inside screen
void arrowClass::move_arrow(int width, int height)
{
    switch (dir)
    {
    case 0:
        y -= speed;
        break;

    case 1:
        x += speed;
        break;

    case 2:
        y += speed;
        break;

    case 3:
        x -= speed;
        break;
    }

    if (x > width - 64)
    {
        x = width - 64;
        speed = 0;
    }

    if (x < 0)
    {
        x = 0;
        speed = 0;
    }

    if (y > height - 64)
    {
        y = height - 64;
        speed = 0;
    }

    if (y < 0)
    {
        y = 0;
        speed = 0;
    }
}