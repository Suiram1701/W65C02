Target = main
SourceFiles = $(wildcard src/*.s src/*.c)

all: $(Target)

${Target}: $(SourceFiles)
	mkdir -p bin
	/sdk/cc65/bin/cl65 --verbose --target none --cpu 65C02 --config w65c02.cfg -I src/ -o bin/$(Target).bin $(SourceFiles)

clean:
	rm -rf bin