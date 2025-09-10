#include "cub3d.h"

int move_active_window_to_mouse_position_with_xdotool(void) 
{
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