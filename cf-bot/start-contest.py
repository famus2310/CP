import requests
from bs4 import BeautifulSoup
import os
import sys

BASE_URL = "https://codeforces.com/contest/"
CONTEST = input("Input Contest Number:")

with requests.Session() as sess:
  url = BASE_URL + CONTEST  
  path = "/home/famus/Documents/CP/"
  if not os.path.isdir(os.path.join(path, "CF")):
    os.mkdir(os.path.join(path, "CF"))

  if not os.path.isdir(os.path.join(path, "CF/" + CONTEST)):
    os.mkdir(os.path.join(path, "CF/" + CONTEST))

  resp = sess.get(url)
  if not resp.ok:
    print("Invalid Contest")
    sys.exit(1)
  soup = BeautifulSoup(resp.text, 'html.parser')
  problems_no = len(soup.findAll("td", {"class" : "id"}))
  for i in range(problems_no):
    cur = str(chr(ord('A') + i))
    if not os.path.isdir(os.path.join(path, "CF/" + CONTEST + "/" + cur)):
      os.mkdir(os.path.join(path, "CF/" + CONTEST + "/" + cur))
    if not os.path.isdir(os.path.join(path, "CF/" + CONTEST + "/" + cur + "/sample")):
      os.mkdir(os.path.join(path, "CF/" + CONTEST + "/" + cur + "/sample"))
    problem_url = BASE_URL + '/' + CONTEST + '/problem/' + cur
    resp = sess.get(problem_url)
    soup = BeautifulSoup(resp.text, 'html.parser')
    inp = soup.findAll("div", {"class" : "input"})
    out = soup.findAll("div", {"class" : "output"})
    for i in range(1, len(inp) + 1):
      with open(os.path.join(path, "CF/" + CONTEST + "/" + cur + "/sample/in" + str(i)), "w+") as f:
        print(inp[i - 1].pre.text.lstrip())
        f.write(inp[i - 1].pre.text.lstrip())
      with open(os.path.join(path, "CF/" + CONTEST + "/" + cur + "/sample/out" + str(i)), "w+") as f:
        f.write(out[i - 1].pre.text.lstrip())

    with open(os.path.join(path, "CF/" + CONTEST + "/" + cur + '/run.sh'), "w+") as f:
      for i in range(1, len(inp) + 1):
        cmd = "./a.out < sample/in" + str(i) + " > sample/usr" + str(i)
        f.write(cmd + '\n')
        cmd = "diff sample/usr" + str(i) + " sample/out" + str(i)
        f.write(cmd + '\n') 
