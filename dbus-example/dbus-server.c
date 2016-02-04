
/*
 * @file   dbus-server.c
 * @author Victor Hugo Erminpour
 * @brief  low-level D-Bus server
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*
 * @function instrospect_callback
 * @param DBusConnection
 * @param DBusMessage
 */
void introspect_callback(DBusConnection *conn, DBusMessage *req)
{
    DBusMessage *reply;
    const char *xml_data =
        " <!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" "
        "\"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">"
        " <node>"
        "   <interface name=\"org.freedesktop.DBus.Introspectable\">"
        "     <method name=\"Introspect\">"
        "       <arg name=\"data\" direction=\"out\" type=\"s\" />"
        "     </method>"
        "   </interface>"
        "   <interface name=\"org.freedesktop.Calculator\">"
        "     <method name=\"Add\">"
        "       <arg name=\"arg1\" direction=\"in\" type=\"i\" />"
        "       <arg name=\"arg2\" direction=\"in\" type=\"i\" />"
        "       <arg name=\"retval\" direction=\"out\" type=\"i\" />"
        "     </method>"
        "     <method name=\"Sub\">"
        "       <arg name=\"arg1\" direction=\"in\" type=\"i\" />"
        "       <arg name=\"arg2\" direction=\"in\" type=\"i\" />"
        "       <arg name=\"retval\" direction=\"out\" type=\"i\" />"
        "     </method>"
        "   </interface>"
        " </node>";

    /* Create a message reply and append the xml data */     
    reply = dbus_message_new_method_return(req);
    dbus_message_append_args(reply, \
                             DBUS_TYPE_STRING, &xml_data, \
                             DBUS_TYPE_INVALID);

    /* Send message and flush the connection */
    dbus_connection_send(conn, reply, NULL);
    dbus_connection_flush(conn);

    /* Free reply message */
    dbus_message_unref(reply);
}

/*
 * @function add_callback
 * @param DBusConnection
 * @param DBusMessage
 */
void add_callback(DBusConnection *conn, DBusMessage *req)
{
    DBusMessage *reply;
    DBusError error;
    int arg1=0, arg2=0, retval=0;
 
    dbus_error_init(&error);
 
    dbus_message_get_args(req, &error,
                          DBUS_TYPE_INT32, &arg1, \
                          DBUS_TYPE_INT32, &arg2, \
                          DBUS_TYPE_INVALID);
    if (dbus_error_is_set(&error))
    {
        reply = dbus_message_new_error(req, "wrong_arguments", \
                                       "Incorrect arguments.");
        dbus_connection_send(conn, reply, NULL);
        dbus_connection_flush(conn);
        dbus_message_unref(reply);
        return;
    }
 
    retval = (arg1+arg2);
     
    reply = dbus_message_new_method_return(req);
    dbus_message_append_args(reply,DBUS_TYPE_INT32, &retval,
                             DBUS_TYPE_INVALID);
    dbus_connection_send(conn, reply, NULL);
    dbus_connection_flush(conn);

    dbus_message_unref(reply);
}

/*
 * @function sub_callback
 * @param DBusConnection
 * @param DBusMessage
 */
void sub_callback(DBusConnection *conn, DBusMessage *req)
{
    DBusMessage *reply;
    DBusError error;
    int arg1=0, arg2=0, retval=0;
 
    dbus_error_init(&error);
 
    dbus_message_get_args(req, &error, \
                          DBUS_TYPE_INT32, &arg1, \
                          DBUS_TYPE_INT32, &arg2, \
                          DBUS_TYPE_INVALID);
    if (dbus_error_is_set(&error))
    {
        reply = dbus_message_new_error(req, "wrong_arguments", \
                                       "Incorrect arguments.");
        dbus_connection_send(conn, reply, NULL);
        dbus_connection_flush(conn);
        dbus_message_unref(reply);
        return;
    }
 
    retval = (arg1-arg2);
     
    reply = dbus_message_new_method_return(req);
    dbus_message_append_args(reply,DBUS_TYPE_INT32, &retval,
                             DBUS_TYPE_INVALID);
    dbus_connection_send(conn, reply, NULL);
    dbus_connection_flush(conn);

    dbus_message_unref(reply);
}

/*
 * @function parse_messages
 * @param DBusConnection
 * @param DBusMessage
 * @param user_data
 */
DBusHandlerResult parse_messages(DBusConnection *conn, \
                                 DBusMessage *message, void *user_data)
{
    /* Get message interface and member_name */
    const char *interface_name = dbus_message_get_interface(message);
    const char *member_name = dbus_message_get_member(message);

    /* Parse message */
    if ((0==strcmp(DBUS_IFACE_INTRO, interface_name)) &&
        (0==strcmp("Introspect", member_name)))
    {
        introspect_callback(conn, message);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
    else if ((0==strcmp(DBUS_IFACE_CALC, interface_name)) &&
             (0==strcmp("Add", member_name)))
    {
        add_callback(conn, message);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
    else if ((0==strcmp(DBUS_IFACE_CALC, interface_name)) &&
             (0==strcmp("Sub", member_name)))
    {
        sub_callback(conn, message);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
    else
        return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

/* main() */
int main(int argc, char *argv[])
{
    DBusConnection *conn = NULL;
    DBusError error;
    DBusObjectPathVTable vtable;
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

    /* Request well-known name on the session bus */
    return_code = dbus_bus_request_name(conn, DBUS_SERVER_NAME, \
                                        DBUS_NAME_FLAG_REPLACE_EXISTING, \
                                        &error);
    exit_on_error("Failed to get well-known name.", &error);
    if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != return_code)
        exit(EXIT_FAILURE);

    /* Set object-path message functions */
    vtable.message_function = parse_messages;
    vtable.unregister_function = NULL;
    
    /* Register the Object path */ 
    dbus_connection_try_register_object_path(conn, \
                                             DBUS_OBJECT_PATH, \
                                             &vtable, \
                                             NULL, \
                                             &error);
    exit_on_error("Failed to register object path.\n", &error);

    /* mainloop */ 
    while(1)
        dbus_connection_read_write_dispatch(conn, 1000);

    /* Free the connection. */
    dbus_connection_unref(conn);
    conn = NULL;

return EXIT_SUCCESS;
}

