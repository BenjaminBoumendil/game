#include "pl.hpp"

typedef struct timeval timeval_t;

static int timeDiff(timeval_t t0, timeval_t t1) {
    return (t1.tv_usec - t0.tv_usec) + (t1.tv_sec - t0.tv_sec) * MICRO_SEC;
}

bool        createMap(Map & map)
{
    if (!map.floorTex.loadFromFile("img/asphalt_clean_big.jpg")) {
        std::cout << "Error loading texture" << std::endl;
        return false;
    }

    map.addFloor();
    return true;
}

void        gameLoop()
{
    /* Init Game loop */
    GameEngine          game;
    GameRenderer        win{WIN_WIDTH, WIN_HEIGHT};
    Map                 map{10, 10};
    timeval_t           t0, t1, tstart;

    gettimeofday(&tstart, 0);
    t0 = tstart;

    if (!createMap(map))
        return ;

    Entity      *entity;
    entity = game.createEntity();

    sf::Sprite      sp;

    /* Start the game loop */
    while (!game.quit)
    {
        gettimeofday(&t1, 0);
        if (timeDiff(t0, t1) >= (MICRO_SEC / FPS))
        {
            win.clear();
            win.eventManager();
            win.renderMap(map);
            win.draw(*entity);
            win.display();
            t0 = t1;
        }
    }
}

int     main(void)
{
    srand(time(NULL));

    gameLoop();

    return (0);
}