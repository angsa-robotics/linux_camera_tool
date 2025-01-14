# Docker Guide

## Build Base Image

Build inside docker:

```
cd docker
docker build . -t licam
```

## Run with GUI

You need a screen attached to the Jetson.

```
xhost +
docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    licam
```

This should open the GUI:

```
# Inside docker:
cd ~/linux_camera_tool/build
./leopard_cam
```

