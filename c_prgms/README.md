# C Development Environment Setup

## How to Install C Compiler (GCC)

### For MSYS2 (Windows)

#### 1. Install MSYS2
1. Download from [msys2.org](https://www.msys2.org/)
2. Run installer with default options
3. Update core packages:
   ```bash
   pacman -Syu
   ```

#### 2. Install GCC
```bash
pacman -S mingw-w64-x86_64-gcc
```
(For 32-bit: `mingw-w64-i686-gcc`)

#### 3. Verify Installation
```bash
gcc --version
```

---

### For WSL (Windows Subsystem for Linux)

#### 1. Install WSL
1. **Enable WSL**:
   ```powershell
   wsl --install
   ```
2. Restart if prompted
3. (Optional) Install specific distro:
   ```powershell
   wsl --install -d <DistroName>
   ```

#### 2. Install Ubuntu
1. From Microsoft Store, install **Ubuntu** (20.04/22.04 LTS)
2. Launch and complete setup (username/password)

#### 3. Install Build Tools
```bash
sudo apt update && sudo apt install build-essential
```

#### 4. Verify Installation
```bash
gcc --version
```

---

# How to Work With C Programs

This project includes a Makefile to automate compilation and project management.

## Steps to Compile Programs
1. **Navigate to project directory**
2. **Run make**:
   ```bash
   make
   ```
   - Creates `build/` directory
   - Compiles all `.c` files
   - Links object files
   - Prints: "All source files are built!"

## Steps to Run Programs
```bash
./build/program_name
```

## Clean the Project
1. **Clean build files**:
   ```bash
   make clean
   ```
   - Removes `build/` directory
   - Prints: "Build folder has been cleaned and removed!"

2. **Full rebuild**:
   ```bash
   make cleanbuild
   ```

## Summary of Commands

| Command          | Action                                  |
|------------------|----------------------------------------|
| `make`           | Compiles all C source files            |
| `make clean`     | Deletes build directory                |
| `make cleanbuild`| Full clean + rebuild                   |
| `./build/program`| Run compiled executable                |

---
