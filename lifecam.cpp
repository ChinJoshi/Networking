#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
	cv::VideoCapture cap(0);
	for(;;){
		std::vector< std::vector< cv::Point > > contours;
		cv::Mat frame,frameThresh;

		//cap>>frame;
		frame = cv::imread("/home/chinmaya/Downloads/picture.jpg");

		cv::resize(frame,frame,cv::Size(640,480));
		cv::cvtColor(frame,frame,CV_BGR2HSV);
		cv::inRange(frame,cv::Scalar(40,195,59),cv::Scalar(75,255,140),frame);
		cv::medianBlur(frame,frame,9);
		cv::findContours(frame,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
		std::vector<cv::Rect> boundRect( contours.size() );
		std::vector<float>radius( contours.size() );
		std::vector<cv::Point2f>center( contours.size() );
		for(int i = 0;i<contours.size();i++){
			boundRect[i] = cv::boundingRect( cv::Mat(contours[i]) );
			minEnclosingCircle( contours[i], center[i], radius[i] );
		}
		cv::Mat drawn = cv::Mat::zeros(frame.rows,frame.cols,CV_8UC3);	
		for(int i = 0; i<contours.size();i++){			
			cv::drawContours(drawn,contours,i,cv::Scalar(255,255,255),1);
			std::cout<<center[i].x<<std::endl;
		}
		cv::imshow("frame",frame);
		cv::imshow("contours",drawn);
		cv::imwrite("tapeContour.jpg",drawn);
		cv::waitKey(15);
	}
return 0;
}
