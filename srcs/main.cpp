#include "pl.hpp"
#include "GameEngine.hpp"
#include "Map.hpp"
#include "GameRenderer.hpp"
#include "Entity.hpp"
#include "Player.hpp"

typedef struct timeval timeval_t;

static int timeDiff(timeval_t t0, timeval_t t1) {
    return (t1.tv_usec - t0.tv_usec) + (t1.tv_sec - t0.tv_sec) * MICRO_SEC;
}

void        gameLoop()
{
    /* Init Game loop */
    GameEngine          game;
    GameRenderer        win{WIN_WIDTH, WIN_HEIGHT};
    Map                 map{20, 20};
    timeval_t           t0, t1, tstart;

    gettimeofday(&tstart, 0);
    t0 = tstart;

    // Entity      *entity;
    // entity = game.createEntity();

    Player      *player;
    player = game.createPlayer();

    /* Start the game loop */
    while (!game.quit)
    {
        gettimeofday(&t1, 0);
        if (timeDiff(t0, t1) >= (MICRO_SEC / FPS))
        {
            win.clear();
            win.eventManager();
            win.renderMap(map);
            game.update(map);
            win.draw(*player);
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