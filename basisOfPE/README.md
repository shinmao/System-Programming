In this .s file is an assembly file which will write the "helloworld" in your terminal.

Two commands are important:
```
$ nasm -felf64 Hello.s -o a.o
$ ld -m elf_x86_64 a.o Hello
```
From commands above we can create a elf of Hello.

Notice that this code only work in x64 Linux system, so we use the "r" registers instead of "e" register.

Look more for writing such a file in my post
[Writing Shellcode](https://null-byte.wonderhowto.com/forum/basic-concepts-and-skills-binary-exploitation-part-1-0179837/)
