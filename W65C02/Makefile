include tools.mk

ROM_NAME   := main
LINKER_CFG := 65C02.cfg
LIBRARIES  := none.lib

SOURCE_FOLDER := src
BUILD_FOLDER  := bin
TEMP_FOLDER   := obj

SOURCE_FILES  := $(wildcard $(SOURCE_FOLDER)/*.s $(SOURCE_FOLDER)/*.c)
OBJECTS       := $(patsubst $(SOURCE_FOLDER)/%.c,$(TEMP_FOLDER)/%.o, $(patsubst $(SOURCE_FOLDER)/%.s,$(TEMP_FOLDER)/%.o,$(SOURCE_FILES)))     # Searches for all source files and convert their format from {src}/%.c into {obj}/%.o

ROM_FILE := $(BUILD_FOLDER)/$(ROM_NAME).bin
MAP_FILE := $(TEMP_FOLDER)/$(ROM_NAME).map

all: $(ROM_FILE)

# Link compiled sources into a single program
$(ROM_FILE): $(OBJECTS) $(LINKER_CFG)
	@$(MKDIR_BINARY) $(MKDIR_FLAGS) $(BUILD_FOLDER)
	$(LD65_BINARY) $(LD65_FLAGS) -C $(LINKER_CFG) -m $(MAP_FILE) -o $@ $(OBJECTS) $(LIBRARIES)

# Compile C and assmebly files
$(OBJECTS): $(SOURCE_FILES)
	@$(MKDIR_BINARY) $(MKDIR_FLAGS) $(TEMP_FOLDER)
	$(CL65_BINARY) $(CL65_FLAGS) $^
	@$(MV_BINARY) $(MV_FLAGS) $(SOURCE_FOLDER)/*.o $(TEMP_FOLDER)

clean:
	$(RM_BINARY) $(RM_FLAGS) $(BUILD_FOLDER) $(TEMP_FOLDER)