# Python Development Environment Setup

## Table of Contents

1. [How to Install Python](#how-to-install-python)

   * [For Windows](#for-windows)
   * [For Linux (and WSL)](#for-linux-and-wsl)
   * [For macOS](#for-macos)

2. [How to Work With Python Programs](#how-to-work-with-python-programs)

   * [Steps to Compile Python Files](#steps-to-compile-python-files)
   * [Steps to Run Python Programs](#steps-to-run-python-programs)
   * [Clean the Project](#clean-the-project)
   * [Summary of Commands](#summary-of-commands)

---

## How to Install Python

### For Windows

1. **Download Python Installer**:

   * Go to [python.org/downloads](https://www.python.org/downloads/)
   * Download the latest stable version for Windows

2. **Run the Installer**:

   * Double-click the downloaded `.exe`
   * **Important**: Check **"Add Python to PATH"**
   * Click **Install Now**

3. **Verify Installation**:

   ```cmd
   python --version
   ```

---

### For Linux (and WSL)

Check out WSL installation [here](../INSTALL_WSL.md).

#### 1. Install Python:
```bash
sudo apt update
sudo apt install python3 python3-pip
```

#### 2. Verify Installation:
```bash
python3 --version
pip3 --version
```

---

### For macOS

#### 1. Choose between default interpreter

Option A — **Use system Python** (already installed on newer macOS versions):
```bash
python3 --version
```

Option B — **Install via Homebrew** (recommended):
```bash
brew install python
```

#### 2. Verify Installation:
```bash
python3 --version
pip3 --version
```

---

## How to Work With Python Programs

This project includes a Makefile to help manage Python bytecode compilation and cleanup.

### Steps to Compile Python Files

1. **Navigate to Project Directory**:
   ```bash
   cd python_prgms
   ```

2. **Run the Make Command**:
   ```bash
   make
   ```

   * Compiles `.py` files in `src/` to `.pyc`
   * Stores bytecode in `src/__pycache__/`
   * Prints: "All Python scripts are compiled!"

### Steps to Run Python Programs

1. **Run Directly**:
   ```bash
   python3 <program>
   ```

2. **Run After Compilation**:
   * Python uses `.pyc` files automatically when available

### Clean the Project

1. **Clean Bytecode Files**:
   ```bash
   make clean
   ```

   * Removes `src/__pycache__/`
   * Prints: "Pycache has been cleaned!"

2. **Clean and Recompile**:
   ```bash
   make cleanbuild
   ```

   * Runs `make clean` and then `make`

### Summary of Commands

| Command              | Action                                |
| ---------------------| ------------------------------------- |
| `make`               | Compiles all Python files to bytecode |
| `make clean`         | Deletes bytecode cache files          |
| `make cleanbuild`    | Cleans and recompiles all files       |
| `python3 <program>`  | Runs a Python script directly         |

---
