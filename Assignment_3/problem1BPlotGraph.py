#!/usr/bin/env python3

import os
import pandas as pd
import matplotlib.pyplot as plt

colors = ['red', 'green', 'blue', 'purple', 'orange']
colorsOptimized = ['']

plt.subplot(1, 2, 1)

### Set your path to the folder containing the .csv files
PATH = 'dataDefaultGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file + ' ' + str(i))

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['AvgLoadTime'])

    ### Create line for every file
    plt.plot(df, c = colors[i], label='image ' + str(i))
    i += 1

### Set your path to the folder containing the .csv files
PATH = 'dataOptimizedGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file)
    ### Read .csv file and append to list
    df2 = pd.read_csv(PATH + file, usecols = ['AvgLoadTime'])

    ### Create line for every file
    plt.plot(df2, c = colors[i], linestyle='dashed', label='image ' + str(i) + ' optimized')
    i += 1

plt.xlabel('repeat count')
plt.ylabel('average load time in seconds')
plt.yscale('log')
plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))


#########################SECOND PLOT#############################

plt.subplot(1, 2, 2)

### Set your path to the folder containing the .csv files
PATH = 'dataDefaultGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i =  0
### Loop over all files
for file in fileNames:
    print(file)

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['GreyScaleTime'])

    ### Create line for every file
    plt.plot(df, c = colors[i], label='image ' + str(i))
    i += 1

### Set your path to the folder containing the .csv files
PATH = 'dataOptimizedGrayscale/' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)

### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if '.csv' in file]

i = 0
### Loop over all files
for file in fileNames:
    print(file)

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file, usecols = ['GreyScaleTime'])

    ### Create line for every file
    ax = plt.plot(df, c = colors[i], linestyle='dashed', label='image ' + str(i) + ' optimized')
    i += 1


### Generate the plot
plt.tight_layout(pad=3.0)
plt.xlabel('repeat count')
plt.ylabel('average greyscale time in seconds')
plt.yscale('log')

# plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))

plt.show()