#include "./Laba2.h"

using namespace cv;
using namespace std;

namespace Laba2 {
	int main(int argc, char** argv) {
        Mat image, result;

        String imagePath("./Laba2/sudoku.jpg");
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

        Blur(image, result, 6);
        imshow("Blur", result);
        imwrite("./Laba2/ChangedImage/Blur.jpg", result);

        SobelGradient(image, result);
        imshow("Gradient", result);
        imwrite("./Laba2/ChangedImage/Gradient.jpg", result);

        waitKey(0);

        return 0;
	}
}