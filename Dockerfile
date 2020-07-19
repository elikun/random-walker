FROM ubuntu:latest

# Install required packages
RUN apt-get update && apt-get install -y build-essential qt5-default x11vnc xvfb

# Set environmental variable for display
ENV DISPLAY :20

# Set working directory
WORKDIR /

# Expose port 5920 to view display using VNC Viewer
EXPOSE 5920
