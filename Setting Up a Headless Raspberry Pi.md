# Getting Started with a Headless Raspberry Pi

This document describes how you can configure your Raspberry Pi and get started with minimal hardware

### Components Required
- Raspberry Pi 4 - 2GB RAM
- 16GB+ Class 10 MicroSD Card
- Computer with MicroSD slot / MicroSD card reader 

## Preparing the SD Card

Download [this](https://drive.google.com/file/d/1Q85kELzaGw0jq9rdeGAWXRQvfeVSWack/view?usp=sharing) Raspberry Pi **Image**

Download and Start / Install [Raspberry Pi **Imager**](https://www.raspberrypi.org/downloads/) software for your Operating System from 

Once the *Image* is downloaded, open the *Imager* and select the *Image* as Step 1

Insert your 16GB+ SD Card into the Computer and select the SD Card in Step 2 of *Imager*

Click Write

> This process takes ample amount of time

## Initial Setup

Once the *Image* is written and verified on the SD Card, remove the SD card from the computer / SD Card reader and insert it into the SD Card slot of the Raspberry Pi. 

> **DO NOT power it up, yet**

Using your Smartphone or a Wifi router, start a Wifi hotspot with 

    SSID: IN4.0 Talent Academy

    Password: password

Make sure the hotspot is turned on and ready to accept new connections

Now, Power up your Raspberry Pi

In a minute or so, the Pi will connect to the Wifi hotspot you are broadcasting

To establish an SSH connection with the Raspberry Pi from your PC / Laptop / Smartphone (connecting device), make sure the connecting device is also in the same network (I mean connect this device as well to the same wifi hotspot)

Using Terminal / Command Prompt / Termius, run the following command to establish an SSH connection

    ssh pi@raspberrypi.local

If your Terminal / Command Prompt is unable to locate raspberry.local, run the following command to find the IP address of the Pi

    ping raspberry.local

With the resultant IP address, initialise the SSH connection with the following command

    ssh pi@A.B.C.D

For the first time, you will be asked to confirm the signature of the device. Respond with `yes`

It will then prompt to enter the password. Use the following term as password

    raspberry

This should get you in to the Raspberry Pi's terminal.

## Configure WiFi

Configure the Raspberry Pi to use your home/office Wifi. To do this, execute the following command

    sudo raspi-config

Navigate to `Network Options -> Wireless LAN`

Enter the `SSID` and `Password` of your Home / Office Wifi

> Make sure you consider the case of letters, spaces and everything. Misconfiguration will lead you to do this exercise from the beginning

Select `OK` to Save the settings and `Finish` to exit from the configuration window

You may now turn off your Mobile hotspot and have your PC / Laptop connected to the Home/Office Wifi

Establish an SSH connection again by executing the following in Terminal / Command Prompt / Termius

    ssh pi@raspberrypi.local

Confirm the signature of device if prompted and enter the password as `raspberry`

You now have full access to your Raspberry Pi's terminal

## Enabling VNC (Graphical User Interface)

This Raspberry Pi Image was built with very minimal features. To suit up with updates and VNC, do the following

    sudo apt-get update

    sudo apt-get upgrade

To install and host a VNC server, do the following

    sudo apt-get install realvnc-vnc-server # Installing VNC Server

    sudo apt-get install lightdm # Installing GUI 

    sudo vncserver # Initializing VNC Server

Enable VNC in config

    sudo raspi-config

> `Interfacing Options -> VNC -> Enable`

> `Advanced Options -> Resolution -> Mode 85`

> `Boot Options -> Desktop -> Start Desktop and login as pi user by default`

> Let the system **reboot** itself whenever prompted

Download and Install a [VNC viewer](https://www.realvnc.com/en/connect/download/viewer/) for your Operating System

Within the VNC Viewer application, connect to Raspberry Pi's VNC Server by establishing a connection with 

    raspberrypi.local

Confirm the Signature when prompted and enter the 

    Username: pi
    Password: raspberry

This should give you the GUI for your Raspberry Pi!

All the best :)
