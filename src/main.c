#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "server_cpu_check.h"

int main(int argc, char *argv[]) {
    const char *filename = "/proc/cpuinfo";
    FILE *cpuinfo;
    char buffer[BUFFER_SIZE];
    char model_name[BUFFER_SIZE] = "";
    double cpu_mhz = 0.0;
    int cache_size = 0;
    int core_count = 0;

    if (argc > 1) {
        filename = argv[1];
    }

    cpuinfo = fopen(filename, "r");
    if (cpuinfo == NULL) {
        fprintf(
            stderr, 
            "Error opening file '%s': %s\n", 
            filename, 
            strerror(errno)
        );
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, cpuinfo) != NULL) {
        extract_cpu_info(
            buffer, 
            model_name, 
            &cpu_mhz, 
            &cache_size
        );
        if (strncmp(buffer, "cache size", 10) == 0) {
            core_count++;
        }
    }

    if (ferror(cpuinfo)) {
        fprintf(
            stderr, 
            "Error reading file '%s': %s\n", 
            filename, 
            strerror(errno)
        );
        fclose(cpuinfo);
        exit(EXIT_FAILURE);
    }

    fclose(cpuinfo);

    print_cpu_info(
        model_name, 
        core_count, 
        cpu_mhz, 
        cache_size
    );

    return 0;
}