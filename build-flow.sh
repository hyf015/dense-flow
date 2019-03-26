# Run on which GPU?
export did=0
# Run which dense optical flow [0,2]
# 0: Farneback
# 1: TVL1
# 2: Brox
export type=1
# Bounds for Flow (largest possible value, used in linear scaling to [0,255])
export bound=20
while read line
do
	# This would create a directory with the name of the video (file-ending stripped). Flow will be saved there
  export dir=`echo $line | sed 's/\.mp4//'`
  mkdir -- $dir
  # If you used a non-standard path for OpenCV lib, make sure to update LD_LIBRARY_PATH. Otherwise, feel free to delete.
  # xFlowFile / yFlowFile : Output filenames
  # clip = 20000 : Process maximum of 20K frames
  # step = 3 : Sample only every 3rd frame
  LD_LIBRARY_PATH=/home/hyf/Downloads/opencv/build/lib build/denseFlow_gpu --vidFile=$line --xFlowFile="$dir/flow_x" --yFlowFile="$dir/flow_y" --device_id=$did --type=$type --bound=$bound --clip=20000 --step=1 --sizex=224 --sizey=224
  # files.txt contains (absolute) paths to the video files
done < files.txt
