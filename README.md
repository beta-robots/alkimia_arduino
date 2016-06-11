# ALKIMIA ARDUINO SOFTWARE
Arduino code for the Alkimia project.

## Get the code

To get the code, please clone this repository with:

``` bash
$ git clone https://github.com/beta-robots/alkimia_arduino.git
```

### How to upload the firmware

It is set up to work with Arduino micro board.

Build the firmware with standard `catkin_make`, or specifically with:

`roscd && cd .. && catkin_make alkimia_arduino_firmware_single_fin`

And upload it (for Arduino Mega) with `catkin_make alkimia_arduino_firmware_single_fin-upload` (the upload mode is triggered by soft)

Note: Check that the arduino board connects to `/dev/ttyACM0`, you can use `cd /dev && ls | grep ttyACM`. If not, you need to change the `firmware/CMakeLists.txt` file. Provide privileges with `sudo chmod 777 /dev/ttyACM0`.

Tip: if you have `sudo` credentials on you PC, add your user to the `dialout` group to provide privileges to all ports by running: `sudo adduser YOUR_USER dialout`

## Electronics
To Do

## Mechanics
See the 3D drawing [here](https://myhub.autodesk360.com/ue2979c7f/g/shares/SHabee1QT1a327cf2b7a8aae6d6e7a079a69)


