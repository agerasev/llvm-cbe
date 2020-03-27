#!/usr/bin/env python3

import numpy as np
import pyopencl as cl
from pyopencl import cltypes

from test.opencl import Mem, run_kernel
from test.cases.tester import Tester as BaseTester


class Tester(BaseTester):
    def __init__(self, *args):
        super().__init__(*args, src="source.cl")

    def run(self, src, **kws):
        m, n = 8, 64
        a = np.zeros(n, dtype=cltypes.int)
        b = np.zeros(n, dtype=cltypes.float)
        run_kernel(self.ctx, src, (n,), *[Mem(x) for x in (a, b)])
        return (a, b)
