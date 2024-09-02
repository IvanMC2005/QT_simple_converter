#include <QApplication>
#include <QString>
#include "downloader.h"
#include "downloaderGui.h"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    DownloaderGui down;
    down.resize(300, 300);
    down.show();
    return app.exec();
}
