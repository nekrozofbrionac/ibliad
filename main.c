#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

/**
 * Returns -1 if opening of the file given in path failed.
 * Otherwise, ignores everything that is not a digit and converts
 * it to an unsigned int. (Or short in this case?)
 */
int read_uint_from_file(const char *path) {
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        return -1;
    }

    int result = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c < '0' || c > '9') {
            continue;
        }
        result *= 10;
        result += (c - '0');
    }
    fclose(file);
    return result;
}

#define CURRENT_BRIGHTNESS_PATH "/sys/class/backlight/intel_backlight/brightness"
#define MAX_BRIGHTNESS_PATH "/sys/class/backlight/intel_backlight/max_brightness"
#define STEPS 20

int main(const int argc, const char *argv[]) {
    const int current_brightness = read_uint_from_file(CURRENT_BRIGHTNESS_PATH);
    if (current_brightness < 0) {
        return 1;
    }
    const int max_brightness = read_uint_from_file(MAX_BRIGHTNESS_PATH);
    if (max_brightness < 0) {
        return 1;
    }

    if (argc < 2) {
        printf("%d", current_brightness);
        return 0;
    }

    int step = max_brightness / STEPS;
    int output_value = current_brightness;
    for (size_t i = 1; i < argc; i++) {
        size_t j = 0;
        while(argv[i][j] != '\0') {
            if (argv[i][j] == '+') {
                output_value += step;
            } 
            if (argv[i][j] == '-') {
                output_value -= step;
            }
            j++;
        }
    }
    if (output_value > max_brightness) {
        output_value = max_brightness;
    }
    if (output_value < 0) {
        output_value = 0;
    }
    printf("%d", output_value);
    return 0;
}
