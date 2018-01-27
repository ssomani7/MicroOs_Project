
MicroOs
=======================
MicroOs is scale downed version of a bootable Operating System written in assembly and C. The OS consists
of basic features like booting of the OS, interrupt and exception handling, basic device drivers for display and
keyboard, and a basic shell.

Developed by :
------------------------
Siddharth Kumar - siddarth306@gmail.com

Shashi Bhushan Mishra - shashi.mishra43@gmail.com

Saurabh Somani - somani.saurabh7@gmail.com

Installation :
--------------------

1. clone repository using the following command
    `git clone https://github.com/shashi07/MicroOs.git`
2. install bochs
    `sudo apt-get install bochs`
3. install nasm
    `sudo apt-get install nasm`

4. install sdl 
```
    sudo apt-get install libsdl2-dev
    sudo apt-get install bochs-sdl
```

Compile and Run:
----------------------
``` 
    >>cd MicroOs
    >>make clean
    >>make 
    >> bochs 
```

