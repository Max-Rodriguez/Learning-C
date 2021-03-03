# ===============================
#
#    Run Assembler - Makefile
#
#   Run 'make all' with TARGET.
#
# ===============================

ASMBLR = \masm32\bin\ml
LINKER = \masm32\bin\Link

TARGET = WinHelloWorld

# ----- Run Assembler ----- #

all: assembler linker clean

assembler:
	$(ASMBLR) /c /Zd /coff $(TARGET).asm

linker:
	$(LINKER) /SUBSYSTEM:CONSOLE $(TARGET).obj

# ----- Clean Object Files ----- #

clean:
	del *.obj