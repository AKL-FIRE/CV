//This is main class to control the whole program.
#ifndef _MAINCONTROLLOR_
#define _MAINCONTROLLOR_
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\opencv.hpp>
#include <queue>
#include <string>
#include <strstream>
#include <Windows.h>

#include "draw.h"
#include "kcftracker.hpp"
#include "tracker.h"
#include "SVMClassifier.h"
#include "DataProcess.h"

#define INIT_FLAG 50 
#define TRACK_FLAG 75



class MainControllor
{
public:
	MainControllor();
	~MainControllor();
	void start(); //The main scnery.
	
private:
	void Predict();//The prediction mode.
	void CollectSample();//The collecting mode.
};



#endif // _MAINCONTROLLOR_
