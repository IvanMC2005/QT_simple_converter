#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "downloaderGui.h"
#include "downloader.h"
DownloaderGui::DownloaderGui(QMainWindow * ui): QMainWindow(ui)
{
    m_pdl = new Downloader(this);
    connect(m_pdl, SIGNAL(done(const QString &)), this, SLOT(slotDone(const QString &)));
    m_pdl->download(QUrl("https://cbr.ru"));
}
void DownloaderGui::slotDone(const QString & buff)
{
    double current_rate[3];
    current_rate[0] = current_rate[1] = current_rate[2] = 0;
    QRegExp icon("<div class=\"col-md-2 col-xs-9 _right mono-num\">.*<div class=\"col-md-2 col-xs-9 _right mono-num\">(\\d*\\,\\d+) ");
    icon.setMinimal(true);
    int i = 0, j = 0;
    while( (i = icon.indexIn(buff, i)) != -1 )
    {
        i += icon.matchedLength();
        current_rate[j++] = icon.cap(1).replace(",", ".").toDouble();
    }
}
void DownloaderGui::slotError()
{
    QMessageBox::critical(0, tr("Error"), tr("An error while download is occured"));
}
