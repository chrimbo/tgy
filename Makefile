# This Makefile is compatible with both BSD and GNU make

ASM?= avra
SHELL = /bin/bash

.SUFFIXES: .inc .hex

ALL_TARGETS = cn.hex
AUX_TARGETS = 

all: $(ALL_TARGETS)

$(ALL_TARGETS): tgy.asm boot.inc
$(AUX_TARGETS): tgy.asm boot.inc

.inc.hex:
	@test -e $*.asm || ln -s tgy.asm $*.asm
	@echo "$(ASM) -fI -o $@ -D $*_esc -e $*.eeprom -d $*.obj $*.asm"
	@set -o pipefail; $(ASM) -fI -o $@ -D $*_esc -e $*.eeprom -d $*.obj $*.asm 2>&1 | grep -v 'PRAGMA directives currently ignored'
	@test -L $*.asm && rm -f $*.asm || true

test: all

clean:
	-rm -f $(ALL_TARGETS) *.obj *.eep.hex *.eeprom *.cof

binary_zip: $(ALL_TARGETS)
	TARGET="tgy_`date '+%Y-%m-%d'`_`git rev-parse --verify --short HEAD`"; \
	mkdir "$$TARGET" && \
	cp $(ALL_TARGETS) "$$TARGET" && \
	git archive -9 --prefix="$$TARGET/" -o "$$TARGET".zip HEAD && \
	zip -9 "$$TARGET".zip "$$TARGET"/*.hex && ls -l "$$TARGET".zip; \
	rm -f "$$TARGET"/*.hex; \
	rmdir "$$TARGET"
