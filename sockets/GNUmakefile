
default: daytime byteorder

daytime:
	cc -o daytime daytime.c

byteorder:
	cc -o byteorder byteorder.c

.PHONY: clean
clean: nuke
.PHONY: nuke
nuke:
	rm -f daytime
	rm -f byteorder

