#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QObject>
/*
1. Add QT += network in .pro file then run qmake
2. Add new C++ class file
3. Base Class QObject
4. Name 'DatabaseHandler'
5. Go to header file
6. #include <QNetworkAccessManager>
7. #include <QNetworkReply>







*/

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);

    //12. Add a destructor here for good coding practice ~DatabaseHandler();
    //13. Right Click > refactor > add definition to cpp
    ~DatabaseHandler();

public://19
    void networkReplyReadyRead();//20
    //21 Refactor

signals:

//8. Add private members after signals line
/*Step 9.
 * Add these
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;

*/

    //10. go to .cpp file
private:
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;

};

#endif // DATABASEHANDLER_H
