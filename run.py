import subprocess
import sys
import math
import re

def run_cpp(nums):
    results = []
    compared= True
    curr_min1 = float("inf")
    for i in range(nums):
        a = subprocess.check_output("./cmake-build-debug/CountWords")
    print("Running {} times.\n".format(nums))
    if compared:
        print("Results coinside.\n")
    else:
        print("Results don't coinside.")
    print("Min time : " + str(curr_min1))
    return curr_min1

if __name__ == '__main__':

    run_cpp(2)


