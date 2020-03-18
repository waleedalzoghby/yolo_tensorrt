#ifndef _CONFIGS_H_
#define _CONFIGS_H_

#include <string>
namespace Tn
{
    const int INPUT_CHANNEL = 3;
    const std::string INPUT_PROTOTXT ="yolov3_trt.prototxt";
    const std::string INPUT_CAFFEMODEL = "yolov3.caffemodel";
    const std::string INPUT_IMAGE = "test.jpg";
    const std::string EVAL_LIST = "";
    const std::string CALIBRATION_LIST = "";
    const std::string MODE = "fp32";
    const std::string OUTPUTS= "yolo-det";//layer82-conv,layer94-conv,layer106-conv
    const std::string DATASET_PATH = "/home/waleed/projects/MIT/MIT-Driverless-CV-TrainingInfra/CVC-YOLOv3/dataset/YOLO_Dataset/";
    const int INPUT_WIDTH = 800; //608;
    const int INPUT_HEIGHT = 800; //608;

    const int DETECT_CLASSES = 80;
    const float NMS_THRESH = 0.45;
}

#endif