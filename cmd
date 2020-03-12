 ./runYolov3 --caffemodel=/home/waleed/Downloads/608/yolov3_608.caffemodel --prototxt=/home/waleed/Downloads/608/yolov3_608_trt.prototxt --input=/home/waleed/Desktop/test/tensorrt-zoo/test.jpg --W=608 --H=608 --class=80 --mode=fp16


./runYolov3 --caffemodel=/home/waleed/Downloads/608/yolov3_608.caffemodel --prototxt=/home/waleed/Downloads/608/yolov3_608_trt.prototxt --input=/home/waleed/Desktop/test/tensorrt-zoo/test.jpg --W=608 --H=608 --class=80 --mode=fp16 --enginefile=./yolov3_fp16.engine



./runYolov3 --caffemodel=/home/waleed/Downloads/608/yolov3_608.caffemodel --prototxt=/home/waleed/Downloads/608/yolov3_608_trt.prototxt --input=/home/waleed/Desktop/test/tensorrt-zoo/test.jpg --W=608 --H=608 --class=80 --mode=fp16 --enginefile=./yolov3_fp16.engine --batchsize=1

./runYolov3 --caffemodel=/home/waleed/Downloads/608/yolov3_608.caffemodel --prototxt=/home/waleed/Downloads/608/yolov3_608_trt.prototxt --input=/home/waleed/Desktop/test/tensorrt-zoo/test.jpg --W=608 --H=608 --class=80 --mode=fp16 --enginefile=./yolov3_fp16.engine --batchsize=1

./runYolov3 --caffemodel=weights_full.caffemodel --prototxt=cfg_full.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/left_high.jpg --W=608 --H=608 --class=80 --mode=fp16 --enginefile=./yolov3_fp16.engine --batchsize=1


./runYolov3 --caffemodel=full_800.caffemodel --prototxt=full_800.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/left_high.jpg --W=800 --H=800 --class=80 --mode=fp16 --enginefile=./full_800_fp16.engine --batchsize=1


./runYolov3 --caffemodel=full_800.caffemodel --prototxt=full_800.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/left_high.jpg --W=800 --H=800 --class=80 --mode=fp16 --enginefile=./full_800_fp16.engine  --batchsize=1 --nms=0.01

./runYolov3 --caffemodel=full_800.caffemodel --prototxt=full_800.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/test.png --W=800 --H=800 --class=80 --mode=int8 --enginefile=./full_800_int8.engine  --batchsize=1 --nms=0.001 --calib=../calib_sample.txt

./runYolov3 --caffemodel=full_800.caffemodel --prototxt=full_800.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/test.png --W=800 --H=800 --class=80 --mode=int8 --enginefile=./full_800_int8.engine  --batchsize=1 --nms=0.001 --calib=../calib_sample.txt

./runYolov3 --caffemodel=full_800.caffemodel --prototxt=full_800.prototxt --input=/home/waleed/Desktop/test/GMS-Feature-Matcher/data/left_high.jpg --W=800 --H=800 --class=80 --mode=int8 --batchsize=1 --nms=0.001 --calib=../calib_sample.txt --enginefile=./full_800_img1700_b1_int8.engine


