#!/usr/bin/env python

import unittest
from os.path import realpath
from path_tools import create_filepath


class TestCreateFilepath(unittest.TestCase):
    def test_identity(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        dest_filepath = create_filepath(original_filepath)
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(original_filepath, dest_filepath)

    def test_prefix(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        expected_filepath = realpath('E:/GoPro/2018-04-18/prefix_GH010926.MP4')
        dest_filepath = create_filepath(original_filepath, prefix='prefix_')
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(expected_filepath, dest_filepath)

    def test_suffix(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        expected_filepath = realpath('E:/GoPro/2018-04-18/GH010926_suffix.MP4')
        dest_filepath = create_filepath(original_filepath, suffix='_suffix')
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(expected_filepath, dest_filepath)

    def test_ext(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        expected_filepath = realpath('E:/GoPro/2018-04-18/GH010926.mp3')
        dest_filepath = create_filepath(original_filepath, ext='.mp3')
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(expected_filepath, dest_filepath)

    def test_another_dir(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        expected_filepath = realpath('C:/temp/GH010926.MP4')
        dest_filepath = create_filepath(original_filepath, dest_dirpath='C:/temp')
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(expected_filepath, dest_filepath)

    def test_another_relative_dir(self):
        original_filepath = realpath('E:/GoPro/2018-04-18/GH010926.MP4')
        expected_filepath = realpath('C:/temp/2018-04-18/GH010926.MP4')
        dest_filepath = create_filepath(original_filepath, original_rootpath='E:/GoPro/', dest_dirpath='C:/temp')
        dest_filepath = realpath(dest_filepath)
        self.assertEqual(expected_filepath, dest_filepath)


if __name__ == '__main__':
    unittest.main()
