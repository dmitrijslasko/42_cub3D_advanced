/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:12:07 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/23 18:40:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sound.h"

int	debug_print(char *str)
{
	if (!DEBUG_PRINT)
		return (0);
	return (printf(str));
}

static int	setup_keyboard_and_mouse_controls(t_data *dt)
{
	setup_keyboard_hooks(dt);
	if (BONUS && ENABLE_MOUSE)
		setup_mouse_hooks(dt);
	return (EXIT_SUCCESS);
}

// unsigned long get_focused_window_id() {
// 	FILE *fp;
// 	char buffer[128];
// 	unsigned long window_id = 0;

// 	fp = popen("xdotool getwindowfocus", "r");
// 	if (fp == NULL) {
// 		perror("popen failed");
// 		return 0;
// 	}

// 	if (fgets(buffer, sizeof(buffer), fp) != NULL) {
// 		window_id = strtoul(buffer, NULL, 10);
// 	} else {
// 		fprintf(stderr, "Failed to read window ID\n");
// 	}

// 	pclose(fp);
// 	return window_id;
// }

int move_active_window_to_mouse_position_with_xdotool() {
	FILE *fp = popen("xdotool getmouselocation --shell", "r");
	if (!fp) {
		perror("Failed to run xdotool");
		return 1;
	}

	int x = -1;
	int y = -1;

	char line[128];
	while (fgets(line, sizeof(line), fp)) {
		if (sscanf(line, "X=%d", &x) == 1) continue;
		if (sscanf(line, "Y=%d", &y) == 1) continue;
	}
	pclose(fp);
	printf("X Y: %d %d\n", x, y);

	if (x < 0 || y < 0) {
		fprintf(stderr, "Could not get mouse coordinates\n");
		return 1;
	}

	// Get active window
	fp = popen("xdotool getactivewindow", "r");
	if (!fp) {
		perror("Failed to get active window");
		return 1;
	}

	char win_id[32];
	if (!fgets(win_id, sizeof(win_id), fp)) {
		fprintf(stderr, "Could not read window ID\n");
		pclose(fp);
		return 1;
	}
	pclose(fp);
	win_id[strcspn(win_id, "\n")] = 0;  // strip newline

	// Build and run move command
	char cmd[128];
	snprintf(cmd, sizeof(cmd), "xdotool windowmove %s %d %d", win_id, x - WINDOW_W/2, y - WINDOW_H/2 - 38);
	int result = system(cmd);
	return result == 0 ? 0 : 1;
}

int move_mouse_to_center_of_active_window(void) {
	Display *dpy = XOpenDisplay(NULL);
	if (!dpy) {
		fprintf(stderr, "Unable to open X display\n");
		return 1;
	}

	Window root = DefaultRootWindow(dpy);
	Atom activeAtom = XInternAtom(dpy, "_NET_ACTIVE_WINDOW", True);
	Atom actualType;
	int actualFormat;
	unsigned long nItems, bytesAfter;
	unsigned char *prop = NULL;

	if (XGetWindowProperty(dpy, root, activeAtom, 0, (~0L), False, AnyPropertyType,
						   &actualType, &actualFormat, &nItems, &bytesAfter, &prop) != Success || !prop) {
		fprintf(stderr, "Unable to get _NET_ACTIVE_WINDOW\n");
		XCloseDisplay(dpy);
		return 1;
	}

	Window activeWindow = *(Window *)prop;
	XFree(prop);

	XWindowAttributes attr;
	if (!XGetWindowAttributes(dpy, activeWindow, &attr)) {
		fprintf(stderr, "Failed to get window attributes\n");
		XCloseDisplay(dpy);
		return 1;
	}

	int x, y;
	Window child;
	XTranslateCoordinates(dpy, activeWindow, root, 0, 0, &x, &y, &child);

	int center_x = x + attr.width / 2;
	int center_y = y + attr.height / 2;

	XWarpPointer(dpy, None, root, 0, 0, 0, 0, center_x, center_y);
	XFlush(dpy);
	XCloseDisplay(dpy);
	return 0;
}

int	main(int argc, char **argv)
{
	t_data	dt;

	init_dt(&dt);
	// check and parse command line arguments
	// check_and_parse_args(&dt, argc, argv);

	char *game_levels[] = {	"./maps/good/01_level.cub",
							"./maps/good/02_level.cub",
							NULL};

	// check_and_parse_map(&dt, argc, game_levels[0]);
	// check_and_parse_args(&dt, argc, argv);
	check_and_parse_all_maps(&dt, argc, game_levels);

	// precalculate sin and cos lookup tables
	precalculate_trig_tables(&dt);

	// setup minilibx stuff
	if (setup_mlx_and_win(&dt))
		return (MLX_ERROR);
		
	// mimic full screen for immersive gameplay
	system("gsettings set org.gnome.desktop.a11y.applications screen-magnifier-enabled false");
	mimic_fullscreen();

	move_mouse_to_center_of_active_window();

	setup_keyboard_and_mouse_controls(&dt);

	// setup dt - sets up the whole game structure and data
	dt.game_status = WELCOME_SCREEN;
	dt.active_level = 0;
	dt.map = &dt.maps[dt.active_level];

	setup_dt(&dt);

	set_sprite_textures(&dt);

	draw_minimap_base_img(&dt);

	print_separator(3, DEF_SEPARATOR_CHAR);

	printf("🎮 Starting game!\n");
	printf("Consumables to collect in this level: %d\n", dt.levels[dt.active_level].level_consumable_count);
	
	dt.player.pos.x = 1.5;
	dt.player.pos.y = 1.5;
	
	mlx_loop_hook(dt.mlx_ptr, &render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}

