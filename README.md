This is my personal school stuff, compiled with gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0.

RIP `conio.h`, you were a real one... Not.

## Compiling and running
Steps to compile a C program.

### All programs
Just use `make`, bro. :)

### Individual program
If you're compiling and running on Turbo C++, please don't forget to do the following steps

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


- Enter the `c_programs` directory.
  ```bash
  cd c_programs/src
  ```
- Compiling.

  - Let's assume you're compiling hello.c,
  ```bash
  gcc hello.c -o hello.o
  ```
  - In other places, replace `hello.c` and `hello.o` with the appropriate file name.

- Running.

   - Again, assuming you're running hello.c
     ```bash
     ./hello.o
     ```
   - If you're outside the `c_programs` directory
     ```bash
     ./c_programs/src/hello.o
     ```

And that's it. Enjoy :)

Sources:
- [Compile C program with gcc compiler on Bash on Ubuntu on Windows 10 & 11](https://developerinsider.co/compile-c-program-with-gcc-compiler-on-bash-on-ubuntu-on-windows-10/)
- [Turbo C++](https://developerinsider.co/download-turbo-c-for-windows-7-8-8-1-and-windows-10-32-64-bit-full-screen/)

Credits:
- anyone who wrote these programs (me, and everyone who contributed).
- ChatGPT for writing the Makefile (yes I got desperate).
- my C lecturer.
- [Vineet Choudhary](https://developerinsider.co/author/vineet/).
