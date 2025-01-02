Target = main
SourceFiles = $(wildcard src/*.s src/*.c)

Cl65 = /sdk/cc65/bin/cl65
Cl65Flags = --verbose -O #--ld-args --mapfile,mapping.txt     # Used for debugging

all: $(Target)

${Target}: $(SourceFiles)
	mkdir -p bin
	$(Cl65) $(Cl65Flags) --target none --cpu 65C02 --config w65c02.cfg -I src/ -o bin/$(Target).bin $(SourceFiles)

clean:
	rm -rf bin