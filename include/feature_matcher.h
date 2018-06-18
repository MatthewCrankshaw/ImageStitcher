#ifndef FEATURE_MATCHER_H
#define FEATURE_MATCHER_H

#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/flann/flann.hpp>
#include<fstream>
#include<ctime>

using namespace std;
using namespace cv;

class feature_matcher
{
    public:
        feature_matcher(int width, int height);
        virtual ~feature_matcher();
        void getHomographySURF(const Mat &src1, const Mat &src2, int param, Mat &mtchs, Mat& h);
        void getHomographySIFT(const Mat &src1, const Mat &src2, int param, Mat &mtchs, Mat& h);
        void getHomographyORB(const Mat &src1, const Mat &src2, int param, Mat &matches, Mat&h);

        void writeDataFile();

    protected:

    private:
        Mat descriptors1, descriptors2;
        vector<KeyPoint> keypoints1, keypoints2;
        string timeData;
        string matchData;

        int imgWidth, imgHeight;

        void matchFeaturesFLANN(vector<vector<DMatch> > &matches, bool isORB);
        void matchFeaturesBruteForce(vector<DMatch> &matches);
};

#endif // FEATURE_MATCHER_H
