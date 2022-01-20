import numpy as np


__all__ = ["Gold"]

from scripis.LFSR import LFSR


class Gold:

    def __init__(self, first_polynomial, first_initial_conditions,
                 second_polynomial, second_initial_conditions,
                 samples_per_frame=None, index=0, matlab=False, debug=False):
        self.mls1 = LFSR(first_polynomial, first_initial_conditions, samples_per_frame=samples_per_frame, matlab=matlab)
        self.mls2 = LFSR(second_polynomial, second_initial_conditions, samples_per_frame=samples_per_frame, matlab=matlab)
        self.index = index
        self.cycled_through = False
        self.debug = debug

    def step(self):
        u = self.mls1.step()
        v = np.roll(self.mls2.step(), -self.index).tolist()
        g = (np.logical_xor(u, v) * 1).tolist()
        if self.debug:
            print("u = {}\nv = {}\nG = {}".format(u, v, g))
        if self.mls1.cycled_through or self.mls2.cycled_through:
            self.cycled_through = True
        return g

    def reset(self):
        self.mls1.reset()
        self.mls2.reset()

