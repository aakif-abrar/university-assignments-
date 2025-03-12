#include <iostream>
class MediaFile {
protected:
    std::string filePath;
    double size;
public:
    MediaFile(std::string path, double s) : filePath(path), size(s) {}
    virtual void play() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
public:
    VisualMedia(std::string path, double s) : MediaFile(path, s) {}
};

class AudioMedia : virtual public MediaFile {
public:
    AudioMedia(std::string path, double s) : MediaFile(path, s) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(std::string path, double s) : MediaFile(path, s), VisualMedia(path, s), AudioMedia(path, s) {}
    void play() override { std::cout << "Playing video file: " << filePath << std::endl; }
};

int main() {
    MediaFile *video = new VideoFile("movie.mp4", 700);
    video->play();
    delete video;
    return 0;
}