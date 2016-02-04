
/*
 * @file   dbus-client.c
 * @author Victor Hugo Erminpour
 * @brief  low-level D-Bus client 
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/* main() */
int main(int argc, char *argv[])
{
    DBusConnection *conn = NULL;
    DBusMessage *msg_query = NULL;
    DBusMessage *msg_reply = NULL;
    DBusError error;

    const char *xml_data = NULL;
    int return_code;

    /* Initialize the error state. */
    dbus_error_init(&error);

    /* Connect to user-session D-Bus */
    fprintf(stdout, "Connecting to Session D-Bus\n");
    conn = dbus_bus_get(DBUS_BUS_SESSION, &error);
    exit_on_error("Failed to open user-session bus.\n", &error);

    /* Print unique name */
    fprintf(stdout, "D-Bus unique name: %s\n", \
                    dbus_bus_get_unique_name(conn));

    /* Request well-know name on the session bus */
    return_code = dbus_bus_request_name(conn, DBUS_CLIENT_NAME, \
                                        DBUS_NAME_FLAG_REPLACE_EXISTING, \
                                        &error);
    exit_on_error("Failed to get well-known name.", &error);
    if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != return_code)
        exit(EXIT_FAILURE);

    /* Send "Introspect" message */
    msg_query = dbus_message_new_method_call(DBUS_SERVER_NAME,  /* Target */
                                             DBUS_OBJECT_PATH,  /* Object */
                                             DBUS_IFACE_INTRO,  /* Interface */
                                             "Introspect");     /* Method name */
 
    msg_reply = dbus_connection_send_with_reply_and_block(conn, msg_query, 1000, &error);
    exit_on_error("Failed to send Introspect message.", &error);

    /* Get the string argument from Introspect call */
    dbus_message_get_args(msg_reply, &error, DBUS_TYPE_STRING, \
                          &xml_data, DBUS_TYPE_INVALID);

    /* Print message information */
    fprintf(stdout, "Object Path \t= %s\n", dbus_message_get_path(msg_query));
    fprintf(stdout, "Interface \t= %s\n", dbus_message_get_interface(msg_query));
    fprintf(stdout, "Message \t= %s\n", dbus_message_get_member(msg_query));
    fprintf(stdout, "Introspect xml_data:\n%s\n", xml_data);

    /* Free messages */
    dbus_message_unref(msg_query);
    dbus_message_unref(msg_reply);
    
    /* Free the connection. */
    dbus_connection_unref(conn);

return EXIT_SUCCESS;
}

