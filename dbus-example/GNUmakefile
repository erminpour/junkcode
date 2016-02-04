##
## GNUmakefile
## @author = Victor Hugo Erminpour

## List of pkg-config packages
pkgcfg_packages := dbus-1

## Get pkg-config flags
PKGCFG_CFLAGS  := $(shell pkg-config --cflags $(pkgcfg_packages))
PKGCFG_LDFLAGS := $(shell pkg-config --libs $(pkgcfg_packages))

## Additional flags
ADD_CFLAGS := -g -Wall common.c

## Combine flags
CFLAGS  := $(PKGCFG_CFLAGS) $(CFLAGS) $(ADD_CFLAGS)
LDFLAGS := $(PKGCFG_LDFLAGS) $(LDFLAGS)

targets =  dbus-client \
		   dbus-server

.PHONY: all nuke
all: $(targets)

dbus-client: dbus-client.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

dbus-server: dbus-server.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

nuke:
	$(RM) $(targets)

