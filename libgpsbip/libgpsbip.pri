INCLUDEPATH *= $$absolute_path(.)
LIBS *= -L$${DESTDIR}

CONFIG(debug, debug|release) {
    LIBS *= -llibgpsbipd
     PRE_TARGETDEPS *= $${DESTDIR}/libgpsbipd.lib
}
CONFIG(release, release|debug) {
    LIBS *= -llibgpsbip
     PRE_TARGETDEPS *= $${DESTDIR}/libgpsbip.lib
}
