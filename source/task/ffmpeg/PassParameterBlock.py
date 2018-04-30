#!/usr/bin/env python
from abc import ABCMeta, abstractmethod
from os.path import realpath
from ..path_tools import secure_path, prepare_writing_file
from .PassParameterIntegral import *


class ParameterBlock(metaclass=ABCMeta):
    @abstractmethod
    def get_option_list(self):
        """ returns the list of parameters to inject into the command line """
        return

    def get_dependant_files(self):
        """ returns the list of files needed to process this pass """
        return []

    def get_produced_files(self):
        """ returns the list of files produced by this pass """
        return []

    def prepare(self):
        """ prepare requirement for command line (like creating directories """
        pass


class VideoFilterNode(metaclass=ABCMeta):
    def __init__(self, name, settings=None):
        self._name = name
        self._settings = settings

    def get_str_for_cmd(self):
        node_string = self._name
        setting_string_list = (s.get_str_for_cmd() for s in self._settings)
        if setting_string_list:
            node_string += '=' + ':'.join(setting_string_list)
        return node_string

    def get_dependant_files(self):
        """ returns the list of files needed to process this pass """
        return []

    def get_produced_files(self):
        """ returns the list of files produced by this pass """
        return []


class VideoFilterStabDetect(VideoFilterNode):
    def __init__(self, vector_filepath, stepsize=6, shakiness=10, accuracy=15):
        self._settings = [
            ParameterInt('stepsize', stepsize),
            ParameterInt('shakiness', shakiness),
            ParameterInt('accuracy', accuracy),
            ParameterPath('result', vector_filepath)
        ]
        self._result = vector_filepath
        VideoFilterNode.__init__(self, 'vidstabdetect', self._settings)

    def get_produced_files(self):
        return [self._result]


class VideoFilterStabTransform(VideoFilterNode):
    def __init__(self, vector_filepath, smoothing=30, relative=1):
        self._settings = [
            ParameterInt('smoothing', smoothing),
            ParameterInt('relative', relative),
            ParameterPath('input', vector_filepath)
        ]
        self._input = vector_filepath
        VideoFilterNode.__init__(self, 'vidstabtransform', self._settings)

    def get_dependant_files(self):
        return [self._input]


class VideoFilterSharpen(VideoFilterNode):
    def __init__(self, luma_msize_x, luma_msize_y, luma_amount, chroma_msize_x, chroma_msize_y, chroma_amount):
        self._settings = [
            ParameterInt('lx', luma_msize_x),
            ParameterInt('ly', luma_msize_y),
            ParameterInt('la', luma_amount),
            ParameterInt('cx', chroma_msize_x),
            ParameterInt('cy', chroma_msize_y),
            ParameterInt('ca', chroma_amount)
        ]
        VideoFilterNode.__init__(self, 'unsharp', self._settings)


class VideoFilterGraph(ParameterBlock):
    def __init__(self, video_filter_nodes=[]):
        self._graph = video_filter_nodes

    def get_str_for_cmd(self):
        return ','.join(f.get_str_for_cmd() for f in self._graph)

    def get_option_list(self):
        graph_string = self.get_str_for_cmd()
        return ['-vf', graph_string]

    def get_produced_files(self):
        produced_files = []
        for node in self._graph:
            produced_files += node.get_produced_files()
        return produced_files


class ParameterBlockTrim(ParameterBlock):
    def __init__(self, start=None, duration=None):
        self._start = start
        self._duration = duration

    def get_option_list(self):
        cmd = []
        if self._start:
            cmd += ['-ss', str(self._start)]
        if self._duration:
            cmd += ['-t', str(self._duration)]
        return cmd


class ParameterBlockCodec(ParameterBlock):
    PRESET_DEFAULT = 'slow'

    def __init__(self):
        self._preset = self.PRESET_DEFAULT

    def get_option_list(self):
        return [
            '-vcodec', 'libx264',
            '-profile:v', 'main',
            '-level:v', '5.2',
            '-preset', self._preset
        ]


class ParameterBlockCodecX264(ParameterBlock):
    def get_option_list(self):
        return [
            '-vcodec', 'libx264',
            '-profile:v', 'main',
            '-level:v', '5.2',
            '-preset', 'slow'
        ]


class ParameterBlockQuiet(ParameterBlock):
    def get_option_list(self):
        return [
            '-loglevel', 'info',
            '-hide_banner'
        ]
