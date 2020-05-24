#ifndef GENERATEIMAGE_H
#define GENERATEIMAGE_H

#include <QString>
#include <vector>
#include <ImageMagick-7/Magick++.h>
class GenerateImage
{
    public:

        //constructor
        GenerateImage(double rDistortion = 3,double rWidth = 10,double rHeight = 10);

        //setters
        void setDistortion(double rDistortion);
        void setWidth(double rWidth);
        void setHeight(double rHeight);

        //getters
        double getDistortion();
        double getWidth();
        double getHeight();

        //logic
        Magick::Image* generateImage();
        void inputImage(std::vector<QString> filePathes);
        bool extractImage(Magick::Image* readyPicture, QString filepath);

    private:
        double distortion;
        double width;
        double height;
        std::vector<Magick::Image> processImages;
};

#endif // GENERATEIMAGE_H
