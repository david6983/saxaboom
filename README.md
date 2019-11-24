# SAXABOOM - VST (Kawasaki Sax-a-boom emulator)

## Presentation

**SAXABOOM** is my **first vst plugin**. 

The idea come from a video from "**The Tonight Show Starring Jimmy Fallon**" named "**Jack Black Performs His Legendary Sax-A-Boom with The Roots**" (https://www.youtube.com/watch?v=cLmCJKT5ssw).

This software emulate the famous toy from **Kawasaki, Sax-a-boom**.

The **original samples** contains in the Samples folder come from
this youtube video : https://www.youtube.com/watch?v=9MCN_7jpYig

## Manual

- **Play the sounds from midi input in a range of C-3 to G-3.**
- **Click on one of the 7 buttons on the right to play a sound.**
    - Note : The first button on top corresponds to C-3 midi note and the last one (bottom-right) corresponds to G-3 on midi keyboard.
- **The main loop button play the main melody part of the Sax-a-boom.**
    - Note : This button is seprated from the other because the sound is not a saxaphone sound !
- **The volume of the sound played from the graphical interface can be set by the rotary slider from 0 to 127.**
    - Note : The range used for the volume corresponds to the velocity of a midi note.
- **One click on the author name redirect you to the author's github page.**

## Install for windows (setup)

- Launch Output/SAXABOOM-x86-1.0.0-vst3.exe

note : **The setup installer will create a folder called Saxaboom in your documents path. Please do not delete this folder fi you launch the vst plugin !**

## Build from sources (Windows only)

prerequisite :
- Juce framework ( https://shop.juce.com/get-juce ) 
    - version 5.4.3 or higher
- inno setup ( http://www.jrsoftware.org/isdl.php )
    - latest version

1) Clone this repository
2) Open the project in Projucer
3) Build with Visual Studio 2017 (version 15.9.11 is the version I used to build the project)
    - if you want to use another build system, **don't forget to modify the setup_script.iss** with inno setup software (change the build path for Sources)
4) Compile the setup_script in the inno setup editor

### Mac OS support

**Comming soon ... (September 2020)**

### Linux support

**Not implemented yet**

### Note for vst2 support

Because steinberg technologies recommend to build vst3 instead of vst2, the **vst2 version of this software is not provided in the setup installer**. However if you persist to use vst2 on your DAW, build this vst from source in the Projucer and add vst2 support.