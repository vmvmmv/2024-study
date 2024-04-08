
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 영상 크기 설정
    int width = 256;
    int height = 256;

    // 그레이스케일 이미지 생성 및 초기화 (흰색: 255)
    Mat image(height, width, CV_8UC1, Scalar(255));

    // 1. 대각선 방향의 X표 그리기 (검정색: 0)
    for (int row = 0; row < height; row++) {
        // 대칭되는 점의 열 값
        int col_symmetric = height - row - 1;
        // 대칭되는 점에 대각선 그리기
        image.at<uchar>(row, row) = 0;
        image.at<uchar>(row, col_symmetric) = 0;
        // 이미지 출력
        imshow("Image", image);
        waitKey(10); // 10ms 대기
    }
    waitKey();
    // 2. 행 단위로 20줄씩 건너뛰며 수평방향의 직선 그리기 (검정색: 0)
    for (int row = 0; row < height; row += 20) {
        uchar* row_ptr = image.ptr<uchar>(row); // 현재 행의 시작 지점 주소
        for (int col = 0; col < width; col++) {
            row_ptr[col] = 0; // 검정색으로 픽셀 설정
        }
        // 이미지 출력
        imshow("Image", image);
        waitKey(10);
    }

    // 3. 정중앙에 크기 80X80크기의 정사각형 그리기 (회색 : 128)
    waitKey();
    int square_size = 80;
    int x = (width - square_size) / 2;
    int y = (height - square_size) / 2;
    Rect roi_rect(x, y, square_size, square_size);
    Mat roi = image(roi_rect);
    for (MatIterator_<uchar> it = roi.begin<uchar>(); it != roi.end<uchar>(); ++it) {
        // 픽셀 값에서 128을 빼고, 음수일 경우 0으로 설정
        *it = max(static_cast<int>(*it) - 128, 0);
    }

    // 이미지 출력
    imshow("Image", image);
    waitKey();

    return 0;
}