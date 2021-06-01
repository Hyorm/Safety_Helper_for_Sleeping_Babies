#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


//Face detetion using Viola-Jones Algorithm
#if 1
int main(int argc, char *argv[])
{
	CascadeClassifier face_classifier;
	Mat frame, logF, grayframe;
	vector<Rect> faces;
	float c = 0.5;
	int i = 0;
	int warn = 0;
	VideoCapture cap("baby.mp4");
	//VideoCapture cap("babyBlack.mp4");

	// face detection configuration
	face_classifier.load("haarcascade_frontalface_alt.xml");

	while (true) {
		// get a new frame from webcam
		cap >> frame;
		if (frame.empty())
			break;

		cvtColor(frame, grayframe, CV_BGR2GRAY);
		grayframe.convertTo(logF, CV_32F);
		logF = abs(logF)+1;
		log(logF, logF);
		normalize(logF, logF, 0, 255, NORM_MINMAX);
		convertScaleAbs(logF, grayframe, c);

		// convert captured frame to gray scale & equalize

		face_classifier.detectMultiScale(
			grayframe,
			faces,
			1.1, // increase search scale by 10% each pass
			3,   // merge groups of three detections
			0,   // not usef for a new cascade
			Size(30, 30) //min size
		);

		// draw the results
		for (i = 0; i < faces.size(); i++) {
			Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point tr(faces[i].x, faces[i].y);
			rectangle(frame, faces[i], Scalar(0, 255, 0), 3, 4, 0);
		}
		if (i == 0) {
			warn++;
			if (warn>60) {
				putText(frame, "Warning!", Point(50, 100), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 255), 8);
			}
		}
		else {
			warn = 0;
		}

		// print the output

		imshow("Face Detection", frame);
		waitKey(cap.get(CAP_PROP_FPS));
	}
	return 0;
}
#endif