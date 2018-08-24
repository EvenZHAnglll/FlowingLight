# FlowingLight
An Arduino project with LED light bar


# Example
  ![Hello World](
      https://github.com/EvenZHAnglll/FlowingLight/blob/master/HelloWorld.jpeg
    )
  A "Hello World" flows in the air with Long-exposure photography.
  
  ![Hello World Dark](
      https://github.com/EvenZHAnglll/FlowingLight/blob/master/HelloWorld_Dark.jpeg
    )  
  It looks pretty cool!
# Hardware 
* An Arduino Uno ( A power bank is used to power Arduino)
* A RGB LED bar with 30 LEDs
* A long wooden stick (used to attach the soft LED bar)

![Stick](
      https://github.com/EvenZHAnglll/FlowingLight/blob/master/stick.jpg
    )  

# How to use it

Python3 and OpenCV are used in this project.

Run a python file image2data.py in WalkingText/im2data folder. 

  It will convert the image file  HelloWorld.jpg into a text file TheImg.txt in the same folder.
  
  Then copy all of the text in TheImg.txt and paste them to the right position of the Arduino script FlowingLight/WalkingText/LED/LED.ino 

Upload into Arduino!
