#!/usr/bin/env python
from abc import ABCMeta, abstractmethod


class ParameterBlock(metaclass=ABCMeta):
    @abstractmethod
    def get_option_list(self):
        """ returns the list of parameters to inject into the command line """
        return

    def get_dependant_files(self,):
        """ returns the list of files needed to process this pass """
        return []

    def get_produced_files(self):
        """ returns the list of files produced by this pass """
        return []


class VideoFilterNode(metaclass=ABCMeta):
    def __init__(self, name, parameter_dict=None):
        self._name = name
        self._parameter_dict = parameter_dict

    def get_node_string(self):
        node_string = self._name
        if self._parameter_dict:
            node_string += '='
            node_string += ':'.join(k+'='+str(v) for k, v in self._parameter_dict.items())
        return node_string


class VideoFilterGraph(ParameterBlock):
    def __init__(self, video_filter_nodes=[]):
        self._graph = video_filter_nodes

    def get_graph_string(self):
        return ','.join(f.get_node_string() for f in self._graph)

    def get_option_list(self):
        graph_string = self.get_graph_string()
        return ['-vf', graph_string]


class VideoFilterStabDetect(VideoFilterNode):
    def __init__(self, vector_filepath, stepsize=6, shakiness=10, accuracy=15):
        detect_options = {
            'stepsize': stepsize,
            'shakiness': shakiness,
            'accuracy': accuracy,
            'result': vector_filepath
        }
        VideoFilterNode.__init__(self, 'vidstabdetect', detect_options)


class VideoFilterStabTransform(VideoFilterNode):
    def __init__(self, vector_filepath, smoothing=30, relative=1):
        transform_options = {
            'smoothing': smoothing,
            'relative': relative,
            'input': vector_filepath
        }
        VideoFilterNode.__init__(self, 'vidstabtransform', transform_options)


class VideoFilterSharpen(VideoFilterNode):
    def __init__(self, luma_msize_x, luma_msize_y, luma_amount, chroma_msize_x, chroma_msize_y, chroma_amount):
        unsharp_options = {
            'lx': luma_msize_x,
            'ly': luma_msize_y,
            'la': luma_amount,
            'cx': chroma_msize_x,
            'cy': chroma_msize_y,
            'ca': chroma_amount
        }
        VideoFilterNode.__init__(self, 'unsharp', unsharp_options)


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


class ParameterBlockCompression(ParameterBlock):
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
