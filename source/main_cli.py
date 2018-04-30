#!/usr/bin/env python3

__author__ = 'jumo'

import argparse
import logging
import os
from os.path import join, exists, isdir, splitext, abspath, dirname, basename
from task.path_tools import is_filepath_ends_with, create_filepath
from task.Task import create_compression_task


VIDEO_EXT_LIST = [".MP4", ".MOV", ".AVI", ".3GP", ".VOB", ".MTS", ".WMV", ".FLV", '.MKV']


def populate_videos(input_path_list, ext_list=VIDEO_EXT_LIST):
    error_count = 0
    movie_file_list = []
    for input_path in input_path_list:
        logging.debug('populating {}'.format(input_path))
        if not exists(input_path):
            logging.error('ERROR input path is not valid : ' + input_path)
            error_count += 1

        elif isdir(input_path):
            logging.info('scanning directory {}'.format(input_path))
            file_list = (join(r, f) for r, d, fs in os.walk(input_path) for f in fs)
            input_files = (file for file in file_list if splitext(file)[1].upper() in ext_list)
            movie_file_list += input_files

        elif os.path.isfile(input_path) and is_filepath_ends_with(input_path, ext_list):
            movie_file_list += [input_path]

        else:
            logging.error("ERROR is not a video file nor a dir : " + input_path)
            error_count += 1

    return movie_file_list


def proceed(input_path_list, output_dirpath):
    movie_file_list = populate_videos(input_path_list)
    logging.debug('listed {} movies to be converted.'.format(len(movie_file_list)))
    task_list = []
    for input_filepath in movie_file_list:
        output_filepath = create_filepath(input_filepath, dest_dirpath=output_dirpath, suffix='_x264', ext='.mp4')
        temp_dirpath = splitext(output_filepath)[0]
        task = create_compression_task(input_filepath, output_filepath, temp_dirpath)
        task_list += [task]

    for task in task_list:
        task.prepare()
        task.process()


def main():
    try:
        parser = argparse.ArgumentParser(description='Description of the program.')
        parser.add_argument('-v', '--verbose', action='store_true', help='verbose message')
        parser.add_argument('-i', '--input', required=True, nargs='+', help='list of input files or directory')
        parser.add_argument('-o', '--output', default=None, help='output directory')
        args = parser.parse_args()

        if args.verbose:
            logging.getLogger().setLevel(logging.INFO)
        if __debug__:
            logging.getLogger().setLevel(logging.DEBUG)

        proceed(args.input, args.output)

    except Exception as e:
        logging.critical(e)
        if __debug__:
            raise


if __name__ == '__main__':
    main()