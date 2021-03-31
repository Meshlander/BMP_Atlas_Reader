@echo off

cl -MT -GR- -EHa- -Oi -W4 -FC -Z7 -O2 GetBitmapBytes.c /link -opt:ref user32.lib gdi32.lib winmm.lib Ws2_32.lib Opengl32.lib 
