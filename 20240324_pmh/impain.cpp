#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	Mat image(300, 500, CV_8UC1, Scalar(255)); // (300, 500) 크기의 배열을 선언하고 255로 초기화
	Point2f center(250, 150), pts[4];
	Size2f size(200, 80);
	RotatedRect rot_rect(center, size, 60);
	circle(image, rot_rect.center, 1, Scalar(0), 2); // image 의 ror_rect의 센터에 원 그리기, 반지름1, 밝기 0, 두께 2
	rot_rect.points(pts); // 배열 pts에 회전사각형의 4점을 반환
	cout << "point = " << endl;

	for (int i = 0; i < 4; i++)
		cout << pts[i] << ", " << endl; // 4점의 좌표 출력
	for (int i = 0; i < 4; i++) {
		circle(image, pts[i], 5, Scalar(0), 2); // image에 회전사각형 4점에 원 그리기, 반지름 4, 두께 1
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); // 직선 4개 그리기
	}

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);
	circle(image, Point(bound_rect.x, bound_rect.y), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x+bound_rect.width, bound_rect.y), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x+bound_rect.width, bound_rect.y+bound_rect.height), 5, Scalar(0), 2);
	circle(image, Point(bound_rect.x, bound_rect.y+bound_rect.height), 5, Scalar(0), 2);
	line(image, Point(250,0), Point(250,300), Scalar(0), 1); // 첫 번째 선
	line(image, Point(0,150), Point(500,150), Scalar(0), 1); // 두 번째 선
	imshow("회전사각형", image); // image를 창을 띄워서 출력
	waitKey(0);
}
	