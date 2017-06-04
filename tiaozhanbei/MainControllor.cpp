#include "MainControllor.h"

MainControllor::MainControllor()
{
}

MainControllor::~MainControllor()
{
}

void MainControllor::start()
{
	while (1)
	{
		std::cout << "Select one mode.! \n" << "1.Using the SVM model to predict the result.\n" << "2.Collecting the sample.\n" << "9.Quit.\n";
		std::cout << ">> ";
		int flag;
		std::cin >> flag;
		switch (flag)
		{
		case 1:
			Predict();
			break;
		case 2:
			CollectSample();
			break;
		case 9:
			break;
		default:
			std::cout << "Bad select.";
			break;
		}
		if (flag == 9)
			break;
	}
}

void MainControllor::Predict()
{
	cv::Mat frame;
	int flag1 = 0;
	int flag2 = 0;
	cv::Rect result;
	KCFTracker *tracker = new KCFTracker;
	SVMClassifier svm;
	svm.LoadModel("svm.xml");

	cv::VideoCapture cap(0);
	cap >> frame;

	cv::namedWindow("result");

	while (1)
	{
		std::queue<cv::Point> pots;
		cv::Mat cut = drawinitial(frame);
		std::cout << "���ٽ���5s�����~\n";
		while (1)
		{
			cap >> frame;
			cv::rectangle(frame, cv::Rect(cv::Point(240, 330), cv::Point(360, 430)), cv::Scalar(0, 0, 0));
			cv::imshow("result", frame);
			cv::waitKey(5);
			flag1++;
			if (flag1 == INIT_FLAG)
			{
				flag1 = 0;
				tracker->init(cv::Rect(cv::Point(240, 330), cv::Point(360, 430)), frame);
				break;
			}
		}

		while (1)
		{
			cap >> frame;
			result = tracker->update(frame);
			cv::rectangle(frame, cv::Point(result.x, result.y), cv::Point(result.x + result.width, result.y + result.height), cv::Scalar(0, 255, 255), 1, 8);
			cv::imshow("result", frame);
			if (pots.size() == 2)
			{
				cv::line(cut, pots.front(), pots.back(), cv::Scalar(255), 35);
				pots.pop();
			}
			pots.push(getcenter(result));
			cv::imshow("cut", cut);
			cv::waitKey(10);
			flag2++;
			if (flag2 == TRACK_FLAG)
			{
				flag2 = 0;
				break;
			}
		}
		cv::Mat testdata;
		cv::threshold(cut, testdata, 2, 1, cv::THRESH_BINARY);
		cv::resize(testdata, testdata, cv::Size(20, 20));
		testdata = testdata.reshape(0, 1);
		testdata.convertTo(testdata, CV_32FC1);
		//cv::Mat result(1,0,CV_32SC1);
		int result = svm.Predict(testdata);
		switch (result)
		{
		case 1:
			std::cout << "�ҽг���\n";
			break;
		case 2:
			std::cout << "��Һ�\n";
			//PlaySound(L".\\hello.wav", NULL, SND_FILENAME | SND_SYNC);
			break;
		case 3:
			std::cout << "лл\n";
			//PlaySound(L".\\thanks.wav", NULL, SND_FILENAME | SND_SYNC);
			break;
		}
	}
	delete tracker;
}

void MainControllor::CollectSample()
{
	cv::Mat frame;
	int flag1 = 0;
	int flag2 = 0;
	char button;
	cv::Rect result;
	KCFTracker* tracker = new KCFTracker;

	cv::VideoCapture cap(0);
	cap >> frame;

	cv::namedWindow("result");

	//Mat image(rows,cols,CV_8UC1,Scalar(0));

	int number = 0;
	cv::FileStorage fs("./test_big.xml", cv::FileStorage::WRITE);
	while (1)
	{
		std::queue<cv::Point> pots;
		cv::Mat cut = drawinitial(frame);
		
		std::cout << "���ٽ���5s�����~\n";
		while (1)
		{
			cap >> frame;
			cv::rectangle(frame, cv::Rect(cv::Point(240, 330), cv::Point(360, 430)), cv::Scalar(0, 0, 0));
			cv::imshow("result", frame);
			cv::waitKey(5);
			flag1++;
			if (flag1 == INIT_FLAG)
			{
				flag1 = 0;
				tracker->init(cv::Rect(cv::Point(240, 330), cv::Point(360, 430)), frame);
				break;
			}
		}

		while (1)
		{
			cap >> frame;
			result = tracker->update(frame);
			cv::rectangle(frame, cv::Point(result.x, result.y), cv::Point(result.x + result.width, result.y + result.height), cv::Scalar(0, 255, 255), 1, 8);
			cv::imshow("result", frame);
			if (pots.size() == 2)
			{
				line(cut, pots.front(), pots.back(), cv::Scalar(255), 35);
				pots.pop();
			}
			pots.push(getcenter(result));
			cv::imshow("cut", cut);
			cv::waitKey(30);
			flag2++;
			if (flag2 == TRACK_FLAG)
			{
				flag2 = 0;
				break;
			}
		}
		std::cout << "Enter 1 to store the data.\n" << ">> ";
		std::cin >> button;
		if (button == '1')
		{
			button = 'n'; 

			threshold(cut, cut, 2, 1, cv::THRESH_BINARY);//convert to binary
													 //cout << sized
			cut.convertTo(cut, CV_32FC1);

			std::strstream ss;//set data's name
			std::string s1, s2("mat");//name is mat1,2,3
			ss << number;
			ss >> s1;
			s2.append(s1);
			fs << s2 << cut;
			std::cout << "The " << number + 1 << "'s have been stored.!\n";
			number++;
			if (number == 2)//control qutting
				break;
		}
	}
	delete tracker;
	fs.release();
}
