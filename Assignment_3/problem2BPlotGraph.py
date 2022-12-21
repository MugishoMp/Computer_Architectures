#!/usr/bin/env python3

import os
import pandas as pd
import matplotlib
matplotlib.use('tkagg')
import matplotlib.pyplot as plt

colors = ['red', 'green', 'blue', 'purple', 'orange']

#########################PLOT #############################

plt.subplot(1, 3, 1)

### Read .csv file and append to list
df = pd.read_csv('matrixMultiplicationExecutionTimes/512.csv', usecols = ['blocksize','executiontimeMsec','baseTimeMsec'])

### Create line for executiontime
plt.plot(df['blocksize'], df['executiontimeMsec'], c = 'red',  label='With loop blocking' )
### Create line for basetime
plt.plot(df['blocksize'], df['baseTimeMsec'], c = 'red', linestyle='dashed', label='Without loop blocking' )

plt.xlabel('block size')
plt.ylabel('Execution time in milliseconds')
# plt.yscale('log')
plt.title('N = 512')


#########################PLOT 2#############################


plt.subplot(1, 3, 2)

### Read .csv file and append to list
df = pd.read_csv('matrixMultiplicationExecutionTimes/1024.csv', usecols = ['blocksize','executiontimeMsec','baseTimeMsec'])

### Create line for executiontime
plt.plot(df['blocksize'], df['executiontimeMsec'], c = 'red',  label='With loop blocking' )
### Create line for basetime
plt.plot(df['blocksize'], df['baseTimeMsec'], c = 'red', linestyle='dashed', label='Without loop blocking' )

plt.xlabel('block size')
plt.ylabel('Execution time in milliseconds')
# plt.yscale('log')
plt.title('N = 1024')

# #########################PLOT 3#############################


plt.subplot(1, 3, 3)

### Read .csv file and append to list
df = pd.read_csv('matrixMultiplicationExecutionTimes/2048.csv', usecols = ['blocksize','executiontimeMsec','baseTimeMsec'])

### Create line for executiontime
plt.plot(df['blocksize'], df['executiontimeMsec'], c = 'red',  label='With loop blocking' )
### Create line for basetime
plt.plot(df['blocksize'], df['baseTimeMsec'], c = 'red', linestyle='dashed', label='Without loop blocking' )

plt.xlabel('block size')
plt.ylabel('Execution time in milliseconds')
# plt.yscale('log')
plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))
plt.title('N = 2048 (-r 1)')
plt.tight_layout(pad=0.1)



fig = plt.gcf()
fig.set_size_inches(4, 3)
fig.savefig('missRateGraph.png', bbox_inches='tight')
plt.show()