from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from tensorflow.python.framework import load_library
from tensorflow.python.platform import resource_loader

add_op_module = load_library.load_op_library(
    resource_loader.get_path_to_datafile('_add_op.so'))

print("Available symbols:", dir(add_op_module))

add_op = add_op_module.my_custom_add