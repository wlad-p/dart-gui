# Dart-gui

Dart-gui is a DIY project which helps tracking points for playing Darts! The device can be screwed to the wall and the program starts when its plugged in. The device is based on a Raspberry Pi 4 and a touch display.

## Turn off Screensaver:
add to /etc/xdg/lxsession/LXDE-pi/autostart:

    @xset -dpms
    @xset s off


## Start program on boot:

    sudo chmod +x start.sh

create /etc/xdg/autostart/dart.desktop:

    [Desktop Entry]
    Type=Application
    Name=Dart
    Comment=Dart GUI Application
    NoDisplay=false
    Exec=/usr/bin/lxterminal -e /home/pi/dart-gui/start.sh
    NotShowIn=GNOME;KDE;XFCE;

Add to /etc/xdg/lxsession/LXDE-pi/autostart:

    @lxterminal -e /home/pi/dart-gui/start.sh
