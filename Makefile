CXX = clang++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build
OUTPUT_DIR = output
TARGET = $(BUILD_DIR)/raytracer
OUTPUT = $(OUTPUT_DIR)/image.ppm

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

all: $(TARGET)

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

run: $(TARGET) | $(OUTPUT_DIR)
	./$(TARGET) > $(OUTPUT)
	@echo "Image rendered to $(OUTPUT)"

clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

.PHONY: all run clean
