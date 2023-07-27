import subprocess as sp
import pandas as pd
import matplotlib.pyplot as plt
import os
import sys

if os.path.exists("sortperf.csv"):
    os.remove("sortperf.csv")

sp.run(["g++", "-o", "main", "src/main.cpp", "-Iinclude"])


def show_graph():
    with open("sortperf.csv") as file:
        data = pd.read_csv(file)
    plt.title("Sorting Algorithm Benchmark")
    algos = ["SelectionSort", "InsertionSort", "BubbleSort", "MergeSort", "QuickSort"]
    n = [i for i in range(1, int(sys.argv[1])+1)]
    for algo in algos:
        plt.plot(n, data[algo])
    plt.legend(algos)
    plt.show()


if os.path.exists("main"):
    sp.run(["./main", sys.argv[1]])
    show_graph()
else:
    print("failed to compile c++ executable.")
