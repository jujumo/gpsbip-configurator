#!/usr/bin/env python
from abc import ABCMeta, abstractmethod
from os.path import realpath
from ..path_tools import secure_path, prepare_writing_file


class ParameterIntegral(metaclass=ABCMeta):
    def __init__(self, name, value):
        self._name = name
        self._value = value

    def name(self):
        return self._name

    def value(self):
        return self._value

    def get_str_for_cmd_value(self):
        return str(self._value)

    def get_str_for_cmd(self):
        cmd = self._name
        if self._value:
            cmd += '=' + self.get_str_for_cmd_value()
        return cmd

    def __str__(self):
        return str(self._value)


class ParameterInt(ParameterIntegral):
    pass


class ParameterStr(ParameterIntegral):
    pass


class ParameterPath(ParameterIntegral):
    QUOTE = "\\'"

    def get_str_for_cmd_value(self):
        return self.QUOTE + realpath(self._value).replace('\\', '/') + self.QUOTE


