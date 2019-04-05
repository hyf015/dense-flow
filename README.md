# dense-flow
Dense optical flow extraction with GPU and opencv3, rewritten from https://github.com/wanglimin/dense_flow and https://github.com/agethen/dense-flow, can be used for extracting and resizing images and optical flow images from video.

# Getting started
## Prerequisites
This tool requires the OpenCV 3.x library to be installed. Make sure that your copy of OpenCV is compiled with CUDA and FFMPEG support. As this is the source of most user errors, here a minimal example on how to compile:
```
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build
cd build
cmake -D WITH_CUDA=ON -D WITH_FFMPEG=ON -D CMAKE_INSTALL_PREFIX=/some/path/opencv -D CUDA_ARCH_BIN=61 ..
make -j4
make install
```
With `CUDA_ARCH_BIN` you can specify the CUDA compute capability of your card, which typically will speedup compilation. If do not know your compute capability, you can leave that flag out.

To make sure everything worked, check the output of the `cmake` line and look for CUDA and FFMPEG.

## Compilation of dense-flow
Let's assume OpenCV is installed in `/some/path/opencv`. You now need to tell dense-flow's Makefile that path. To do this, edit `Makefile.config` and modify the paths in the second and third line.
Example:
```
INCLUDE=-I/some/path/opencv/include -Iinclude/
LIB=-L/some/path/opencv/lib
```

Once this is done, simply run:
```
mkdir build
make
```

## Running dense-flow
For convenience, we included a little script `build-flow.sh` that can batch process videos. You first need to edit line 19 and change `LD_LIBRARY_PATH` to point to your OpenCV installation. Do NOT forget this step, as the program might otherwise try to load a preinstalled version of OpenCV (which do not have CUDA support). Again assuming OpenCV is installed at `/some/path/opencv`, you would write:
```
LD_LIBRARY_PATH=/some/path/opencv/lib build/denseFlow_gpu .........
```

Now, we need to provide a list of the video files we would like to process. Under Linux, you can do the following:
```
find /path/to/your/videos -name "*.mp4" > files.txt
```
This should list all `*.mp4` files line-by-line in the textfile files.txt. You can also work with other formats like '.avi'.

Once this is done, you are ready to go. Just execute:
```
bash build-flow.sh
```
# Usage without the bash script
Example:
./denseFlow_gpu --vidFile="video.mp4" --xFlowFile="flow_x" --yFlowFile="flow_y" --imgFile="im" --bound=16 --type=2 --device_id=0 --step=10 --width=224 --height=224

Reads from file video.mp4, saving the Dense Optical flow with corresponding path prefixes flow_x / flow_y, the images with path prefix im, cuts off all flow values < -16 and > 16, using method 2 (Brox Optical Flow) on GPU 0, sampling only every 10th frame, with image width=224, height=224.

# References
https://github.com/wanglimin/dense_flow

https://github.com/agethen/dense-flow
