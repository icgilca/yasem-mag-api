#ifndef TIMESHIFT_H
#define TIMESHIFT_H


#include <QObject>

namespace yasem
{
class MagProfile;
class AbstractWebPage;

class TimeShift : public QObject
{
    Q_OBJECT
public:
    TimeShift(MagProfile *profile, AbstractWebPage* page);
signals:

public slots:
    void SetSlidingMode(bool enable);

    void SetTimeShiftFolder(const QString &folderName);
    void SetMaxDuration(qint64 maxDuration);
protected:
    MagProfile *profile;
    AbstractWebPage* m_page;
};

}

#endif // TIMESHIFT_H
