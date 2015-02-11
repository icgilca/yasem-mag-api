#include "stbwebwindow.h"
#include "macros.h"
#include "magprofile.h"
#include "browserplugin.h"
#include "abstractwebpage.h"

using namespace yasem;

StbWebWindow::StbWebWindow(MagProfile *profile, AbstractWebPage* page)
{
    this->profile = profile;
    this->m_page = page;
}

void StbWebWindow::close()
{
    STUB();

    m_page->close();

    //parent->page()->close();
}

QString StbWebWindow::windowId()
{
    STUB();
    return "---------";
}
