#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
class QNetworkAccessManager;
class QNetworkReply;
class Downloader :public QObject
{
    Q_OBJECT
    QNetworkAccessManager* m_pnarn;
public:
    Downloader(QObject* pobj = nullptr);
    void download(const QUrl&);
signals:
    void done(const QString &);
    void error();
private slots:
void slotFinished(QNetworkReply*);
};
#endif // DOWNLOADER_H
