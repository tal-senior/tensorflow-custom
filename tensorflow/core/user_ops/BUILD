# User ops.

load(
    "//tensorflow:tensorflow.bzl",
    "tf_copts",
)
load(
    "//tensorflow/core/platform:rules_cc.bzl",
    "cc_library",
)

package(
    # copybara:uncomment default_applicable_licenses = ["//tensorflow:license"],
    default_visibility = [
        "//tensorflow/core:__pkg__",
    ],
    licenses = ["notice"],
)

# One target for all user ops.
cc_library(
    name = "user_ops_op_lib",
    srcs = glob(["*.cc"]),
    copts = tf_copts(),
    linkstatic = 1,
    alwayslink = 1,
    visibility = ["//tensorflow/core:__pkg__"],
    deps = [
        "//tensorflow/core:framework",
        "//tensorflow/core:portable_gif_internal",
    ],
)

cc_binary(
    name = "python/_add_op.so",
    srcs = [
        "ops/add_op.cc",
        "kernels/add_kernel.cc",
    ],
    linkshared = 1,
    deps = [
        "//tensorflow/core:framework",
    ],
)

py_library(
    name = "add_ops_py",
    srcs = [
        "python/add_op.py",
    ],
    data = [
        ":python/_add_op.so",
    ],
    srcs_version = "PY2AND3",
)

py_test(
    name = "add_op_py_test",
    srcs = [
        "python/add_op_test.py",
    ],
    main = "python/add_op_test.py",
    deps = [
        ":add_ops_py",
        "//tensorflow:tensorflow_py",
    ],
    data = [
        ":python/_add_op.so",
    ],
    env = {
        "PYTHONPATH": "/Users/tal.senior/miniconda3/envs/tf-custom-env/lib/python3.11/site-packages/",
    },
    srcs_version = "PY2AND3",
)

py_library(
    name = "add_py",
    srcs = [
        "__init__.py",
        "python/__init__.py",
    ],
    deps = [
        ":add_ops_py",
    ],
    srcs_version = "PY2AND3",
)
