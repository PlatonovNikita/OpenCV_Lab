#include "./Laba4.h"

using namespace std;
using namespace cv;

namespace Laba4 {
	int main(int argc, char** argv) {
        vector<Mat> images;
        vector<string> paths = { "./Laba4/Part1.jpg", "./Laba4/Part2.jpg" };
        Mat panorama;

        if (argc > 1)
        {
            paths = {};
            for (int i = 1; i < argc; ++i)
            {
                paths.push_back(argv[i]);
            }
        }

        for (int i = 0; i < paths.size(); i++) {
            Mat image = imread(paths[i]);
            if (image.empty())
            {
                std::cout << "Could not read the image: " << paths[i] << std::endl;
                return 1;
            }
            images.push_back(image);
        }

        Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA);
        Stitcher::Status status = stitcher->stitch(images, panorama);

        if (status != Stitcher::OK)
        {
            cout << "Can't stitch images, error code = " << status << endl;
            return -1;
        }

        imshow("Panorama", panorama);
        imwrite("./Laba3/ChangedImage/Panorama.jpg", panorama);
        waitKey(0);
        return 0;
	}
}