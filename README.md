# RGB-Charlieplexed-Cube

Drive link for videos and pics:https://drive.google.com/drive/folders/19HEllqTeNNRnMAUlORyuMgxC3-3JILuz?usp=sharing

I followed this tutorial: https://aglick.com/charliecube.html

The .ino file is modified to integrate with bluetooth control. Have also added letter animations along with few other animations.
The basic app to control this was made with Kodular.
I used 82 ohm resistors on each of the 16 microcontroller outputs to solve the issue of ghosting of red LED's.
The onboard Pin 13 LED gave problems and hence changed that pin to A4 of the Nano in the mappings.h file of the original project. 
