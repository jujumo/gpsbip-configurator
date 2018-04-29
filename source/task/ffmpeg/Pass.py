#!/usr/bin/env python
from abc import ABCMeta, abstractmethod


class Pass(metaclass=ABCMeta):
    @abstractmethod
    def get_dependant_files(self,):
        """ returns the list of files needed to process this pass """
        return

    @abstractmethod
    def get_produced_files(self):
        """ returns the list of files produced by this pass """
        return

    @abstractmethod
    def get_command_line(self):
        """ returns the command line """
        return

    def __repr__(self):
        cmd = self.get_command_line()
        return ' '.join(str(i) for i in cmd)


class PassFfmpeg(Pass):
    def __init__(self, input_filepath, ffmpeg_params=[], output_filepath=None):
        self._input_filepath = input_filepath
        self._output_filepath = output_filepath
        self._parameters = ffmpeg_params

    def get_dependant_files(self):
        dependant_files = [self._input_filepath]
        return dependant_files

    def get_produced_files(self):
        produced_files = []
        if self._output_filepath:
            produced_files = [self._output_filepath]
        for pb in self._parameters:
            pb_out = pb.produced_files()
            if pb_out:
                produced_files += pb_out
        return produced_files

    def get_command_line(self):
        cmd = [
            'ffmpeg',
            '-i', self._input_filepath
            ]

        for pb in self._parameters:
            cmd += pb.get_option_list()

        # do not output actual video
        if self._output_filepath:
            cmd += ['-y', self._output_filepath]
        else:
            cmd += ['-f', 'null', '-']

        return cmd
