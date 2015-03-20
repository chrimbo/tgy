# This Makefile is compatible with both BSD and GNU make

ASM?= avra
SHELL = /bin/bash

.SUFFIXES: .inc .hex

ALL_TARGETS = afro.hex afro2.hex afro_hv.hex afro_nfet.hex arctictiger.hex birdie70a.hex bs_nfet.hex bs.hex bs40a.hex dlu40a.hex dlux.hex dys_nfet.hex hk200a.hex hm135a.hex kda.hex kda_8khz.hex kda_nfet.hex mkblctrl1.hex rb50a.hex rb70a.hex rct50a.hex tbs.hex tbs_hv.hex tp.hex tp_8khz.hex tp_i2c.hex tp_nfet.hex tp70a.hex tgy6a.hex tgy.hex
AUX_TARGETS = diy0.hex

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
