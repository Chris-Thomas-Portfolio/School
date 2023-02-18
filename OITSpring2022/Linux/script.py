#!/usr/bin/python
import sys
import subprocess
import time

file1 = open("README.txt", "w")
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 1000'])
end_time = time.time()
L = ["Linear sorted 1000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 2000'])
end_time = time.time()
L = ["Linear sorted 2000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 3000'])
end_time = time.time()
L = ["Linear sorted 3000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 4000'])
end_time = time.time()
L = ["Linear sorted 4000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 5000'])
end_time = time.time()
L = ["Linear sorted 5000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 6000'])
end_time = time.time()
L = ["Linear sorted 6000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
start_time = time.time()
subprocess.run(['filesort', '-i', 'word.list', '-o', 'sort.dat', '-n 7000'])
end_time = time.time()
L = ["Linear sorted 7000 items in ", str(end_time - start_time), " seconds\n"]
file1.writelines(L)
file1.close()
