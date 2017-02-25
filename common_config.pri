CONFIG(debug, debug|release) {
    win32: TARGET = $$join(TARGET,,,d)
}

DESTDIR = $${PWD}/bin
