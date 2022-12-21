#!/usr/bin/env python3

import os
import pandas as pd
import matplotlib.pyplot as plt

colors = ['red', 'green', 'blue', 'purple', 'orange']

#########################PLOT #############################

### Set your path to the folder containing the .csv files
PATH = 'dataCachegrindDefaultGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file + ' ' + str(i))

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['Ir'])

    ### Create line for every file
    plt.plot(df, c = colors[i], linestyle='dashed', label='image ' + str(i))
    i += 1

### Set your path to the folder containing the .csv files
PATH = 'dataCachegrindOptimizedGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file)
    ### Read .csv file and append to list
    df2 = pd.read_csv(PATH + file, usecols = ['Ir'])

    ### Create line for every file
    plt.plot(df2, c = colors[i], label='image ' + str(i) + ' optimized')
    i += 1

plt.xlabel('repeat count')
plt.ylabel('No. instructions executed')
plt.yscale('log')
plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))

fig = plt.gcf()
fig.set_size_inches(4, 3)
fig.savefig('numberInstructionsGraph.png', bbox_inches='tight')
plt.show()