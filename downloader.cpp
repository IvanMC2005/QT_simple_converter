#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QRegExp>
#include "downloader.h"
#include "downloaderGui.h"
Downloader::Downloader(QObject* pobj): QObject(pobj)
{
    m_pnarn = new QNetworkAccessManager(this);
    connect(m_pnarn, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slotFinished(QNetworkReply*)));
}
void Downloader::download(const QUrl& url)
{
    QNetworkRequest request(url);
    m_pnarn->get(request);
}
void Downloader::slotFinished(QNetworkReply* pnr)
{
    if (pnr->error() != QNetworkReply::NoError)
    {
        emit error();
    }
    else
    {
        emit done(QString(pnr->readAll()));
    }
    pnr->deleteLater();
}
