#include "cub3d.h"

int update_current_level_pointers(t_data *dt)
{
    dt->map = &get_curr_level(dt)->map;

    dt->sprites = get_curr_level(dt)->sprites;
    dt->sprite_count = get_curr_level(dt)->sprite_count;

    dt->sprite_textures = get_curr_level(dt)->sprite_textures;
    dt->sprite_texture_count = get_curr_level(dt)->sprite_texture_count;

    dt->doors = get_curr_level(dt)->doors;
    dt->door_count = get_curr_level(dt)->door_count;

    dt->ambient_light = &get_curr_level(dt)->ambient_light;

    return (EXIT_SUCCESS);
}