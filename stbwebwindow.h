#ifndef STBWEBWINDOW_H
#define STBWEBWINDOW_H


#include <QObject>

namespace yasem
{
class MagProfile;

class StbWebWindow : public QObject
{
    Q_OBJECT
public:
    explicit StbWebWindow(MagProfile *profile);


signals:

public slots:
    void close();

    QString windowId();
protected:
    MagProfile *profile;
};

}


#endif // STBWEBWINDOW_H