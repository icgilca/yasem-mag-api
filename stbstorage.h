#ifndef STBSTORAGE_H
#define STBSTORAGE_H

#include "enums.h"
#include "macros.h"

#include <QObject>
#include <QHash>

namespace yasem
{
class MagProfile;
class MediaPlayerPlugin;

class StbStorage : public QObject
{
    Q_OBJECT
public:
    explicit StbStorage(MagProfile *profile);

signals:

public slots:

    void removeItem(const QString &name);
    void setItem(const QString &name, const QString &value);
    QString getItem(const QString &name);
protected:
    MagProfile *profile;
    QHash<QString, QString> items;

};

}

#endif // STBSTORAGE_H
