This is my personal school stuff, compiled with gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0.

RIP `conio.h`, you were a real one... Not.

# Compiling and running
Steps to compile a C program.

In case you need help setting up, click [here](https://github.com/PCG06/my_programs/?tab=readme-ov-file#help-center).

## All programs

Just `make`, bro. :)
```bash
make
```

### To compile a little faster

The command `nproc` tells you how many thread you have on your computer.
```bash
nproc
```

Running make -j will speed up the process, based on the number of threads on your computer.
```bash
make -j${nproc}
```

`make` will build all source files present in `/src`.

To run any program, in this case let's assume it's hello.c

```bash
./build/hello
```

In case you want to erase all build artifacts,

```bash
make clean
```

`make clean` will erase all build artifacts, allowing you to `make` again.

## Individual program

If you're compiling and running on Turbo C++, please don't forget to do the following steps.

```diff
  #include <stdio.h>
+ #include <conio.h>

  void main()
  {
      int a, b, c;
+     clrscr();
      ...
      ...
+     getch();
  }
```

You need to include `conio.h`, and use the functions `clrscr()` before printing statements, and `getch()` at the bottom.

- Compiling.

  - Let's assume you're compiling hello.c,
  ```bash
  gcc hello.c -o hello.o
  ```
  - In other places, replace `hello.c` and `hello.o` with the appropriate file name.
  - By default, running this command won't create the output file in `build` dir, it'll be in the `src` dir, unless you `make` or use a more complex command.

- Running.

   - Again, assuming you're running hello.c
     ```bash
     ./hello.o
     ```
And that's it. Enjoy :)

# Help Center:
In case you need help setting up your environment.
- [Stepwise Guide to Enable Windows Subsystem for Linux (WSL)](https://developerinsider.co/stepwise-guide-to-enable-windows-10-subsystem-for-linux/)
- [Compile C program with gcc compiler on Bash on Ubuntu on Windows 10 & 11](https://developerinsider.co/compile-c-program-with-gcc-compiler-on-bash-on-ubuntu-on-windows-10/)
- [Turbo C++](https://developerinsider.co/download-turbo-c-for-windows-7-8-8-1-and-windows-10-32-64-bit-full-screen/)

# Credits:
All people who helped in one way or the other.
- anyone who wrote these programs (me, and everyone who contributed).
- ChatGPT for writing the Makefile (yes I got desperate).
- my C lecturer.
- [Vineet Choudhary](https://developerinsider.co/author/vineet/).
