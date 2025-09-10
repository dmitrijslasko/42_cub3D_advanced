#include "cub3d.h"

unsigned long get_focused_window_id(void) 
{
	FILE *fp;
	char buffer[128];
	unsigned long window_id = 0;

	fp = popen("xdotool getwindowfocus", "r");
	if (fp == NULL) {
		perror("popen failed");
		return 0;
	}

	if (fgets(buffer, sizeof(buffer), fp) != NULL) {
		window_id = strtoul(buffer, NULL, 10);
	} else {
		fprintf(stderr, "Failed to read window ID\n");
	}

	pclose(fp);
	return window_id;
}