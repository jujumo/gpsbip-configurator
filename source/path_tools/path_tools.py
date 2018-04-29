#!/usr/bin/env python

import os
import logging
from os.path import basename, join, splitext, commonpath, dirname


def is_filepath_ends_with(filename, ext_list):
    return os.path.splitext(filename)[1].upper() in [ext.upper() for ext in ext_list]


# get_files_with_ext return the list of couples (path, filename)
# of all files with given extension in the directory and all its subdirs.
def get_files_with_ext(input_path, ext_list):
    file_list = []
    tree = os.walk(input_path)
    for (dirpath, dirs, files) in tree:
        file_list += [[dirpath, n] for n in files if is_filepath_ends_with(n, ext_list)]
    return file_list


def which(binary_name, local_path=None):
    possible_dirpath_list = os.getenv('PATH').split(os.path.pathsep)
    if local_path:
        # append local path to use system program in priority
        possible_dirpath_list.append(local_path)

    # make sure there is the ending .exe for windows
    if os.name == 'nt' and not splitext(binary_name)[1]:  # windows
        binary_name += '.exe'

    # try them all
    possible_filepath_list = (join(d, binary_name) for d in possible_dirpath_list)
    for attempting_path in possible_filepath_list:
        logging.debug('attempting {}'.format(attempting_path))
        if os.path.exists(attempting_path) and os.access(attempting_path, os.X_OK):
            return attempting_path

    error_message = '{} not found'.format(binary_name)
    logging.error(error_message)
    return None


def create_filepath(original_filepath,
                    original_rootpath=None,
                    dest_dirpath=None,
                    prefix=None,
                    suffix=None,
                    ext=None):
    # handle filename
    original_filename = basename(original_filepath)
    splited_filename = splitext(original_filename)
    dest_filename = ''
    if prefix:
        dest_filename += prefix
    dest_filename += splited_filename[0]
    if suffix:
        dest_filename += suffix
    if ext:
        dest_filename += ext
    else:
        dest_filename += splited_filename[1]

    # handle path
    original_dirpath = dirname(original_filepath)
    if dest_dirpath and original_rootpath:
        common_root = commonpath([original_rootpath, original_dirpath])
        relative_path = original_dirpath[len(common_root)+1:]
    else:
        relative_path = ''

    if not dest_dirpath:
        dest_dirpath = original_dirpath
    return join(dest_dirpath, relative_path, dest_filename)

