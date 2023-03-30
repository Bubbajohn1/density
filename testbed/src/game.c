#include <core/logger.h>
#include "game.h"

b8 game_initialized(struct game *game_inst)
{
    D_DEBUG("game was initialized. (game_initialized called)")
    return TRUE;
}

b8 game_update(struct game *game_inst, f32 delta_time)
{
    return TRUE;
}

b8 game_render(struct game *game_inst, f32 delta_time)
{
    return TRUE;
}

void game_on_resize(struct game *game_inst, u32 width, u32 height)
{
}