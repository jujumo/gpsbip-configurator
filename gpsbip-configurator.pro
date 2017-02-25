TEMPLATE = subdirs

SUBDIRS += \
    libgpsbip \
    gpsbip-configurator \
    tests

gpsbip-configurator.depends = libgpsbip
tests.depends = libgpsbip

