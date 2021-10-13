# XV6-implementation-using-QEMU

XV6 is an operating system developed by MIT for the exact same purpose. It is an implementation of the Unix version 6 using ANSI C language for x86 platforms. It is a great resource for learning operating systems and many universities all over the world have already used it in their courses.
XV6 is a modern re-implementation of UNIX. It is basically functioning like a parallel OS compiler in which we can new system calls can be identified.
This implementation of the project will contain running xv6 in Qemu emulator and adding some system calls to the XV6.

# Instructions

We are running xv6 operating system on a QEMU virtual machine simply on top of a 64-bit Ubuntu 18.06 LTS machine. We have to install some tools and packages on our Ubuntu Linux system as follows:
sudoapt-getupdate
sudoapt-getinstallbuild-essentialo sudoapt-getinstallgcc-multilib o sudoapt-getinstallqemu
sudoapt-getinstallgit
Then download the source code of the xv6 operating system. MIT provided an official git repository to download the source code. 
git clone https://github.com/mit-pdos/xv6-public.git

Now, compile and run xv6 system on the QEMU emulator.
