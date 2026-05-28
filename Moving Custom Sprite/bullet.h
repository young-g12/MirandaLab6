#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <cstdlib>
#include <ctime>

class bullet
{
public:
    bullet();

    void create_bullet_bitmap(ALLEGRO_DISPLAY* display);
    void fire();
    int move_bullet(int arrowX, int arrowY, int width, int length, int height);
    void erase_bullet();
    bool getStatus();

private:
    int x, y;
    bool alive;
    ALLEGRO_BITMAP* bullet_bmp;
};

