#include "bullet.h"
bullet::bullet()
{
	alive = false;;
	srand(time(0));
}
bool bullet::getStatus()
{
	return alive;
}

void bullet::fire()
{
	x=rand()%615+10;
	y = 10;
	alive=true;

}
void bullet::erase_bullet()
{
	al_draw_filled_rectangle(x,y,x+5,y+5,al_map_rgb(0,0,0)); //black color
}
int bullet::move_bullet (int arrowX, int arrowY, int width, int length, int height)
{
	y++;
	// draw bullet bitmap
	al_draw_bitmap(bullet_bmp, x, y, 0);


	if (x + 16 > arrowX &&
		x < arrowX + width &&
		y + 16 > arrowY &&
		y < arrowY + length) {
		al_draw_filled_rectangle(x, y, x + 16, y + 16, al_map_rgb(0, 0, 0));
		alive=false;
		return 1;
	}
	if (y> height)
		alive = false;
	return 0;


} 

// create bullet sprite
void bullet::create_bullet_bitmap(ALLEGRO_DISPLAY* display)
{
	bullet_bmp = al_create_bitmap(16, 16);

	al_set_target_bitmap(bullet_bmp);

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_circle(8, 8, 6, al_map_rgb(255, 255, 0));

	al_draw_filled_rectangle(6, 2, 10, 14, al_map_rgb(255, 0, 0));

	al_set_target_backbuffer(display);
}


