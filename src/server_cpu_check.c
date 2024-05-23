#include <stdio.h>
#include <string.h>
#include "server_cpu_check.h"

void extract_cpu_info(
    const char *buffer, 
    char *model_name, 
    double *cpu_mhz, 
    int *cache_size
) {
    if (strncmp(buffer, "model name", 10) == 0) {
        sscanf(buffer, "model name : %[^\n]", model_name);
    } else if (strncmp(buffer, "cpu MHz", 7) == 0) {
        sscanf(buffer, "cpu MHz : %lf", cpu_mhz);
    } else if (strncmp(buffer, "cache size", 10) == 0) {
        sscanf(buffer, "cache size : %d", cache_size);
    }
}

void print_cpu_info(
    const char *model_name, 
    int core_count, 
    double cpu_mhz, 
    int cache_size
) {
    printf(
        "CPU Information:\n"
        "Model: %s\n"
        "Number of Cores: %d\n"
        "Clock Speed: %.3f MHz\n"
        "Cache Size: %d KB\n",
        model_name, core_count, cpu_mhz, cache_size
    );
}
