#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int load_map(t_map *map, const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error\nFailed to open map file");
        return 0;
    }

    char buffer[1024];
    int row = 0;
    map->collectibles = 0;

    while (read(fd, buffer, 1024) > 0) {
        int len = strlen(buffer);

        // Remove trailing newline
        if (buffer[len - 1] == '\n') buffer[--len] = '\0';

        if (len > MAP_WIDTH || row >= MAP_HEIGHT) {
            printf("Error\nMap dimensions exceed allowed size.\n");
            close(fd);
            return 0;
        }

        for (int col = 0; col < len; col++) {
            map->data[row][col] = buffer[col];

            if (buffer[col] == 'P') {
                map->player_x = col;
                map->player_y = row;
            }
            if (buffer[col] == 'C') {
                map->collectibles++;
            }
        }
        row++;
    }

    map->width = strlen(map->data[0]);
    map->height = row;

    close(fd);
    return validate_map(map);
}

int validate_map(t_map *map) {
    if (!check_surrounded_by_walls(map)) {
        printf("Error\nMap is not surrounded by walls.\n");
        return 0;
    }

    if (!validate_components(map)) {
        printf("Error\nInvalid map components.\n");
        return 0;
    }

    if (!check_valid_path(map)) {
        printf("Error\nNo valid path exists from player to exit/collectibles.\n");
        return 0;
    }

    return 1;
}

int check_surrounded_by_walls(t_map *map) {
    for (int i = 0; i < map->width; i++) {
        if (map->data[0][i] != '1' || map->data[map->height - 1][i] != '1')
            return 0;
    }

    for (int j = 0; j < map->height; j++) {
        if (map->data[j][0] != '1' || map->data[j][map->width - 1] != '1')
            return 0;
    }

    return 1;
}

int validate_components(t_map *map) {
    int player_count = 0;
    int exit_count = 0;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            char cell = map->data[i][j];
            if (cell == 'P') player_count++;
            if (cell == 'E') exit_count++;

            if (cell != '0' && cell != '1' && cell != 'C' && cell != 'E' && cell != 'P') {
                return 0;
            }
        }
    }

    return (player_count == 1 && exit_count == 1);
}

int check_valid_path(t_map *map) {
    int visited[MAP_HEIGHT][MAP_WIDTH] = {0};
    int queue[MAP_HEIGHT * MAP_WIDTH][2];
    int front = 0, rear = 0;

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // Right, Down, Left, Up

    // Start from the player's initial position
    queue[rear][0] = map->player_x;
    queue[rear][1] = map->player_y;
    visited[map->player_y][map->player_x] = 1;
    rear++;

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        // Check if we reached the exit
        if (map->data[y][x] == 'E')
            return 1;

        // Explore the four possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            // Check boundaries and ensure it's not a wall ('1') or already visited
            if (nx >= 0 && nx < map->width && ny >= 0 && ny < map->height &&
                map->data[ny][nx] != '1' && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }

    return 0;  // No valid path found
}
