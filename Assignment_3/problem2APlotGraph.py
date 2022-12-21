#!/usr/bin/env python3

import os
import pandas as pd
import matplotlib
matplotlib.use('tkagg')
import matplotlib.pyplot as plt

colors = ['red', 'green', 'blue', 'purple', 'orange']

#########################PLOT #############################

plt.subplot(1, 3, 1)

### Set your path to the folder containing the .csv files
PATH = 'dataMatrixMultiplication/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file + ' ' + str(i))

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['blocksize','llrefs','llmisses'])

    ### Create line for every file
    ax = plt.plot(df['blocksize'], df['llrefs'], c = colors[i], label='With loop blocking')
    plt.hlines(y=1076103904,xmin=0, xmax=600, label='Without loop blocking' )
    i += 1

plt.xlabel('block size')
plt.ylabel('LL references')
plt.yscale('log')


#########################PLOT 2#############################

plt.subplot(1, 3, 2)
### Set your path to the folder containing the .csv files
PATH = 'dataMatrixMultiplication/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file + ' ' + str(i))

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['blocksize','llrefs','llmisses'])

    ### Create line for every file
    plt.plot(df['blocksize'], df['llmisses'], c = colors[i], label='With loop blocking' )
    plt.hlines(y=1076043621,xmin=0, xmax=600, label='Without loop blocking' )
    i += 1

plt.xlabel('block size')
plt.ylabel('LL misses')
# plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))
plt.tight_layout(pad=1.0)
plt.yscale('log')

#########################PLOT 3#############################

plt.subplot(1, 3, 3)
### Set your path to the folder containing the .csv files
PATH = 'dataMatrixMultiplication/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file + ' ' + str(i))

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['blocksize','llrefs','llmisses'])

    ### Create line for every file
    plt.plot(df['blocksize'], ((df['llmisses'] / df['llrefs'])), c = colors[i], label='With loop blocking' )
    plt.hlines(y=0.99994398031,xmin=0, xmax=600, label='Without loop blocking' )
    i += 1

plt.xlabel('block size')
plt.ylabel('LL miss rate')
plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))
plt.tight_layout(pad=1.0)
plt.yscale('log')



fig = plt.gcf()
fig.set_size_inches(4, 3)
fig.savefig('missRateGraph.png', bbox_inches='tight')
plt.show()