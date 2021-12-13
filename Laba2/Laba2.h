#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

namespace Laba2 {
	int main(int argc, char** argv);

    uchar calculatePixel(const cv::Mat& image, const std::vector<std::vector<double>>& kernel, int i, int j);

    void MatrixFilter(const cv::Mat& image, cv::Mat& result, const std::vector<std::vector<double>>& convolutionMatrix);

    void Blur(const cv::Mat& image, cv::Mat& result, unsigned size);

    void SobelGradient(const cv::Mat& image, cv::Mat& result);
}
