#!/usr/bin/env python3
#Original from https://github.com/willkill07

from bs4 import BeautifulSoup
import requests
import json
import sys
import pypandoc
import os

#Assuming this is run from repo root
SESSION_KEY=open('./Tools/session_key.txt').read()

DESCR_URL = 'http://adventofcode.com/2018/day/{}'
DESCR = 'Day{:02}.md'

INPUT_URL = 'http://adventofcode.com/2018/day/{}/input'
INPUT = 'Day{:02}.txt'

SRC_DIR = 'Day{:02}/'

session = dict(session=SESSION_KEY)

def downloadDesc(day):
  print('Downloading description for Day {:02}...'.format(day)),
  r = requests.get(DESCR_URL.format(day), cookies=session)
  soup = BeautifulSoup(r.text, "html5lib")
  data = '\n'.join(str(p) for p in soup('article'))
  pypandoc.convert_text(data, 'markdown', format='html', outputfile='./'+SRC_DIR.format(day)+DESCR.format(day))
  print('Done')

def downloadInput(day):
  print('Downloading input for Day {:02}...'.format(day)),
  try:
    os.stat('./'+SRC_DIR.format(day)+INPUT.format(day))
    print('Already exists')
  except:
    r = requests.get(INPUT_URL.format(day), cookies=session)
    with open('./'+SRC_DIR.format(day)+INPUT.format(day), 'w') as of:
      of.write(r.text)
    print('Done')

def createDirIfNotExists(day):
  file_path = "./"+SRC_DIR.format(day)
  directory = os.path.dirname(file_path)
  print('Attempting to create directory {}...'.format(directory)),
  try:
    os.stat(directory)
    print('Already exists')
  except:
    os.mkdir(directory)
    os.mkdir(directory+'/bootstrap')
    print('Done')

def createCMakeGenerator(day):
    file_path = "./"+SRC_DIR.format(day)
    print('Checking if need to bootstrap day...'),
    try:
      os.stat(file_path+'/CMakeVars.txt')
      print('Already exists')
    except:
      file = open('./'+SRC_DIR.format(day)+'CMakeVars.txt', 'w')
      file.write('set (DAY {})\n'.format(day))
      file.write('set (DAY_PREFIX "Day{:02}")\n'.format(day))
      file.close()

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("Usage: {} <day>".format(sys.argv[0]))
  else:
    day = int(sys.argv[1])
    createDirIfNotExists(day)
    downloadDesc(day)
    downloadInput(day)
    createCMakeGenerator(day)
