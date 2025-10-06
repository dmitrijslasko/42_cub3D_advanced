#!/bin/bash

# Hardcoded folder path
FOLDER="../maps/bad"

# Check if folder exists
if [ ! -d "$FOLDER" ]; then
	echo "Folder not found: $FOLDER"
	exit 1
fi

# Loop through each file (not directory) in the folder
for file in "$FOLDER"/*; do
	if [ -f "$file" ]; then
		echo "Running ./cub3d on $file"
		valgrind ./cub3D "$file"
	fi
	echo ""
done
