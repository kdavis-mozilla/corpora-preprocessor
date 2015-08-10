DIRS=src


all: $(DIRS)

clean: $(DIRS)

$(DIRS):
	$(MAKE) -C "$@" $(MAKEFLAGS) $(MAKECMDGOALS)

.PHONY: all clean $(DIRS)
