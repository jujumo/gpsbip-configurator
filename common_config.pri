CONFIG(debug, debug|release) {
    win32: TARGET = $$join(TARGET,,,d)
}

CONFIG *= warn_on

DESTDIR = $${PWD}/bin
