DIRS=src


all: $(DIRS)

preprocessed-text:
	bin/download_raw.sh
	bin/make_directories.sh
	bin/preprocess.sh

clean: $(DIRS)

$(DIRS):
	$(MAKE) -C "$@" $(MAKEFLAGS) $(MAKECMDGOALS)

.PHONY: all clean $(DIRS)
