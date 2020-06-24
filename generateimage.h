#ifndef GENERATEIMAGE_H
#define GENERATEIMAGE_H

#include <QString>
#include <vector>
#include "ImageMagick-7/Magick++.h"
class GenerateImage
{
    public:

        //constructor
        GenerateImage(double rDistortion,double rWidth,double rHeight);

        //setters
        void setDistortion(double rDistortion);
        void setWidth(double rWidth);
        void setHeight(double rHeight);

        //getters
        double getDistortion();
        double getWidth();
        double getHeight();

        //logic
        void generateImage();
        void inputImage(const QStringList& filePathes);
        double randomizeCoords(const double& y);
        bool extractImage(Magick::Image* readyPicture, QString filepath);
        Magick::Image placeText(Magick::Image& modifcate, const std::string& text);

    private:
        double distortion;
        double width;
        double height;
        std::vector<Magick::Image> processImages;
};

#endif // GENERATEIMAGE_H
