#include "cub3d.h"

int	mimic_fullscreen(void)
{
	printf("Entering fullscreen mode (if set so)...\n");
	if (MIMIC_FULLSCREEN)
	{
		system("gsettings set org.gnome.desktop.peripherals.mouse speed -1.0");
		if (LINUX_22)
			system("xdotool mousemove 960 540");
		system("gsettings set org.gnome.desktop.a11y.magnifier mag-factor 3.0");
		system("gnome-extensions disable ubuntu-dock@ubuntu.com");
		system("gsettings set org.gnome.desktop.a11y.magnifier mouse-tracking centered");
		move_active_window_to_mouse_position_with_xdotool();
		system("gsettings set org.gnome.desktop.a11y.applications screen-magnifier-enabled true");

		if (LINUX_22)
		{
			sleep(1);
			system("gsettings set org.gnome.desktop.a11y.magnifier mouse-tracking push");
		}
	}
}
