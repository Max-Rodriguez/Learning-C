# ===============================
#
#    Run Assembler - Makefile
#
#   Run 'make all' with TARGET.
#
# ===============================

TARGET = WinHelloWorld

# ----- Run Assembler ----- #

all: assembler linker clean

assembler:
	\masm32\bin\ml /c /Zd /coff $(TARGET).asm

linker:
	\masm32\bin\Link /SUBSYSTEM:CONSOLE $(TARGET).obj

# ----- Clean Object Files ----- #

clean:
	del *.obj