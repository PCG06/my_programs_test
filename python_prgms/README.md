# Python Development Environment Setup

## How to Install Python

### For Windows

#### 1. Install Python on Windows

1. **Download Python Installer**:
   - Visit the official Python website: [python.org/downloads](https://www.python.org/downloads/)
   - Download the latest stable version for Windows

2. **Run the Installer**:
   - Double-click the downloaded executable
   - **Important**: Check the box that says **"Add Python to PATH"**
   - Click "Install Now"

3. **Verify Installation**:
   - Open Command Prompt and run:
     ```cmd
     python --version
     ```
   - You should see the installed Python version

---

### For WSL (Windows Subsystem for Linux)

#### 1. Install Python on WSL

1. **Update Package List**:
   ```bash
   sudo apt update
   ```

2. **Install Python**:
   ```bash
   sudo apt install python3 python3-pip
   ```

3. **Verify Installation**:
   - Check Python version:
     ```bash
     python3 --version
     ```
   - Check pip version:
     ```bash
     pip3 --version
     ```

---

# How to Work With Python Programs

This project includes a Makefile to help manage Python bytecode compilation and project cleanup.

## Steps to Compile Python Files

1. **Navigate to Project Directory**:
   - Open a terminal in the directory containing the Makefile

2. **Run the Make Command**:
   ```bash
   make
   ```
   - This will:
     - Compile all `.py` files in `src/` to bytecode (`.pyc`)
     - Store compiled files in `src/__pycache__/`
     - Print: "All Python scripts are compiled!"

## Steps to Run Python Programs

1. **Run Directly** (no compilation needed):
   ```bash
   python3 src/your_script.py
   ```

2. **Run After Compilation**:
   - Bytecode files are used automatically by Python interpreter

## Clean the Project

1. **Clean Bytecode Files**:
   ```bash
   make clean
   ```
   - Removes the `src/__pycache__/` directory
   - Prints: "Pycache has been cleaned!"

2. **Clean and Recompile**:
   ```bash
   make cleanbuild
   ```
   - Runs `make clean` followed by `make`

## **Summary of Commands**

| Command          | Action                                  |
|------------------|----------------------------------------|
| `make`           | Compiles all Python files to bytecode  |
| `make clean`     | Deletes all bytecode cache files       |
| `make cleanbuild`| Cleans and recompiles all files        |
| `python3 src/file.py` | Runs a Python script directly        |

---
