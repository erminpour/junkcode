
/*
 * @file   common.c
 * @author Victor Hugo Erminpour
 * @brief  D-Bus common functions
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void exit_on_error(const char *msg, const DBusError *error)
{
    /* check error bit, print messages and exit */
    if (dbus_error_is_set(error))
    {
        fprintf(stderr, msg);
        fprintf(stderr, "DBusError->name: %s\n", error->name);
        fprintf(stderr, "DBusError->message: %s\n", error->message);
        exit(EXIT_FAILURE);
    }
}

