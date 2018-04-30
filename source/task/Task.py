#!/usr/bin/env python
from abc import ABCMeta, abstractmethod
from .ffmpeg.Pass import *
from .ffmpeg.PassParameterBlock import *
from os import path


class FmmpegTask:
    def __init__(self, passes):
        self._passes = passes

    def get_passes(self):
        return self._passes

    def prepare(self):
        for p in self._passes:
            p.prepare()

    def process(self):
        for p in self._passes:
            p.process()

    def clean(self):
        for p in self._passes:
            p.clean()

    def __repr__(self):
        return '\n'.join(p.__repr__() for p in self._passes)


def create_compression_task(input_filepath, output_filepath, temp_dirpath):
    stab_detect_filepath = path.join(temp_dirpath, 'motion_vectors.trf')

    video_trim = ParameterBlockTrim()
    compression_settings = ParameterBlockCodecX264()
    quiet_setting = ParameterBlockQuiet()

    stab_detect_filter = VideoFilterStabDetect(stab_detect_filepath)
    stab_detect_graph = VideoFilterGraph([stab_detect_filter])
    stab_detect_pass = PassFfmpeg(input_filepath, [stab_detect_graph, video_trim, quiet_setting])

    stab_transform_filter = VideoFilterStabTransform(stab_detect_filepath)
    sharpen_filter = VideoFilterSharpen(5, 5, 0.8, 3, 3, 0.4)
    stab_transform_graph = VideoFilterGraph([stab_transform_filter, sharpen_filter])
    stab_transform_pass = PassFfmpeg(input_filepath, [stab_transform_graph, video_trim, compression_settings, quiet_setting], output_filepath)

    passes = [stab_detect_pass, stab_transform_pass]
    return FmmpegTask(passes)