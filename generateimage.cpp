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
        GenerateImage::placeText(image).write("/home/prise/testImages/"+ fileName);
        i++;
    }
}

Magick::Image GenerateImage::placeText(Magick::Image& modificate) {

    modificate.font("Celestina");
    modificate.fontPointsize(72);
    modificate.strokeColor("blue");
//    modificate.draw(Magick::DrawableStrokeColor("blue"));
//    modificate.draw(Magick::DrawableFillColor("blue"));
    modificate.draw(Magick::DrawableFont("Calestina",Magick::AnyStyle,800,Magick::NormalStretch));

    modificate.draw(Magick::DrawableText(1,100,"G"));
    modificate.draw(Magick::DrawableText(50,100,"o"));
    modificate.draw(Magick::DrawableText(100,100,"v"));
    modificate.draw(Magick::DrawableText(150,100,"n"));
    modificate.draw(Magick::DrawableText(200,100,"o"));

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

