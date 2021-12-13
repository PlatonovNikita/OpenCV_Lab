#include "./Laba2.h"

using namespace std;
using namespace cv;

namespace Laba2 {
    void Blur(const Mat& image, Mat& result, unsigned size) {
        image.copyTo(result);
        vector<vector<double> > convolutionMatrix(size, vector<double>(size, 1. / (size * size)));
        MatrixFilter(image, result, convolutionMatrix);
    }

    void SobelGradient(const Mat& image, Mat& result) {
        image.copyTo(result);
        vector<vector<double> > convolutionMatrix = { 
            {-1, -2, -1},{0, 0, 0},{1, 2, 1} };
        MatrixFilter(image, result, convolutionMatrix);
    }

    void MatrixFilter(const Mat& image, Mat& result,
        const vector<vector<double>>& convolutionMatrix) {
        int border = convolutionMatrix.size() / 2;

        vector<Mat> colorChannels;
        split(image, colorChannels);
        vector<Mat> resultColorChannels = colorChannels;

        for (int i = border; i < image.rows - border; ++i) {
            for (int j = border; j < image.cols - border; ++j) {
                for (int k = 0; k < resultColorChannels.size(); k++) {
                    resultColorChannels[k].at<uchar>(i, j) = calculatePixel(colorChannels[k], convolutionMatrix, i, j);
                }
            }
        }
        merge(resultColorChannels, result);
    }

    uchar calculatePixel(const Mat& image, const vector<vector<double>>& convolutionMatrix,
        int i, int j) {
        int newPixel = 0;

        for (int offsetI = 0; offsetI < convolutionMatrix.size(); ++offsetI) {
            for (int offsetJ = 0; offsetJ < convolutionMatrix.size(); ++offsetJ) {
                newPixel += image.at<uchar>(i + offsetI, j + offsetJ) * convolutionMatrix[offsetI][offsetJ];
            }
        }

        return saturate_cast<uchar>(newPixel);
    }
}