#include "databasehandler.h"

#include <QNetworkRequest>
#include <QDebug>
#include <QVariantMap> //1
//3
#include <QJsonDocument>

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject{parent}
{
    m_networkManager = new QNetworkAccessManager(this);
    //2
    QVariantMap newPet;
    newPet["Type"] = "Elephant";
    newPet["Food"] = "Dumbo";
    newPet["Name"] = "Peanuts";

    //4 Create new json file
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newPet);
    //5 Create new network request called newPetrequest

    //QNetworkRequest newPetrequest(QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets.json"));

    //PUT REQUEST - Step 01 - target by specifying the json
    QNetworkRequest newPetrequest(QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets/Two.json"));

    //6 Set a header
    newPetrequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    //7 Perform a POST Request
    //m_networkManager->post(newPetrequest,jsonDoc.toJson());

    //PUT REQUEST - STEP 02 - Put instead of Post
        m_networkManager->put(newPetrequest,jsonDoc.toJson());
}

DatabaseHandler::~DatabaseHandler()
{
    m_networkManager -> deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
    qDebug()<<m_networkReply->readAll();
}

