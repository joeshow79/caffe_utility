Author: jasonj

[plot_loss]
Usage:  sh plot_loss.sh caffe.INFO

Dependencies: python/numpy/pylab

[masktuner]
Usage:  masktuner [-h] <Image_Dir_Path>

Dependencies: opencv/c++

Description:
	Go through the dir named with Image_Dir_Path, find the original image (with postfix of jpg) and the raw mask image (with postfix of png), merge the 2 images for editing.
	After editing, the modified mask images save in the Image_Dir_Path by  the names with the p_ prefix and png postfix.

Keys:
	Shift + Left Mouse Button down: Mask the pixel as frontground <white>
	Shift + Right Mouse Button down: Mask the pixel as background <black>
	Shift + Left Mouse Button down + Mouse Move: Mask the pixels as frontground with brush <white>
	Right + Right Mouse Button down + Mouse Move: Mask the pixels as background with brush <black>
	Enter: save the result and go to next image.
	Esc: Quit

