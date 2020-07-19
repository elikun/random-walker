#!/bin/bash

# Set DISPLAY variable
export DISPLAY=:20

# Configure screen resolution
Xvfb :20 -screen 0 640x640x16 &

# Start VNC server
x11vnc -passwd 2020 -display :20 -N -forever &

# Run Commander subsystem
/app/exe/commander &

# Run Environment subsystem
/app/exe/environment &
