#ifndef JSONCALLS_H
#define JSONCALLS_H
#include <QApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

QJsonDocument getDirJSON(QString path)
{
    qDebug() << "MOIST\n";
    QNetworkAccessManager m_manager;
    QNetworkRequest request = QNetworkRequest(QUrl("localhost:8081/api/getDir?path="+path));
    QNetworkReply* reply = m_manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        QString ReplyText = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
        QJsonObject obj = doc.object();
        QJsonValue value = obj.value(QString("filename"));
        qDebug() << value << '\n';
    });
    return QJsonDocument();
}


#endif // JSONCALLS_H
