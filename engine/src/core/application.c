#include "application.h"
#include "platform/platform.h"
#include "logger.h"
#include "game_types.h"
#include "core/density_memory.h"

typedef struct application_state
{
    game *game_inst;
    b8 is_running;
    b8 is_suspended;
    platform_state platform;
    i16 width;
    i16 height;
    f64 last_time;
} application_state;

static b8 initialized = FALSE;
static application_state state;

b8 application_create(game *game_inst)
{
    if (initialized)
    {
        D_ERROR("application_create called more than once");
        return FALSE;
    }

    state.game_inst = game_inst;

    // initialize_logging();

    D_FATAL("Test message");
    D_ERROR("Test Message");
    D_WARN("Test message");
    D_INFO("Test Message");
    D_DEBUG("Test message");
    D_TRACE("Test Message");

    state.is_running = TRUE;
    state.is_suspended = FALSE;

    if (!platform_startup(
            &state.platform,
            game_inst->config.name,
            game_inst->config.start_pos_x,
            game_inst->config.start_pos_y,
            game_inst->config.start_width,
            game_inst->config.start_height))
    {
        return FALSE;
    }

    if (!state.game_inst->initialized(state.game_inst))
    {
        D_FATAL("Game initialization failed.");
        return FALSE;
    }

    state.game_inst->on_resize(state.game_inst, state.width, state.height);

    initialized = TRUE;
    return TRUE;
}

b8 application_run()
{
    D_INFO(get_memory_usage_str());

    while (state.is_running)
    {
        if (!platform_pump_messages(&state.platform))
        {
            state.is_running = FALSE;
        }

        if (!state.is_suspended)
        {
            if (!state.game_inst->update(state.game_inst, (f32)0))
            {
                D_FATAL("Game update failed.");
                state.is_running = FALSE;
                break;
            }

            if (!state.game_inst->render(state.game_inst, (f32)0))
            {
                D_FATAL("Game render failed.");
                state.is_running = FALSE;
                break;
            }
        }
    }

    state.is_running = FALSE;
    platform_shutdown(&state.platform);

    return TRUE;
}