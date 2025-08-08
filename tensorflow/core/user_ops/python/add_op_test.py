from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import numpy as np

from tensorflow.python.platform import test
from tensorflow.core.user_ops.python.add_op import add_op


class MyCustomAddOpTest(test.TestCase):
    def testAddOp(self):
        with self.test_session():
            self.assertAllClose(
                add_op([1, 2], 1), np.array([2, 3]))


if __name__ == '__main__':
    test.main()