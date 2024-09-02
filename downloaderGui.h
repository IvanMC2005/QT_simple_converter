#ifndef DOWNLOADERGUI_H
#define DOWNLOADERGUI_H
#pragma once
#include "downloader.h"
#include <QMainWindow>
#include <QUrl>
class Downloader;
class DownloaderGui : public QMainWindow
{
    Q_OBJECT
private:
    Downloader *m_pdl;
public:
    DownloaderGui(QMainWindow * ui = nullptr);
private slots:
    void slotError();
    void slotDone(const QString &);
};
#endif // DOWNLOADERGUI_H
