#include "generateimage.h"
#include <ImageMagick-7/Magick++.h>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
GenerateImage::GenerateImage(double rDistortion,double rWidth,double rHeight) {

    setDistortion(rDistortion);
    setWidth(rWidth);
    setHeight(rHeight);
}

double GenerateImage::getWidth() {
    return this->width;
}

double GenerateImage::getHeight() {
    return this->height;
}

double GenerateImage::getDistortion() {
    return this->distortion;
}

void GenerateImage::setWidth(double rWidth) {
    this->width = rWidth;
}

void GenerateImage::setHeight(double rHeight) {
    this->height = rHeight;
}

void GenerateImage::setDistortion(double rDistortion) {
    this->distortion = rDistortion;
}

void GenerateImage::inputImage(const QStringList& filePathes){
    Magick::Image image;
    try {
        for(const auto& filePath: filePathes) {
            image.read(filePath.toStdString());
            this->processImages.push_back(image);
        }
    }
    catch(std::exception &error_ ) {
        qDebug() << "Caught exception: " << error_.what() << '\n';
    }
}

void GenerateImage::generateImage() {
    for(auto& image : this->processImages) {
        qDebug() << "processing\n";
        std::string fileName = image.baseFilename();
        int i = fileName.size() - 1;
        while(fileName[i] != '/') {
            i--;
        }
        fileName = fileName.substr(i,fileName.size()-i);
        GenerateImage::placeText(image).write("/home/prise/testImages/" + fileName);
        i++;
    }
}

Magick::Image GenerateImage::placeText(Magick::Image& modificate) {
    modificate.strokeColor("red");
    modificate.fillColor("green");
    modificate.draw(Magick::DrawableCircle(100,100,50,100));
    qDebug() << QString::fromStdString(modificate.format())<< '\n';
    return modificate;
}

bool GenerateImage::extractImage(Magick::Image* readyPicture, QString fullPath) {
    if(readyPicture != nullptr) {
        readyPicture->write(fullPath.toStdString());
        return true;
    } else {
        return false;
    }
}

