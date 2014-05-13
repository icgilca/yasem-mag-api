#ifndef STBWINDOWMGR_H
#define STBWINDOWMGR_H

#include <QObject>

namespace yasem
{
class GuiPlugin;
class MagProfile;

class StbWindowMgr : public QObject
{
    Q_OBJECT
public:
    explicit StbWindowMgr(MagProfile *profile);

signals:

public slots:
    void openWebFavorites(const QString &url, const QString &params);
    void openWebFavorites(const QString &url, int params);
    void openDownloadManager(const QString &url);
    void setBookmarkImplUrl(const QString &url);

    void showBrowserBookmarks();
    void SetVirtualKeyboardCoord(const QString &coord);
    void setVirtualKeyboardInitAttr(const QString &options);
    void setWebFaceInitAttr(const QString &options);
    QString getCurrWebUrl();
    void initWebWindow(const QString &url);
    void resizeWebWindow(int x, int y, int width, int height);
    void raiseWebWindow();
    void raiseWebFaceWindow();
protected:
    GuiPlugin* gui;
    MagProfile *profile;
    QString localPortalUrl;

    QString transformInnerPortalPathToLocal(QString innerPortalPath);
    QString openNewWindow(const QString &url, const QString &params, const QString &name);

};
}
#endif // STBWINDOWMGR_H