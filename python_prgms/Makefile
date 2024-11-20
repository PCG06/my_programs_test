# Directories for source files and build outputs
SRC_DIR = src

# Python interpreter and other flags
PYTHON = python3

# Automatically find all .py files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.py)
OBJECTS = $(patsubst $(SRC_DIR)/%.py,$(SRC_DIR)/__pycache__/%.cpython-%.pyc,$(SOURCES))

# Default target
all: $(OBJECTS)
	@echo "All Python scripts are compiled!"

# Rule for compiling .py files into .pyc files in the __pycache__ folder
$(SRC_DIR)/__pycache__/%.cpython-%.pyc: $(SRC_DIR)/%.py
	$(PYTHON) -m py_compile $<

# Clean up generated files
clean:
	rm -rf $(SRC_DIR)/__pycache__
	@echo "Pycache has been cleaned!"

# Clean up generated files and rebuild all
cleanbuild: clean all

.PHONY: all clean
