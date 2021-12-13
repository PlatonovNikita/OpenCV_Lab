#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

namespace Laba1 {
	int main(int argc, char** argv) {

		Mat image, image2;
		String imagePath("./Laba1/Kitty.jpg");
		if (argc > 1)
		{
			imagePath = argv[1];
		}
		image = imread(imagePath);

		if (image.empty())
		{
			std::cout << "Could not read the image: " << imagePath << std::endl;
			return 1;
		}

		imshow("Original", image);
		imwrite("./Laba1/ChangedImage/Original.jpg", image);

		cvtColor(image, image2, COLOR_RGBA2GRAY);
		imshow("BlackAndWhite", image2);
		imwrite("./Laba1/ChangedImage/BlackAndWhite.jpg", image2);

		cvtColor(image, image2, COLOR_BGR2HSV);
		imshow("HSV", image2);
		imwrite("./Laba1/ChangedImage/HSV.jpg", image2);

		cvtColor(image, image2, COLOR_BGR2YUV);
		imshow("YUV", image2);
		imwrite("./Laba1/ChangedImage/YUV.jpg", image2);

		Canny(image, image2, 30, 150);
		imshow("Canny", image2);
		imwrite("./Laba1/ChangedImage/Canny.jpg", image2);

		GaussianBlur(image, image2, Size(5, 5), 0);
		imshow("Blur", image2);
		imwrite("./Laba1/ChangedImage/Blur.jpg", image2);
		waitKey(0);
		
		return 0;
	}
}