#ifndef LOG_H
#define LOG_H

#include <stdbool.h>
#include <stdio.h>

/**
 * @file
 * This is the logging system. It is required to keep track of any code
 * failure. This is not a typical debug system. This will log not only debug
 * code, but also write to a file for system validations. I.E. whether or not
 * solutions are running low or needing repair or replacement.
*/

/**
 * init_log
 *
 * Initalize the logging system. This will look for a file based on DATETIME to
 * ensure that the system does not overwrite data, allowing for checks whenever
 * desired, so long as there is enough memory.
*/
uint8_t init_log(void);

/**
 * custom print-style wrapper for dlog.
 */
void dlog_wrap(const char *fmt, ...) __attribute__ ((format (printf, 1 ,2)));


/**
 * Will be U[S]ART logging system for debugging. For now it is using stdio.
 *
 * @param const char **msg
 * The string to be logged.
*/
void dlog(const char *msg);

/**
 * Write data to a file.
 *
 * @param FILE *f
 * The file to write to. This will be picked up by the system as long as there
 * is still room in memory.
 *
 * @param const char **data
 * This is the data to saved.
*/
void log_file(FILE *f, const char *data);

/**
 * shut down the logging system
*/
uint8_t close_log(void);
#endif
