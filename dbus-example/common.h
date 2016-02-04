
/*
 * @file   common.h
 * @author Victor Hugo Erminpour
 * @brief  common header file
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#include <dbus/dbus.h>

#define DBUS_SERVER_NAME "test.dbus.server"
#define DBUS_CLIENT_NAME "test.dbus.client"
#define DBUS_OBJECT_PATH "/org/freedesktop/Calculator"
#define DBUS_IFACE_CALC  "org.freedesktop.Calculator"
#define DBUS_IFACE_INTRO "org.freedesktop.DBus.Introspectable"

void exit_on_error(const char *msg, const DBusError *error);

#endif /* __COMMON_H__ */

