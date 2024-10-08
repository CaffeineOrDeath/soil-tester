#include "arduino/log.h"

uint8_t init_log(void){
    // TODO: config log system
    // for now, using stdio
    puts("Logging Enabled!");
    return 0;
}

void dlog(const char *msg){
    puts(msg);
}

void dlog_wrap(const char *fmt, ...){
    char* string;
    va_list args;

    va_start(args, fmt);
    if (0 > vasprint(&srting, fmt, args)) string = NULL;
    va_end(args);

    if(string){
        dlog(string);
        free(string);
    } else {
        dlog("Error while logging: malloc failed!\n");
    }
}

void log_file(FILE *f, const char *msg){
    // TODO: implement file system
}

uint8_t close_log(void){
    // TODO: close log
    puts("Logging Disabled!");
    return 0;
}
