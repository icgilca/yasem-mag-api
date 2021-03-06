#ifndef STBEVENT_H
#define STBEVENT_H

#include <QObject>

namespace yasem
{
class MagProfile;

namespace SDK {
class WebPage;
}

class StbEvent : public QObject
{
    Q_OBJECT
    Q_ENUMS(Events)
public:
    explicit StbEvent(MagProfile *m_profile, SDK::WebPage* page);
    virtual ~StbEvent();

    Q_PROPERTY(int event READ getEventCode)

    enum Events {
        STB_EVENT_NO_ERROR = 0,
        /**
         * The player reached the end of the media content or detected a discontinuity of the stream.
         * */
        STB_EVENT_EOF = 1,
        /**
         * Information on audio and video tracks of the media content is received. It's now possible to call gSTB.GetAudioPIDs etc.
         * */
        STB_EVENT_GOT_INFO = 2,
        /**
         * Video and/or audio playback has begun.
         * */
        STB_EVENT_PLAY_START = 4,
        /**
         * Error when opening the content: content not found on the server or connection with the server was rejected.
         * */
        STB_EVENT_PLAY_ERROR = 5,
        /**
         * Detected DualMono AC-3 sound.
         * */
        STB_EVENT_DUAL_MONO_AC3 = 6,
        /**
         * The decoder has received info about the content and started to play. It's now possible to call gSTB.GetVideoInfo.
         * */
        STB_EVENT_GOT_VIDEO_INFO = 7,
        /**
         * Error occurred while loading external subtitles.
         * */
        STB_EVENT_SUBTITLE_LOAD_ERROR = 8,
        /**
         * Found new teletext subtitles in stream.
         * */
        STB_EVENT_TELETEXT_FOUND = 9,
        /**
         * HDMI device has been connected.
         * */
        STB_EVENT_HDMI_DEVICE_CONNECTED = 32,
        /**
         * HDMI device has been disconnected.
         * */
        STB_EVENT_HDMI_DEVICE_DISCONNECTED = 33,
        /**
         * Recording task has been finished successfully. See Appendix 13. JavaScript API for PVR subsystem.
         * */
        STB_EVENT_RECORDING_INISHED_SUCCESSFULLY = 34,
        /**
         * Recording task has been finished with error. See Appendix 13. JavaScript API for PVR subsystem.
         * */
        STB_EVENT_RECORDING_FINISHED_WITH_ERROR = 35,
        /**
         * Scanning DVB Channel in progress.
         * */
        STB_EVENT_DVB_SCAN_PROGRESS = 40,
        /**
         * Scanning DVB Channel found.
         * */
        STB_EVENT_DVB_SCAN_FOUND = 41,
        /**
         * DVB Channel EPG update.
         * */
        STB_EVENT_DVB_EPG_UPDATE = 42,
        /**
         * DVB antenna power off.
         * */
        STB_EVENT_DVB_ANTENNA_POWER_OFF = 43,
        /**
         * When playing RTP-stream the numbering of RTP-packets was broken.
         * */
        STB_EVENT_RTP_PACKETS_BROKEN = 129
    };

signals:

public slots:

    void sendEvent(int m_event_code);
    void onEvent(int m_event_code, const QString& data);
    void initEvents();
    void onBroadcastMessage(int windowId, const QString& message, const QString& data);
    void onInternetStateChange(bool status);
    void onLanguageChange();
    void onMediaAvailable();
    void onMessage(int windowId, const QString& message, const QString& data);
    void onMount(int state);
    void onNetworkStateChange(bool status);
    void onScreenSaverActivation(bool mode);
    void onScreenSaverOverride();
    void onWebBrowserProgress(int progress);
    void onWindowActivated();

protected:
    MagProfile *m_profile;
    int getEventCode();
    int m_event_code;
    SDK::WebPage* m_page;

    QString getEventName(Events event);
};

}

#endif // STBEVENT_H
