#ifndef SERVER_CPU_CHECK_H
#define SERVER_CPU_CHECK_H

#define BUFFER_SIZE 1024

void extract_cpu_info(
    const char *buffer, 
    char *model_name, 
    double *cpu_mhz, 
    int *cache_size
);

void print_cpu_info(
    const char *model_name, 
    int core_count, 
    double cpu_mhz, 
    int cache_size
);

#endif