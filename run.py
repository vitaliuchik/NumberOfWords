import subprocess
import sys


def read_file(filename):
    file = open(filename)
    lines = file.readlines()
    file.close()
    return lines


def read_configuration(config_file="config.dat"):
    lines = read_file(config_file)
    config = dict()

    for line in lines:
        line = line[:-1].split('=') if line[-1] == '\n' else line.split('=')
        config[line[0]] = line[1][1:-1] if line[1][0] == '\"' else line[1]

    return config


def run_cpp(nums, config):
    coinside, compare = True, True
    min_time = [float("inf") for _ in range(3)]
    prev_fileA, prev_fileN = [], []

    # subprocess.call('cmake -S . -B build -G "Unix Makefiles"')
    # subprocess.call('cmake --build build') 

    for i in range(nums):
        curr_time = subprocess.check_output("./cmake-build-debug/NumberOfWords")
        # curr_time = "Loading: 1.234\nAnalyzing: 50.1\nTotal: 60.23\n"
        curr_time = [float(el.split(': ')[1]) for el in curr_time.split('\n')[:-1]]
        min_time = [min(last, curr) for last, curr in zip(min_time, curr_time)]
        
        print(config)
        curr_fileA = read_file(config['out_by_a'])
        curr_fileN = read_file(config['out_by_n'])
        if i > 0:
            compare = curr_fileA == prev_fileA and curr_fileN == prev_fileN
        if compare: 
            prev_fileA, prev_fileN = curr_fileA, curr_fileN
        else:
            coinside, compare = False, True

    return tuple(min_time), coinside


if __name__ == '__main__':

    num_attr = len(sys.argv) - 1
    if num_attr != 1 and num_attr != 2:
        raise Exception("Wrong number of arguments!")

    config = read_configuration() if num_attr == 1 else read_configuration(sys.argv[2])
    (loading, analizing, total), coinside = run_cpp(int(sys.argv[1]), config)

    print("Running {} times.\n".format(sys.argv[1]))
    print("Results coinside.\n") if coinside else print("Results don't coinside.")
    print("Min loading time :", loading)
    print("Min analizing time :", analizing)
    print("Min total time :", total)
