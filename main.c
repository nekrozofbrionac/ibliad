#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

/**
 * Returns -1 if opening of the file given in path failed.
 * Otherwise, ignores everything that is not a digit and converts
 * it to an unsigned int. (Or short in this case?)
 */
int read_uint_from_file(const char* path) {
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

int main() {
    const char *current_brightness_path 
        = "/sys/class/backlight/intel_backlight/brightness";
    const char *max_brightness_path 
        = "/sys/class/backlight/intel_backlight/max_brightness";

    const int current_brightness = read_uint_from_file(current_brightness_path);
    const int max_brightness = read_uint_from_file(max_brightness_path);

    printf("current brightness : %d\n", current_brightness);
    printf("max brightness     : %d\n", max_brightness);

    return 0;
}
