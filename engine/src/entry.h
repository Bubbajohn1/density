#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "core/density_memory.h"
#include "game_types.h"

extern b8 create_game(game *out_game);

// main entry point
int main(void)
{
    initialize_logging();
    initialize_memory();

    game game_inst;
    if (!create_game(&game_inst))
    {
        D_FATAL("Could not create game.");
        return -1;
    }

    if (!game_inst.render || !game_inst.update || !game_inst.initialized || !game_inst.on_resize)
    {
        D_FATAL("Game functions must be defined.");
        return -2;
    }

    if (!application_create(&game_inst))
    {
        D_INFO("Application failed to create.");
        return 1;
    }

    if (!application_run())
    {
        D_INFO("Application didnt shutdown right.");
        return 2;
    }

    shutdown_memory();

    return 0;
}
