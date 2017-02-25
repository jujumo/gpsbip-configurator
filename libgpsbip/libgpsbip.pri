INCLUDEPATH += $$absolute_path(./libgpsbip)
LIBS += -L$${DESTDIR}

CONFIG(debug, debug|release) {
    LIBS += -llibgpsbipd
}
CONFIG(release, release|debug) {
    LIBS += -llibgpsbip
}
